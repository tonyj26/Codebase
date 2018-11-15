import binascii
import socket
import struct
import sys
import hashlib
import time

UDP_IP = "127.0.0.1"
UDP_PORT = 5005
unpacker = struct.Struct('I I 32s')
TIMEOUT = .009
ACK = 0
SEQ = 0


packet_list = ['NCC-1701', 'NCC-1664', 'NCC-1017']

print("UDP target IP:" ,UDP_IP)
print("UDP target Port:", UDP_PORT)

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

def start_timer():
    start_time = timer.perf_counter()


def compute_chksum(ack, seq, data):
    values = (ack, seq, data)
    UDP_Data = struct.Struct('I I 8s')
    packed_data = UDP_Data.pack(*values)
    chksum = bytes(hashlib.md5(packed_data).hexdigest(), encoding="UTF-8")
    return chksum

def make_pkt(ack, seq, data):

    chksum = compute_chksum(ack, seq, data)
    values = (ack, seq, data, chksum)
    UDP_PACKET_DATA = struct.Struct('I I 8s 32s')
    UDP_PACKET = UDP_PACKET_DATA.pack(*values)
    return UDP_PACKET

def udt_send(data):
    sock.sendto(data, (UDP_IP, UDP_PORT))

def rdt_send(data):
    udt_send(data)
    start_time = time.perf_counter()

    #while(start_time < TIMEOUT):
    #    resp, addr = sock.recvfrom(4096)
    #    rcvpkt = unpacker.unpack(resp)
    #    cur_seq = SEQ
    #    resp_seq = rcvpkt[1]




data = make_pkt(ACK, SEQ, b'NCC-1701')
rdt_send(data)


