#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

/*

Leia um vetor A de 6 elementos contendo o gabarito da Mega-Sena. 
O sorteio consiste na extra��o de 6 n�meros diferentes, no universo de 1 � 60. 
 A seguir, ler um vetor B para a aposta de tamanho 10. Esse vetor dever� ter no m�nimo 6 valores e no m�ximo 10 valores. 
Aten��o: Uma aposta s� poder� ser finalizada quando tiver pelo menos 6 n�meros digitados.
Uma aposta ser� finalizada automaticamente quando tiver 10 n�meros digitados.
Escrever quantos pontos fez o apostador, e se ele fez a sena (6 acertos), a quina (5 acertos) ou a quadra (4 acertos).
Nesse exerc�cio o usu�rio digita todos os valores, o gabarito e a aposta.
N�o permitir que o usu�rio digite n�meros repetidos para o gabarito ou aposta.
N�o permitir que o usu�rio digite n�meros fora do universo de 1 � 60.

*/

int main(){
	setlocale(LC_ALL, "portuguese");
	
	int gabarito[6], aposta[10], escolha, pontos=0, i, j, k;
	
	
	//recebendo n�meros do gabarito e controle dos n�meros permitidos
	printf("  INSIRA OS N�MEROS DO GABARITO (de 1 � 60)\n");
	for(i=0; i<6; i++){
		do{
			printf("%i� N�mero:  ", i+1);
			scanf("%i", &gabarito[i]);
			
			if(gabarito[i] > 60 || gabarito[i] < 1){
				printf("\nPermitido somente valores de 1 at� 60! Digite novamente\n");
			}
			
		}while(gabarito[i] > 60 || gabarito[i] < 1);
		
		//verifica��o de n�meros repetidos
		for(j=0; j<i;j++){
			if(gabarito[i] == gabarito[j]){
				printf("\nN�o � permitido n�meros repetidos! Digite novamente\n");
				i--;
				break;
			}
		}
	}
	
	system("cls");
	printf("     GABARITO INCLU�DO COM SUCESSO!\n");
	
	//controle de n�meros permitidos na aposta
	do{
		printf("Quantos n�meros deseja apostar (m�nimo 6 - m�ximo 10): ");
		scanf("%i", &escolha);
		
		if(escolha < 6){
			printf("\nVoc� deve apostar no m�nimo 6 n�meros. Tente novamente!!\n");
		}
		else if(escolha > 10){
			printf("\nVoc� pode apostar no m�ximo 10 n�meros. Tente novamente!\n");
		}
		
	}while(escolha < 6 || escolha > 10);
	
	system("cls");
	printf("TUDO CERTO! AGORA INSIRA OS N�MEROS DA APOSTA\n");
	
	//recebendo n�meros da aposta
	for(i=0; i<escolha; i++){
		
		//verifica��o de n�meros v�lidos
		do{
			printf("%i� n�mero: ", i+1);
			scanf("%i", &aposta[i]);
			
			if(aposta[i] > 60 || aposta[i] < 1){
				printf("\n� permitido somente apostas do n�mero 1 at� 60!Digite novamente\n");
			}
			
		}while(aposta[i] > 60 || aposta[i] < 1);
		
		//verifica��o de n�meros repetidos
		k = i;
		
		for(j=0; j<i; j++){
			if(aposta[i] == aposta[j]){
				printf("\nN�o � permitida a aposta de n�meros repetidos!!Digite novamente\n");
				i--;
				break;
			}
		}
		
		//verifica��o de acertos
		if(k == i){
			for(j=0; j<6; j++){
				if(aposta[i] == gabarito[j]){
					pontos++;
				}
			}
		}
	}
	
	system("cls");
	
	//exibi��o dos resultados
	if(pontos == 6){
		printf("\nPARAB�NS!! VOC� OBTEVE 6 ACERTOS E FEZ A SENA, AGORA VOC� � UM MILION�RIO\n");
		system("pause");
	}
	else if(pontos == 5){
		printf("\nPARAB�NS!! VOC� OBTEVE 5 ACERTOS E FEZ A QUINA\n");
		system("pause");
	}
	else if(pontos == 4){
		printf("\nPARAB�NS!! VOC� OBTEVE 4 ACERTOS E FEZ A QUADRA\n");
		system("pause");
	}
	else{
		printf("\nQUE PENA, VOC� OBTEVE %i ACERTOS! JOGUE NOVAMENTE E VOC� PODER� SER O PR�XIMO MILION�RIO!!\n", pontos);
		system("pause");
	}
	
	return 0;
}
