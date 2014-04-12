##
## Makefile for Makefile in /home/bequig_s//workspace/piscine-Tek2/d01/ex01
## 
## Made by sebastien bequignon
## Login   <bequig_s@epitech.net>
## 
## Started on  Wed Jan  9 11:42:34 2013 sebastien bequignon
## Last update Wed Jan  9 21:15:24 2013 sebastien bequignon
##

NAME	= menger_face

SRC	= menger.c \
	drawing.c \
	bitmap_header.c \
	main.c 

OBJ	= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror -std=gnu99

CC	= gcc

RM	= rm -f
ECHO	= echo -e

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_PATH)

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

