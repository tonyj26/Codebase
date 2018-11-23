import binascii
import socket
import struct
import sys
import hashlib
import time

# IP and port 127.0.0.1 needed for loopback
UDP_IP = "127.0.0.1"
UDP_PORT = 5005

# structs for packign and unpacking data
unpacker = struct.Struct('I I 32s')
sent_data = struct.Struct('I I 8s 32s')
ack_packer = struct.Struct('I I')
UDP_data = struct.Struct(' I I 8s')


# Current ack and seq number
ACK = 0
SEQ = 0


# packets to send
packet_list = [b'NCC-1701', b'NCC-1664', b'NCC-1017']

print("UDP target IP:" ,UDP_IP)
print("UDP target Port:", UDP_PORT)

# creates the socket, sets a time out of 9ms for the socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
timeout = sock.settimeout(.009)

def is_corrupt(packet):
    # packs the values and computes checksum
    values = (packet[0], packet[1])
    packed_data = ack_packer.pack(*values)
    chksum = bytes(hashlib.md5(packed_data).hexdigest(), encoding="UTF-8")
    
    # check if checksums match
    if packet[2] == chksum:
        return True
    else:
        return False

# compute the checksum for the packet
def compute_chksum(ack, seq, data):
    # creates a tuple of values, and packs them as a byte object
    values = (ack, seq, data)
    packed_data = UDP_data.pack(*values)

    # compute the checksum from the byte object
    chksum = bytes(hashlib.md5(packed_data).hexdigest(), encoding="UTF-8")
    return chksum

# create the packet to send
def make_pkt(ack, seq, data):

    # calculate checksum
    chksum = compute_chksum(ack, seq, data)

    # pack values including checksum and create a byte object 
    values = (ack, seq, data, chksum)
    UDP_PACKET_DATA = struct.Struct('I I 8s 32s')
    UDP_PACKET = UDP_PACKET_DATA.pack(*values)
    return UDP_PACKET 

def udt_send(data):

    # send the packet over udp 
    sock.sendto(data, (UDP_IP, UDP_PORT))
    send_packet = sent_data.unpack(data)
    print("sent packet", send_packet)

def rdt_send(data):

    # lets us access the global seq number
    global SEQ
    cur_seq = SEQ

    while cur_seq == SEQ:

        # sends the packet
        udt_send(data)
        resp = ''
        addr = ''

        try:

            # receives data from server
            resp, addr = sock.recvfrom(4096)

        # if socket times out
        except socket.timeout:
            print("timer expired")
            continue

        # the packet is received, check if gucci
        resp_packet = unpacker.unpack(resp)

        if is_corrupt(resp_packet) == True:
            print("Packet received okay")
        else:
            print("corrupted ack")

        # wrong sequence number
        while resp_packet[1] != cur_seq:
            continue

        #change the sequence number after each packet
        SEQ = (SEQ + 1) % 2



# main run
for data in packet_list:
    rdt_send(make_pkt(ACK, SEQ, data))
