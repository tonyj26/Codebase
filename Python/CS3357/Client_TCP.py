#!/usr/bin/env python3

# Client_TCP.py
# Kyle Cheung
# Commands: "exit", "What is the current date and time?"

import socket

# IP and PORT
TCP_IP = '127.0.0.1'
TCP_PORT = 5005
BUFFER_SIZE = 1024

# creates client socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))

while True:
    # gets user input
    print("Enter Message: ", end="")
    msg = input()

    # if exit command break close connection
    if (msg == "exit"):
        s.send(str.encode(msg))
        s.close()
        break
    s.send(str.encode(msg))
    data = s.recv(BUFFER_SIZE)
    print("received data:", data)
# close socket
s.close()

