#include "realizarAtendimento.h"
#include "atenderPaciente.h"
#include "visualizarSenhas.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void mostrarTituloAtendimento(void) {
    printf(
        "  ______   ________  ________  __    __  _______   ______  __       __  ________  __    __  ________   ______  \n"
        " /      \\ /        |/        |/  \\  /  |/       \\ /      |/  \\     /  |/        |/  \\  /  |/        | /      \\ \n"
        "/$$$$$$  |$$$$$$$$/ $$$$$$$$/ $$  \\ $$ |$$$$$$$  |$$$$$$/ $$  \\   /$$ |$$$$$$$$/ $$  \\ $$ |$$$$$$$$/ /$$$$$$  |\n"
        "$$ |__$$ |   $$ |   $$ |__    $$$  \\$$ |$$ |  $$ |  $$ |  $$$  \\ /$$$ |$$ |__    $$$  \\$$ |   $$ |   $$ |  $$ |\n"
        "$$    $$ |   $$ |   $$    |   $$$$  $$ |$$ |  $$ |  $$ |  $$$$  /$$$$ |$$    |   $$$$  $$ |   $$ |   $$ |  $$ |\n"
        "$$$$$$$$ |   $$ |   $$$$$/    $$ $$ $$ |$$ |  $$ |  $$ |  $$ $$ $$/$$ |$$$$$/    $$ $$ $$ |   $$ |   $$ |  $$ |\n"
        "$$ |  $$ |   $$ |   $$ |_____ $$ |$$$$ |$$ |__$$ | _$$ |_ $$ |$$$/ $$ |$$ |_____ $$ |$$$$ |   $$ |   $$ \\__$$ |\n"
        "$$ |  $$ |   $$ |   $$       |$$ | $$$ |$$    $$/ / $$   |$$ | $/  $$ |$$       |$$ | $$$ |   $$ |   $$    $$/ \n"
        "$$/   $$/    $$/    $$$$$$$$/ $$/   $$/ $$$$$$$/  $$$$$$/ $$/      $$/ $$$$$$$$/ $$/   $$/    $$/     $$$$$$/  \n"
        "\n"
    );
}

void realizarAtendimento(Senha *senhaNormal, Senha *senhaPreferencial, Senha *senhaUrgente) {
	bool noMenu = true;
	
	while(noMenu) {
		system("cls");
		mostrarTituloAtendimento();
		printf("1 - Realizar atendimento\n");
        printf("2 - Visualizar senhas\n");
        printf("3 - Voltar ao menu principal\n");
        
        char entrada[50];
        char *fim;

        if (fgets(entrada, sizeof entrada, stdin) == NULL) {
            break;
        }

        long opcao = strtol(entrada, &fim, 10);

        if (fim == entrada || *fim != '\n' ||
            opcao < 1 || opcao > 3) {
            printf("Opcao invalida!\n");
            continue;
        }
        
        switch (opcao) {
        	case 1:
        		atenderPaciente(senhaNormal, senhaPreferencial, senhaUrgente);
        		break;
        		
        	case 2:
        		visualizarSenhas(senhaNormal, senhaPreferencial, senhaUrgente);
        		break;
        	case 3:
        		noMenu = false;
        		break;
		}
	}
}
