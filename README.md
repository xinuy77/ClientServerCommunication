# Preamble
- author 	    : Yu Yamanaka, Christopher Blackman
- purpose 	    : Client/Server bijective comunication
- assumtions    : None abrut connections 
- source	    : main.c, server.c, client.c, socket.c 
- headers	    : defs.h
- data files    : None

# Compiling

```bash
# in order to compile
make build

# in order to run
make run

# in order to clean up the dir
make clean
```

# Direction
1. Compile
2. Run
3. Choose mode
- Enter talk to send message as client mode
- Enter wait to recieve message as server mode
4. If client mode
- enter ip address of server you want to connect
5. If server mode
- default port is set to 60002
- wait for connection from client
