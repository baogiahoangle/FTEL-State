CC=gcc
CFLAGS=-I.

all: unit_test.exe

unit_test.exe: unit_test.o cmd.o
	$(CC) $^ -o $@

unit_test.o: unit_test.c
	$(CC) -c $< -o $@ $(CFLAGS)

cmd.o: cmd.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f *.o unit_test.exe