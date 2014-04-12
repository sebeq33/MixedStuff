NAMESERV	= server
NAMECLIENT	= client
SRCDIRSERV	= src_server
SRCDIRCLIENT	= src_client
SRCSERV		= $(SRCDIRSERV)/server.c
SRCCLIENT	= $(SRCDIRCLIENT)/client.c
LIB		= -L lib/ -lmy
INC		= -I include/
OBJSERV		= $(SRCSERV:.c=.o)
OBJCLIENT	= $(SRCCLIENT:.c=.o)

CC		= /usr/bin/gcc

CFLAGS		= -W -Wall -Wextra -ansi -pedantic $(INC)
CDEBUG		= -O2 -g -ggdb

RM		= rm -f
ECHO		= echo -e

all		: $(NAMESERV) $(NAMECLIENT)

$(NAMESERV)	: $(OBJSERV)
		@$(CC) $(INC) $(CFLAGS) -o $(NAMESERV) $(OBJSERV) $(LIB)
		@$(ECHO) '\033[0;32m> Serv Compiled\033[0m'

$(NAMECLIENT)	: $(OBJCLIENT)
		@$(CC) $(INC) $(CFLAGS) -o $(NAMECLIENT) $(OBJCLIENT) $(LIB)
		@$(ECHO) '\033[0;32m> Client Compiled\033[0m'

clean	:
	-@$(RM) $(OBJSERV)
	-@$(RM) *~
	-@$(RM) \#*#
	@$(ECHO) '\033[0;31m> Directory Serv cleaned\033[0m'

	-@$(RM) $(OBJSERV)
	-@$(RM) *~
	-@$(RM) \#*#
	@$(ECHO) '\033[0;31m> Directory Client cleaned\033[0m'


fclean	: clean
	-@$(RM) $(NAMESERV)
	-@$(RM) $(NAMECLIENT)
	@$(ECHO) '\033[0;31m> Remove executable\033[0m'

re	: fclean all

.PHONY	: all clean fclean re

debug	: $(OBJ)
	@$(CC) $(INC) $(CDEBUG) -o $(NAME) $(OBJ) $(LIB)
	@$(ECHO) '\033[0;33m> Mode Debug: done\033[0m'

