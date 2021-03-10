#
# wycat.c
# Author: Romello Wallace
# Date: Feb 18, 2020
#
# COSC 3750, Homework 4
#
# This is a simple version of the cat utility. It is
# designed to read either from standard input and files
# and write to standard output
#
CC=gcc
CFLAGS=-ggdb -Wall
.PHONY: clean
wyls: 
	$(CC) $(CFLAGS) -o wyls wyls.c
clean:
	/bin/rm -f wyls
