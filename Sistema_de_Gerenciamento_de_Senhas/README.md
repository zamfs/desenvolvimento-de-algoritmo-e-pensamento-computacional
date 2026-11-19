# Sistema de Gerenciamento de Senhas

Projeto acadêmico desenvolvido em **C** para organizar o atendimento de pacientes de uma clínica de especialidades médicas. O sistema funciona pelo terminal e permite cadastrar pacientes, emitir senhas e realizar atendimentos conforme a prioridade de cada categoria.

## Funcionalidades

- Cadastro de vários pacientes durante a execução, informando nome, idade, gênero, gestação (quando aplicável) e necessidade especial.
- Classificação automática dos pacientes em três categorias de atendimento.
- Emissão de senhas com numeração independente por categoria, como `N001`, `P001` e `U001`.
- Consulta dos pacientes aguardando, organizados por prioridade e ordem de chegada dentro de cada categoria.
- Chamada do próximo paciente e exibição do nome e da senha em atendimento.
- Finalização do atendimento e chamada do próximo paciente disponível.
- Retorno aos menus sem perder o paciente que está em atendimento.
- Validação da idade, das opções dos menus e das respostas de gênero, gestação e necessidade especial.

## Regras de atendimento

| Categoria | Prefixo | Critério implementado | Ordem de chamada |
| --- | --- | --- | --- |
| Urgente | `U` | Paciente com mais de 80 anos | 1ª |
| Preferencial | `P` | Gestante ou pessoa com necessidade especial, desde que não se enquadre como urgente | 2ª |
| Normal | `N` | Demais pacientes | 3ª |

Dentro de cada categoria, o atendimento segue a ordem de emissão das senhas (**FIFO**: o primeiro a entrar é o primeiro a sair). A numeração começa em 1 para cada categoria e continua avançando durante a execução, mesmo após os atendimentos.

Ao ser chamado, o paciente é removido da fila de espera e passa a ser o paciente em atendimento. Finalizar o atendimento não o devolve à fila. Um atendimento iniciado permanece ativo ao voltar aos menus; novas prioridades são consideradas na próxima chamada.

A classificação de urgência por idade é uma regra do exercício e não substitui avaliação clínica.

## Tecnologias e organização

O projeto utiliza C, estruturas (`struct`), ponteiros, vetores com alocação dinâmica (`realloc`), estruturas de decisão e repetição. A memória das filas é liberada com `free` ao encerrar o programa.

| Arquivo ou pasta | Responsabilidade |
| --- | --- |
| `src/main.c` | Menu principal, inicialização das filas e encerramento |
| `src/paciente.c` | Cadastro, validação dos dados e classificação do paciente |
| `src/senha.c` | Alocação de memória e geração sequencial das senhas |
| `src/retirarSenha.c` | Cadastro e encaminhamento à fila correspondente |
| `src/realizarAtendimento.c` | Menu de atendimento e consulta das filas |
| `src/atenderPaciente.c` | Chamada, manutenção do atendimento atual e finalização |
| `src/visualizarSenhas.c` | Exibição dos pacientes aguardando |
| `include/` | Cabeçalhos com estruturas e declarações das funções |
| `Sistema_de_Gerenciamento_de_Senhas.dev` | Projeto para o Dev-C++ |
| `Makefile.win` | Arquivo de compilação gerado pelo Dev-C++ |
| `build/` | Arquivos intermediários gerados na compilação |
| `bin/` | Executável gerado na compilação |

As pastas `build/` e `bin/` podem precisar ser criadas após clonar o repositório, pois os arquivos de compilação são ignorados pelo Git.

### Estruturas de dados

- **`Paciente`**: armazena nome, idade, gênero, condição de gestação, necessidade especial, categoria e número da senha.
- **`Senha`**: representa uma fila, armazenando o vetor de pacientes, a quantidade atual, a capacidade alocada e a última senha emitida.

## Funções implementadas

| Função | Responsabilidade |
| --- | --- |
| `main()` | Inicializa as três filas, controla o menu principal e libera a memória ao sair |
| `mostrarMenu()` | Exibe o título do menu principal |
| `criarPaciente()` | Solicita os dados, valida as entradas e retorna o paciente classificado |
| `definirPrioridade()` | Define a categoria `U`, `P` ou `N`; função interna de `paciente.c` |
| `adicionarSenha()` | Amplia o vetor quando necessário, atribui a próxima senha e adiciona o paciente à fila |
| `retirarSenha()` | Cadastra o paciente, seleciona a fila e apresenta a senha emitida |
| `realizarAtendimento()` | Controla o submenu de atendimento e visualização |
| `atenderPaciente()` | Chama o próximo paciente por prioridade, mantém o atendimento atual e permite finalizá-lo |
| `visualizarSenhas()` | Lista os pacientes que aguardam atendimento |
| `mostrarTituloCadastro()`, `mostrarTituloAtendimento()`, `mostrarTituloEmAtendimento()` e `mostrarTituloSenhas()` | Exibem os títulos das telas; funções internas dos respectivos módulos |

