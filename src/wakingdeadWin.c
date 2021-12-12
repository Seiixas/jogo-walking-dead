#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

#define COLUNA 10
#define LINHA 10

#define CAMINHO_LIVRE 0
#define ESTOU_AQUI -1
#define PASSEI_AQUI -2

int matrizEsqueleto[LINHA][COLUNA] = { CAMINHO_LIVRE };

void menu() {
  printf("                  .....   \n");                                               
  printf("                 C C  /   \n");                                               
  printf("                /<   /    \n"); 
  printf(" ___ __________/_#__=o    \n");  
  printf("/(- /(\\_\\________   \\     \n"); 
  printf("\\ ) \\ )_      \\o     \\    \n"); 
  printf("==================== THE WALKING DEAD ======================\n");
  printf("=   Olá, sobrevivente!                                     =\n");
  printf("=                                                          =\n");
  printf("=  Ao buscar por suprimentos na cidade, você ficou         =\n");
  printf("=  encurralado em uma loja por uma horda que escutou       =\n");
  printf("=  um louco atirando de sniper no telhado                  =\n");
  printf("=                                                          =\n");
  printf("=  Você possui apenas 50 munições para atravessar          =\n");
  printf("=  os quarteirões que possuem certa quantidade de zumbis   =\n");
  printf("=  para cada quantidade, será descontada de suas munições  =\n");
  printf("=                                                          =\n");
  printf("=               Teclas de navegação:                       =\n");
  printf("=                                                          =\n");
  printf("=                        'w'                               =\n");
  printf("=                                                          =\n");
  printf("=                  'a'	       'd'                         =\n");
  printf("=                                                          =\n");
  printf("=                        's'                               =\n");
  printf("=                                                          =\n");
  printf("=            Pressione 'x' para encerrar o jogo.           =\n");
  printf("======================= ROCKET TEAM ========================\n");

  printf("\n\nPressione ENTER para continuar...");
  getchar();
  system("cls");
}

void jogoGanho() {
  setlocale(LC_ALL, "Portuguese");
  system("cls");
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
  system("pause");
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
        matrizEsqueleto[i][j] = ESTOU_AQUI;
      }

      if(matrizEsqueleto[i][j] == PASSEI_AQUI) {
        printf ("* ");
      } 
      else if (matrizEsqueleto[i][j] == ESTOU_AQUI) {
        printf ("_ ");
        
        municaoRestante = pontuacao - zumbis[i][j];

        matrizEsqueleto[i][j] = PASSEI_AQUI;
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
  setlocale(LC_ALL, "Portuguese");
  int seed = time(NULL);
  int linhaAtual = 0, colunaAtual = 0;
  int municao = 50;
  char comando;

  menu();

  system("cls");

  renderizaCampo(linhaAtual, colunaAtual, seed, municao);
  printf ("\n\t MUNIÇÃO ATUAL: %d\n\n", municao);

  while (municao >= 0) {
    comando = getch();
    system("cls");
    switch (comando) {
      case 'w':
          linhaAtual--;
          if (linhaAtual < 0) {
            linhaAtual++;
            renderizaCampo(linhaAtual, colunaAtual, seed, municao);
            printf ("\n\tMovimento irregular");
          }
          else {
            if (matrizEsqueleto[linhaAtual][colunaAtual] == CAMINHO_LIVRE)
              municao = renderizaCampo(linhaAtual, colunaAtual, seed, municao);
            else {
              linhaAtual++;
              matrizEsqueleto[linhaAtual][colunaAtual] == CAMINHO_LIVRE;
              renderizaCampo(linhaAtual, colunaAtual, seed, municao);
              printf ("\n\tMovimento irregular");
            }
          }
        break;
      case 's':
          linhaAtual++;
          if (linhaAtual > (LINHA - 1)) {
            linhaAtual--;
            renderizaCampo(linhaAtual, colunaAtual, seed, municao);
            printf ("\n\tMovimento irregular");
          }
          else {
            if (matrizEsqueleto[linhaAtual][colunaAtual] == CAMINHO_LIVRE)
            municao = renderizaCampo(linhaAtual, colunaAtual, seed, municao);
            else {
              linhaAtual--;
              matrizEsqueleto[linhaAtual][colunaAtual] == CAMINHO_LIVRE;
              renderizaCampo(linhaAtual, colunaAtual, seed, municao);
              printf ("\n\tMovimento irregular");
            }
          }
        break;
      case 'a':
          colunaAtual--;
          if (colunaAtual < 0) {
            colunaAtual++;
            renderizaCampo(linhaAtual, colunaAtual, seed, municao);
            printf ("\n\tMovimento irregular");
          }
          else {
            if (matrizEsqueleto[linhaAtual][colunaAtual] == CAMINHO_LIVRE)
              municao = renderizaCampo(linhaAtual, colunaAtual, seed, municao);
            else {
              colunaAtual++;
              matrizEsqueleto[linhaAtual][colunaAtual] == CAMINHO_LIVRE;
              renderizaCampo(linhaAtual, colunaAtual, seed, municao);
              printf ("\n\tMovimento irregular");
            }
          }
        break;
      case 'd':
          colunaAtual++;
          if (colunaAtual > (COLUNA - 1)) { 
            colunaAtual--;
            renderizaCampo(linhaAtual, colunaAtual, seed, municao);
            printf ("\n\tMovimento irregular");
          }
          else {
            if (matrizEsqueleto[linhaAtual][colunaAtual] == CAMINHO_LIVRE)
              municao = renderizaCampo(linhaAtual, colunaAtual, seed, municao);
            else {
              colunaAtual--;
              matrizEsqueleto[linhaAtual][colunaAtual] == CAMINHO_LIVRE;
              renderizaCampo(linhaAtual, colunaAtual, seed, municao);
              printf ("\n\tMovimento irregular");
            }
          }
          
        break;
      case 'x':
          exit(1);
        break;
      default:
          renderizaCampo(linhaAtual, colunaAtual, seed, municao);
          printf ("\n\tComando inválido!");
        break;
    }

    printf ("\n\t MUNIÇÃO ATUAL: %d\n\n", municao);

  }
  
  system("cls");
  printf("  ____ \n");
  printf(" /     \\\n");
  printf("| () () |  VOCÊ FOI INFECTADO\n");
  printf(" \\  ^  /        GAME OVER\n");
  printf("  |||||   \n");
  printf("  |||||   \n");
  
  system("pause");

  return 0;
}