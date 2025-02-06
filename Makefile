CC = gcc
CFLAGS = -lws2_32
SRC = src/server.c
BIN = bin/server.exe

all: $(BIN)

$(BIN): $(SRC)
    $(CC) $(SRC) -o $(BIN) $(CFLAGS)

run: $(BIN)
    ./$(BIN)

clean:
    rm -f $(BIN)