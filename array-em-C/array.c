#include <stdio.h>

int main() {
	//Declarando a lista
	int lista_numeros[20];
	
	//Declarando as variáveis para contagem e comparação
	int soma_multiplos_de_tres = 0;
	int count_pares = 0;
	float media_pares = 0;
	int positivos = 0;
	int negativos = 0;
	int i;
	
	for (i = 0; i < 20; i++) {
		printf("Digite um numero: ");
		scanf("%d", &lista_numeros[i]);
		
		if ((lista_numeros[i] % 3) == 0 ) {
			soma_multiplos_de_tres += lista_numeros[i]; // somando multiplos de 3
		}
		
		if ((lista_numeros[i] % 2) == 0 ) {
			media_pares += lista_numeros[i]; //somando para depois calcular a media
			count_pares++; //valor que será usado depois para fazer a média
		}
		
		if (lista_numeros[i] > 0) {
			positivos++;
		} else if (lista_numeros[i] < 0) { // não pode ser apenas um else, pois o 0 não pode ser considerado como positivo ou negativo
			negativos++;
		}
	}
	
	if (count_pares > 0) {
		media_pares = media_pares / count_pares; //terminando de calcular a media dos pares
	}
	
	int maior = lista_numeros[0], menor = lista_numeros[0]; // já fornecendo os primeiros valores para ser possível realizar as comparações
		
	for (i = 1; i < 20; i++) { //começando do 1 porque o 0 já foi usado na declaração das variáveis
		if (lista_numeros[i] > maior) {
			maior = lista_numeros[i];
		}
		if (lista_numeros[i] < menor) {
			menor = lista_numeros[i];
		}
	}	
	
	printf("\n=============== RESULTADOS ===============\n"); //menu para exibir os resultados
	printf("\nSoma dos multiplos de 3: %d", soma_multiplos_de_tres);
	printf("\nMedia dos numeros pares: %.2f", media_pares);
	printf("\nQuantidade de:\nPositivos: %d\nNegativos: %d", positivos, negativos);
	printf("\nMaior numero: %d", maior);
	printf("\nMenor numero: %d", menor);
	
	printf("\nTODOS OS NUMEROS:");
	
	for (i = 0; i < 20; i++) { // mostrando todos os numeros da lista
		printf("\n - %d", lista_numeros[i]);
	}
	
	printf("\nFIM DO PROGRAMA");
	
	
	return 0;
}
