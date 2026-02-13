# Projeto: Cadastro e Comparação de Cartas (Super Trunfo)

Este projeto foi desenvolvido como atividade do curso de **Análise e Desenvolvimento de Sistemas (ADS)** e marcou o meu **primeiro contato com linguagem C e com programação no geral**.

A proposta do exercício foi construir, no terminal, uma versão inicial de um jogo no estilo **Super Trunfo**, com foco em praticar fundamentos de programação.

## 🎯 Intuito do exercício no curso

O objetivo da atividade não era criar um jogo completo com interface gráfica, mas sim treinar a base da lógica de programação usando C, especialmente:

- entrada e saída de dados com `scanf`, `fgets` e `printf`;
- criação e uso de `struct` para organizar dados;
- funções para separar responsabilidades do código;
- laços de repetição e menus interativos;
- estruturas condicionais para tomada de decisão;
- cálculos com dados numéricos;
- comparação de valores para definir vencedores.

Em resumo, foi um exercício pensado para ensinar como transformar regras de um problema real em código executável.

## 🧠 O que foi implementado no programa

O sistema foi evoluído para além do cadastro básico e hoje executa as etapas abaixo:

### 1) Cadastro de duas cartas
Para cada carta, o programa solicita:

- estado;
- cidade;
- quantidade de pontos turísticos;
- população;
- área da cidade (km²);
- PIB.

### 2) Cálculos automáticos
Após o cadastro, o programa calcula:

- **densidade populacional** = população / área;
- **PIB per capita** = PIB / população;
- **super poder** = soma dos atributos numéricos da carta.

Também há validação simples para evitar divisão por zero.

### 3) Exibição organizada dos dados
Os dados de cada carta são mostrados no terminal com formatação, incluindo os valores calculados.

### 4) Menu de comparação entre cartas
Depois de cadastrar as cartas, o usuário pode comparar:

1. Super Poder;
2. Densidade Populacional;
3. Pontos Turísticos;
4. Área;
5. PIB.

Regras da comparação:

- na **densidade populacional**, vence o **menor valor**;
- nos demais critérios, vence o **maior valor**;
- se os valores forem iguais, ocorre empate.

## 🛠️ Conceitos praticados com este projeto

- Definição de estruturas (`struct Carta`);
- Funções (`cadastrarCarta`, `mostrarCarta`, `compararCartas`, etc.);
- Manipulação de buffer de entrada (`limparBuffer`);
- Controle de fluxo com `switch`, `if/else`, `do...while`;
- Organização do código em blocos reutilizáveis;
- Construção de menus em aplicações de console.

## 📚 Observação pessoal

Por ser meu primeiro projeto em C, este exercício foi importante para entender, na prática, como programar:

- como ler dados do usuário;
- como armazenar informações de forma estruturada;
- como aplicar fórmulas;
- e como usar lógica para comparar resultados.

Mais do que o resultado final, o principal ganho foi o aprendizado da base que será usada em projetos maiores no curso.
