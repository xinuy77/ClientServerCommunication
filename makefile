SOURCES = server.c client.c io.c socket.c main.c
HEADERS = defs.h
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
FLAGS = -Wall -std=c99 -ggdb3

EXECUTABLE = main

TESTFILE = tester

PACKAGE_NAME = assignment_7
PACKAGE = $(SOURCES) $(HEADERS) README.md makefile 

all : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(FLAGS) -o $@ $(OBJECTS)

defbug : $(SOURCES)
	$(CC) $(FLAGS) -o $(EXECUTABLE) $(SOURCES)
.o:
	$(CC) $(FLAGS) -g -c $< $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

test: $(EXECUTABLE) 
	./$(EXECUTABLE) < $(TESTFILE)

tar: $(PACKAGE)
	rm -f $(PACKAGE_NAME).tar
	tar -cvf $(PACKAGE_NAME).tar $(PACKAGE)

clean:
	rm -f main a.out
	rm -f *.o
	rm -f $(PACKAGE_NAME).tar
