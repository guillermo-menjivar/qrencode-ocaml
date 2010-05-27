OCAMLC = ocamlfind ocamlc 

all: 
	$(OCAMLC) -c qrencode_stubs.c
	$(OCAMLC) -c qRencodeMode.mli
	$(OCAMLC) -c qRinput.mli
	$(OCAMLC) -c qRcode.mli


test: 
	$(OCAMLC) -custom qrencode_stubs.o test.ml -o test -cclib -lqrencode 

clean: 
	rm -f *.o
	rm -f *.cm*
	rm -f test