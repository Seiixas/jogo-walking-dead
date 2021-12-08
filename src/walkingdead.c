#include <stdio.h>
#include <stdlib.h>
#include <gconio.h>
#include <time.h>

#define COLUNA 10
#define LINHA 10

void renderizaCampo(int posPlayerLinha, int posPlayerColuna, int seedSorteio) {
  // int zumbis[LINHA][COLUNA];

  // for(int i = 0; i < LINHA; i++) {
  //   for(int j = 0; i < COLUNA; j++) {
  //     zumbis[i][j] = rand() % 10;
  //   }
  // }

  for(int i = 0; i < LINHA; i++) {
    for(int j = 0; j < COLUNA; j++) {
      if (posPlayerLinha == i && posPlayerColuna == j)
        printf ("* ");
      else
        printf ("$ ");
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