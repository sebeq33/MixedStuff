##
## Makefile for libmy in /home/bequig_s//workspace/libmy
## 
## Made by sebastien bequignon
## Login   <bequig_s@epitech.net>
## 
## Started on  Mon Oct 22 09:29:19 2012 sebastien bequignon
## Last update Mon Apr 29 18:28:59 2013 sebastien bequignon
##

NAME		= liblist.a

SRC		= list.c 		\
		list_push.c 		\
		list_pull.c 		\
		list_search.c 		\
		list_next_prev.c 	\
		list_transform.c 	\
		list_common_utils.c	\
		list_default_func.c	\
		list_position.c		\
		list_apply.c 		\
		node.c

OBJ		= $(SRC:.c=.o)

CC		= gcc

CFLAGS		= -g

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean: 	
	rm -f ${OBJ}

fclean:	clean
	rm -f $(NAME)

re: fclean all
