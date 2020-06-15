# Posix Lab

O Posix Lab é composto pelos aqrivos "src/mintest/macros.h" e "src/mintest/runner.h", além de um arquivo de testes "testes.c"

Para executar todos os testes $ ./test

Caso esse executavel não esteja na pasta, você poce obtê-lo dessa forma:

    $gcc -Wall testes.c -o test

Para executar um unico teste basta escrever $ ./test testx, onde o x deve ser mudado para o número do teste que deseja executar.

O relatório de teste imprime os resultados seguindo um código de cores:
 - [PASS]: Verde;
 - [FAIL]: Vermelho;
 - [ERRO]: Magenta;

A funão fork() garante a execução dos testes de maneira isolada, evitando interferências de um teste no outro.

Ao fim da execução é possível ver quantos testes passaram e no total testado.
