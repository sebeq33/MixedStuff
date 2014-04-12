##
## Makefile for libmy in /home/bequig_s//workspace/libmy
## 
## Made by sebastien bequignon
## Login   <bequig_s@epitech.net>
## 
## Started on  Mon Oct 22 09:29:19 2012 sebastien bequignon
## Last update Fri Nov 23 00:50:47 2012 sebastien bequignon
##

NAME		= libmy.a

MY.H_PATH	= my.h

DEST_PATH	= /afs/epitech.net/users/epitech_2015s/bequig_s/rendu

SRC		= convert_base.c \
		my_find_prime_sup.c \
		my_getnbr.c \
		my_isalphanumeric.c \
		my_is_prime.c \
		my_power_rec.c \
		my_putchar.c \
		my_put_nbr.c \
		my_revstr.c \
		my_showmem.c \
		my_showstr.c \
		my_square_root.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strlcat.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strstr.c \
		my_strupcase.c \
		my_swap.c \
		my_swapchar.c \
		my_strdup.c \
		my_epur_str.c \
		my_remove_spaces.c \
		my_intlen.c \
		my_getstr.c \
		my_putstr_error.c \
		get_part_of_string.c \
		my_getenv.c \
		my_putstr.c

MY_PRINTF_SRC = my_printf/convert.c \
		my_printf/display.c \
		my_printf/display_common.c \
		my_printf/flags.c \
		my_printf/execution.c \
		my_printf/generate_query.c \
		my_printf/manage_flags.c \
		my_printf/manage_precision.c \
		my_printf/manage_types.c \
		my_printf/manage_width.c \
		my_printf/my_printf.c

OBJ	      = $(SRC:.c=.o)
MY_PRINTF_OBJ = $(MY_PRINTF_SRC:.c=.o)

CC		= cc

all: $(NAME)

$(NAME): $(OBJ) $(MY_PRINTF_OBJ)
	ar rc $(NAME) $(OBJ) $(MY_PRINTF_OBJ)
	ranlib $(NAME)

cp : 
	cp -r ~/workspace/libmy/* $(DEST_PATH)/lib/my/
	cp $(NAME) $(DEST_PATH)/lib/
	cp $(MY.H_PATH) $(DEST_PATH)/include/

clean: 	
	rm -f ${OBJ}

fclean:	clean
	rm -f $(NAME)

re: fclean all
