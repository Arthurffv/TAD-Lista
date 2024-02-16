#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int codigo;
  float preco;
  char nome[100];
  char descricao[200];
  int quantidade;
} TProduto;

typedef struct celula {
  TProduto Item;
  struct celula *prox;
} TCelula;

typedef struct {
  TCelula *primeiro;
  TCelula *ultimo;
  int tamanho;
} TLista;

void FLVazia(TLista *Lista);
int Vazia(TLista Lista);
void Inserir(TProduto x, TLista *Lista);
void ImprimirProduto(TProduto produto);
void Imprimir(TLista Lista);
TCelula *Pesquisar(TLista Lista, TProduto Item);
void Excluir(TLista *Lista, TProduto *Item);
void LerProduto(TProduto *Produto);
TCelula *PesquisarPorNome(TLista Lista, TProduto produto);
void LiberarLista(TLista *Lista);
void Atualizar(TLista *Lista, TProduto produto);
void ordemAlfabetica(TLista *lista);
int ListasIguais(TLista Lista01, TLista Lista02);
void JuntarListas(TLista *Lista01, TLista *Lista02);

#endif // LISTA_H_INCLUDED
