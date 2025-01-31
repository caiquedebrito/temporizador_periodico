# Temporizador periódico

Esta tarefa tem como objetivo a programação de um semáforo utilizando a função `add_repeating_timer_ms()`.

## Componentes utilizados

- Microcontrolador Raspberry Pi Pico W
- 3 LEDs (Vermelho, amarelo e verde)
- 3 Resistores de 330 Ω

## Requisitos implementados

1) O acionamento dos LEDs (sinais do semáforo) deve iniciar na cor vermelha, alterando para amarela e, em seguida, verde. 
2) O temporizador deve ser ajustado para um atraso de 3 segundos (3.000ms). 
3) A mudança de estado dos LEDs deve ser implementa na função de call-back do temporizador. 
4) A rotina principal, presente no interior da estrutura de repetição while, deve imprimir algum tipo de informação a cada segundo (1.000 ms). 
5) Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIOs 11, 12 e 13.

## Como executar o projeto

### Pré-requisitos

- Git
- CMake
- Ferramentas de desenvolvimento para Raspberry Pi Pico
- Visual Studio Code com as extensões recomendadas
- Extensão do Wokwi

### Passos

1. Clone o repositório
Abra o terminal e execute o comando:
```
git clone https://github.com/caiquedebrito/temporizador_periodico.git
cd temporizador_periodico
```

2. Abra o projeto no VS Code
```
code .
```

3. Compile o projeto com a extensão CMake

4. Clique no arquivo diagram.json para abrir o simulador wokwi

5. Execute o projeto