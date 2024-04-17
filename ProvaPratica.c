#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <locale.h>
#include <ctype.h>

typedef struct no{
	char motivo[3];
	struct no *proximo;
}No;

typedef struct{
	No *topo;
}Pilha;

void imprimirPilha(Pilha *p){
	No *aux;
	aux = p->topo;
	int i;
	while(aux->proximo){
		printf("Valor: ");
		for(i = 0; i < 3; i++){
			printf("%c ", aux->motivo[i]);
		}
		printf("\n");
		aux = aux->proximo;
	}	
	printf("Valor: ");
	for(i = 0; i < 3; i++){
		printf("%c", aux->motivo[i]);
	}
		
}

//Este metodo empilha a pilha
void empilhar(Pilha *p, char motivo[3]){
	No *novo = (No*) malloc (sizeof(No));
	int i;
	for(i = 0; i < 3; i++)
		novo->motivo[i] = motivo[i];
	
	
	if(p->topo == NULL){	
		novo->proximo = NULL;
		p->topo = novo;
	}else{
		No *aux = p->topo;
		novo->proximo = aux;
		p->topo = novo;
	}	
}

//Metedo que valida o vetor booleano, procurando um valor true, ou seja, caso
//ele ache um valor false ele retorna true
//caso ele ache um valor true ele retorna false
bool validaVetorV(bool input[3]){
	int i;
	for(i = 0; i < 3; i++){
		if(!input[i])
			return true;
	}
	return false;	
}

//Metodo que valida se o grupo que encontramos é um motivo que escolhemos
//se for ele retorna true
//se não retorna false
bool validaMotivo(char input[3]){
	char mot1[3];
	char mot2[3];
	char mot3[3];
	
	mot1[0] = 'U';
	mot1[1] = 'U';
	mot1[2] = 'U';
	
	mot2[0] = 'U';
	mot2[1] = 'C';
	mot2[2] = 'U';
	
	mot3[0] = 'A';
	mot3[1] = 'G';
	mot3[2] = 'A';
	
	int i, j;
	bool cV[3];
	for(i = 1; i <= 3; i++){
		if(i == 1){
			for(j = 0; j < 3; j++){
				if(input[j] == mot1[j]){
					cV[j] = true;	    		
				}else{
					cV[j] = false; 
				}
					
			}	
		} 
		if (i == 2 && validaVetorV(cV)){
			for(j = 0; j < 3; j++){
				if(input[j] == mot2[j]){
					cV[j] = true;	    		
				}else{
					cV[j] = false;
				}		 
			}
		}else if (!validaVetorV(cV)){
			return true;
		}
			
		if (i == 3 && validaVetorV(cV)){
			for(j = 0; j < 3; j++){
				if(input[j] == mot3[j]){
					cV[j] = true;	    		
				}else{
					cV[j] = false;
				}
					 
			}
		}else if (!validaVetorV(cV)){
			return true;
		}
		
		
		if(!validaVetorV(cV)){
			return true;
		}		
	}
	return false;
}

//Metodo responsável por fazer a entrada dos dados
char* entrada(){
	
	char *result;
	
	result = (char*)malloc(256 * sizeof(char));
	
	printf("Digite a sequência: ");
	
	
	gets(result);
	
	return result;
}

bool validaVetorVazio(char input[3]){
	int i;
	for(i = 0; i < 3; i++){
		if(input[i] == '\0')
			return true;
	}
	
	return false;
}

//Metodo responsável por separar a sequencia de 3 carcteres do vetor principal e chamar
//os metodos validadores
void separaMotivos(Pilha *p, char *input){
    int i = -1;
    int j;
    char motivo[3];
    bool vetVazio;

    do {
        i++;

        for (j = 0; j < 3; j++) { 
            motivo[j] = *(input + i + j);
        }
        vetVazio = validaVetorVazio(motivo);

        if (!vetVazio) 
            empilhar(p, motivo); 
        
    } while (*(input + i) != '\0' && !vetVazio);

}


int main (void){
	setlocale(LC_ALL, "PORTUGUESE");
	
	Pilha pilha;
	fflush(stdout);
	char *input = entrada(); 
	separaMotivos(&pilha, input);
	imprimirPilha(&pilha);
	
	//char teste[10];
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return -1;
}
