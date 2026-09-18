#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	printf("\n = - = - = BEM VINDO AO PROGRAMA DE MONITORAMENTO DE TEMPERATURAS = - = - =\n");
	
	printf("\nDefinindo valores.");
	
	//definindo o max e o min para as temperaturas geradas de forma aleatória
	double tempMin, tempMax;
	
	do {
		printf("\nDigite o valor maximo: ");
		scanf("%lf", &tempMax);
		
		printf("\nDigite o valor minimo:  ");
		scanf("%lf", &tempMin);
		
		if (tempMax < tempMin) {
			printf("\nERRO. O valor maximo nao pode ser menor que o valor minimo. Tente novamente!");
		}
	} while(tempMax < tempMin);
	
	//Definindo o valor Limite
	double TEMPERATURA_LIMITE;
	
	do {
		printf("\nDigite o valor limite: ");
		scanf("%lf", &TEMPERATURA_LIMITE);
		
		if (TEMPERATURA_LIMITE > tempMax) {
			printf("\nTemperatura limite nao pode ser maior do que a temperatura maxima!");
		} else if (TEMPERATURA_LIMITE < tempMin) {
			printf("\nTemperatura limite nao pode ser menor do que a temperatura minima!");
		}
	} while (TEMPERATURA_LIMITE > tempMax || TEMPERATURA_LIMITE < tempMin);
	
	//inicializando o srand
	srand(time(NULL)); 
	
	// inicializando as variáveis
	double mediaTemp, somaTemperaturas = 0;
	double maiorTemp, menorTemp;
	int acimaLimite = 0, totalTemperaturas = 0, maxAcimaLimiteCons = 0;
	
	do {
		//Gerando as temperaturas de forma aleatória com casas decimais.
		double escala = (double)rand() / RAND_MAX;
		double temp = tempMin + escala * (tempMax - tempMin);
		
		
		//dando os primeiros valores para o maior e o menor para realizar as futuras comparações com as outras temperaturas
		if (totalTemperaturas == 0) {
			maiorTemp = temp;
			menorTemp = temp;
		} else { // verificando se é maior ou menor do que as temperaturas que já tinham sido definidas
			if (temp > maiorTemp) {
				maiorTemp = temp;
			} else if (temp < menorTemp) {
				menorTemp = temp;
			}
		}
		
		if (temp > TEMPERATURA_LIMITE) { // verificando se está acima do limite
			acimaLimite++;
			maxAcimaLimiteCons++;
			printf("\nTemperatura ACIMA DO LIMITE: %.2f", temp);
		} else {
			maxAcimaLimiteCons = 0; // senão estiver acima do limite, o maximo de limites consecutivos reinicia, volta a 0.
		}
		
		somaTemperaturas += temp; //incrementando a soma das temperaturas para realizar a média posteriormente
		totalTemperaturas++; //incrementando para depois saber quantas temperaturas foram lidas
		
	} while (maxAcimaLimiteCons < 3); //3 temperaturas acima do limite consecutivas para encerrar o laço
	
	mediaTemp = somaTemperaturas / totalTemperaturas;
	double percentualAcimaLimite = ((double)acimaLimite/totalTemperaturas) * 100;
	
	printf("\n\n========== RELATORIO ==========\n");
	printf("\nTotal de temperaturas verificadas: %d", totalTemperaturas);
	printf("\nTotal de temperaturas acima do limite: %d", acimaLimite);
	printf("\nPercentual acima do limite: %.2f%%", percentualAcimaLimite);
	printf("\nMedia das temperaturas: %.2f oC", mediaTemp);
	printf("\nMaior temperatura: %.2f oC", maiorTemp);
	printf("\nMenor temperatura: %.2f oC", menorTemp);
	printf("\n\n===============================\n");
	
	return 0;
}
