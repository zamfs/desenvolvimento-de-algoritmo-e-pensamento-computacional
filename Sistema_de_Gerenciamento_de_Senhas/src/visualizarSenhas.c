#include "visualizarSenhas.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void mostrarTituloSenhas(void) {
    printf(
        " _______    ______    ______   ______  ________  __    __  ________  ________   ______  \n"
        "/       \\  /      \\  /      \\ /      |/        |/  \\  /  |/        |/        | /      \\ \n"
        "$$$$$$$  |/$$$$$$  |/$$$$$$  |$$$$$$/ $$$$$$$$/ $$  \\ $$ |$$$$$$$$/ $$$$$$$$/ /$$$$$$  |\n"
        "$$ |__$$ |$$ |__$$ |$$ |  $$/   $$ |  $$ |__    $$$  \\$$ |   $$ |   $$ |__    $$ \\__$$/ \n"
        "$$    $$/ $$    $$ |$$ |        $$ |  $$    |   $$$$  $$ |   $$ |   $$    |   $$      \\ \n"
        "$$$$$$$/  $$$$$$$$ |$$ |   __   $$ |  $$$$$/    $$ $$ $$ |   $$ |   $$$$$/     $$$$$$  |\n"
        "$$ |      $$ |  $$ |$$ \\__/  | _$$ |_ $$ |_____ $$ |$$$$ |   $$ |   $$ |_____ /  \\__$$ |\n"
        "$$ |      $$ |  $$ |$$    $$/ / $$   |$$       |$$ | $$$ |   $$ |   $$       |$$    $$/ \n"
        "$$/       $$/   $$/  $$$$$$/  $$$$$$/ $$$$$$$$/ $$/   $$/    $$/    $$$$$$$$/  $$$$$$/  \n"
        "\n"
        "  ______    ______   __    __   ______   _______   _______    ______   __    __  _______    ______  \n"
        " /      \\  /      \\ /  |  /  | /      \\ /       \\ /       \\  /      \\ /  \\  /  |/       \\  /      \\ \n"
        "/$$$$$$  |/$$$$$$  |$$ |  $$ |/$$$$$$  |$$$$$$$  |$$$$$$$  |/$$$$$$  |$$  \\ $$ |$$$$$$$  |/$$$$$$  |\n"
        "$$ |__$$ |$$ | _$$/ $$ |  $$ |$$ |__$$ |$$ |__$$ |$$ |  $$ |$$ |__$$ |$$$  \\$$ |$$ |  $$ |$$ |  $$ |\n"
        "$$    $$ |$$ |/    |$$ |  $$ |$$    $$ |$$    $$< $$ |  $$ |$$    $$ |$$$$  $$ |$$ |  $$ |$$ |  $$ |\n"
        "$$$$$$$$ |$$ |$$$$ |$$ |  $$ |$$$$$$$$ |$$$$$$$  |$$ |  $$ |$$$$$$$$ |$$ $$ $$ |$$ |  $$ |$$ |  $$ |\n"
        "$$ |  $$ |$$ \\__$$ |$$ \\__$$ |$$ |  $$ |$$ |  $$ |$$ |__$$ |$$ |  $$ |$$ |$$$$ |$$ |__$$ |$$ \\__$$ |\n"
        "$$ |  $$ |$$    $$/ $$    $$/ $$ |  $$ |$$ |  $$ |$$    $$/ $$ |  $$ |$$ | $$$ |$$    $$/ $$    $$/ \n"
        "$$/   $$/  $$$$$$/   $$$$$$/  $$/   $$/ $$/   $$/ $$$$$$$/  $$/   $$/ $$/   $$/ $$$$$$$/   $$$$$$/  \n"
        "\n"
    );
}

void visualizarSenhas(Senha *senhaNormal, Senha *senhaPreferencial, Senha *senhaUrgente) {
	Senha *filas[3] = {
	    senhaUrgente,
	    senhaPreferencial,
	    senhaNormal
	};
	
	int f, i;
	
	bool noMenu = true;
	
	while (noMenu) {
		system("cls");
		mostrarTituloSenhas();
		
		for (f = 0; f < 3; f++) {
			for (i = 0; i < filas[f]->quantidade; i++) {
				printf("%s - Senha: %c%d\n",
					filas[f]->pacientes[i].nome,
					filas[f]->pacientes[i].prioridade,
					filas[f]->pacientes[i].senha);
			}
		}
		
		if (senhaNormal->quantidade == 0 && senhaPreferencial->quantidade == 0 && senhaUrgente->quantidade == 0) {
			printf("Nenhum paciente aguardando.\n");
		}
		
		printf("\nDigite 1 para voltar para o menu anterior: ");
		
		char entrada[50];
	    char *fim;
	
	    if (fgets(entrada, sizeof entrada, stdin) == NULL) {
	        break;
	    }
	
	    long opcao = strtol(entrada, &fim, 10);
	
	    if (fim == entrada || *fim != '\n' ||
	        opcao != 1) {
	        printf("\nOpcao invalida!\n");
	        continue;
	    }
	    
	    if (opcao == 1) {
	    	break;
		}
	}
}
