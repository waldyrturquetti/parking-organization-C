#include"estacionamento.h"

void main(){

	NoCabeca *cabeca1=CriaCabeca();
	NoCabeca *cabeca2=CriaCabeca();
	char placa[100];
	int op;

	printf("\ndigite:\n1-Para inserir um Carro no estacionamento;\n2-Para retirar um carro do estacionamento;\n3-Imprimir ah Lista de Carros do Estacionamento e Fila de Espera;\n4-Para sair;\n");
	scanf("%d", &op);

	while(op != 4){
		switch(op){

			case 1:{

				printf("digite a placa do carro que vai entrar no estacionamento:");
				setbuf(stdin,NULL);
				scanf("%s", placa);

				if(verificaPlaca(placa)){
					if(cabeca1->qtdcar < 0){
						if(verifica(&cabeca1 , placa)){
							insereInicioListaEncadeada(&cabeca1,placa);
							acrescentaChegada(&cabeca1);
							printf("\nCarro de Placa %s Inserido no Estacionamento\n", cabeca1->prim->placa);
						}
						else
							printf("\n************\nImpossível guardar o carro, carro já existente no estacionamento\n************\n");
					}
					else{
						if(verifica(&cabeca2 , placa)){
							insereInicioListaEncadeada(&cabeca2,placa);
							printf("\nCarro de Placa %s Inserido na Fila de Espera\n", cabeca2->prim->placa);
						}
						else
							printf("\n************\nImpossível guardar o carro, carro já existente no estacionamento\n************\n");
					}
				}
				else
					printf("\n************\nPlaca inválida, digite as opções novamente\n************\n");
			}break;

			case 2:{

				printf("digite a placa do carro que vai sair do estacionamento:");
				setbuf(stdin,NULL);
				scanf("%s", placa);

				if(verificaPlaca(placa)){
					if(!verifica(&cabeca1 , placa)){
						retiraFimListaEncadeada_1(&cabeca1,placa);
						retiraEspera_InsereEstacionamento(&cabeca1,&cabeca2);
						cabeca1->qtdcar = cabeca1->qtdcar - 1;
					}
					else{ 
						if(!verifica(&cabeca2 , placa)){
							retiraFimListaEncadeada_2(&cabeca2,placa);
							//printf("Carro de Placa %s foi Retirado da Fila de Espera:\n", placa);
						}
						else
							printf("\n************\nImpossível retirar o carro, carro inexistente no estacionamento\n************\n");
						}
				}
				else
					printf("\n************\nPlaca inválida, digite as opções novamente\n************\n");
							
			}break;

			case 3:{
				printf("\nFila Estacionamento:\n");
				imprimeLista(cabeca1->ult);
				printf("\nFila de Espera:\n");
				imprimeLista(cabeca2->ult);
			}break;

			default:{printf("\n************\nopção inválida!!, digite novamente\n************\n");}
		}

		setbuf(stdin,NULL);
		printf("\ndigite:\n1-Para inserir um Carro no estacionamento;\n2-Para retirar um carro do estacionamento;\n3-Imprimir ah Lista de Carros do Estacionamento e Fila de Espera;\n4-Para sair;\n");
		scanf("%d", &op);
	}
}