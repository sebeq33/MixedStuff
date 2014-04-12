open Sdl
open Sdlwm
open Sdlevent
open Sdlkey
open Sdlvideo
open Int32
open List
open Maze

(* Ordre des surfaces : Screen - ground - wall - vdoor - hdoor *)

module type DISPLAY =
  sig
    type display

    val new_display : int -> int -> display
    val calc_ws : int -> int -> int
    val calc_hs : int -> int -> int
    val create_item : display -> int -> int -> surface
    val color_item : surface -> color -> unit 
    val show_item : int -> int -> surface -> surface -> unit
    val set_color : surface list -> int -> unit
    val create_wall : display -> surface list -> int -> int -> unit 
    val create_door : display -> surface list -> int -> int -> maze -> unit
    val create_door : display -> surface list -> int -> int -> maze -> unit
    val create_window : display -> surface list -> int -> int -> maze -> unit
    val init : display -> surface list
    val display : surface list -> display -> maze -> unit
    val wait_for_escape : display -> surface list -> maze -> unit
    val loop : display -> maze -> unit
    val display_maze : maze -> unit
  end

module Display : DISPLAY =
  struct

    type display = { rmask : int32;
		     gmask : int32;
		     bmask : int32;
		     amask : int32;
		     w : int;
		     h : int;
		     ws : int;
		     hs : int;
		     realw : int;
		     realh : int}

    let calc_ws w h = match w, h with
      | w, h when w >= 42 && h >= 42 -> 2
      | _ , _ -> 5

    let calc_hs w h = match w, h with
      | w, h when w >= 42 && h >= 42 -> 8
      | _ , _ -> 20

    let new_display width height =
      let wall_width = calc_ws width height in
      let wall_height = calc_hs width height in
      { rmask = of_int 0;
	gmask = of_int 0;
	bmask = of_int 0;
	amask = of_int 255;
	w = width;
	h = height;
	ws = wall_width;
	hs = wall_height;
        realw = (wall_width + wall_height) * width - wall_width;
        realh = (wall_width + wall_height) * height - wall_width}
	
    let create_item d w h = create_RGB_surface [`HWSURFACE] w h 32 d.rmask d.gmask d.bmask d.amask
      
    let color_item item color = fill_rect item (map_RGB item color)
      
    let show_item x y src dest = 
      begin
	let pos = rect x y 5 5 in
	blit_surface ~dst_rect:pos ~src:src ~dst:dest ()
      end
	
    let rec set_color list n = match list with
      | [] -> ()
      | head::tail -> if n < 2 then 
	  begin 
	    color_item head white; 
	    set_color tail (n + 1);
	  end
	else
	  begin 
	    color_item head black; 
	    set_color tail (n + 1);
	  end

    let create_wall d list x y =
	show_item ((d.hs) + x) ((d.hs) + y) (nth list 2) (nth list 0)
	  
    let create_vdoor d list x y maze =
      begin
	let square = Maze.get_square maze x y in
	let res = List.find (fun x -> x = square.right) (Square.get_doors tab.(x).(y)) in 
	if Door.is_open (door.(res)) then show_item ((d.hs) + x) (y) (nth list 3) (nth list 0);      
      end

    let create_hdoor d list x y maze =
      begin
	let square = Maze.get_square maze x y in
	let res = List.find (fun x -> x = square.down) (Square.get_doors tab.(x).(y)) in
	if Door.is_open (door.(res)) then show_item (x) ((d.hs) +y) (nth list 4) (nth list 0);
      end

    let create_window d list x y maze= 
      begin 
	set_color (tl list) 1;
	create_wall d list x y maze;
	create_vdoor d list x y maze;
	create_hdoor d list x y maze;
	show_item (x) (y) (nth list 1) (nth list 0);
      end

    let init d = 
      begin 
	init [`VIDEO];
	[set_video_mode ~w:(d.realw) ~h:(d.realh) ~bpp:16 [`HWSURFACE];
	 create_item d d.hs d.hs;
	 create_item d d.ws d.ws;
	 create_item d d.ws d.hs;
	 create_item d d.hs d.ws]
      end

    let display list d maze = 
      let rec set_maze d x y maze = match x, y with
	| x, y when y >= d.realh -> () 
	| x, y when x >= d.realw -> set_maze d 0 (y + (d.ws + d.hs)) maze
	| x, y		-> 
	  begin
	    create_window d list x y maze;
	    set_maze d (x + (d.ws + d.hs)) y maze;
	  end
      in
      begin
	color_item (nth list 0) white; 
	set_maze d 0 0 maze;
	flip (nth list 0);
      end

    let rec wait_for_escape d list maze =
      match wait_event () with
	| VIDEOEXPOSE -> display list d maze
	| QUIT -> ()
	| KEYDOWN {keysym=KEY_ESCAPE} -> ()
	| event ->
          wait_for_escape d list maze

    let loop d maze =
      let list = init d in
      begin
	set_caption "A-Maze-Ing" "";
	display list d maze;
	wait_for_escape d list maze;
	quit ();
      end
	
    let display_maze maze = 
      begin
	let d = new_display maze.dimx maze.dimy in
	loop d maze;
      end
  end
