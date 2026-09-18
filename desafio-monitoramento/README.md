# 🌡️ Monitoramento de Temperaturas

## 📌 Identificação

* **Aluno:** Zamorano Sousa
* **Disciplina:** Algoritmos e Pensamento Computacional
* **Professora:** Profa. Karla Sartin
* **Projeto:** Monitoramento de Temperaturas
* **Linguagem:** C

---

## 🎯 Objetivo

O objetivo deste projeto é desenvolver um programa em linguagem C capaz de realizar o **monitoramento de temperaturas geradas aleatoriamente**, utilizando estruturas de repetição e estruturas de decisão.

O programa permite que o usuário defina uma temperatura mínima, uma temperatura máxima e um valor limite. A partir desses valores, temperaturas aleatórias são geradas e analisadas.

O monitoramento é encerrado automaticamente quando são identificadas **3 temperaturas consecutivas acima do limite definido pelo usuário**.

Ao final, o programa apresenta um relatório com informações sobre as temperaturas monitoradas.

---

## ⚙️ Funcionamento

O programa funciona seguindo algumas etapas:

### 1. Definição da temperatura mínima e máxima

Primeiramente, o usuário informa os valores mínimo e máximo que serão utilizados para gerar as temperaturas aleatórias.

O programa verifica se o valor máximo é menor que o valor mínimo. Caso isso aconteça, uma mensagem de erro é apresentada e os valores precisam ser informados novamente.

```c
do {
    printf("\nDigite o valor maximo: ");
    scanf("%lf", &tempMax);

    printf("\nDigite o valor minimo:  ");
    scanf("%lf", &tempMin);

    if (tempMax < tempMin) {
        printf("\nERRO. O valor maximo nao pode ser menor que o valor minimo. Tente novamente!");
    }
} while(tempMax < tempMin);
```

---

### 2. Definição do limite de temperatura

Depois, o usuário informa a temperatura limite.

O valor limite precisa estar dentro do intervalo definido anteriormente. Portanto:

* O limite não pode ser maior que a temperatura máxima.
* O limite não pode ser menor que a temperatura mínima.

Caso uma dessas condições aconteça, o programa solicita novamente o valor.

```c
do {
    printf("\nDigite o valor limite: ");
    scanf("%lf", &TEMPERATURA_LIMITE);

    if (TEMPERATURA_LIMITE > tempMax) {
        printf("\nTemperatura limite nao pode ser maior do que a temperatura maxima!");
    } else if (TEMPERATURA_LIMITE < tempMin) {
        printf("\nTemperatura limite nao pode ser menor do que a temperatura minima!");
    }
} while (TEMPERATURA_LIMITE > tempMax || TEMPERATURA_LIMITE < tempMin);
```

---

### 3. Geração das temperaturas

Após definir os valores, o programa utiliza a função `rand()` para gerar temperaturas aleatórias dentro do intervalo definido pelo usuário.

A função `srand(time(NULL))` é utilizada para inicializar a geração dos números aleatórios.

```c
srand(time(NULL));

double escala = (double)rand() / RAND_MAX;
double temp = tempMin + escala * (tempMax - tempMin);
```

Dessa forma, cada execução do programa pode gerar uma sequência diferente de temperaturas.

---

### 4. Verificação do limite

Cada temperatura gerada é comparada com o limite definido pelo usuário.

Quando a temperatura está acima do limite:

* O contador de temperaturas acima do limite é incrementado.
* O contador de temperaturas consecutivas acima do limite também é incrementado.
* A temperatura é exibida como **ACIMA DO LIMITE**.

```c
if (temp > TEMPERATURA_LIMITE) {
    acimaLimite++;
    maxAcimaLimiteCons++;

    printf("\nTemperatura ACIMA DO LIMITE: %.2f", temp);
}
```

Quando a temperatura não está acima do limite, o contador de temperaturas consecutivas é reiniciado:

```c
else {
    maxAcimaLimiteCons = 0;
}
```

---

### 5. Encerramento do monitoramento

O programa continua gerando temperaturas enquanto não forem encontradas 3 temperaturas consecutivas acima do limite.

```c
} while (maxAcimaLimiteCons < 3);
```

Por exemplo:

| Temperatura | Acima do limite? | Consecutivas |
| ----------: | :--------------: | -----------: |
|    45.20 °C |        Não       |            0 |
|    52.10 °C |        Sim       |            1 |
|    54.30 °C |        Sim       |            2 |
|    48.70 °C |        Não       |            0 |
|    53.90 °C |        Sim       |            1 |
|    56.20 °C |        Sim       |            2 |
|    58.40 °C |        Sim       |            3 |

Nesse caso, o programa é encerrado após a última temperatura, pois foram identificadas 3 temperaturas consecutivas acima do limite.

---

## 🔁 Estruturas de repetição

O projeto utiliza a estrutura **`do...while`** em três momentos principais.

### Definição dos valores mínimo e máximo

É utilizado para garantir que o usuário informe novamente os valores caso a temperatura máxima seja menor que a mínima.

### Definição do limite

Também é utilizado para garantir que o limite esteja dentro do intervalo estabelecido.

