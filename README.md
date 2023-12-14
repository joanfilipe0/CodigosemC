# Códigos de Conceitos de Programação em C

Os códigos fornecidos demonstram diferentes conceitos em programação, incluindo programação concorrente, programação paralela e uso de bibliotecas específicas em linguagem C

Esses códigos são exemplos educativos e demonstram como lidar com tarefas concorrentes e paralelas em C, utilizando bibliotecas como pthreads e MPI. Cada código aborda diferentes aspectos da programação concorrente e paralela, oferecendo insights sobre como lidar com esses desafios em ambientes multi-thread e multi-processo.

# 01 - Barreira

O código ilustra como dividir uma tarefa entre duas threads para acelerar o processo de soma de um grande conjunto de dados. O uso de semáforos garante que as threads executem suas tarefas de maneira coordenada, evitando condições de corrida e garantindo um resultado correto. Este exemplo pode ser útil para entender conceitos básicos de programação concorrente em C.

# 02 - Mestre Escravo

Este exemplo demonstra como implementar um modelo mestre-escravo para a multiplicação de matrizes distribuída entre diferentes processos. A utilização do MPI permite a execução paralela, acelerando o processo em sistemas com suporte a MPI.

Este código pode ser uma base útil para entender como dividir tarefas em um ambiente distribuído e pode ser adaptado para matrizes maiores ou outros tipos de operações distribuídas.

# 03 - Multi Matriz

Este exemplo simples em C demonstra como multiplicar duas matrizes usando três loops aninhados. Pode servir como uma introdução à multiplicação de matrizes em linguagem C e ser uma base para experimentação e aprendizado.

Este código pode ser modificado para lidar com matrizes de tamanhos diferentes ou para incluir funcionalidades adicionais, conforme necessário.

# 04 - Produto Consumidor

O buffer é representado por um array chamado buffer.
As variáveis head e tail indicam a posição de leitura e escrita no buffer.
O semáforo empty controla o número de posições vazias no buffer.
O semáforo full controla o número de posições ocupadas no buffer.
O produtor gera dados e os coloca no buffer, enquanto o consumidor os retira.

Este exemplo serve como uma introdução prática ao uso de semáforos e threads em C para resolver um problema de concorrência, como o problema produtor-consumidor. Pode ser expandido e adaptado para cenários mais complexos ou servir como base para experimentação e aprendizado em programação concorrente.

# 05 - Semáforo

Funcionamento
A variável global quantidade é compartilhada entre as threads.
A função incrementa incrementa a quantidade por 10.000 vezes, garantindo exclusão mútua com o uso do semáforo.
A criação e execução das threads são feitas no main.
A função pthread_join é utilizada para esperar a conclusão das threads antes de imprimir o resultado.

Este exemplo ilustra a importância da sincronização ao lidar com variáveis compartilhadas entre threads em um ambiente concorrente. A utilização do semáforo garante a consistência dos resultados, evitando condições de corrida. Pode ser uma base útil para entender conceitos básicos de programação concorrente em C.

# 06 - Thread

As matrizes A e B são inicializadas com valores específicos.
Cada thread é responsável por calcular uma parte da matriz resultante C.
A função mult realiza o cálculo da multiplicação para uma determinada parte da matriz.
A criação e execução das threads são realizadas no main.
A função pthread_join é utilizada para aguardar a conclusão de cada thread antes de prosseguir.

O número de threads é definido por n, e cada thread é atribuída a uma parte específica da matriz C.
A implementação utiliza a biblioteca pthread para criação e controle de threads.

Este exemplo ilustra como realizar a multiplicação de matrizes em paralelo usando threads pthreads em C. Pode servir como uma base útil para experimentação e aprendizado em programação paralela em sistemas multicore.
