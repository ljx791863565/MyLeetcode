#!/bin/bash
g++ -o client main_client.cpp Buffer.cpp InetAddress.cpp Socket.cpp Channel.cpp Epoller.cpp TcpServer.cpp -std=c++11 -pthread
