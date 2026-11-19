#include "paciente.h"
#include "senha.h"

void retirarSenha(Senha *senhaNormal, Senha *senhaPreferencial, Senha *senhaUrgente) {
	Paciente paciente = criarPaciente();

if (paciente.prioridade == 'U') {
	adicionarSenha(&paciente, senhaUrgente);	
} else if (paciente.prioridade == 'P') {
	adicionarSenha(&paciente, senhaPreferencial);
} else {
	adicionarSenha(&paciente, senhaNormal);
}
}


