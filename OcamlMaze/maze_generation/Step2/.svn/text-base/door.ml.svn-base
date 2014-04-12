module type DOOR =
  sig
    type status
    type door
      
    val new_door : (int * int) -> (int * int) -> door
    val is_open : door -> bool
    val open_door : door -> unit
    val get_status : door -> status
    val set_status : door -> status -> unit
    val get_left : door -> (int * int)
    val get_right : door -> (int * int)
    val get_other : door -> (int * int) -> (int * int)
      
  end

module Door : DOOR =
  struct

    type status = Open | Close
    type door = {status : status ref; right : (int * int); left : (int * int)}

    let new_door r l = {status = ref Close; right = r; left = l}

    let is_open {status = r} = if (!r = Open) then true else false
    let open_door {status = r} = r := Open
    let set_status {status = r} stat = r := stat 
    let get_status {status = r} = !r
    let get_left {right = r} = r
    let get_right {left = l} = l
    let get_other {right = r; left = l} current =
      if (current = r) then l else r
      
  end
