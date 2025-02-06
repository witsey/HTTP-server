# Simple TCP Server in C (Windows)

## Overview
This project is a basic TCP server written in C using the Winsock library. The server listens for incoming connections on **port 8080** and sends a simple response to clients. This is part of a learning journey to understand **socket programming** and **network communication** in C.

## Features
✅ Creates a TCP socket using `socket()`  
✅ Binds the socket to an IP and port using `bind()`  
✅ Listens for incoming connections using `listen()`  
✅ Accepts client connections using `accept()`  
✅ Sends a basic HTTP response to the client  

## How to Run
### Prerequisites
- Windows OS
- MinGW or MSVC (for compiling C code)
- Git (optional, for version control)

### Steps
1. **Clone the Repository** (if applicable)
   ```sh
   git clone <your-repo-url>
   cd <your-repo-folder>
   ```
2. **Compile the Code**
   Using MinGW:
   ```sh
   gcc server.c -o server.exe -lws2_32
   ```
   Using MSVC:
   ```sh
   cl server.c /link ws2_32.lib
   ```
3. **Run the Server**
   ```sh
   server.exe
   ```
4. **Test the Server**
   - Open a browser and visit: `http://127.0.0.1:8080`
   - You should see `Hello, world!` displayed.

## How It Works
This program follows the standard steps for creating a server:
1. **Initialize Winsock** using `WSAStartup()`
2. **Create a socket** using `socket(AF_INET, SOCK_STREAM, 0)`
3. **Configure socket options** with `setsockopt()`
4. **Define the server address** (`sockaddr_in` structure)
5. **Bind the socket** to the address using `bind()`
6. **Start listening** for connections using `listen()`
7. **Accept incoming connections** using `accept()`
8. **Send a response** to the client (`send()`) before closing the connection
9. **Cleanup** using `closesocket()` and `WSACleanup()`

## Next Steps
🚀 Implement **handling multiple clients**  
🚀 Add **better error handling & logging**  
🚀 Serve **static files (HTML, CSS, JS)**  
🚀 Make the server accessible over a network  

## Contribution
If you want to contribute, feel free to fork the repo and submit a pull request. Feedback and improvements are welcome!

