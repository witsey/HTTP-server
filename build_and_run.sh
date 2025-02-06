#!/bin/bash
gcc src/server.c -o bin/server.exe -lws2_32
./bin/server.exe