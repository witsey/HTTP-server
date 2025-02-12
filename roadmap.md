Phase 1: Fundamentals & Setup
--------------------------------
- Learn About Sockets in C:
  - Understand socket(), bind(), listen(), accept(), recv(), and send().
  - Experiment with a simple TCP server that accepts a connection and sends a basic response.

- Understand HTTP Basics:
  - Read the HTTP/1.1 specification (RFC 2616) and learn about request/response structure.
  - Understand common HTTP methods (GET, POST, PUT, DELETE) and response status codes.



Phase 2: Building a Minimal HTTP Server 
----------------------------------------
- Create a Simple HTTP Server:
  - Bind to a port (e.g., 8080) and listen for incoming connections.
  - Accept and handle a single client request.
  - Parse a simple HTTP request (e.g., GET / HTTP/1.1).
  - Send a basic HTTP response (200 OK with plain text).
 
- Handle Multiple Clients (Concurrency): 
  - Use fork(), pthread, or select()/poll() to handle multiple clients.
  - Ensure the server can process multiple connections efficiently.



Phase 3: Improving Request Handling **<-- currently here**
------------------------------------
- Parse HTTP Headers Properly: 
  - Read the entire HTTP request (headers + body).
  - Extract request method, URL, and headers.

- Serve Static Files:
  - Implement file handling to serve .html, .css, .js, and images.
  - Use open(), read(), and write() to send files.
  - Implement proper Content-Type headers.

- Handle Different HTTP Methods:
  - Support GET for serving files.
  - Support POST and read request bodies.



Phase 4: Advanced Features
--------------------------
- Logging & Error Handling:
  - Log requests to a file (method, URL, timestamp).
  - Send proper error responses (404 Not Found, 500 Internal Server Error).

- Implement Basic Routing:
  - Create a simple routing mechanism (/about, /contact).
  - Map URLs to different response handlers.

- Optimize Performance:
  - Use epoll (Linux) for better performance.
  - Implement a thread pool to handle connections efficiently.



Phase 5: Bonus Features (Optional)
-----------------------------------
- Add CGI Support:
  - Execute scripts (e.g., Python, PHP) to generate dynamic content.

- Add HTTPS Support:
  - Use OpenSSL to handle encrypted HTTPS connections.

- Support HTTP/1.1 Features:
  - Implement persistent connections (Connection: keep-alive).
  - Implement chunked transfer encoding.