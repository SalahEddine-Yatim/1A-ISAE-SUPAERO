CC = gcc
CFLAGS = -std=c99 -Wall -o 

myprog : prog.c point.c point.h		
	$(CC) $(CFLAGS) myprog prog.c point.c

run	: myprog
	./myprog

committer : 

	svn commit -m "je commit avec makefile"