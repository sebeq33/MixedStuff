##
## Makefile for Makefile in /home/bequig_s//workspace/asm/asm
## 
## Made by sebastien bequignon
## Login   <bequig_s@epitech.net>
## 
## Started on  Tue Mar 26 19:54:19 2013 sebastien bequignon
## Last update Fri Mar 29 19:15:31 2013 sebastien bequignon
##

NAME	= libasm.so
FORMAT	= elf64
RM	= rm -f

OBJ	= memcpy.o \
	memmove.o \
	memset.o \
	rindex.o \
	strcasecmp.o \
	strchr.o \
	strcspn.o \
	strlen.o \
	strncmp.o \
	strpbrk.o \
	strstr.o

CFLAGS	= -f elf64


CC	= nasm

all	: $(NAME)

$(NAME)	:
	nasm -f $(FORMAT) memcpy.S -o memcpy.o
	nasm -f $(FORMAT) memmove.S -o memmove.o
	nasm -f $(FORMAT) memset.S -o memset.o
	nasm -f $(FORMAT) rindex.S -o rindex.o
	nasm -f $(FORMAT) strcasecmp.S -o strcasecmp.o
	nasm -f $(FORMAT) strchr.S -o strchr.o
	nasm -f $(FORMAT) strcspn.S -o strcspn.o
	nasm -f $(FORMAT) strlen.S -o strlen.o
	nasm -f $(FORMAT) strncmp.S -o strncmp.o	
	nasm -f $(FORMAT) strpbrk.S -o strpbrk.o
	nasm -f $(FORMAT) strstr.S -o strstr.o
	gcc -shared $(OBJ) -o $(NAME)

main:
	gcc main.c -L. -lasm -o maintest -fno-builtin

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

