
(* ################################ *)
(* #                              # *)
(* #                              # *)
(* #         maze display         # *)
(* #                              # *)
(* #                              # *)
(* ################################ *)

let display_maze maze dimy dimx = 
  let rec rec_display maze y x = match y, x with
    | y, x when y >= dimy	-> print_newline ()
    | y, x when x >= dimx	->
      begin		
	print_newline ();
	rec_display maze (y + 1) 0
      end			
    | y, x			-> 
      begin
	Printf.printf "%3d " maze.(y).(x);
	rec_display maze (y) (x + 1)
      end
  in
  rec_display maze 0 0

let check_end maze dimy dimx = 
  let rec rec_check maze check y x = match y, x with
    | y, x when y >= dimy			-> true
    | y, x when x >= dimx			-> 
      rec_check maze check (y + 1) 0
    | y, x when (maze.(y).(x) != check)		-> false
    | y, x					->
      rec_check maze check (y) (x + 1)
  in
  rec_check maze (maze.(0).(0)) 0 1

let create_maze dimy dimx gen =
  begin
    Random.self_init (); 
    gen (Array.make_matrix dimy dimx 0) dimy dimx
  end

(* ################################ *)
(* #                              # *)
(* #                              # *)
(* #     random maze creation     # *)
(* #     100 * 100 ~= 2.4 sec     # *)
(* #                              # *)
(* ################################ *)

let gen_random_maze maze dimy dimx = 
  let init_maze maze = 
    let rec rec_init maze y x = match y, x with
      | y, x when y >= dimy			-> ()
      | y, x when x >= dimx			-> 
	rec_init maze (y + 1) 0
      | y, x					->
	begin
	  maze.(y).(x) <- ((y * dimx) + x);
	  rec_init maze (y) (x + 1)
	end
    in
    rec_init maze 0 0
  in
  let try_open maze y x id =
    let in_maze y x = (x >= 0 && y >= 0 && y < dimy && x < dimx) in
    let rec open_way maze y x id new_id =
      if ((in_maze y x) && (maze.(y).(x) = id)) then
	begin
	  maze.(y).(x) <- new_id;
	  open_way maze y (x + 1) id new_id;
	  open_way maze y (x - 1) id new_id;
	  open_way maze (y + 1) x id new_id;
	  open_way maze (y - 1) x id new_id
	end
    in
    if ((in_maze y x) && (maze.(y).(x) != id)) then
      begin
	open_way maze y x maze.(y).(x) id;
	true
      end
    else
      false
  in
  let random_gen maze limit =
    let rec rec_random_gen maze y x limit = 
      match (limit = 0) || (limit = -1 && check_end maze dimy dimx) with
      | true	-> ()
      | false	-> 
	let check_door nb_door = match Random.int nb_door with
	  | 0 -> try_open maze y (x + 1) maze.(y).(x)
	  | 1 -> try_open maze y (x - 1) maze.(y).(x)
	  | 2 -> try_open maze (y + 1) x maze.(y).(x)
	  | 3 -> try_open maze (y - 1) x maze.(y).(x)
	  | _ -> false
	in
	begin
	  let opened = check_door 4 in
	  let next_limit = if (opened && limit > 0) then limit - 1 else limit in
	  rec_random_gen maze (Random.int dimy) (Random.int dimx) next_limit
	end
    in
    rec_random_gen maze (Random.int dimy) (Random.int dimx) limit
  in
  let end_gen maze =
    let rec rec_end_gen maze y x = match y, x with
      | y, x when y >= dimy		-> ()
      | y, x when x >= dimx		-> rec_end_gen maze (y + 1) 0
      | y, x				->
	begin
	  ignore (try_open maze y (x + 1) maze.(y).(x));
	  ignore (try_open maze y (x - 1) maze.(y).(x));
	  ignore (try_open maze (y + 1) x maze.(y).(x));
	  ignore (try_open maze (y - 1) x maze.(y).(x));
	  rec_end_gen maze (y) (x + 1)
	end
    in
    rec_end_gen maze 0 0
  in
  begin
    init_maze maze;
    let lim = 
      (int_of_float ((float_of_int dimy) *. (float_of_int dimx) *. 1.0)) - 1 
    in
    random_gen maze lim;
    if (check_end maze dimy dimx = false) then
      begin
	end_gen maze
      end;
    maze
  end

(* ################################# *)
(* #                               # *)
(* #                               # *)
(* #  back_tracking maze creation  # *)
(* #     100 * 100 = 0.12 sec      # *)
(* #                               # *)
(* ################################# *)

let gen_stack_maze maze dimy dimx =
  let in_maze y x = (x >= 0 && y >= 0 && y < dimy && x < dimx) in
  let can_open maze y x = (in_maze y x && maze.(y).(x) = 0) in
  let door_avail maze y x =
    let rec check_door maze y x current res = 
      if (current >= 4) then
	res
      else
	let next_res = match current with
	  | 0				-> 
	    if (can_open maze y (x + 1)) then ((y, (x + 1))::res) else res
	  | 1				->
	    if (can_open maze y (x - 1)) then ((y, (x - 1))::res) else res
	  | 2				->
	    if (can_open maze (y + 1) x) then (((y + 1), x)::res) else res
	  | 3				->
	    if (can_open maze (y - 1) x) then (((y - 1), x)::res) else res
	  | _				-> res
	in
	check_door maze y x (current + 1) next_res
    in
    check_door maze y x 0 []
  in
  let rec rec_gen maze y x stack = 
    let doors = door_avail maze y x in
    if (List.length doors = 0) then match stack with
      | []			-> maze
      | (newy, newx)::tail	-> rec_gen maze newy newx (List.tl stack)
    else
      let (newy, newx) = List.nth doors (Random.int (List.length doors)) in 
      begin
	maze.(newy).(newx) <- 1;
	rec_gen maze newy newx ((y, x)::stack)
      end
  in
  let starty = (Random.int dimy) in
  let startx = (Random.int dimx) in
  rec_gen maze starty startx ((starty, startx)::[])

