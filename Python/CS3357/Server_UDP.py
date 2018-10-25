#!/usr/bin/env python3

# Server_UDP.py
# Kyle Cheung
# Commands: "exit", "What is the current date and time?"

import socket 
import datetime

# grabs ip and port number from user
print("UDP_IP: ", end="")
UDP_IP = input()            # localhost: '127.0.0.1'
print("UDP_PORT: ", end="") 
UDP_PORT = int(input())     # default port: 5005
BUFFER_SIZE = 1024

# creates the socket using SOCK_DGRAM as the socket type(UDP)
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # Creates a UDP socket 
s.bind((UDP_IP, UDP_PORT))
print(f"listening on UDP_IP: {UDP_IP}, UDP_PORT: {UDP_PORT} .., ")

while True:
    print("Waiting to receive Message")

    # breaks up the data and the address from received datagram
    data, addr = s.recvfrom(BUFFER_SIZE)
    print('Connection Address:', addr)
    if not data: break

    # compare received data to valid commands
    if (bytes.decode(data) == "What is the current date and time?"):
        print ("received data:", data)
        toSend = "Current Date and Time - " + \
            str(datetime.datetime.now().strftime("%m/%d/%y %H:%M:%S"))
        # sends response
        s.sendto(str.encode(toSend), addr)

        # if exit command is sent
    elif (bytes.decode(data) == "exit"):
        s.close()
        break

    else: 
        # if command is invalid
        print("Invalid Command")
        s.sendto(str.encode("Invalid Command"), addr)

# close connection
s.close()
