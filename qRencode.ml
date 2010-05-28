module QRencodeMode = 
  struct 
    type t 
    external mode_num : unit -> t = "ocaml_QRencodeMode_num"
    external mode_an : unit -> t = "ocaml_QRencodeMode_an"
    external mode_8 : unit -> t = "ocaml_QRencodeMode_8"
    external mode_kanji : unit -> t = "ocaml_QRencodeMode_kanji"
  end

module QRinput = 
  struct 
    type t 
    external create : unit -> t = "ocaml_QRinput_new" 
    external append : t -> QRencodeMode.t -> String.t -> int = "ocaml_QRinput_append"
  end

module QRcode = 
  struct 
    type t
    external encode : QRinput.t -> t = "ocaml_QRcode_encodeInput"
    external to_png : t -> int -> int -> String.t ->  unit = "ocaml_writePNG"
  end




