
open Maze

let start x y gen = 
  let generator = match gen with
    | "stack"	-> Maze.gen_stack
    | "random"	-> Maze.gen_random
    | _		-> raise (Invalid_argument "Generator don't exist")
  in
  begin
    Printf.printf "Size %d %d %s\n" x y gen;
    Test.display_maze (Maze.gen_maze (Maze.new_maze x y) generator)
  end

let main () = 
  if Array.length Sys.argv > 2 then
    begin
      try
	let x = int_of_string (Sys.argv.(1)) in
	let y = int_of_string (Sys.argv.(2)) in
	let gen = 
	  if (Array.length Sys.argv > 3) then
	    Sys.argv.(3)
	  else
	    "random" 
	in
	start x y gen
      with
	| Invalid_argument(value)	-> print_endline value
	| Failure(_)			-> print_endline "Need ints"
    end
  else
    print_endline "./step1 x y"
	
let _ = main ()
