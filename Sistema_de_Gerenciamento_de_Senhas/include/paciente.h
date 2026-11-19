#ifndef PACIENTE_H
#define PACIENTE_H

#include <stdbool.h>

typedef struct {
		char nome[50];
		int idade;
		char genero;
		bool gestante;
		bool necessidadeEspecial;
		char prioridade;
		int senha;
	} Paciente;

Paciente criarPaciente(void);

#endif
