#!/usr/bin/env python3

import socket 
import datetime

print("TCP_IP: ", end="")
TCP_IP = input()            # localhost: '127.0.0.1'
print("TCP_PORT: ", end="") 
TCP_PORT = int(input())     # default port: 5005
BUFFER_SIZE = 1024

s = socket.socket()         # Defaults to socket.AF_INET and socket.SOCK_STREAM
s.bind((TCP_IP, TCP_PORT))
s.listen(1)
print(f"listening on TCP_IP: {TCP_IP}, TCP_PORT: {TCP_PORT} .., ")

conn, addr = s.accept()
print ('Connection Address:', addr)
while True:
    data = conn.recv(BUFFER_SIZE)
    if not data: break
    if (bytes.decode(data) == "What is the current date and time?"):
        print ("received data:", data)
        print("Current Date and Time - ", datetime.datetime.now().strftime("%m/%d/%y %H:%M:%S"))

    else: print("Invalid Command")
    conn.send(data) #echo
conn.close()
