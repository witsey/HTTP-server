# Simple Multithreaded TCP Server in C (Windows)

## Overview
This project is a basic **multithreaded** TCP server written in C using the Winsock library. The server listens for incoming connections on **port 8080** and sends a simple HTTP response. It demonstrates **socket programming, multithreading, and basic HTTP handling** in Windows.

## Features  
✅ **Socket Initialization**: Uses Winsock (`WSAStartup()`) to create a TCP socket.  
✅ **Binding & Listening**: Binds to `localhost:8080` and listens for incoming connections.  
✅ **Multithreading**: Uses `CreateThread()` to handle multiple clients concurrently.  
✅ **Basic HTTP Handling**: Sends a simple `Hello, world!` response.  
✅ **Graceful Cleanup**: Uses `closesocket()` and `WSACleanup()`.  

## How to Build & Run

### Prerequisites  
- Windows OS  
- **MinGW** or **MSVC** (for compiling C code)  
- Git (optional, for version control)  

### Steps  

1. **Clone the Repository**  
   ```sh
   git clone <your-repo-url>
   cd <your-repo-folder>
   ```
2. **Compile the Code**  
   - Using **MinGW**:  
     ```sh
     gcc src/server.c -o bin/server.exe -lws2_32
     ```
   - Using **MSVC**:  
     ```sh
     cl src/server.c /link ws2_32.lib
     ```

3. **Run the Server**  
   ```sh
   bin/server.exe
   ```
4. **Test the Server**  
   - Open a **browser** and visit: [`http://127.0.0.1:8080`](http://127.0.0.1:8080)  
   - Or use **cURL** in a terminal:  
     ```sh
     curl -v http://localhost:8080
     ```
   - You should see:  
     ```sh
     Hello, world!
     ```

## How It Works  

1. **Initialize Winsock** (`WSAStartup()`)  
2. **Create a TCP socket** (`socket(AF_INET, SOCK_STREAM, 0)`)  
3. **Configure socket options** (`setsockopt()`)  
4. **Bind the socket** (`bind()`) to `localhost:8080`  
5. **Listen for incoming connections** (`listen()`)  
6. **Accept client connections** (`accept()`)  
7. **Create a new thread** for each client using `CreateThread()`  
8. **Handle the client request** (introduce a delay to test multithreading)  
9. **Send a response** (`send()`) and close the connection  
10. **Cleanup** (`closesocket()`, `WSACleanup()`)  

## Testing Multithreading  
To verify multithreading, send multiple requests in quick succession:  
```sh
curl -v http://localhost:8080 &
curl -v http://localhost:8080 &
```
If working correctly, multiple requests will be processed **simultaneously**.

## Next Steps 🚀  
🔹 **Improve HTTP Parsing**: Extract method, headers, and request body.  
🔹 **Serve Static Files**: Handle `.html`, `.css`, `.js`, and images.  
🔹 **Support HTTP Methods**: Implement `GET` (serve files) and `POST` (read body).  
🔹 **Thread Pool & Demultiplexing**: Optimize performance for concurrent requests.  

## Contribution  
If you’d like to contribute:
1. ** check out the project roadmap on my notion page https://www.notion.so/HTTP-Server-Project-19d9ebfa16f8809eb893c548ff83956c?pvs=4 or simple read roadmap.md**
2. **Fork the repo**  
3. **Create a new branch**  
4. **Submit a pull request**  

