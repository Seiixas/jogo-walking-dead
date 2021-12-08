#include <stdio.h>
#include <stdlib.h>
#include <gconio.h>
#include <time.h>

#define COLUNA 10
#define LINHA 10

void renderizaCampo(int posPlayerLinha, int posPlayerColuna, int seedSorteio) {
  int zumbis[LINHA][COLUNA];

  printf ("[%d][%d]\n\n", posPlayerLinha, posPlayerColuna);

  srand(seedSorteio);

  for(int i = 0; i < LINHA; i++) {
    for(int j = 0; j < COLUNA; j++) {
      zumbis[i][j] = rand() % 10;
    }
  }

  for(int i = 0; i < LINHA; i++) {
    for(int j = 0; j < COLUNA; j++) {
      printf (
        (posPlayerColuna == j && posPlayerLinha == i) 
        ? "* "
        : "%d ", zumbis[i][j]
      );
    }
    printf ("\n");
  }
  
}

int main () {
  int sorteio[LINHA][COLUNA];
  int seed = time(NULL);
  int linhaAtual = 0, colunaAtual = 0;
  char comando;

  renderizaCampo(linhaAtual, colunaAtual, seed);

  while (1) {

    comando = getch();
    switch (comando) {
      case 'w':
          linhaAtual--;
          if (linhaAtual < 0) linhaAtual++;
        break;
      case 's':
          linhaAtual++;
          if (linhaAtual > (LINHA - 1)) linhaAtual--;
        break;
      case 'a':
          colunaAtual--;
          if (colunaAtual < 0) colunaAtual++;
        break;
      case 'd':
          colunaAtual++;
          if (colunaAtual > (COLUNA - 1)) colunaAtual--;
        break;
      default:
          exit(1);
        break;
    }

    system ("clear");
    renderizaCampo(linhaAtual, colunaAtual, seed);

  }

  return 0;
}