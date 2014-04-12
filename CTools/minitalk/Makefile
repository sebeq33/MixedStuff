##
## Makefile for Makefile in /home/bequig_s//workspace/module-Unix/minitalk
## 
## Made by sebastien bequignon
## Login   <bequig_s@epitech.net>
## 
## Started on  Mon Nov 12 14:24:45 2012 sebastien bequignon
## Last update Fri Nov 16 20:31:55 2012 sebastien bequignon
##

NAME		= minitalk
CLIENT_NAME	= client
SERVER_NAME	= server

CLIENT_SRC	= client.c
SERVER_SRC	= server.c \
		manage_clients.c \
		manage_signal.c

LIB_PATH	= minilib/libmy.a
MAKE_LIB_PATH	= minilib/

CLIENT_OBJ	= $(CLIENT_SRC:.c=.o)
SERVER_OBJ	= $(SERVER_SRC:.c=.o)

CFLAGS		= 
DFLAGS		= -Werror -Wall -pedantic -g

CC		= cc
RM		= rm -f
ECHO		= echo -e

all	: $(NAME)

$(NAME)	: lib $(CLIENT_NAME) $(SERVER_NAME)

client	: $(CLIENT_NAME)
server	: $(SERVER_NAME)

$(CLIENT_NAME)	: $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJ) $(LIB_PATH)
	@$(ECHO) '\033[0;33m> Client compiled\033[0m'

$(SERVER_NAME)	: $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJ) $(LIB_PATH)
	@$(ECHO) '\033[0;33m> Server compiled\033[0m'

clean	:
	$(RM) $(CLIENT_OBJ) 
	$(RM) $(SERVER_OBJ) 
	@$(ECHO) '\033[0;33m> Directory cleaned\033[0m'

lib:
	make -C $(MAKE_LIB_PATH)

fclean	: clean
	$(RM) $(CLIENT_NAME)
	$(RM) $(SERVER_NAME)	
	@$(ECHO) '\033[0;33m> Remove executables\033[0m'

re	: fclean all

