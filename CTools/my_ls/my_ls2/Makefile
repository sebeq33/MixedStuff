##
## Makefile for libmy in /home/bequig_s//workspace/libmy
##
## Made by sebastien bequignon
## Login   <bequig_s@epitech.net>
##
## Started on  Mon Oct 22 09:29:19 2012 sebastien bequignon
## Last update Sun Nov  4 22:07:19 2012 sebastien bequignon
##

NAME	= my_ls

LIB_PATH = ./minilib/libmy.a
MAKE_LIB_PATH = ./minilib/

SRC	= display.c \
	insert_file_list.c \
	main.c \
	manage_dir_list.c \
	manage_file.c \
	manage_file_list.c \
	manage_param.c \
	manage_path.c \
	my_ls.c \
	my_strcmp_ls.c

OBJ	= $(SRC:.c=.o)

CC	= cc

CFLAGS  = -Wall -pedantic -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_PATH)

lib:
	make -C $(MAKE_LIB_PATH)
	make re
clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f $(NAME)

re: fclean all
