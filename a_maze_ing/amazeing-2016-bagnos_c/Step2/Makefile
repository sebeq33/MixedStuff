OCAML=ocamlopt
OCAMLFLAGS= -I +sdl
OCAMLLD= bigarray.cmxa sdl.cmxa

test: door.ml square.ml maze.ml test.ml main.ml
	${OCAML} ${OCAMLFLAGS} ${OCAMLLD} -o test door.ml square.ml maze.ml test.ml main.ml

clean::
	rm -f *~ *.o *.cm? test

