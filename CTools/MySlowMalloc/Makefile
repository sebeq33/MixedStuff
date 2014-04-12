##
## Makefile for Makefile in /home/bequig_s//workspace/systemUnixTek2/malloc/malloc
## 
## Made by sebastien bequignon
## Login   <bequig_s@epitech.net>
## 
## Started on  Thu Jan 31 15:43:29 2013 sebastien bequignon
## Last update Sat Feb  9 15:38:01 2013 caroline bagnost
##

NAME	= libmy_malloc_$(HOSTTYPE).so

SRC	= malloc.c \
	free.c \
	c_realloc.c \
	show_alloc_mem.c \
	mutex_call.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -fPIC -c -W -Wall -Werror -Wextra 

CC	= gcc

RM	= rm -f
ECHO	= echo -e

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) -shared  -o $(NAME) $(OBJ) -W -Wall -Werror -Wextra
	ln -s $(PWD)/$(NAME) libmy_malloc.so
	@$(ECHO) '\033[0;33m> Compiled\033[0m'


clean	:
	$(RM) $(OBJ)
	@$(ECHO) '\033[0;33m> Directory cleaned\033[0m'

fclean	: clean
	$(RM) $(NAME)
	@$(ECHO) '\033[0;33m> Remove executable\033[0m'

re	: fclean all

