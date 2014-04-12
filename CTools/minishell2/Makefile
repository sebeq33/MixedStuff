##
## Makefile for Makefile in /home/bequig_s//workspace/module-Unix/minishell
## 
## Made by sebastien bequignon
## Login   <bequig_s@epitech.net>
## 
## Started on  Sun Nov 11 18:53:37 2012 sebastien bequignon
## Last update Fri Nov 30 16:42:00 2012 sebastien bequignon
##

NAME	= mysh

SRC	= minishell.c \
	read_cmd.c \
	exec.c \
	manage_env.c \
	cat_string.c \
	parser_cmd.c \
	parser_buffer.c \
	print_errors.c \
	change_dir.c \
	setenv.c \
	unsetenv.c \
	env_free_exit.c

LIB_PATH = minilib/libmy.a
MAKE_LIB_PATH = minilib/

OBJ	= $(SRC:.c=.o)

CC	= cc

CFLAGS	= -Wall -pedantic

RM	= rm -f
ECHO	= echo -e

all	: $(NAME)

$(NAME)	: $(OBJ)
	make -C $(MAKE_LIB_PATH)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_PATH)
	@$(ECHO) '\033[0;33m> Compiled\033[0m'

clean	:
	$(RM) $(OBJ)
	@$(ECHO) '\033[0;33m> Directory cleaned\033[0m'

fclean	: clean
	$(RM) $(NAME)
	@$(ECHO) '\033[0;33m> Remove executable\033[0m'

re	: fclean all

