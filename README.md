# Minitalk - Simple communication system between a server and a client

## 📌 Overview
Minitalk is a project that involves creating a simple communication system between a server and a client using Unix signals. The client sends messages to the server, and the server processes and responds to them. The project focuses on learning how to use signals for inter-process communication, handling message encoding and decoding, and understanding how to manage processes.

## ⚡ Features
- Server-client communication using Unix signals.
- Sending messages in binary using signals.
- Efficient handling of multiple messages.

## 📂 Directory Structure
```
Minitalk/
├── includes/        # Header files
├── client.c         # Source code
├── server.c         # Source code
├── Makefile         # Compilation automation
└── README.md        # Project documentation
```

## 🚀 Installation
To compile and use Minitalk:
```sh
git clone https://github.com/Tudor-Ursescu/Minitalk.git
cd Minitalk
make
```
This will generate the executables `server` and `client`

## 🛠️ Usage
After compiling, you can use the program by running:
```sh
./server
./client [server_pid] [message]
```
- Start the server first using the command ./server.
- Then, run the client to send a message to the server. The client requires the server's PID and the message as arguments.
- If everything works fine, the server will receive the message and display it. And since communication is done by pushing bits, sending emojis or other Unicode characters will work correctly.

## 📜 License
This project is open-source.

## 👤 Author
[**Tudor Ursescu**](https://github.com/Tudor-Ursescu)