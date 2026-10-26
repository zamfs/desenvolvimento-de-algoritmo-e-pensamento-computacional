# 📋 Cadastro de Equipamentos em C

Projeto desenvolvido para a atividade prática da disciplina **Desenvolvimento de Algoritmos e Programação em C**.

O programa permite cadastrar e consultar equipamentos de um laboratório de informática, armazenando os registros em um arquivo de texto.

## 🎯 Objetivo

Desenvolver um sistema simples em linguagem C para cadastrar equipamentos, armazenar suas informações em um arquivo e consultar os registros posteriormente, aplicando conceitos de lógica de programação, estruturas de repetição, estruturas condicionais e manipulação de arquivos.

## ⚙️ Funcionalidades

- **Cadastrar equipamento:** solicita o nome, o código de identificação e a localização.
- **Listar equipamentos:** lê o arquivo e exibe todos os equipamentos cadastrados no terminal.
- **Sair:** encerra a execução do programa.

Os registros são armazenados em `equipamentos.txt`. Novos cadastros são adicionados ao final do arquivo, preservando as informações existentes.

## 🛠️ Tecnologias e conceitos utilizados

- Linguagem C.
- Biblioteca `stdio.h`.
- Variáveis e vetores de caracteres.
- Estrutura condicional `switch`.
- Estrutura de repetição `do-while`.
- Entrada e saída de dados com `scanf()`, `fgets()` e `printf()`.
- Manipulação de arquivos com `fopen()`, `fprintf()`, `fgets()` e `fclose()`.
- Modo de abertura de arquivos `a+`.

## 📁 Estrutura do projeto

```text
cadastro-de-equipamentos/
├── cadastro_equipamentos.c
├── equipamentos.txt
└── README.md
