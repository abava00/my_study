all:  mysh old_mysh

clean:
	rm -f  mysh

mysh: old_mysh.c
	gcc -o old_mysh old_mysh.c -Wall

mysh: mysh.c
	gcc -o mysh mysh.c -Wall