### Monitoramento das temperaturas

A estrutura `do...while` é utilizada para gerar e analisar as temperaturas até que sejam encontradas 3 temperaturas consecutivas acima do limite.

A escolha do `do...while` é adequada porque o bloco precisa ser executado **pelo menos uma vez antes da verificação da condição**.

No monitoramento, isso é especialmente importante porque a temperatura precisa ser gerada e analisada antes de verificar se o contador de temperaturas consecutivas chegou a 3.

---

## 📊 Cálculos realizados

Ao final do monitoramento, o programa calcula e apresenta:

### Total de temperaturas

Quantidade total de temperaturas geradas durante o monitoramento.

### Quantidade acima do limite

Quantidade de temperaturas que ultrapassaram o limite definido pelo usuário.

### Percentual acima do limite

O percentual é calculado utilizando:

```c
double percentualAcimaLimite = ((double)acimaLimite / totalTemperaturas) * 100;
```

A fórmula utilizada é:

**Percentual = (quantidade acima do limite ÷ total de temperaturas) × 100**

### Média das temperaturas

A média é calculada dividindo a soma das temperaturas pela quantidade total de temperaturas:

```c
mediaTemp = somaTemperaturas / totalTemperaturas;
```

### Maior temperatura

O programa compara cada temperatura gerada com a maior temperatura registrada anteriormente e atualiza o valor quando encontra uma temperatura maior.

### Menor temperatura

Da mesma forma, cada temperatura é comparada com a menor temperatura registrada anteriormente, permitindo identificar a menor temperatura de todo o monitoramento.

---

## 🧪 Testes

### Teste 1 — Validação dos valores

**Objetivo:** verificar se o programa impede valores inválidos para os limites.

**Exemplo:**

* Temperatura máxima: `30`
* Temperatura mínima: `50`

**Resultado esperado:**

O programa identifica que a temperatura máxima é menor que a mínima e solicita os valores novamente.

Também é testado um limite fora do intervalo definido, como:

* Temperatura mínima: `20`
* Temperatura máxima: `50`
* Limite: `60`

Nesse caso, o programa informa que o limite não pode ser maior que a temperatura máxima.

---

### Teste 2 — Temperaturas acima do limite sem três consecutivas

**Objetivo:** verificar se o contador de temperaturas consecutivas é reiniciado quando uma temperatura não está acima do limite.

**Exemplo de sequência:**

```text
55 → acima
40 → normal
53 → acima
45 → normal
58 → acima
```

O contador de consecutivas deve funcionar da seguinte maneira:

```text
1 → 0 → 1 → 0 → 1
```

**Resultado esperado:** o programa não deve ser encerrado por atingir 3 temperaturas consecutivas acima do limite.

Como as temperaturas do programa são geradas aleatoriamente, a sequência exata pode variar a cada execução.

---

### Teste 3 — Três temperaturas consecutivas acima do limite

**Objetivo:** verificar o encerramento automático após 3 temperaturas consecutivas acima do limite.

**Exemplo:**

```text
45 → normal
55 → acima
52 → acima
58 → acima
```

Após a terceira temperatura consecutiva acima do limite, o contador chega a `3` e o `do...while` é encerrado.

**Resultado esperado:** o programa finaliza o monitoramento e apresenta o relatório.

---

## ▶️ Como executar

### Compilação

Utilizando o GCC:

```bash
gcc sensor_temperatura.c -o sensor_temperatura
```

### Execução

No Linux/macOS:

```bash
./sensor_temperatura
```

No Windows:

```bash
sensor_temperatura.exe
```

---

## 📋 Relatório final

Ao terminar o monitoramento, o programa apresenta:

* Total de temperaturas verificadas;
* Total de temperaturas acima do limite;
* Percentual de temperaturas acima do limite;
* Média das temperaturas;
* Maior temperatura registrada;
* Menor temperatura registrada.

Exemplo:

```text
========== RELATORIO ==========

Total de temperaturas verificadas: 10
Total de temperaturas acima do limite: 4
Percentual acima do limite: 40.00%
Media das temperaturas: 47.35 oC
Maior temperatura: 58.72 oC
Menor temperatura: 31.42 oC

===============================
```

---

## 💭 Reflexão final

A estrutura `do...while` foi escolhida porque permite que o bloco de código seja executado pelo menos uma vez antes da condição ser verificada. Isso é importante principalmente no monitoramento, pois uma temperatura precisa ser gerada e analisada antes de verificar se o programa deve continuar ou ser encerrado.

A diferença entre verificar a condição antes ou depois da execução também é importante. No monitoramento, a condição precisa ser analisada **depois** que a temperatura foi processada, pois somente após verificar uma temperatura é possível saber se ela está acima do limite e se o contador de temperaturas consecutivas chegou a 3.

O projeto também utiliza estruturas condicionais para validar os valores informados pelo usuário, comparar as temperaturas com o limite e atualizar os valores de maior e menor temperatura.

Dessa forma, o programa aplica conceitos de **variáveis, entrada e saída de dados, operadores, estruturas condicionais, estruturas de repetição, números aleatórios e cálculos** em uma situação de monitoramento de temperaturas.
