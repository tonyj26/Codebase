#!/usr/bin/env python3

# Server_TCP.py
# Kyle Cheung
# Commands: "exit", "What is the current date and time?"

import socket 
import datetime

# grabs IP and PORT number from user
print("TCP_IP: ", end="")
TCP_IP = input()            # localhost: '127.0.0.1'
print("TCP_PORT: ", end="") 
TCP_PORT = int(input())     # default port: 5005
BUFFER_SIZE = 1024

# creates the socket with default values
s = socket.socket()         # Defaults to socket.AF_INET and socket.SOCK_STREAM

# reuse the port to avoid address in use errors
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

# binds the port and listens for clients
s.bind((TCP_IP, TCP_PORT))
s.listen(1)
print(f"listening on TCP_IP: {TCP_IP}, TCP_PORT: {TCP_PORT} .., ")

# accepts the request
conn, addr = s.accept()
print ('Connection Address:', addr)
while True:

    # received message
    data = conn.recv(BUFFER_SIZE)
    if not data: break

    # message comparison to valid command
    if (bytes.decode(data) == "What is the current date and time?"):
        print ("received data:", data)

        # formats date and time
        sendTo = "Current Date and Time - " + datetime.datetime.now().strftime("%m/%d/%y %H:%M:%S")

        # sends data to client then closes connection
        conn.send(str.encode(sendTo))

    # if exit code
    elif(bytes.decode(data) == "exit"):
        break

    else: 

        # if invalid command
        print("Invalid Command")
        conn.send(str.encode("Invalid Command"))

#close connection
conn.close()
