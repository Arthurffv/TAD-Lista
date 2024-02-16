#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

int main() {
  TLista Lista01;
  TLista Lista02;

  FLVazia(&Lista01);
  FLVazia(&Lista02);
  Vazia(Lista01);
  Vazia(Lista02);

  MENU(&Lista01, &Lista02);

  LiberarLista(&Lista01);
  LiberarLista(&Lista02);

  return 0;
}
