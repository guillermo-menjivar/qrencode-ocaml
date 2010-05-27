/* 
 * stubs
 */

// STD
#include <stdio.h>

// OCAML 
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/custom.h>

// QRENCODE 
#include <qrencode.h>

/********************************/
/* Dealing with 'struct QRcode' */
/********************************/

static struct custom_operations qrcode_ops = {
  "tmf.qrencode.qrcode",
  custom_finalize_default,
  custom_compare_default,
  custom_hash_default,
  custom_serialize_default,
  custom_deserialize_default
};

/* Accessing the QRcode * part of a Caml custom block */
#define QRcode_val(v) (*((QRcode **) Data_custom_val(v)))

/* Allocating a Caml custom block to hold the given QRcode * */
static value alloc_QRcode(QRcode * w)
{
  value v = alloc_custom(&qrcode_ops, sizeof(QRcode *), 0, 1);
  QRcode_val(v) = w;
  return v;
}

/*********************************/
/* Dealing with 'struct QRinput' */
/*********************************/


/* Accessing the QRinput * part of a Caml custom block */
#define QRinput_val(v) (*((QRinput **) Data_custom_val(v)))

void ocaml_QRinput_finalize (value qrinput) 
{
  printf ("@@@ About to finalize qrinput value"); 
  QRinput_free (QRinput_val (qrinput)); 
  return ;
}

static struct custom_operations qrinput_ops = {
  "tmf.qrencode.qrcode",
  ocaml_QRinput_finalize,
  custom_compare_default,
  custom_hash_default,
  custom_serialize_default,
  custom_deserialize_default
};

/* Allocating a Caml custom block to hold the given QRinput * */
static value alloc_QRinput(QRinput * w)
{
  value v = alloc_custom(&qrinput_ops, sizeof(QRinput *), 0, 1);
  QRinput_val(v) = w;
  return v;
}

/*************************************/
/* Dealing with typedef QRencodeMode */
/*************************************/

/* Accessing the QRencodeMode * part of a Caml custom block */
#define QRencodeMode_val(v) (*((QRencodeMode **) Data_custom_val(v)))

void ocaml_QRencodeMode_finalize (value mode)
{
  printf ("@@@ About to finalize mode value"); 
  free (QRencodeMode_val (mode)) ; 
  return ;  
}

static struct custom_operations qrencodemode_ops = {
  "tmf.qrencode.qrencodemode",
  ocaml_QRencodeMode_finalize,
  custom_compare_default,
  custom_hash_default,
  custom_serialize_default,
  custom_deserialize_default
};

/* Allocating a Caml custom block to hold the given QRinput * */
static value alloc_QRencodeMode(QRencodeMode * w)
{
  value v = alloc_custom(&qrencodemode_ops, sizeof(QRencodeMode *), 0, 1);
  QRencodeMode_val(v) = w;
  return v;
}


/***********************/
/* Cst creation        */
/* This is probably overkill */
/***********************/

value ocaml_QRencodeMode_num (value unit) 
{
  CAMLparam1(unit); 
  QRencodeMode *mode = (QRencodeMode *) malloc (sizeof (QRencodeMode)); 
  *mode = QR_MODE_NUM; 
  CAMLreturn (alloc_QRencodeMode(mode)) ;
}

value ocaml_QRencodeMode_an(value unit) 
{
  CAMLparam1(unit); 
  QRencodeMode *mode = (QRencodeMode *) malloc (sizeof (QRencodeMode)); 
  *mode = QR_MODE_AN; 
  CAMLreturn (alloc_QRencodeMode(mode)) ;
}

value ocaml_QRencodeMode_8 (value unit) 
{
  CAMLparam1(unit); 
  QRencodeMode *mode = (QRencodeMode *) malloc (sizeof (QRencodeMode)); 
  *mode = QR_MODE_8; 
  CAMLreturn (alloc_QRencodeMode(mode)) ;
}

value ocaml_QRencodeMode_kanji (value unit) 
{
  CAMLparam1(unit); 
  QRencodeMode *mode = (QRencodeMode *) malloc (sizeof (QRencodeMode)); 
  *mode = QR_MODE_KANJI; 
  CAMLreturn (alloc_QRencodeMode(mode)) ;
}



/**********************************/
/* Input data                     */
/**********************************/

value ocaml_QRinput_new(value unit)
{
  CAMLparam1 (unit);
  QRinput * new_input = QRinput_new (); 
  CAMLreturn (alloc_QRinput (new_input));
}


value ocaml_QRinput_append(value input, value mode, value size, value data) 
{
  CAMLparam4 (input, mode, size, data); 
  int rc = QRinput_append (QRinput_val(input), 
			   *(QRencodeMode_val (mode)), 
			   Int_val (size), 
			   (const unsigned char *) String_val (data)); 
  CAMLreturn (Val_int (rc)) ;  
}


/***********************************/
/* Code data                       */
/***********************************/

value ocaml_QRcode_encodeInput (value input) 
{
  CAMLparam1(input); 
  QRcode * new_code = QRcode_encodeInput (QRinput_val (input)); 
  CAMLreturn (alloc_QRcode (new_code)); 
}
