open Door

module type SQUARE =
  sig
    type square

    val new_square : int list -> square
    val empty : unit -> square
    val is_empty : square -> bool  

    val get_id : square -> int
    val set_id : square -> int -> unit
    val get_nbDoors : square -> int
    val get_doors : square -> int list
  end

module Square : SQUARE =
  struct

    type square = {id : int ref; doors : int list}

    let new_square l = 
      {id = ref 0; doors = l}
	
    let empty () = {id = ref 0; doors = []}

    let is_empty {doors = r} = (r = []) 

    let get_id {id = r} = !r
    let set_id {id = r} value = r := value 
    let get_nbDoors {doors = doors} = List.length doors
    let get_doors {doors = r} = r
  end
