##
## Makefile for Makefile in /home/bequig_s//workspace/systemUnixTek2/lemiPC/lemiPC/lemipc
## 
## Made by sebastien bequignon
## Login   <bequig_s@epitech.net>
## 
## Started on  Sun Mar 31 01:25:08 2013 sebastien bequignon
## Last update Sun Mar 31 19:16:13 2013 sebastien bequignon
##

NAME		= lemipc
NAME_DISPLAY	= lemipc_display

SRC_LEMI 	= common_utils.c \
		check_start.c \
	 	player.c \
		player_utils.c \
		player_update.c \
		player_move.c \
		manage_ipc.c \
		manage_msg.c \
		main.c 

SRC_DISPLAY 	= display.c \
		manage_ipc.c \
		up_display.c \
		curses.c \
		common_utils.c

OBJ_LEMI	= $(SRC_LEMI:.c=.o)
OBJ_DISPLAY	= $(SRC_DISPLAY:.c=.o)

CFLAGS		= -Wall -Wextra -Werror

CC		= gcc

RM		= rm -f
ECHO		= echo -e


all	: $(NAME) $(NAME_DISPLAY)

$(NAME)	: $(OBJ_LEMI)
	$(CC) -o $(NAME) $(OBJ_LEMI) -lm

$(NAME_DISPLAY)	: $(OBJ_DISPLAY)
	$(CC) -o $(NAME_DISPLAY) $(OBJ_DISPLAY) -lncurses

clean	:
	$(RM) $(OBJ_LEMI)
	$(RM) $(OBJ_DISPLAY)

fclean	: clean
	$(RM) $(NAME)
	$(RM) $(NAME_DISPLAY)

re	: fclean all

