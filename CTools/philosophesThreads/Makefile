##
## Makefile for philosophes-2015s-2016-2017si-sfez_a in /home/sfez_a/Local/projects/c/svn/philosophes-2015s-2016-2017si-sfez_a
##
## Made by sebastien bequignon
## Login   <bequig_s@epitech.net>
##
## Started on  Sun Mar 24 06:25:38 2013 sebastien bequignon
## Last update Sun Mar 24 20:47:13 2013 sebastien bequignon
##

NAME	=	philo

SRC	=	src/philo.c \
		src/xfunc.c \
			src/actions.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -Iinclude/

CC	=	gcc

RM	=	rm -f
ECHO	=	echo -e

all:	 $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lpthread
	@$(ECHO) '\033[0;33m> Compiled\033[0m'

clean:
	$(RM) $(OBJ)
	@$(ECHO) '\033[0;33m> Directory cleaned\033[0m'

fclean:	clean
	$(RM) $(NAME)
	@$(ECHO) '\033[0;33m> Remove executable\033[0m'

re:	fclean all

.PHONY:	all clean fclean re

repair:		
	echo -en '\033[?25h'