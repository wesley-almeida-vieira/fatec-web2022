#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

/*

Leia um vetor A de 6 elementos contendo o gabarito da Mega-Sena. 
O sorteio consiste na extração de 6 números diferentes, no universo de 1 à 60. 
 A seguir, ler um vetor B para a aposta de tamanho 10. Esse vetor deverá ter no mínimo 6 valores e no máximo 10 valores. 
Atenção: Uma aposta só poderá ser finalizada quando tiver pelo menos 6 números digitados.
Uma aposta será finalizada automaticamente quando tiver 10 números digitados.
Escrever quantos pontos fez o apostador, e se ele fez a sena (6 acertos), a quina (5 acertos) ou a quadra (4 acertos).
Nesse exercício o usuário digita todos os valores, o gabarito e a aposta.
Não permitir que o usuário digite números repetidos para o gabarito ou aposta.
Não permitir que o usuário digite números fora do universo de 1 à 60.

*/

int main(){
	setlocale(LC_ALL, "portuguese");
	
	int gabarito[6], aposta[10], escolha, pontos=0, i, j, k;
	
	
	//recebendo números do gabarito e controle dos números permitidos
	printf("  INSIRA OS NÚMEROS DO GABARITO (de 1 á 60)\n");
	for(i=0; i<6; i++){
		do{
			printf("%iº Número:  ", i+1);
			scanf("%i", &gabarito[i]);
			
			if(gabarito[i] > 60 || gabarito[i] < 1){
				printf("\nPermitido somente valores de 1 até 60! Digite novamente\n");
			}
			
		}while(gabarito[i] > 60 || gabarito[i] < 1);
		
		//verificação de números repetidos
		for(j=0; j<i;j++){
			if(gabarito[i] == gabarito[j]){
				printf("\nNão é permitido números repetidos! Digite novamente\n");
				i--;
				break;
			}
		}
	}
	
	system("cls");
	printf("     GABARITO INCLUÍDO COM SUCESSO!\n");
	
	//controle de números permitidos na aposta
	do{
		printf("Quantos números deseja apostar (mínimo 6 - máximo 10): ");
		scanf("%i", &escolha);
		
		if(escolha < 6){
			printf("\nVocê deve apostar no mínimo 6 números. Tente novamente!!\n");
		}
		else if(escolha > 10){
			printf("\nVocê pode apostar no máximo 10 números. Tente novamente!\n");
		}
		
	}while(escolha < 6 || escolha > 10);
	
	system("cls");
	printf("TUDO CERTO! AGORA INSIRA OS NÚMEROS DA APOSTA\n");
	
	//recebendo números da aposta
	for(i=0; i<escolha; i++){
		
		//verificação de números válidos
		do{
			printf("%iº número: ", i+1);
			scanf("%i", &aposta[i]);
			
			if(aposta[i] > 60 || aposta[i] < 1){
				printf("\nÉ permitido somente apostas do número 1 até 60!Digite novamente\n");
			}
			
		}while(aposta[i] > 60 || aposta[i] < 1);
		
		//verificação de números repetidos
		k = i;
		
		for(j=0; j<i; j++){
			if(aposta[i] == aposta[j]){
				printf("\nNão é permitida a aposta de números repetidos!!Digite novamente\n");
				i--;
				break;
			}
		}
		
		//verificação de acertos
		if(k == i){
			for(j=0; j<6; j++){
				if(aposta[i] == gabarito[j]){
					pontos++;
				}
			}
		}
	}
	
	system("cls");
	
	//exibição dos resultados
	if(pontos == 6){
		printf("\nPARABÉNS!! VOCÊ OBTEVE 6 ACERTOS E FEZ A SENA, AGORA VOCÊ É UM MILIONÁRIO\n");
		system("pause");
	}
	else if(pontos == 5){
		printf("\nPARABÉNS!! VOCÊ OBTEVE 5 ACERTOS E FEZ A QUINA\n");
		system("pause");
	}
	else if(pontos == 4){
		printf("\nPARABÉNS!! VOCÊ OBTEVE 4 ACERTOS E FEZ A QUADRA\n");
		system("pause");
	}
	else{
		printf("\nQUE PENA, VOCÊ OBTEVE %i ACERTOS! JOGUE NOVAMENTE E VOCÊ PODERÁ SER O PRÓXIMO MILIONÁRIO!!\n", pontos);
		system("pause");
	}
	
	return 0;
}
