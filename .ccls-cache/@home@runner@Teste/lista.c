#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

void FLVazia(TLista *Lista) {
  Lista->primeiro = (TCelula *)malloc(sizeof(TCelula));
  Lista->ultimo = Lista->primeiro;
  Lista->primeiro->prox = NULL;
  Lista->tamanho = 0;
}

int Vazia(TLista Lista) { return (Lista.primeiro == Lista.ultimo); }

void Inserir(TProduto x, TLista *Lista) {
  Lista->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
  Lista->ultimo = Lista->ultimo->prox;
  Lista->ultimo->Item = x;
  Lista->ultimo->prox = NULL;
  Lista->tamanho++;
}

void ImprimirProduto(TProduto produto) {
  printf("\nO codigo do produto solicitado e %d\n", produto.codigo);
  printf("O valor do produto solicitado e R$ %.2f\n", produto.preco);
  printf("O nome do produto solicitado e %s\n", produto.nome);
  printf("Descricao do produto: %s\n", produto.descricao);
  printf("Temos %d unidades desse produto\n", produto.quantidade);
}

void Imprimir(TLista Lista) {
  TCelula *Aux;
  Aux = Lista.primeiro->prox;
  while (Aux != NULL) {
    ImprimirProduto(Aux->Item);
    Aux = Aux->prox;
  }
}

TCelula *Pesquisar(TLista Lista, TProduto Item) {
  TCelula *Aux;
  Aux = Lista.primeiro;
  while (Aux->prox != NULL) {
    if (Aux->prox->Item.codigo == Item.codigo) {
      return Aux;
    }
    Aux = Aux->prox;
  }
  return NULL;
}

void Excluir(TLista *Lista, TProduto *Item) {
  TCelula *Aux1, *Aux2;
  Aux1 = Pesquisar(*Lista, *Item);
  if (Aux1 != NULL) {
    Aux2 = Aux1->prox;
    Aux1->prox = Aux2->prox;
    *Item = Aux2->Item;
    if (Aux1->prox == NULL)
      Lista->ultimo = Aux1;
    free(Aux2);
    Lista->tamanho--;
  }
}

void LerProduto(TProduto *Produto) {
  printf("Digite o codigo do produto:\n");
  fflush(stdin);
  scanf("%d", &Produto->codigo);
  fflush(stdin);
  printf("\nDigite o valor do produto:\n");
  fflush(stdin);
  scanf("%f", &Produto->preco);
  printf("\nDigite o nome do produto, ate 100 caracteres:\n");
  fflush(stdin);
  getchar();
  fgets(Produto->nome, 100, stdin);
  printf("\nDigite a descricao do produto, ate 200 caracteres:\n");
  fflush(stdin);
  getchar();
  fgets(Produto->descricao, sizeof(Produto->descricao), stdin);
  printf("\nDigite a quantidade de produtos:\n");
  fflush(stdin);
  scanf("%d", &Produto->quantidade);
}

TCelula *PesquisarPorNome(TLista Lista, TProduto produto) {
  TCelula *Aux;
  Aux = Lista.primeiro;
  int teste;
  while (Aux->prox != NULL) {
    teste = strcmp(Aux->prox->Item.nome, produto.nome);
    if (teste == -10) {
      return Aux;
    }
    Aux = Aux->prox;
  }
  return NULL;
}

void LiberarLista(TLista *lista) {
  TCelula *aux;
  while (!Vazia(*lista)) {
    if (!Vazia(*lista)) {
      aux = lista->primeiro->prox;
      lista->primeiro->prox = aux->prox;
      free(aux);
      if (lista->primeiro->prox == NULL) {
        lista->ultimo = lista->primeiro;
      }
      (lista->tamanho)--;
    }
  }
  free(lista->primeiro);
}

void Atualizar(TLista *Lista, TProduto produto) {
  if (PesquisarPorNome(*Lista, produto) == NULL) {
    printf("Produto nao encontrado.\n");
    return;
  }
  printf("Produto encontrado com sucesso.\n");
  printf("Digite as novas informacoes do produto.\n");
  LerProduto(&produto);

  TCelula *Aux;
  Aux = Lista->primeiro;
  while (Aux->prox != NULL) {
    int teste = strcmp(Aux->prox->Item.nome, produto.nome);
    if (teste == -10) {
      Aux->Item = produto;
    }
    Aux = Aux->prox;
  }

  printf("LISTA ATUALIZADA COM SUCESSO.\n");
}

int menorstring(char str01[500], char str02[500]) {
  int tam01 = strlen(str01);
  int tam02 = strlen(str02);
  if (tam01 > tam02) {
    return tam02;
  } else {
    return tam01;
  }
}

void ordemAlfabetica(TLista *lista) {
  TProduto produto;
  printf("Digite as informacoes do produto que deseja adicionar.\n");
  LerProduto(&produto);
  Inserir(produto, lista);

  TLista AuxL;
  FLVazia(&AuxL);
  Vazia(AuxL);
  TProduto anterior;

  while (lista->tamanho != 0) {
    anterior = lista->primeiro->prox->Item;
    TCelula *Ceauxilar = lista->primeiro->prox->prox;
    while (Ceauxilar != NULL) {
      for (int i = 0; i < menorstring((lista->primeiro->Item.nome),
                                      (Ceauxilar->Item.nome));
           i++) {
        if (anterior.nome[i] >
            Ceauxilar->Item
                .nome[i]) // Compara caracter com caracter, caso algum seja
                          // antes do outro ja faz a subistituicao da ordem.
        {
          anterior =
              Ceauxilar->Item; // Qual string for anterior a outra vai para a
                               // variavel para ser adicionada na lista auxiliar
          break;
        } else if (anterior.nome[i] < Ceauxilar->Item.nome[i]) {
          break;
        }
      }
      Ceauxilar = Ceauxilar->prox; // Anda com as comparacoes
    }
    Inserir(anterior, &AuxL);  // Inseri na lista aux na onrdem alfabetica
    Excluir(lista, &anterior); // Deleta da outra lista.
  }
  *lista = AuxL; // Lista principal vira a lista auxiliar.
}

int ListasIguais(TLista Lista01, TLista Lista02) {

  if (Lista01.tamanho != Lista02.tamanho) {
    return 0;
  }
  TCelula *Aux01;
  TCelula *Aux02;
  Aux01 = Lista01.primeiro->prox;
  Aux02 = Lista02.primeiro->prox;

  while (Aux01 != NULL && Aux02 != NULL) {
    // Verifica se o nomes s�o diferentes, caso seja retorna 0.
    if (strcmp(Aux01->Item.nome, Aux02->Item.nome)) {
      return 0;
    }

    // Compara se as descri�es sao diferentes, caso seja retorna 0.
    if (strcmp(Aux01->Item.descricao, Aux02->Item.descricao)) {
      return 0;
    }

    // Verifica de codigo ou pre�o ou quantidade s�o diferente, caso sejam
    // retorna 0.
    if (Aux01->Item.codigo != Aux02->Item.codigo ||
        Aux01->Item.preco != Aux02->Item.preco ||
        Aux01->Item.quantidade != Aux02->Item.quantidade) {
      return 0;
    }
    Aux01 = Aux01->prox;
    Aux02 = Aux02->prox;
  }
  return 1;
}

void JuntarListas(TLista *Lista01, TLista *Lista02) {
  TCelula *Aux = Lista02->primeiro->prox;
  while (Aux != NULL) {
    Inserir(Aux->Item, Lista01);
    Aux = Aux->prox;
  }
}
