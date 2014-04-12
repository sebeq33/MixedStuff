##
## Makefile for bequig_s in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
## 
## Made by sebastien bequignon
## Login   <bequig_s@epitech.net>
## 
## Started on  Sun Apr 14 19:12:41 2013 sebastien bequignon
## Last update Sun Apr 14 19:19:57 2013 sebastien bequignon
##

NAME		=	serveur
NAME2		=	client



SRC_SERVER	= server.c		\
		server_loop.c		\
		server_exec.c		\
		server_files.c		\
		server_ls.c		\
		server_path.c		\
		file_put.c		\
		file_get.c		\
		my_str_to_wordtab.c	\
		get_next_line.c		\
		my_getnbr.c

SRC_CLIENT	= client.c		\
		client_loop.c		\
		client_actions.c	\
		file_put.c		\
		file_get.c		\
		my_str_to_wordtab.c	\
		get_next_line.c		\
		my_getnbr.c

CFLAGS		=	-W -Wall

OBJ_C     	=       $(SRC_CLIENT:.c=.o)

OBJ_S		=	$(SRC_SERVER:.c=.o)

CC              =       gcc
RM		=	rm -f

all:		$(NAME) $(NAME2)

$(NAME):	$(OBJ_S)
		$(CC) -o $(NAME) $(OBJ_S) $(CFLAGS)

$(NAME2):	$(OBJ_C)
		$(CC) -o $(NAME2) $(OBJ_C) $(CFLAGS)


clean:
		$(RM) $(OBJ_C) $(OBJ_S)

fclean:
		$(RM) $(OBJ_S) $(NAME)
		$(RM) $(OBJ_C) $(NAME2)

re: 		fclean all

.PHONY:		all clean fclean re
