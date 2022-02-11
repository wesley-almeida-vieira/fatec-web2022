#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>
#include<conio.h>
#include "ANSI-color-codes.h"

//prototipos de funções
void MenuMateria();
void algoritmos();
void bancoDados();
void informatica();
void mostrarPergunta(int numQuestao);
void validarPontuacao(int numQuestao, char resposta);

//variaveis globais
char nomeJogador[30];
int  pontuacao=0;

//função principal
int main(){
	//configuração
	setlocale(LC_ALL,"portuguese");
	FILE *file;
	
	//variaveis
	int opcao;
	char ranking[30];
	
	//inicio int	 
		printf(RED "\n--------------QUIZ de COMPUTAÇÃO--------------\n" reset);
		printf("Nome jogador: ");
		fflush(stdin);gets(nomeJogador);
				
		do{
			MenuMateria();
			scanf("%i", &opcao);
			
			switch(opcao){
				case  1:
					bancoDados();
				break;
		
				case 2:
					informatica();
				break;
				
				case 3:
					algoritmos();
				break;
				
				case 4:
					system("cls");
					printf("\n\n\n                           Sua pontuação atual é %i\n", pontuacao);
					printf("ÚLTIMAS PONTUAÇÕES:\n\n");
					
					//manipulando arquivo
					file=fopen("ranking.txt", "r");
					
					if(file == NULL){
						printf("o ranking não pôde ser aberto!!!\n");
						break;
					}
					
					while(fgets(ranking, 30, file) != NULL){
						printf("%s", ranking);
					}
					
					fclose(file);
					//arquivo fechado
					
					getch();
				break;
				
				case 5:
					system("cls");
					printf("Agradecimentos especiais para a professora Angelina\n\n");
					printf("                         Este jogo foi desenvolvido por:\n"
					"                                       Wesley Vieira de Almeida\n"
					"                                       Fábio Canedo Leão\n"
					"                                       Raquel Moreira da Costa\n\n\n");
					getch();
				break;
				
				case 6:
					system("cls");
					printf("%s, sua pontuação foi de %i pontos.\n\n", nomeJogador, pontuacao);
					printf("\n\n\n\n                            Obrigado por jogar!!\n\n\n");
					
					//manipulando arquivo
					file=fopen("ranking.txt", "a");
					fprintf(file, "%s    %i\n", nomeJogador, pontuacao);
					fclose(file);
					//arquivo fechado
					return 0;
				break;
				
				default:
					system("cls");
					printf("Essa opção não existe. Digite um valor válido: ");
					getch();
				break;
			}//fim switch opcao
			
		}while(opcao != 6);
		
	return 0;
}// fim função principal

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//função banco de dados
void bancoDados(){
	int i, primeiraQuestao=4, ultimaQuestao=6;
	char resposta;
	
	system("cls");	
	printf("--------------Banco de Dados-----------");
	printf("\nSão 3 perguntas sobre a matéria de Banco de Dados... BOA SORTE %s", nomeJogador);
	getch();
	system("cls");
	
	for(i=primeiraQuestao; i<=ultimaQuestao; i++){
		do{
			mostrarPergunta(i);
			scanf(" %c", &resposta);
			resposta = toupper(resposta);
						 
			if(resposta < 65 || resposta > 68){
				printf("\nRESPOSTA INVALIDA ! Tente novamente.\n\n");
				system("pause");
				system("cls");
			}
		}while(resposta < 65 || resposta > 68);
			
		validarPontuacao(i, resposta);
	}				
				
}//fim funcao banco de dados

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//função sistemas de informacao
void informatica(){
	int i, primeiraQuestao=7, ultimaQuestao=9;
	char resposta;
	
	system("cls");
	printf("--------------INFORMÁTICA-----------");
	printf("\nSão 3 perguntas sobre a matéria de INFORMÁTICA... BOA SORTE %s", nomeJogador);
	getch();
	system("cls");
				
	//inicio questao 1
		//repete enquanto resposta for diferente das alternativa
	for(i=primeiraQuestao; i<=ultimaQuestao; i++){
		do{
			mostrarPergunta(i);
			scanf(" %c", &resposta);
			resposta = toupper(resposta);
						 
			if(resposta < 65 || resposta > 68){
				printf("\nRESPOSTA INVALIDA ! Tente novamente.\n\n");
				system("pause");
				system("cls");
			}
		}while(resposta <65 || resposta > 68);
		
		validarPontuacao(i, resposta);	
	}
					
}//fim funcao informatica

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//função algoritmos
void algoritmos(){
	int i, primeiraQuestao=1, ultimaQuestao=3;
	char resposta;
	
	system("cls");
	printf("--------------ALGORITMOS-----------");
	printf("\nSão 3 perguntas sobre a matéria de ALGORITMOS... BOA SORTE %s", nomeJogador);
	getch();
	system("cls");
				
	//inicio questao 1
		//repete enquanto resposta for diferente das alternativa
	for(i=primeiraQuestao; i<=ultimaQuestao; i++){
		do{
			mostrarPergunta(i);
			scanf(" %c", &resposta);
			resposta = toupper(resposta);
						 
			if(resposta < 65 || resposta > 68){
				printf("\nRESPOSTA INVALIDA ! Tente novamente.\n\n");
				system("pause");
				system("cls");
			}
		}while(resposta <65 || resposta > 68);
			
		validarPontuacao(i, resposta);
	}
					
} //fim funcao algoritmos

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//função menu
void MenuMateria(){
	
	system("cls");
	printf("\n--------------MENU--------------\n");
	printf("\nMatérias disponíveis para jogar\n"
	"[1] Banco de dados\n"
	"[2] Informática\n"
	"[3] Algoritmos\n\n"
	"[4] Últimas pontuações\n"
	"[5] Créditos\n"
	"[6] Sair\n"
	"Escolha: ");
	
}//fim função menu

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//função mostrar perguntas
void mostrarPergunta(int numQuestao){
	
	switch (numQuestao){
		case 1:
			printf("Qual função imprime algo no terminal em C ?\n"
			"[A] printf\n"
			"[B] scanf\n"
			"[C] gets\n"
			"[D] system\n"
			"Resposta: ");
		break;
			
		case 2:
			printf("São as estruturas de repetições em C ?\n"
			"[A] Do..While, if, case\n"
			"[B] If, for, while\n"
			"[C] for, while, Do..While\n"
			"[D] case, for, Do..While\n"
			"Resposta: ");
		break;
			
		case 3:
			printf("Para que serve a sintaxe ELSE IF em C ?\n"
			"[A] Para quebrar a continuidade da IF\n"
			"[B]Quando existir mais de uma opção envolvendo o IF\n"
			"[C] Para verificar a operação logica do IF\n"
			"[D] Funciona como um ELSE alternativo\n"
			"Reposta: ");
		break;
			
		case 4:
			printf("Qual modelo você utiliza para estruturar o MER ?\n"
			"[A] DEM\n"
			"[B] TED\n"
			"[C] DER\n"
			"[D] MER\n"
			"Resposta: ");
		break;
			
		case 5:
			printf("Qual comando da linguagem SQL você cria uma tabela ?\n"
			"[A] CREATE TABLE\n"
			"[B] CREATY TABLE\n"
			"[C] CRIAR TABELA\n"
			"[D] DELETE TABLE\n"
			"Resposta: ");
		break;
			
		case 6:
			printf("Quantas formas normais são necessárias aplicar no seu Banco de Dados ?\n"
			"[A] 4\n"
			"[B] 5\n"
			"[C] 2\n"
			"[D] 3\n"
			"Resposta: ");
		break;
		
		case 7:
			printf("Em qual guia fica a opção de gravar MACROS no excel?\n"
			"[A] Inserir\n"
			"[B] Dados\n"
			"[C] Desenvolvedor\n"
			"[D] Página Inicial\n"
			"Resposta: ");
		break;
		
		case 8:
			printf("Atalho que formata um número qualquer para porcentagem:\n"
			"[A] Ctrl + Shift + #\n"
			"[B] Ctrl + Shift + _\n"
			"[C] Ctrl + +\n"
			"[D] Ctrl + Shift + %% \n"
			"Resposta: ");
		break;
		
		case 9:
			printf("Extensão de arquivo correta quando gravamos macros no Excel:\n"
			"[A] xls\n"
			"[B] xlm\n"
			"[C] xlg\n"
			"[D] xlt\n"
			"Resposta: ");
		break;
	}//fim switch pergunta

}//fim função mostrar perguntas

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//função de validar pontuação
void validarPontuacao(int numQuestao, char resposta){
	char respostas[9]="ACBCADCDB";
	
	if(resposta == respostas[numQuestao-1]){
		system("cls");
		printf("Resposta CERTA !\n\n");
		getch();
		pontuacao += 1;
		system("cls");
	}
	else{
			system("cls");
			printf("Resposta ERRADA ! \n\n");
			getch();
			system("cls");
	}
}//fim função de validar pontuação

