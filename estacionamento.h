#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct no{

	char placa[7];
	int c;
	int p;
	struct no *prox;
	struct no *ant;
}No;

typedef struct nocabeca{

	int qtdcar;
	struct no *prim;
	struct no *ult;
}NoCabeca;

NoCabeca *CriaCabeca();

void insereInicioListaEncadeada(NoCabeca **cabeca, char *placa);

void retiraFimListaEncadeada_1(NoCabeca **cabeca , char *placa);

void retiraFimListaEncadeada_2(NoCabeca **cabeca , char *placa);

void retiraEspera_InsereEstacionamento(NoCabeca **cabeca1, NoCabeca **cabeca2);

void imprimeLista(No *p);

int verifica(NoCabeca **cabeca, char *placa);

int verificaPlaca(char *placa);

void acrescentaPartida(NoCabeca **cabeca, int p);

void acrescentaChegada(NoCabeca **cabeca);