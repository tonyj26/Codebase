import binascii
import socket
import struct
import sys
import hashlib

UDP_IP = "127.0.0.1"
UDP_PORT = 5005
unpacker = struct.Struct('I I 8s 32s')


def check_chksum(packet):
    values = (packet[0], packet[1], packet[2])
    packer = struct.Struct('I I 8s')
    packed_data = packer.pack(*values)
    chksum = bytes(hashlib.md5(packed_data).hexdigest(), encoding="UTF-8")
    if packet[3] == chksum:
        return True
    else:
        return False


def listen(ip, port):
    sock = socket.socket(socket.AF_INET,
                        socket.SOCK_DGRAM)
    sock.bind((ip, port))

    while True:
        data, addr = sock.recvfrom(1024)
        UDP_Packet = unpacker.unpack(data)
        print("received from:", addr)
        print("received message:", UDP_Packet)
        
        if check_chksum(UDP_Packet) == True:
            print('CheckSums Match, Packet OK')
        else:
            print('Checksums Do Not Match, Packet Corrupt')

listen(UDP_IP, UDP_PORT)
