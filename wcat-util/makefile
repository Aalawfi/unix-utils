CC = gcc
PROGRAM := wcat
OBJ := wcat.c
CFLAGS= -Wall -Werror -g
$(PRGORAM): $(PROGRAM).o 
	$(CC) $(PROGRAM).o -o $(PROGRAM)

$(PROGRAM).o : $(PROGRAM).c 
	$(CC) -c $(PROGRAM).c -o $(PROGRAM).o $(CFLAGS)
clean:
	rm -f *.o
