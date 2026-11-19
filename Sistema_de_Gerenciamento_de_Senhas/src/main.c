#include "senha.h"
#include "retirarSenha.h"
#include "realizarAtendimento.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void mostrarMenu(void) {
	printf(" __       __  ________  __    __  __    __        _______   _______   ______  __    __   ______   ______  _______    ______   __\n");      
	printf("/  \\     /  |/        |/  \\  /  |/  |  /  |      /       \\ /       \\ /      |/  \\  /  | /      \\ /      |/       \\  /      \\ /  |\n");     
	printf("$$  \\   /$$ |$$$$$$$$/ $$  \\ $$ |$$ |  $$ |      $$$$$$$  |$$$$$$$  |$$$$$$/ $$  \\ $$ |/$$$$$$  |$$$$$$/ $$$$$$$  |/$$$$$$  |$$ |\n");      
	printf("$$$  \\ /$$$ |$$ |__    $$$  \\$$ |$$ |  $$ |      $$ |__$$ |$$ |__$$ |  $$ |  $$$  \\$$ |$$ |  $$/   $$ |  $$ |__$$ |$$ |__$$ |$$ |\n");      
	printf("$$$$  /$$$$ |$$    |   $$$$  $$ |$$ |  $$ |      $$    $$/ $$    $$<   $$ |  $$$$  $$ |$$ |        $$ |  $$    $$/ $$    $$ |$$ |\n");      
	printf("$$ $$ $$/$$ |$$$$$/    $$ $$ $$ |$$ |  $$ |      $$$$$$$/  $$$$$$$  |  $$ |  $$ $$ $$ |$$ |   __   $$ |  $$$$$$$/  $$$$$$$$ |$$ |\n");      
	printf("$$ |$$$/ $$ |$$ |_____ $$ |$$$$ |$$ \\__$$ |      $$ |      $$ |  $$ | _$$ |_ $$ |$$$$ |$$ \\__/  | _$$ |_ $$ |      $$ |  $$ |$$ |_____\n"); 
	printf("$$ | $/  $$ |$$       |$$ | $$$ |$$    $$/       $$ |      $$ |  $$ |/ $$   |$$ | $$$ |$$    $$/ / $$   |$$ |      $$ |  $$ |$$       |\n");
	printf("$$/      $$/ $$$$$$$$/ $$/   $$/  $$$$$$/        $$/       $$/   $$/ $$$$$$/ $$/   $$/  $$$$$$/  $$$$$$/ $$/       $$/   $$/ $$$$$$$$/\n"); 
                                                                                                                                       
                                                                                                                                       
}

int main(){
	system("mode con: cols=150 lines=35");
	
	Senha senhaNormal = {0};
	Senha senhaPreferencial = {0};
	Senha senhaUrgente = {0};
	
	bool executando = true;
	
	while (executando){
		system("cls");
		
		char entrada[50];
		int opcao;
		
		mostrarMenu();
		printf("\n\n1-Retirar senha\n");
		printf("2-Realizar atendimento\n");
		printf("3-Sair\n");
		if (fgets(entrada, sizeof entrada, stdin) == NULL) {
		    break;
		}
		
		char *fim;
		long opcaoNaoOfc = strtol(entrada, &fim, 10);
		
		if (fim != entrada && *fim == '\n'
		    && opcaoNaoOfc >= 1 && opcaoNaoOfc <= 3) {
		    opcao = (int) opcaoNaoOfc;
		} else {
		    printf("Opcao invalida!\n");
		    continue;
		}
		
		switch (opcao) {
			case 1:
				retirarSenha(&senhaNormal, &senhaPreferencial, &senhaUrgente);
				break;
			case 2:
				realizarAtendimento(&senhaNormal, &senhaPreferencial, &senhaUrgente);
				break;
			case 3:
				executando = false;
				break;
			default:
				printf("Opcao invalida!");
				break;	
		}
	}
	
	printf("Saindo...");
	
	free(senhaNormal.pacientes);
	free(senhaPreferencial.pacientes);
	free(senhaUrgente.pacientes);
	
	printf("Finalizado!");
	
	return 0;
}
