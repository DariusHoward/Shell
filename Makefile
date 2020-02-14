# Variable Declaration
CC = gcc
CFLAGS = -c -Wall
OBJECT = fibonacci.o hello.o shell.o 
PROGRAM = uab_sh
DEP = functions.h
# Rules
all: $(PROGRAM)

fibonacci.o: fibonacci.c $(DEP)
		$(CC) $(CFLAGS) fibonacci.c

hello.o: hello.c $(DEP)
		$(CC) $(CFLAGS) hello.c

shell.o: shell.c $(DEP)
		$(CC) $(CFLAGS) shell.c

$(PROGRAM): $(OBJECT) $(DEP)
		$(CC) $(OBJECT) -o $(PROGRAM)

exec:
		./uab_sh

clean:
		rm -rf uab_sh
		rm -rf *.o
#End of file
