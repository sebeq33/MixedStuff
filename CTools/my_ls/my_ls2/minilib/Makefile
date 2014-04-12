##
## Makefile for libmy in /home/bequig_s//workspace/libmy
## 
## Made by sebastien bequignon
## Login   <bequig_s@epitech.net>
## 
## Started on  Mon Oct 22 09:29:19 2012 sebastien bequignon
## Last update Sun Nov  4 21:47:47 2012 sebastien bequignon
##

NAME		= libmy.a

SRC	= my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_strcat.c \
	my_strcmp.c \
	my_strcpy.c \
	my_strlen.c \
	my_strdup.c

OBJ	= $(SRC:.c=.o)

CC	= cc

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean: 	
	rm -f ${OBJ}

fclean:	clean
	rm -f $(NAME)

re: fclean all
