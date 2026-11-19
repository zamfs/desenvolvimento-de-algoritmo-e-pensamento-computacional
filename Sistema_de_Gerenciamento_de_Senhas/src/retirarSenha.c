#include "paciente.h"
#include "senha.h"

#include <stdio.h>
#include <windows.h>

void retirarSenha(Senha *senhaNormal, Senha *senhaPreferencial, Senha *senhaUrgente) {
	Paciente paciente = criarPaciente();

	if (paciente.prioridade == 'U') {
		adicionarSenha(&paciente, senhaUrgente);	
	} else if (paciente.prioridade == 'P') {
		adicionarSenha(&paciente, senhaPreferencial);
	} else {
		adicionarSenha(&paciente, senhaNormal);
	}
	
	printf("Sua senha: %c%03d", paciente.prioridade, paciente.senha);
	
	Sleep(2000);
}


