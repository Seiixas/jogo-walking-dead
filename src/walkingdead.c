#include <stdio.h>
#include <stdlib.h>
#include <gconio.h>
#include <time.h>

#define COLUNA 10
#define LINHA 10

void renderizaCampo(int posPlayerLinha, int posPlayerColuna, int seedSorteio) {
  int zumbis[LINHA][COLUNA];

  srand(seedSorteio);

  for(int i = 0; i < LINHA; i++) {
    for(int j = 0; j < COLUNA; j++) {
      zumbis[i][j] = rand() % 10;
    }
  }

  for(int i = 0; i < LINHA; i++) {
    for(int j = 0; j < COLUNA; j++) {
      if (posPlayerLinha == i && posPlayerColuna == j)
        printf ("* ");
      else
        printf ("%d ", zumbis[i][j]);
    }
    printf ("\n");
  }
  
}

int main () {
  int linha, coluna, sorteio[LINHA][COLUNA];
  int seed = time(NULL);

  renderizaCampo(5, 5, seed);

  return 0;
}