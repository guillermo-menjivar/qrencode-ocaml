type t
external encode : QRinput.t -> t = "ocaml_QRcode_encodeInput"
external to_png : t -> int -> int -> String.t ->  unit = "ocaml_writePNG"
