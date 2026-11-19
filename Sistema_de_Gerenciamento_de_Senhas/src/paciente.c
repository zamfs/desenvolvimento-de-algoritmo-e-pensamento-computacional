#include "paciente.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

static void mostrarTituloCadastro(void) {
    printf(
        "  ______    ______   _______    ______    ______   ________  _______    ______  \n"
        " /      \\  /      \\ /       \\  /      \\  /      \\ /        |/       \\  /      \\ \n"
        "/$$$$$$  |/$$$$$$  |$$$$$$$  |/$$$$$$  |/$$$$$$  |$$$$$$$$/ $$$$$$$  |/$$$$$$  |\n"
        "$$ |  $$/ $$ |__$$ |$$ |  $$ |$$ |__$$ |$$ \\__$$/    $$ |   $$ |__$$ |$$ |  $$ |\n"
        "$$ |      $$    $$ |$$ |  $$ |$$    $$ |$$      \\    $$ |   $$    $$< $$ |  $$ |\n"
        "$$ |   __ $$$$$$$$ |$$ |  $$ |$$$$$$$$ | $$$$$$  |   $$ |   $$$$$$$  |$$ |  $$ |\n"
        "$$ \\__/  |$$ |  $$ |$$ |__$$ |$$ |  $$ |/  \\__$$ |   $$ |   $$ |  $$ |$$ \\__$$ |\n"
        "$$    $$/ $$ |  $$ |$$    $$/ $$ |  $$ |$$    $$/    $$ |   $$ |  $$ |$$    $$/ \n"
        " $$$$$$/  $$/   $$/ $$$$$$$/  $$/   $$/  $$$$$$/     $$/    $$/   $$/  $$$$$$/  \n"
        "\n"
    );
}

static char definirPrioridade(Paciente paciente){
	if (paciente.idade > 80) {
		return 'U';
	}
	else if (paciente.necessidadeEspecial == true || paciente.gestante == true) {
		return 'P';
	} else {
		return 'N';
	}
}

Paciente criarPaciente(void) {
	system("cls");
	
	mostrarTituloCadastro();
	
	Paciente paciente = {0};
	char entrada[50];
	
	printf("Nome: ");
	if (fgets(paciente.nome, sizeof paciente.nome, stdin) == NULL) {
		return paciente;
	}
	
	paciente.nome[strcspn(paciente.nome, "\n")] = '\0';
	
	while (true) {
		printf("Idade: ");
		if (fgets(entrada, sizeof entrada, stdin) == NULL) {
			return paciente;
		}
		
		char *fim;
		long idade = strtol(entrada, &fim, 10);
		
		if (fim != entrada && *fim == '\n' && idade >=0 && idade <= 130) {
			paciente.idade = (int) idade;
			break;
		}
		
		printf("Digite uma idade inteira entre 0 e 130.\n");
		Sleep(2000);
	}
	
	while (true) {
		printf("Genero ('M'/Masculino) ('F'/Feminino): ");
		if (fgets(entrada, sizeof entrada, stdin) == NULL) {
			return paciente;
		}
		
		if((entrada[0] == 'M' || entrada[0] == 'F') && entrada[1] == '\n') {
			paciente.genero = entrada[0];
			break;
		}
		
		printf("Digite apenas M ou F.\n");
		Sleep(2000);
	}
	
	if (paciente.genero == 'M') {
		paciente.gestante = false;
	} else {
		while(true) {
			printf("Gestante? (S/N): ");
			if (fgets(entrada, sizeof entrada, stdin) == NULL) {
				return paciente;
			}
			
			if((entrada[0] == 'S' || entrada[0] == 'N') && entrada[1] == '\n') {
				if(entrada[0] == 'S') {
					paciente.gestante = true;
					break;
				} else {
					paciente.gestante = false;
					break;
				}
			}
			
			printf("Digite apenas S ou N.\n");
			Sleep(2000);
		}
	}
	
	while(true) {
		printf("Necessidade especial? S/N: ");
		if (fgets(entrada, sizeof entrada, stdin) == NULL) {
			return paciente;
		}
		
		if((entrada[0] == 'S' || entrada[0] == 'N') && entrada[1] == '\n') {
			if (entrada[0] == 'S') {
				paciente.necessidadeEspecial = true;
				break;
			} else {
				paciente.necessidadeEspecial = false;
				break;
			}
		}
		
		printf("Digite apenas S ou N.\n");
		Sleep(2000);
	}
	
	paciente.prioridade = definirPrioridade(paciente);
	
	return paciente;
}
