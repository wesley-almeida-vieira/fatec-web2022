#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

int main(){
	
	char senha[10], tamsenha;
	int i, resp;
	
	do{
		system("cls");
		printf("1- Criptografar senha \n2- Descriptografar senha \n0- Sair\n");
		scanf("%i", &resp);
		
		if(resp==1){
			system("cls");
			printf("Digite sua senha (max 10 caracteres): ");
			scanf(" %s", senha);
			tamsenha = strlen(senha);
			
			for(i=0; i<tamsenha; i++){
				senha[i] -= 1;
			}
			
			printf("\nSenha criptografada: %s\n\n", senha);
			system("pause");
		}
		else if(resp==2){
			system("cls");
			printf("Senha a ser descriptografada (max 10 caracteres): ");
			scanf(" %s", &senha);
			tamsenha = strlen(senha);
			
			for(i=0; i<tamsenha; i++){
				senha[i] += 1;
			}
			
			printf("\nSenha descriptografada: %s\n\n", senha);
			system("pause");
		}
		
	}while(resp != 0);
	

	
	
	
	
	
	
	return 0;
}
