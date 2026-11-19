#include "atenderPaciente.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

static void mostrarTituloEmAtendimento(void) {
    printf(
        " ________  __       __ \n"
        "/        |/  \\     /  |\n"
        "$$$$$$$$/ $$  \\   /$$ |\n"
        "$$ |__    $$$  \\ /$$$ |\n"
        "$$    |   $$$$  /$$$$ |\n"
        "$$$$$/    $$ $$ $$/$$ |\n"
        "$$ |_____ $$ |$$$/ $$ |\n"
        "$$       |$$ | $/  $$ |\n"
        "$$$$$$$$/ $$/      $$/\n"
        "\n"
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

void atenderPaciente(Senha *senhaNormal, Senha *senhaPreferencial, Senha *senhaUrgente) {
	static Paciente pacienteAtual;
	static bool emAtendimento = false;
	
	Senha *filas[3] = {
		senhaUrgente,
		senhaPreferencial,
		senhaNormal
	};
	
	bool noMenu = true;
	int f, i;
	
	while(noMenu) {
		system("cls");
		mostrarTituloEmAtendimento();
		
		if (!emAtendimento) {
			Senha *fila = NULL;
			
			for (f = 0; f < 3; f++) {
				if (filas[f]->quantidade > 0) {
					fila = filas[f];
					break;
				}
			}
			
			if (fila == NULL) {
				printf("\nNenhum paciente aguardando!\n");
				Sleep(2000);
				break;
			}
			
			pacienteAtual = fila->pacientes[0];
			
			for (i = 1; i < fila->quantidade; i++) {
				fila->pacientes[i - 1] = fila->pacientes[i];	
			}
			
			fila->quantidade--;
			emAtendimento = true;
		}
	
		printf("\nEm atendimento: %s - Senha: %c%03d\n",
	               pacienteAtual.nome,
	               pacienteAtual.prioridade,
	               pacienteAtual.senha);
	
	    printf("\n1 - Finalizar atendimento e chamar proximo\n");
	    printf("2 - Voltar\n");
	    
	    char entrada[50];
	    char *fim;
	
	    if (fgets(entrada, sizeof entrada, stdin) == NULL) {
	        break;
	    }
	
	    long opcao = strtol(entrada, &fim, 10);
	
	    if (fim == entrada || *fim != '\n' ||
	        opcao < 1 || opcao > 2) {
	        printf("Opcao invalida!\n");
	        Sleep(2000);
	        continue;
	    }
	    
	    switch (opcao) {
	    	case 1:
	    		printf("\nAtendimento de %s finalizado.\n", pacienteAtual.nome);
	    		Sleep(2000);
	    		
	    		pacienteAtual = (Paciente){0};
	    		emAtendimento = false;
	    		break;
	    	
			case 2:
				noMenu = false;
				break;
		}
	}
}
