# 📞 minitalk

> A project from 42 (1337) Coding School that implements a simple **inter-process communication** using **signals** in C. The objective is to demonstrate a basic communication protocol between two processes using Unix signals.

## 📌 Project Overview

In this project, I implemented a messaging system between a **client** and a **server** using Unix signals. The client sends messages to the server, which decodes and prints the received messages. The key challenge is to use **signals** to transmit characters as binary data, building a communication system purely based on **signal handling**.

---

## 🎯 Objectives

- **Client**: Send a message to the server by encoding each character as a binary signal.
- **Server**: Receive the binary signals, decode them into characters, and print the message.
- Handle the communication using **Unix signals**.
- Minimize the number of operations and optimize signal handling.

---

## 🧩 How It Works

The communication works as follows:
1. **Client**:
   - Sends a signal to the server for each **bit** of the message.
   - A `SIGUSR1` signal is sent for `0` and `SIGUSR2` for `1`.
   - After sending the complete message, the client waits for an acknowledgment from the server to confirm the message was received.

2. **Server**:
   - Listens for the incoming signals.
   - Each signal is translated into a binary bit and accumulated to form a complete character.
   - After each message, the server prints the decoded message and sends an acknowledgment signal back to the client.

---

## 🧰 How to Compile and Run

### 1. Clone the repository

```bash
git clone https://github.com/na7li/minitalk.git
cd minitalk
```

### 2. Compile the code
```bash
make
```

### 3. Run the Server
```bash
./server
```

### 4. Run the Client
In a different terminal, run the client:

```bash
./client <server_pid> <message>
```

Where:
* <server_pid>: the PID of the server process
* <message>: the message to be sent

For example:
```bash
./client 12345 "Hello"
```
The client will send the message "Hello" to the server running with PID 12345.

## ⚙️ Tools & Libraries
* Language: C
* Signals: UNIX signals (SIGUSR1, SIGUSR2, etc.)
* Compiler: gcc
* System: Linux or macOS

## 📝 Notes
* The server and client communicate using signals (i.e., SIGUSR1, SIGUSR2), which are sent one by one.
* The system is designed to handle one character at a time, but it can work with longer messages by encoding each character bit by bit.
* It is a simple example of inter-process communication using Unix signals, demonstrating how processes can share data without the use of shared memory, pipes, or sockets.

## 👨‍💻 Author
Mohamed NAHLI – 1337 Coding School
🔗 github.com/na7li/minitalk_42
