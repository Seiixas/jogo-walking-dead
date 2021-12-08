#include <stdio.h>
#include <stdlib.h>
#include <gconio.h>
#include <time.h>

#define COLUNA 10
#define LINHA 10

int matrizEsqueleto[LINHA][COLUNA] = { 0 };

int renderizaCampo(int posPlayerLinha, int posPlayerColuna, int seedSorteio, int pontuacao) {
  int zumbis[LINHA][COLUNA], municaoRestante;

  srand(seedSorteio);

  for(int i = 0; i < LINHA; i++) {
    for(int j = 0; j < COLUNA; j++) {
      zumbis[i][j] = rand() % 10;
    }
  }

  for(int i = 0; i < LINHA; i++) {
    for(int j = 0; j < COLUNA; j++) {
      if(posPlayerColuna == j && posPlayerLinha == i) {
        matrizEsqueleto[i][j] = -1;
      }

      if(matrizEsqueleto[i][j] == -2) {
        printf ("_ ");
      } 
      else if (matrizEsqueleto[i][j] == -1) {
        printf ("* ");
        
        municaoRestante = pontuacao - zumbis[i][j];

        matrizEsqueleto[i][j] = -2;
      }
      else {
        printf ("%d ", zumbis[i][j]);
      }
    }
    printf ("\n");
  }
  
  return municaoRestante;
}

int main () {
  int sorteio[LINHA][COLUNA];
  int seed = time(NULL);
  int linhaAtual = 0, colunaAtual = 0;
  int municao = 50;
  char comando;

  renderizaCampo(linhaAtual, colunaAtual, seed, municao);
    printf ("\n\t MUNIÇÃO ATUAL: %d\n\n", municao);

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
    municao = renderizaCampo(linhaAtual, colunaAtual, seed, municao);
    if (municao <= 0) {
      system("clear");
      printf("  ____ \n");
      printf(" /     \\\n");
      printf("| () () |  VOCÊ FOI INFECTADO\n");
      printf(" \\  ^  /        GAME OVER\n");
      printf("  |||||   \n");
      printf("  |||||   \n");
      break;
    } else 
    printf ("\n\t MUNIÇÃO ATUAL: %d\n\n", municao);

  }

  return 0;
}