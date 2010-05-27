open Printf

let _ = 
  let input = QRinput.create () in 
  let mode = QRencodeMode.mode_num () in 
  let rc = QRinput.append input mode 0 "test" in 
  let code = QRcode.encode input in
    printf "@@@ %d\n" rc ; flush stdout 