## Compilação e execução

### Requisitos

- Windows.
- Compilador C GCC/MinGW, disponível também na instalação do Dev-C++ com compilador.
- Dev-C++ para utilizar o arquivo de projeto, ou terminal com `gcc` no `PATH`.

O código utiliza `windows.h`, `Sleep` e comandos do console do Windows (`cls` e `mode`). Para executar em outros sistemas operacionais, é necessário adaptar essas chamadas.

### Pelo Dev-C++

1. Abra o arquivo `Sistema_de_Gerenciamento_de_Senhas.dev` no Dev-C++.
2. Caso não existam, crie as pastas `build` e `bin` na pasta do projeto.
3. Use **Execute > Rebuild All** para recompilar todos os módulos.
4. Use **Execute > Run** para iniciar o programa.

O executável será gerado em `bin/Sistema_de_Gerenciamento_de_Senhas.exe`. Abra o projeto `.dev` para compilar todos os módulos em conjunto.

### Pelo terminal (PowerShell)

Na pasta `Sistema_de_Gerenciamento_de_Senhas`, execute:

```powershell
New-Item -ItemType Directory -Force -Path build, bin | Out-Null
gcc -std=c99 -Wall -Wextra -I include src/main.c src/paciente.c src/senha.c src/retirarSenha.c src/realizarAtendimento.c src/atenderPaciente.c src/visualizarSenhas.c -o bin/Sistema_de_Gerenciamento_de_Senhas.exe
.\bin\Sistema_de_Gerenciamento_de_Senhas.exe
```

## Como utilizar

O menu principal oferece:

```text
1 - Retirar senha
2 - Realizar atendimento
3 - Sair
```

### Retirar uma senha

Selecione a opção `1` e informe os dados solicitados. A idade deve ser um número inteiro entre 0 e 130. Utilize letras maiúsculas nas respostas: `M` ou `F` para gênero e `S` ou `N` para gestação e necessidade especial. A pergunta sobre gestação é apresentada quando o gênero informado é `F`.

Ao concluir, o programa apresenta a senha e retorna ao menu principal.

### Consultar e realizar atendimentos

Selecione a opção `2` do menu principal para acessar:

```text
1 - Realizar atendimento
2 - Visualizar senhas
3 - Voltar ao menu principal
```

- **Realizar atendimento:** chama o próximo paciente disponível ou retoma o atendimento em andamento. A opção `1` finaliza o atendimento e busca o próximo; a opção `2` volta ao submenu mantendo o atendimento atual.
- **Visualizar senhas:** mostra os pacientes aguardando na ordem de chamada: urgentes, preferenciais e normais. Digite `1` para voltar.
- **Voltar ao menu principal:** permite cadastrar outros pacientes ou encerrar o sistema.

Quando não há pacientes aguardando, o programa informa que a fila está vazia.

## Exemplo de utilização

Considere os seguintes cadastros, realizados nesta ordem:

| Ordem de cadastro | Nome | Dados relevantes | Senha emitida |
| --- | --- | --- | --- |
| 1 | Carlos | 30 anos, sem necessidade especial | `N001` |
| 2 | Ana | 28 anos, gestante | `P001` |
| 3 | João | 85 anos | `U001` |
| 4 | Pedro | 40 anos, sem necessidade especial | `N002` |

Se nenhum atendimento tiver sido iniciado, a ordem de chamada será:

1. João — `U001`.
2. Ana — `P001`.
3. Carlos — `N001`.
4. Pedro — `N002`.

Ao chamar João, a tela apresenta:

```text
Em atendimento: João - Senha: U001

1 - Finalizar atendimento e chamar proximo
2 - Voltar
```

Na consulta de espera, os números são atualmente exibidos sem preenchimento com zeros, como `P1`, `N1` e `N2`. A emissão e a tela de atendimento utilizam o formato com pelo menos três dígitos.


Os dados ficam apenas na memória durante a execução. Ao fechar o programa, os cadastros e as filas são descartados, e os contadores recomeçam na próxima execução. Não há armazenamento em arquivo, banco de dados ou histórico de atendimentos finalizados.
