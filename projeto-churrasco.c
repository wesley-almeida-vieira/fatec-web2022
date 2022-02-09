#include<stdio.h>
#include<locale.h>

int main(){
	
	setlocale(LC_ALL,"portuguese");
	
	//variaveis de contagem
	int qtdCrianca, qtdAdolescente, qtdHomem, qtdMulher;
	
	//variaveis de insumos
	float carneBovina,linguica, farofa, arroz, carneFrango, sal, carvao;
	float refrigerante, agua, suco;
	int pao, cerveja, gelo;
	//-------------------------------------------------------------------------------------------------------------------------
	
	
	//leitura dos dados
	printf("                         ******** LISTA DE COMPRAS PARA CHURRASCO ********\n\n");
	printf("Digite a quantidade de mulheres: ");
	scanf("%i", &qtdMulher);
	
	printf("Digite a quantidade de homens: ");
	scanf("%i", &qtdHomem);
	
	printf("Digite a quantidade de adolescentes: ");
	scanf("%i", &qtdAdolescente);
	
	printf("Digite a quantidade de crianças: ");
	scanf("%i", &qtdCrianca);
	
	printf("--------------------------------------------------------------------------------------------");
	
	
	//calculo de insumos
	carneBovina = (qtdCrianca * 0.2) + (qtdAdolescente * 0.3) + (qtdHomem * 0.4) + (qtdMulher * 0.4);
	carneFrango = (qtdCrianca * 0.1) + (qtdAdolescente * 0.2) + (qtdHomem * 0.3) + (qtdMulher * 0.3);
	linguica = (qtdCrianca * 0.1) + (qtdAdolescente * 0.15) + (qtdHomem * 0.2) + (qtdMulher * 0.2);
	farofa = (qtdCrianca * 0.02) + (qtdAdolescente * 0.03) + (qtdHomem * 0.04) + (qtdMulher * 0.04);
	arroz = (qtdCrianca * 0.07) + (qtdAdolescente * 0.08) + (qtdHomem * 0.09) + (qtdMulher * 0.09);
	pao = (qtdCrianca * 1) + (qtdAdolescente * 2) + (qtdHomem * 2) + (qtdMulher * 2);
	sal = (carneBovina + carneFrango) * 0.018;
	
	refrigerante = (qtdCrianca * 0.6) + (qtdAdolescente * 1.5) + (qtdHomem * 0.6) + (qtdMulher * 0.6);
	cerveja =(qtdHomem * 14) + (qtdMulher * 8);
	agua = (qtdCrianca * 0.2) + (qtdAdolescente * 0.4) + (qtdHomem * 0.5) + (qtdMulher * 0.5);
	suco = (qtdCrianca * 0.6) + (qtdAdolescente * 0.8) + (qtdMulher * 0.4);
	gelo = (qtdCrianca + qtdAdolescente + qtdMulher + qtdHomem);
	
	carvao = (carneBovina + carneFrango + linguica) * 1.2;
	//--------------------------------------------------------------------------------------------------------------------------
	
	
	//apresentação da lista
	printf("\n     Alimentos                           Bebidas");
	printf("\nCarne bovina:    %.3f Kg", carneBovina), printf("      Refrigerante:    %.3f L", refrigerante); 
	printf("\nCarne de frango: %.3f Kg", carneFrango), printf("      Suco:            %.3f L", suco);
	printf("\nlinguiça:        %.3f Kg", linguica),    printf("      Agua:            %.3f L", agua);    
	printf("\nFarofa:          %.3f Kg", farofa),      printf("      Cerveja:         %i LT", cerveja);     
	printf("\nArroz:           %.3f Kg", arroz);
	printf("\nPão:             %i UN\n", pao);
	
	printf("\nAdicionais");
	printf("\nSal:             %.3f Kg", sal);	
	printf("\nGelo:            %i Kg", gelo);
	printf("\nCarvão:          %.3f Kg", carvao);
	
	return 0;
}
