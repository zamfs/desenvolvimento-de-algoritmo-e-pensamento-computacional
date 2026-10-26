📋 Cadastro de Equipamentos em C

Projeto desenvolvido para a atividade prática da disciplina Desenvolvimento de Algoritmos e Programação em C.

O programa tem como objetivo auxiliar no cadastro e na consulta de equipamentos de um laboratório de informática, utilizando arquivos de texto para armazenar os registros.

🎯 Objetivo

Desenvolver um sistema simples em linguagem C que permita cadastrar equipamentos, armazenar suas informações em um arquivo e consultar os registros posteriormente, aplicando conceitos de lógica de programação, estruturas de repetição, seleção e manipulação de arquivos.

⚙️ Funcionalidades

O sistema apresenta um menu interativo com as seguintes opções:

Cadastrar equipamento: solicita o nome, o código de identificação e a localização do equipamento.
Listar equipamentos: realiza a leitura do arquivo e exibe os equipamentos cadastrados no terminal.
Sair: encerra a execução do programa.

Os registros são armazenados no arquivo equipamentos.txt. Novos cadastros são adicionados ao final do arquivo, preservando as informações existentes.

🛠️ Tecnologias e conceitos utilizados
Linguagem C.
Biblioteca padrão stdio.h.
Variáveis e vetores de caracteres.
Estruturas condicionais com switch.
Estrutura de repetição do-while.
Entrada e saída de dados com scanf(), fgets() e printf().
Manipulação de arquivos com fopen(), fprintf(), fgets() e fclose().
Modos de abertura de arquivos, com destaque para a+.
📁 Estrutura do projeto
text
cadastro-de-equipamentos/
├── cadastro_equipamentos.c
├── equipamentos.txt
└── README.md

cadastro_equipamentos.c: código-fonte do programa.
equipamentos.txt: arquivo de texto utilizado para armazenar os equipamentos cadastrados e disponibilizar um exemplo de registros.
README.md: documentação do projeto e instruções de execução.
💻 Como compilar e executar
Pré-requisitos
Compilador C, como o GCC.
Terminal ou prompt de comando.
1. Clone o repositório
bash
git clone URL_DO_REPOSITORIO


Entre na pasta do projeto:

bash
cd NOME_DA_PASTA


Substitua URL_DO_REPOSITORIO pelo endereço real do repositório no GitHub e NOME_DA_PASTA pelo nome da pasta criada.

2. Compile o programa

Com o GCC instalado, execute:

bash
gcc cadastro_equipamentos.c -o cadastro_equipamentos

3. Execute o programa

No Linux ou macOS:

bash
./cadastro_equipamentos


No Windows, utilizando o GCC:

bash
cadastro_equipamentos.exe


Observação: os comandos consideram que o arquivo-fonte se chama cadastro_equipamentos.c. Caso tenha outro nome, ajuste o comando de compilação.

📝 Exemplo de utilização

Ao executar o programa, o usuário verá o seguinte menu:

text
========== MENU DE OPCOES ==========
1 - Adicionar equipamento
2 - Listar equipamentos
3 - Sair

Escolha uma opcao:


Ao selecionar a opção de cadastro, o sistema solicita as informações do equipamento.

Exemplo de conteúdo do arquivo equipamentos.txt:

text
Equipamento: Computador
Codigo: 101
Localizacao: Laboratorio 1

Equipamento: Impressora
Codigo: 102
Localizacao: Secretaria


Ao selecionar a opção de listagem, os registros armazenados no arquivo são exibidos no terminal.

📂 Armazenamento dos dados

O arquivo equipamentos.txt é utilizado para manter os registros entre diferentes execuções do programa.

O modo de abertura a+ permite ler o conteúdo existente e adicionar novos registros ao final do arquivo, sem apagar os dados anteriores. O programa utiliza funções da biblioteca padrão de C para gravar e consultar essas informações.

🎓 Informações acadêmicas
Disciplina: Desenvolvimento de Algoritmos e Programação em C.
Atividade: Cadastro de Equipamentos em C.
Modalidade: Individual.
Valor: 0,5 ponto.
✅ Critérios contemplados

O projeto foi desenvolvido com base nos requisitos propostos na atividade:

Menu funcional para cadastro, listagem e encerramento.
Entrada dos dados de cada equipamento.
Gravação dos registros em arquivo de texto.
Leitura e exibição dos equipamentos cadastrados.
Preservação dos registros existentes durante novos cadastros.
Organização do código-fonte e documentação para execução.

Projeto acadêmico desenvolvido para praticar os fundamentos de algoritmos, programação em C e manipulação de arquivos.
