##
## Makefile for libmy in /home/bequig_s//workspace/libmy
## 
## Made by sebastien bequignon
## Login   <bequig_s@epitech.net>
## 
## Started on  Mon Oct 22 09:29:19 2012 sebastien bequignon
## Last update Fri Nov 16 20:31:42 2012 sebastien bequignon
##

NAME		= libmy.a

MY.H_PATH	= my.h

DEST_PATH	= /afs/epitech.net/users/epitech_2015s/bequig_s/rendu

SRC	= my_getnbr.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_str_isnum.c \
	my_epur_str.c \
	my_strcpy.c \
	my_putstr_error.c

OBJ	= $(SRC:.c=.o)

CC	= cc

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@$(ECHO) '\033[0;33m> Lib compiled\033[0m'

cp : 
	cp $(NAME) $(DEST_PATH)/lib/
	cp $(MY.H_PATH) $(DEST_PATH)/include/

clean: 	
	rm -f ${OBJ}

fclean:	clean
	rm -f $(NAME)

re: fclean all
