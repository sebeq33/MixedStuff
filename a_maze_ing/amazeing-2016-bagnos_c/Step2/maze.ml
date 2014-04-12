open Square
open Door

module type MAZE =
  sig

    type maze

    val new_maze : int -> int -> maze

    (*val display_maze : maze -> unit*)

    val get_dimx : maze -> int
    val get_dimy : maze -> int
    val get_start : maze -> (int * int)
    val get_finish : maze -> (int * int)
    val set_start : maze -> (int * int) -> unit
    val set_finish : maze -> (int * int) -> unit
    val get_square : maze -> int -> int -> Square.square
    val set_square : maze -> int -> int -> int -> unit

    val in_maze : maze -> int -> int -> bool
    val check_end : maze -> bool

    val gen_maze : maze -> (maze -> maze) -> maze
    val gen_random : maze -> maze
    val gen_stack : maze -> maze

  end

module Maze : MAZE =
  struct

    (* ################################ *)
    (* #                              # *)
    (* #                              # *)
    (* #          Maze init           # *)
    (* #                              # *)
    (* #                              # *)
    (* ################################ *)

    type maze = {dimx : int; 
		 dimy : int; 
		 nb_door : int;
		 start : (int * int) ref; 
		 finish : (int * int) ref; 
		 doors : Door.door array;
		 tab : Square.square array array}
    
    let maze_init maze =
      let {dimx = dimx; dimy = dimy; nb_door = nb_door; doors = doors; tab = tab} = maze in
      let door_line = dimx * 2 - 1 in
      let rec init x y = 
	let valid_door id = (id / door_line = y && id >= 0 && id < nb_door) in
	match x, y with
	  | x, y when y >= dimy	-> maze
	  | x, y when x >= dimx	-> init x (y + 1)
	  | x, y			->
	    let right = y * door_line + x in
	    let down = right + dimx - 1 in
	    let around = (right)::(right - 1)::(down)::(right - dimx)::[] in
	    let doors_list = List.filter valid_door around
	    in
	    begin
	      if (right < nb_door) then
		doors.(right) <- Door.new_door (x, y) (x + 1, y);
	      if (down < nb_door) then
		doors.(down) <- Door.new_door (x, y) (x, y + 1);
	      tab.(x).(y) <- Square.new_square doors_list;
	      init (x + 1) y
	    end
      in
      init 0 0

    let new_maze dx dy = maze_init
      {dimx = dx;
       dimy = dy;
       nb_door = (((dx * dy) - 1) * 2);
       start = ref (-1, -1);
       finish = ref (-1, -1);
       doors = Array.make (((dx * dy) - 1) * 2) (Door.new_door (-1, -1) (-1, -1));
       tab = Array.make_matrix (dx) (dy) (Square.new_square [])}	

    (* ################################ *)
    (* #                              # *)
    (* #                              # *)
    (* #          Maze utils          # *)
    (* #                              # *)
    (* #                              # *)
    (* ################################ *)

    let in_maze {dimx = dimx; dimy = dimy} x y =
      (x >= 0 && y >= 0 && x < dimy && y < dimy)

    let check_end {dimx = dimx; dimy = dimy; tab = tab} = 
      let rec rec_check check x y = match x, y with
      	| x, y when y >= dimy					-> true
      	| x, y when x >= dimx					->
      	  rec_check check 0 (y + 1)
      	| x, y when (Square.get_id (tab.(y).(x)) != check)	-> false
      	| x, y							->
      	  rec_check check (x + 1) (y)
      in
      rec_check (Square.get_id (tab.(0).(0))) 1 0

    (*let display_maze {dimx = dimx; dimy = dimy; tab = tab; doors = doors} = 
      let rec bottom_doors x y = match x, y with
	| x, y when y >= dimy - 1	-> ()
	| x, y when x >= dimx		-> print_newline ()

	| x, y				->
	  begin
	    begin
	      if (x < dimx) then
		begin
		  let down = (y * (dimx * 2 - 1) + x + dimx - 1) in		
		try
		  let res = List.find (fun x -> x = down) (Square.get_doors tab.(x).(y)) in
		  if Door.is_open (doors.(res)) then print_char ' ' else print_char '-'
		with
		  | Not_found -> print_char '-'
		end;
                if (x < dimx - 1) then
                  print_char '+'
	    end ;
	     bottom_doors (x + 1) y
	  end
      in
      let rec display x y = match x, y with
      	| x, y when y >= dimy		-> ()
      	| x, y when x >= dimx		->
	  begin
	    print_newline ();
	    bottom_doors 0 y;
	    display 0 (y + 1)
	  end
	| x, y				->
	  begin
	    print_int (Square.get_id tab.(x).(y));
	    begin
	      if (x < dimx - 1) then
		let right = y * (dimx * 2 - 1) + x in		
		try
		  let res = List.find (fun x -> x = right) (Square.get_doors tab.(x).(y)) in
		  if Door.is_open (doors.(res)) then print_char ' ' else print_char '|'
		with
		    Not_found -> print_char '|'
	    end;
	    display (x + 1) y
	  end
      in
      display 0 0*)


    (* ################################ *)
    (* #                              # *)
    (* #                              # *)
    (* #      Maze getter/setter      # *)
    (* #                              # *)
    (* #                              # *)
    (* ################################ *)

    let get_dimx {dimx = r} = r
    let get_dimy {dimy = r} = r
    let get_start {start = r} = !r
    let get_finish {finish = r} = !r
    let set_start {start = r} pos = r := pos 
    let set_finish {finish = r} pos = r := pos 

    let get_square maze x y =
      let {dimx = _; dimy = _; start = _; finish = _; tab = tab} = maze in
      if (in_maze maze x y) then
	tab.(y * 2).(x * 2)
      else
	Square.empty ()

    let set_square maze x y id =
      let {dimx = _; dimy = _; start = _; finish = _; tab = tab} = maze in
      if (in_maze maze x y) then
	Square.set_id tab.(x).(y) id 
	  
    (* ################################ *)
    (* #                              # *)
    (* #                              # *)
    (* #        Maze generation       # *)
    (* #                              # *)
    (* #                              # *)
    (* ################################ *)
	
    let gen_maze maze gen =
      begin
	Random.self_init ();
	gen maze
      end
	
    let gen_random maze = maze

    let gen_stack maze =
      let {dimx = dimx; dimy = dimy; tab = tab; doors = doors} = maze in
      let in_maze x y = (x >= 0 && y >= 0 && y < dimy && x < dimx) in
      let door_avail x y =
	let can_open id = 
	  let (destx, desty) = Door.get_other doors.(id) (x, y) in
	  (in_maze destx desty && (Square.get_id tab.(destx).(desty) = 0)) 
	in
	let list = List.filter can_open (Square.get_doors tab.(x).(y)) in
	begin
	  (* List.iter (fun x -> print_int x) list; *)
	  List.map (fun id -> doors.(id)) list
	end
      in
      let rec rec_gen x y stack = 
	let good_doors = door_avail x y in
	match good_doors, stack with
	  | [], []			-> print_endline "END"; maze
	  | [], (newx, newy)::tail	-> rec_gen newx newy tail
	  | good_doors, stack		->
	    let choosen_door = 
	      List.nth good_doors (Random.int (List.length good_doors)) 
	    in
	    let (newx, newy) = 
	      Door.get_other choosen_door (x, y)
	    in 
	    begin
	      print_endline "CONTINUE";
	      Door.open_door choosen_door;
	      Square.set_id tab.(newx).(newy) 1;
	      rec_gen newx newy ((x, y)::stack)
	    end
      in
      let starty = (Random.int dimy) in
      let startx = (Random.int dimx) in
      begin
	print_endline "STACK";
	rec_gen startx starty ((startx, starty)::[])
      end

  end
