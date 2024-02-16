#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"

void MSG_MENU() {
  system("cls");
  printf(
      "\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
  printf("\n\n\t1. INSERIR");
  printf("  \n\t2. PESQUISAR");
  printf("  \n\t3. EXCLUIR");
  printf("  \n\t4. IMPRIMIR");
  printf("  \n\t5. LIBERAR LISTA");
  printf("  \n\t6. ATUALIZAR LISTA");
  printf("  \n\t7. INSERIR ONDEM ALFABETICA");
  printf("  \n\t8. COMPARACAO LISTAS IGUAIS");
  printf("  \n\t9. JUNTAR LISTAS");
  printf("  \n\t10. SAIR");
}

void MENU(TLista *Lista01, TLista *Lista02) {
  TProduto produto;
  int opcao = 0;
  int i;
  int opl = 0;
  int igua = 0;
  do {
    MSG_MENU();
    printf("\n\nDigite uma opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
      printf("Opcao 1 para Lista 01.\n");
      printf("Opcao 2 para Lista 02.\n");
      printf("Digite em qual lista deseja inserir.\n");
      fflush(stdin);
      scanf("%d", &opl);
      if (opl == 1) {
        LerProduto(&produto);
        Inserir(produto, Lista01);
      }
      if (opl == 2) {
        LerProduto(&produto);
        Inserir(produto, Lista02);
      }
      break;
    case 2:
      printf("Digite o codigo do produto que deseja pesquisar: ");
      scanf("%d", &produto.codigo);

      if (Pesquisar(*Lista01, produto) != NULL) {
        printf("Encontrado lista 01");
      }

      if (Pesquisar(*Lista02, produto) != NULL) {
        printf("Encontrado lista 02");
      }
      break;
    case 3:
      printf("Opcao 1 para Lista 01.\n");
      printf("Opcao 2 para Lista 02.\n");
      printf("Digite em qual lista deseja excluir.\n");
      fflush(stdin);
      scanf("%d", &opl);
      if (opl == 1) {
        printf("Digite o codigo do produto.\n");
        fflush(stdin);
        scanf("%d", &produto.codigo);
        Pesquisar(*Lista01, produto);
        Excluir(Lista01, &produto);
      }
      if (opl == 2) {
        printf("Digite o codigo do produto.\n");
        fflush(stdin);
        scanf("%d", &produto.codigo);
        Pesquisar(*Lista01, produto);
        Excluir(Lista02, &produto);
      }
      break;
    case 4:
      printf("Lista 01.\n");
      Imprimir(*Lista01);
      printf("\nLista 02.\n");
      Imprimir(*Lista02);
      break;
    case 5:
      printf("Opcao 1 para Lista 01.\n");
      printf("Opcao 2 para Lista 02.\n");
      printf("Digite qual lista deseja liberar.\n");
      fflush(stdin);
      scanf("%d", &opl);
      if (opl == 1) {
        LiberarLista(Lista01);
      }
      if (opl == 2) {
        LiberarLista(Lista02);
      }
      break;

    case 6:
      printf("Opcao 1 para Lista 01.\n");
      printf("Opcao 2 para Lista 02.\n");
      printf("Digite em qual lista deseja atualizar.\n");
      fflush(stdin);
      scanf("%d", &opl);
      if (opl == 1) {
        printf("Digite o nome do produto que deseja atualizar.\n");
        getchar();
        fgets(produto.nome, sizeof(produto.nome), stdin);
        Atualizar(Lista01, produto);
      }
      if (opl == 2) {
        printf("Digite o nome do produto que deseja atualizar.\n");
        getchar();
        fgets(produto.nome, sizeof(produto.nome), stdin);
        Atualizar(Lista02, produto);
      }
      break;
    case 7:
      printf("Opcao 1 para Lista 01.\n");
      printf("Opcao 2 para Lista 02.\n");
      printf("Digite em qual lista deseja inserir produtos em ordem "
             "alfabetica.\n");
      fflush(stdin);
      scanf("%d", &opl);
      if (opl == 1) {
        ordemAlfabetica(Lista01);
      }
      if (opl == 2) {
        ordemAlfabetica(Lista02);
      }
      break;
    case 8:
      igua = ListasIguais(*Lista01, *Lista02);
      if (igua == 0) {
        printf("As Listas NAO sao iguais.\n");
      } else {
        printf("AS LISTAS SAO IGUAIS.\n");
      }
      break;
    case 9:
      JuntarListas(Lista01, Lista02);
      break;
    case 10:
      system("cls");
      printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
      system("PAUSE");
      break;

    default:
      system("cls");
      printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
      system("PAUSE");
    }
  } while (opcao != 11);
}
