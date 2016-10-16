CFLAGS=-Wall -g

all: clean create see

clean:
	rm -f b.hack

create:
	cc assembler.c 
	./a.out <Add.asm >b.hack

see:
	cat b.hack
