CC = gcc
CFLAGS = -Wall -g

all: process_scheduler

process_scheduler: main.o process.o scheduler.o
	$(CC) $(CFLAGS) -o process_scheduler main.o process.o scheduler.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o process_scheduler
