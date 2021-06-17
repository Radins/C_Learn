#include <stdio.h>
#include <stdlib.h>

int main(){

  int dif;

  printf("Começando novo jogo\n");
  usleep(500000);
  printf(".\n");
  usleep(500000);
  printf(".\n");
  usleep(500000);
  printf(".\n");
  usleep(500000);
 // clean_terminal();

  printf("Escolha a dificuldade do jogo:\n");
  usleep(700000);
  printf("1 - Fácil\n"
          "2 - Médio\n"
          "3 - Difícil \n"
          "-> " );
  scanf("%i", &dif);
  while(!(dif>=1 && 3>=dif)){
    printf("Entrada não reconhecida, por favor, tente novamente: ");
    scanf("%i", &dif);
  }

  printf("%i", dif);

}