#include <stdio.h>
#include <stdlib.h>
#include <gconio.h>
#include <time.h>

#define COLUNA 10
#define LINHA 10

int matrizEsqueleto[LINHA][COLUNA] = { 0 };

void jogoGanho() {
  system("clear");
  printf("              ,       \n");
  printf("     __  _.-\"` `'-.   \n");
  printf("    /||\\'._ __{}_(     PARABÉNS, SOBREVIVENTE!\n");
  printf("    ||||  |'--.__\\    CONSEGUIU CHEGAR AO ABRIGO\n");
  printf("    |  L.(   ^_\\^     \n");
  printf("    \\ .-' |   _ |     \n");
  printf("    | |   )\\___/      \n");
  printf("    |  \\-'`:._]       \n");
  printf("    \\__/;      '-.    \n");
  printf("    |   |o     __ \\   \n");
  printf("    |   |o     )( |   \n");
  printf("    |   |o     \\/ \\   \n");
  exit(1);
}

int renderizaCampo(int posPlayerLinha, int posPlayerColuna, int seedSorteio, int pontuacao) {
  int zumbis[LINHA][COLUNA], municaoRestante;

  srand(seedSorteio);

  for(int i = 0; i < LINHA; i++) {
    for(int j = 0; j < COLUNA; j++) {
      zumbis[i][j] = rand() % 10;
    }
  }

  printf ("*\n");
  for(int i = 0; i < LINHA; i++) {
    for(int j = 0; j < COLUNA; j++) {
      if(posPlayerColuna == j && posPlayerLinha == i) {
        matrizEsqueleto[i][j] = -1;
      }

      if(matrizEsqueleto[i][j] == -2) {
        printf ("* ");
      } 
      else if (matrizEsqueleto[i][j] == -1) {
        printf ("_ ");
        
        municaoRestante = pontuacao - zumbis[i][j];

        matrizEsqueleto[i][j] = -2;
      }
      else {
        printf ("%d ", zumbis[i][j]);
      }
    }
    printf ("\n");
  }

  printf ("\t\t [@]\n");
  
  if(posPlayerColuna == (COLUNA - 1) && posPlayerLinha == (LINHA - 1) && municaoRestante >= 0) {
    jogoGanho();
  }
  
  return municaoRestante;
}

int main () {
  int sorteio[LINHA][COLUNA];
  int seed = time(NULL);
  int linhaAtual = 0, colunaAtual = 0;
  int municao = 50;
  char comando;

  system("clear");

  renderizaCampo(linhaAtual, colunaAtual, seed, municao);
  printf ("\n\t MUNIÇÃO ATUAL: %d\n\n", municao);

  while (municao >= 0) {

    comando = getch();
    system("clear");
    switch (comando) {
      case 'w':
          linhaAtual--;
          if (linhaAtual < 0) linhaAtual++;
          if (matrizEsqueleto[linhaAtual][colunaAtual] == 0)
            municao = renderizaCampo(linhaAtual, colunaAtual, seed, municao);
          else {
            linhaAtual++;
            matrizEsqueleto[linhaAtual][colunaAtual] == 0;
            renderizaCampo(linhaAtual, colunaAtual, seed, municao);
            printf ("\n\tMovimento irregular");
          }
        break;
      case 's':
          linhaAtual++;
          if (linhaAtual > (LINHA - 1)) linhaAtual--;
          if (matrizEsqueleto[linhaAtual][colunaAtual] == 0)
            municao = renderizaCampo(linhaAtual, colunaAtual, seed, municao);
          else {
            linhaAtual--;
            matrizEsqueleto[linhaAtual][colunaAtual] == 0;
            renderizaCampo(linhaAtual, colunaAtual, seed, municao);
            printf ("\n\tMovimento irregular");
          }
        break;
      case 'a':
          colunaAtual--;
          if (colunaAtual < 0) colunaAtual++;
          if (matrizEsqueleto[linhaAtual][colunaAtual] == 0)
            municao = renderizaCampo(linhaAtual, colunaAtual, seed, municao);
          else {
            colunaAtual++;
            matrizEsqueleto[linhaAtual][colunaAtual] == 0;
            renderizaCampo(linhaAtual, colunaAtual, seed, municao);
            printf ("\n\tMovimento irregular");
          }
        break;
      case 'd':
          colunaAtual++;
          if (colunaAtual > (COLUNA - 1)) colunaAtual--;
          if (matrizEsqueleto[linhaAtual][colunaAtual] == 0)
            municao = renderizaCampo(linhaAtual, colunaAtual, seed, municao);
          else {
            colunaAtual--;
            matrizEsqueleto[linhaAtual][colunaAtual] == 0;
            renderizaCampo(linhaAtual, colunaAtual, seed, municao);
            printf ("\n\tMovimento irregular");
          }
        break;
      default:
          exit(1);
        break;
    }

    municao = 500;
    printf ("\n\t MUNIÇÃO ATUAL: %d\n\n", municao);

  }
  
  system("clear");
  printf("  ____ \n");
  printf(" /     \\\n");
  printf("| () () |  VOCÊ FOI INFECTADO\n");
  printf(" \\  ^  /        GAME OVER\n");
  printf("  |||||   \n");
  printf("  |||||   \n");

  return 0;
}