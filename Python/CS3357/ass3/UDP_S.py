import binascii
import socket
import struct
import sys
import hashlib

# ip and port
UDP_IP = "127.0.0.1"
UDP_PORT = 5005

# structs or packing and unpacking into byte objects
unpacker = struct.Struct('I I 8s 32s')
packer = struct.Struct('I I 8s')
packet_struct = struct.Struct('I I 32s')
ack_data = struct.Struct('I I') 

# create an ack packet to send back to client
def make_ack(ack, seq):

    # pack the ack
    values = (ack, seq)
    packed_data = ack_data.pack(*values)

    # calculate the checksum  and pack it into a packet with the ack
    chksum = bytes(hashlib.md5(packed_data).hexdigest(), encoding="UTF-8")
    pack_values = (ack, seq, chksum)
    packet_data = packet_struct.pack(*pack_values)
    return packet_data


# checks the checksum and returns true if correct
def check_chksum(packet):
    values = (packet[0], packet[1], packet[2])
    packed_data = packer.pack(*values)
    chksum = bytes(hashlib.md5(packed_data).hexdigest(), encoding="UTF-8")
    if packet[3] == chksum:
        return True
    else:
        return False


# listen for messages
def listen(ip, port):

    # open UDP socket for listening 
    sock = socket.socket(socket.AF_INET,
                        socket.SOCK_DGRAM)
    sock.bind((ip, port))

    while True:

        # receive from socket
        data, addr = sock.recvfrom(4096)

        # unpack packet and print
        UDP_Packet = unpacker.unpack(data)
        print("received from:", addr)
        print("received message:", UDP_Packet)
        
        # check the checksum
        if check_chksum(UDP_Packet) == True:
            print('CheckSums Match, Packet OK')
            ackresp = make_ack(1, UDP_Packet[1])

            # send ack back to client
            sock.sendto(ackresp, addr)
        else:
            print('Checksums Do Not Match, Packet Corrupt')

            # packet is corrupt, let it time out
            time.sleep(.009)

listen(UDP_IP, UDP_PORT)
