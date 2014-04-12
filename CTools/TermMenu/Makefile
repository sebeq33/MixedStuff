##
## Makefile for Makefile in /home/bequig_s//workspace/module-Unix/my_select
## 
## Made by sebastien bequignon
## Login   <bequig_s@epitech.net>
## 
## Started on  Mon Nov 19 18:18:05 2012 sebastien bequignon
## Last update Fri Nov 23 16:30:25 2012 sebastien bequignon
##

NAME	= my_select

SRC	= terminal.c \
	my_select.c \
	generate_list.c \
	my_strcmp_alpha.c \
	update_list.c \
	execute.c \
	display.c \
	manage_actions.c \
	actions.c \
	my_putstr_fd.c

LIB_PATH 	= minilib/libmy.a
MAKE_LIB_PATH 	= minilib/

OBJ	= $(SRC:.c=.o)

CFLAGS	=
DFLAGS	= -Wall -Werror -pedantic -g

CC	= cc

RM	= rm -f
ECHO	= echo -e

all	: $(NAME)

$(NAME)	: $(OBJ)
	make -C $(MAKE_LIB_PATH)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_PATH) -lncurses
	@$(ECHO) '\033[0;33m> Compiled\033[0m'

clean	:
	$(RM) $(OBJ)
	@$(ECHO) '\033[0;33m> Directory cleaned\033[0m'

fclean	: clean
	$(RM) $(NAME)
	@$(ECHO) '\033[0;33m> Remove executable\033[0m'

re	: fclean all

