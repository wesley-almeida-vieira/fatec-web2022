#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#define TAM 5

int main(){
	//configurações
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	
	//variaveis
	int numeros[TAM], resposta[TAM], acertos=0, i;
	
	printf("Adivinhe os valores \n\n");
	system("pause");
	
	//apresentação dos valores aleatórios
	for(i=0; i<TAM; i++){
		numeros[i] = rand() % 10;
		printf("%i   ", numeros[i]);
		usleep(0.1);
	}
	sleep(1);
	Beep(300,300);
	
	//recebendo as respostas
	system("cls");	
	printf("\n");
	
	for(i=0; i<TAM; i++){
		scanf("%i", &resposta[i]);
		Beep(250,300);
		
		if(resposta[i] == numeros[i]){
			acertos++;
		}
	}
	
	//acertos
	printf("\n\nVocê obteve %i acertos\n\n", acertos);
	
	
	system("pause");
	return 0;
}
