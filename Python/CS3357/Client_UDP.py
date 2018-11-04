#!/usr/bin/env python3

# Client_UDP.py
# Kyle Cheung
# Commands: "exit", "What is the current date and time?"

import socket

# specified port and ip address
UDP_IP = '127.0.0.1'
UDP_PORT = 5005
BUFFER_SIZE = 1024

# creates client socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
while True:

    # get user message
    print("Enter Message: ", end="")
    msg = input()

    # closes client if exit command
    if (msg == "exit"):

        # encodes the string and sends it to server
        s.send(str.encode(msg))
        break
    s.send(str.encode(msg))

    # response from server
    data = s.recv(BUFFER_SIZE)
    print("received data: ", data)

# close socket

