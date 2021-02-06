#include"estacionamento.h"

NoCabeca *CriaCabeca(){

	NoCabeca *aux=NULL;
	aux=(NoCabeca*)malloc(sizeof(NoCabeca));

	aux->qtdcar=0;
	aux->prim=NULL;
	aux->ult=NULL;

	return aux;	
}

void insereInicioListaEncadeada(NoCabeca **cabeca, char *placa){

	assert(cabeca);
	No *aux=NULL;
	aux=(No*)malloc(sizeof(No));

	if((*cabeca)->prim == NULL){

		aux->prox=NULL;
		aux->ant=NULL;
		aux->c=0;
		aux->p=0;
		strcpy(aux->placa,placa);
		(*cabeca)->prim = aux;
		(*cabeca)->ult = aux;
		(*cabeca)->qtdcar = (*cabeca)->qtdcar + 1;
	}
	else{

		strcpy(aux->placa, placa);
		aux->c=0;
		aux->p=0;
		aux->prox=(*cabeca)->prim;
		aux->ant=NULL;
		(*cabeca)->prim=aux;
		aux->prox->ant=aux;
		(*cabeca)->qtdcar = (*cabeca)->qtdcar + 1;
	}
}

void retiraFimListaEncadeada_1(NoCabeca **cabeca , char *placa){

	No *aux=NULL;

	while(1){
		aux=(*cabeca)->ult;
		if(!strcmp(aux->placa,placa)){
			if(aux->ant==NULL && aux->prox==NULL){
				(*cabeca)->ult=NULL;
				(*cabeca)->prim=NULL;
				printf("Carro de Placa %s foi Retirado do Estacionamento:\n", aux->placa);
				free(aux);
				aux=NULL;
				break;
			}
			else{
				(*cabeca)->ult=aux->ant;
				(*cabeca)->ult->prox=NULL;
				printf("Carro de Placa %s foi Retirado do Estacionamento:\n", aux->placa);
				free(aux);
				aux=NULL;
				break;
				}
		}
		else{
			aux=(*cabeca)->ult;
			(*cabeca)->ult=(*cabeca)->ult->ant;
			(*cabeca)->ult->prox=NULL;
			insereInicioListaEncadeada(cabeca,aux->placa);
			acrescentaPartida(cabeca,aux->p);
			free(aux);
			aux=NULL;
		}
	}
}

void retiraFimListaEncadeada_2(NoCabeca **cabeca , char *placa){

	No *aux=NULL, *aux2=NULL;

	aux=(*cabeca)->prim;

	if(aux->prox != NULL){
		while(aux->prox !=NULL){
			if(!strcmp(aux->placa,placa))
				break;
			aux=aux->prox;
		}

		if(!strcmp((*cabeca)->ult->placa,placa)){
			(*cabeca)->ult=aux->ant;
			(*cabeca)->ult->prox=NULL;
			free(aux);
			aux=NULL;
		}
		else{
			if(!strcmp((*cabeca)->prim->placa,placa)){
				(*cabeca)->prim=aux->prox;
				(*cabeca)->prim->ant=NULL;
				free(aux);
				aux=NULL;
			}
			else{
				aux2=aux->ant;
				aux2->prox=aux->prox;
				aux2=aux->prox;
				aux2->ant=aux->ant;
				printf("Carro de Placa %s foi Retirado da Fila de Espera:\n", aux->placa);
				free(aux);
				aux=NULL;
			}
		}
	}
	else{

		(*cabeca)->prim = NULL;
		(*cabeca)->ult = NULL;
		free(aux);
		aux=NULL;
	}

}

void retiraEspera_InsereEstacionamento(NoCabeca **cabeca1, NoCabeca **cabeca2){

	if((*cabeca2)->prim == NULL)
		return ;

	No *aux=NULL;
	aux=(*cabeca2)->ult;
	insereInicioListaEncadeada(cabeca1,aux->placa);
	retiraFimListaEncadeada_2(cabeca2,aux->placa);
	acrescentaChegada(cabeca1);
	printf("Carro de Placa %s Inserida no Estacionamento", (*cabeca1)->prim->placa);
	printf("\n");
	free(aux);
	aux=NULL;
}

void imprimeLista(No *p){

	No *aux=NULL;
	if(p==NULL){
		printf("Vazia\n");
		return ;
	} 
    
    aux=p;
    while(aux != NULL){
        printf("Placa:%s, Chegada:%d, Partida:%d\n", aux->placa, aux->c, aux->p);
        aux=aux->ant;
    }
    printf("\n");
    return;
}

int verifica(NoCabeca **cabeca, char *placa){

	No* aux=NULL;

	aux=(*cabeca)->prim;
	if(aux==NULL)
		return 1;

	else{		
		while(aux!=NULL){
			if(!strcmp(aux->placa , placa))
				return 0;
				
			aux=aux->prox;
		}
		return 1;
	}
}

int verificaPlaca(char *placa){

	if(placa[7] != '\0')
		return 0;

	for(int i=0;i<7;i++){

		if(i==3 || i>4){
			if(placa[i]<48 || placa[i]>57)
				return 0;

			continue;	
		}else{
			if(placa[i]<65 || placa[i]>90)
				return 0;
		}
	}
	return 1;
}

void acrescentaPartida(NoCabeca **cabeca, int p){
	(*cabeca)->prim->p = p + 1;
	(*cabeca)->prim->c = 1;
}

void acrescentaChegada(NoCabeca **cabeca){
	(*cabeca)->prim->c = (*cabeca)->prim->c + 1;	
}