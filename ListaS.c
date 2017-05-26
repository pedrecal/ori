#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef void(*MOSTRA)(void*);
typedef int(*COMPARA)(void*, void*);

typedef struct _no{
    void *data;
    struct _no *prox;
}No;

typedef struct _empregado{
    char nome[32];
    unsigned int idade;
}Empregado;

typedef struct _listaLigada{
    No *cabeca, *calda, *atual, *ant;
}ListaLigada;

//funcoes
void inicializaLista(ListaLigada *);
void insereCabeca(ListaLigada *, void *);
void insereCalda(ListaLigada *, void *);
void mostraListaLigada(ListaLigada *, MOSTRA);
No *getNo(ListaLigada*, COMPARA, void *);
void remover(ListaLigada*, No*);

//funcoes compara e mostra definidas:::
int comparaEmpregado(Empregado *e1, Empregado *e2){
	return strcmp(e1->nome, e2->nome);
}

void mostraEmpregado(Empregado *empregado){
	printf ("%s\t%d\n", empregado->nome, empregado->idade);
}


int main(){
	ListaLigada listaLigada;

	Empregado* E1 = (Empregado *) malloc(sizeof(Empregado));
	strcpy(E1->nome, "E1");
	E1->idade = 1;

	Empregado *E2 = (Empregado *) malloc(sizeof(Empregado));
	strcpy(E2->nome, "E2");
	E2->idade = 2;

	Empregado *E3 = (Empregado *) malloc(sizeof(Empregado));
	strcpy(E3->nome, "E3");
	E3->idade = 3;

	inicializaLista(&listaLigada);

	insereCabeca(&listaLigada, E1);
	insereCalda(&listaLigada, E3);
	insereCabeca(&listaLigada, E2);


	//mostra
	mostraListaLigada (&listaLigada, (MOSTRA)mostraEmpregado);

	//teste getno
	getNo (&listaLigada, (COMPARA) comparaEmpregado, E1);

	//libera
	free(E1);
	free(E2);
	free(E3);

    return 0;
}


void inicializaLista(ListaLigada * li){
    li->cabeca = NULL;
    li->calda = NULL;
    li->atual = NULL;
	  li->ant = NULL;
}

void insereCabeca(ListaLigada * li, void *data){
	No *novo = (No*)malloc(sizeof(No));
	if(novo == NULL){
		printf ("Erro\n");
		exit (-1);
	}
	novo->data = data;

	if (li->cabeca == NULL)
		li->calda = novo;

	novo->prox = li->cabeca;
	li->cabeca = novo;
}

void insereCalda(ListaLigada *li, void *data){
	No *novo = (No*)malloc(sizeof(No));
	if(novo == NULL){
		printf ("Erro\n");
		exit(-1);
	}
	novo->data = data;
	novo->prox = NULL;

	if(li->cabeca == NULL){//lista vazia: início
        li->cabeca = novo;
    }else{
        li->calda->prox = novo;
	}
	li->calda = novo;
}

void mostraListaLigada(ListaLigada *li, MOSTRA mostra){
	if(li->cabeca == NULL)//lista vazia: início
        printf("Lista Vazia\n");
	else{
		li->atual = li->cabeca;
		while (li->atual != NULL){
			mostra(li->atual->data);
			li->atual = li->atual->prox;
		}
	}
}

No *getNo(ListaLigada *li, COMPARA compara, void *data){
	//if(li->cabeca == NULL) //lista vazia
		//return NULL;

	li->atual = li->cabeca;
	while(li->atual != NULL && compara(li->atual->data, data) == 0)
		li->atual = li->atual->prox;

	return li->atual;
}

void remover(ListaLigada *li, No *rm){
	if(li->cabeca == NULL){//lista vazia: início
        printf("Lista Vazia\n");
		return;
	}

	li->atual = li->cabeca;
	while(li->atual != NULL && li->atual != rm){
		li->ant = li->atual;
		li->atual = li->atual->prox;
	}

	if (li->atual == NULL){
		printf("Elemento nao enconrado\n");
		return;
	}


	if(li->atual == li->cabeca) //inicio
		li->cabeca = li->cabeca->prox;
	else
		li->ant->prox = li->atual->prox;
	free(li->atual);
}
