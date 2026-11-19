#include "senha.h"

#include <stdlib.h>


void adicionarSenha(Paciente *paciente, Senha *senha) {
	if (senha->capacidade == senha->quantidade) {
		int novaCapacidade = senha->quantidade + 1;
		Paciente *novoVetor = realloc(senha->pacientes, novaCapacidade * sizeof(Paciente));
		
		if (novoVetor == NULL) {
			return;
		}
		
		senha->pacientes = novoVetor;
		senha->capacidade = novaCapacidade;
	}
	
	paciente->senha = senha->ultimaSenha + 1;
	senha->pacientes[senha->quantidade] = *paciente;
	
	senha->quantidade++;
	senha->ultimaSenha = paciente->senha;  
}

