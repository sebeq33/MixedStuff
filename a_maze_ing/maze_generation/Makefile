NAME	= amazeing

ML 	= door.ml	\
	square.ml	\
	maze.ml	\
	main.ml

MLI 	= door.mli	\
	square.mli	\
	maze.mli

CMI 	= $(MLI:.mli=.cmi)
CMO 	= $(ML:.ml=.cmo)
CMX 	= $(ML:.ml=.cmx)


OCAMLDPE  	= ocamldep
CAMLFLAGS 	= -w Aelz -warn-error A
OCAMLC 	  	= ocamlc $(CAMLFLAGS)
OCAMLOPT  	= ocamlopt $(CAMLFLAGS)


all:		.depend $(CMI) $(NAME)

byte:		.depend $(CMI) $(NAME).byte

$(NAME):	$(CMX)
		$(OCAMLOPT) -o $@ $(CMX)

$(NAME).byte:	$(CMO)
		$(OCAMLC) -o $@ $(CMO)

%.cmx:		%.ml
		$(OCAMLOPT) -c $<

%.cmo:		%.ml
		$(OCAMLC) -c $<

%.cmi:		%.mli
		$(OCAMLC) -c $<


re:		fclean all


clean:
		/bin/rm -f *.cm* *.o .depend *~


fclean: 	clean
		/bin/rm -f $(NAME) $(NAME).byte


.depend:
		/bin/rm -f .depend
		$(OCAMLDPE) $(MLI) $(ML) > .depend
