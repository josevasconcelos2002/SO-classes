CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: mycat mycp

mycat: mycat.c
	$(CC) $(CFLAGS) -o mycat mycat.c

mycp: mycp.c
	$(CC) $(CFLAGS) -o mycp mycp.c

clean:
	rm -f mycat mycp