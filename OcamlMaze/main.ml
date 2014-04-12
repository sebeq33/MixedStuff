let start x y =
  Printf.printf "%d %d\n" x y

let main () = 
  if Array.length Sys.argv > 2 then
    try
      let x = int_of_string (Sys.argv.(1)) in
      let y = int_of_string (Sys.argv.(2)) in
      start x y
    with
	Failure(_) -> print_endline "Need ints"
  else
    print_endline "./step1 x y"
	
let _ = main ()
