CC = gcc

all: sieve

clean: 
	rm -f *.o sieve

%.o: %.c
	$(CC) -c $< 

sieve: main.o sieve.o point.o circle.o bb.o
	$(CC)  $^ -o $@
