#ifndef SENHA_H
#define SENHA_H

#include "paciente.h"

typedef struct {
	Paciente *pacientes;
	int quantidade;
	int capacidade;
	int ultimaSenha;
} Senha;

void adicionarSenha(Paciente *paciente, Senha *senha);

#endif
