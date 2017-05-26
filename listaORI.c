#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
void *data;
struct _no *prox;
} No;

typedef struct listaLigada {
  No * head;
  No * tail;
  No * atual;
} ListaLigada;

typedef void(*MOSTRA)(void*);
typedef int(*COMPARA)(void*, void*);

void inicializaLista(ListaLigada*);
void insereCabeca(ListaLigada*, void*);
void insereCalda(ListaLigada*, void*);
void mostraListaLigada(ListaLigada*, MOSTRA);
No *getNo(ListaLigada*, COMPARA, void*);
void remove(ListaLigada*, No*);

void inicializaLista(ListaLigada *lista)
{
  lista->head = NULL;
  lista->tail = NULL;
  lista->atual = NULL;
}

void insereCabeca(ListaLigada *list, void *data)
{
  No *New = (No*)malloc(sizeof(No));
  if(New == NULL)
    exit(-1);
  New->data = data;
  New->prox = NULL;

  if(list->head == NULL)
  {
    list->head->prox = New;
    list->tail->prox = New;
  }
  else
  {
    New->prox = list->head->prox;
    list->head = New;
  }
}

void insereCalda(ListaLigada *list, void *data)
{
  No *New = (No*)malloc(sizeof(No));
  if(New == NULL)
    exit(-1);
  New->data = data;
  New->prox = NULL;

  if(list->tail == NULL)
  {
    list->head->prox = New;
    list->tail->prox = New;
  }
  else
  {
    list->tail->prox = New;
    list->tail = New;
  }
}

void mostraListaLigada(ListaLigada* list, MOSTRA mostra)
{
  if (list->head == NULL)
  {
    printf("LISTA VAZIA\n");
  }
  else
  {
    while (list->prox != NULL)
    {

    }
  }
}
