#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<locale.h>

#define TAM 10

int main(){
	//configurações
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	
	//variaveis
	unsigned char xadrez[TAM][TAM];
	int i, j, linhaWolly, colunaWolly, respLinha, respColuna, respChance, chances;
	
	//escolhendo dificuldade
	printf("Quantas chances deseja? ");
	scanf("%i", &respChance);
	chances = respChance;
	system("cls");
	
	//atribuição de valor e apresentação da matriz
	for(i=0; i<TAM; i++){
		for(j=0; j<TAM; j++){
			xadrez[i][j] = 1;
		}
	}
	
	for(i=0; i<TAM; i++){
		for(j=0; j<TAM; j++){
			printf("%c | ", xadrez[i][j]);
		}
		printf("\n");
	}
	
	//Posição do Wolly na matriz
	linhaWolly = rand() % 10;
	colunaWolly = rand() % 10;
	xadrez[linhaWolly][colunaWolly] = 2;
	
	//Recebendo resposta do jogador
	do{
		printf("Onde está o Wolly? (você tem %i chances)\n", chances);
		printf("  Linha: "); 
		scanf("%i", &respLinha); 
		Beep(400,300);
		printf("  Coluna: "); 
		scanf("%i", &respColuna);
		Beep(300,300);
		
		respLinha = respLinha -1;
		respColuna = respColuna-1;
		
		if(respLinha==linhaWolly && respColuna==colunaWolly){
			system("cls");
			printf("  ******ACERTOU!!!****** \n");
			printf("Linha: %i \nColuna: %i\n\n", respLinha+1, respColuna+1);
			
			//musiquinha de vitória
			Beep(293,250);
			Beep(293,250);
			Beep(220,250);
			Beep(220,250);
			Beep(293,250);
			Beep(293,250);
			Beep(330,250);
			Beep(330,250);
			Beep(349,250);
			Beep(349,250);
			Beep(330,250);
			Beep(330,250);
			Beep(293,250);
			Beep(293,250);
			Beep(330,250);
			Beep(293,250);
			Beep(262,250);
			Beep(262,250);
			Beep(196,250);
			Beep(196,250);
			Beep(262,250);
			Beep(262,250);
			
			for(i=0; i<TAM; i++){
				for(j=0; j<TAM; j++){
					printf("%c | ", xadrez[i][j]);
				}
				printf("\n");
			}
			
			break;
		}
		else{
			chances--;
		}
	}while(chances != 0);
	
	if(chances == 0){
		system("cls");
		printf("\n\n     ********GAME OVER********\n");
		printf("  resposta\nLinha: %i\nColuna: %i\n\n", linhaWolly+1, colunaWolly+1);
		
		//musiquinha de game over
		Beep(293,250);
		Beep(293,250);
		Beep(220,250);
		Beep(220,250);
		Beep(293,250);
		Beep(293,250);
		Beep(330,250);
		Beep(330,250);
		Beep(349,250);
		Beep(349,250);
		Beep(330,250);
		Beep(330,250);
		Beep(293,250);
		Beep(293,250);
		Beep(330,250);
		Beep(293,250);
		Beep(262,250);
		Beep(262,250);
		Beep(196,250);
		Beep(196,250);
		Beep(262,250);
		Beep(262,250);
		
		for(i=0; i<TAM; i++){
			for(j=0; j<TAM; j++){
				printf("%c | ", xadrez[i][j]);
			}
			printf("\n");
		}
	}	
	
	system("pause");
	return 0;
}
