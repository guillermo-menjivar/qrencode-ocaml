


    type t 
    
    external create : unit -> t = "ocaml_QRinput_new" 
    (* external create2 : int -> int -> t *)
    external append : t -> QRencodeMode.t -> int -> String.t -> int = "ocaml_QRinput_append"
    
