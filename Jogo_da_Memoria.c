#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

struct Play{
    int i,j;
}try[2];

int menu();

char **creat_main_board(int i, int j);

char **creat_played_board(int i, int j);

int select_difficulty();

void clean_terminal();

void board_size(int dif, int *i, int *j);

void randon_main_board(char **board, int i, int j);

void print_board(char **board, int i, int j);

int player_try(char **main_board, char **played_board, int size_i, int size_j);

void show_instructions();

int main(){
    srand(time(NULL));

    int game_option,
        size_i, size_j,
        difficulty,
        game_try,
        score_plus=0, score_minus=0,
        playing=1;
    char **main_board,
         **played_board;

    game_option = menu();

    switch(game_option){
        case 1:
            difficulty = select_difficulty();
            board_size(difficulty, &size_i, &size_j);
            main_board = creat_main_board(size_i, size_j);
            played_board = creat_played_board(size_i, size_j);
            clean_terminal();
            randon_main_board(main_board, size_i, size_j);
            printf("Você tem %i segundos para memorizar o seu jogo!\n\n", (size_i*size_j)/3);
            print_board(main_board, size_i, size_j);
            sleep((size_i*size_j)/3);
            clean_terminal();

            while(playing==1){
                game_try = player_try(main_board, played_board, size_i, size_j);
                if(game_try==1)
                    score_plus++;
                if(game_try==0)
                    score_minus++;
                if(score_plus==size_i*size_j/2){
                    playing =0;
                }
            print_board(played_board, size_i, size_j); 
                
            }
            sleep(1);
            clean_terminal();
            printf("VOCE GANHOU!\n");
            printf("Sua pontuação final foi de: %i\n", (10-(10*score_minus)/(size_i*size_j)));
            break;
        case 2:
            printf("Essa opção ainda não está disponível...\n");
            break;
        case 3:
            show_instructions();
            break;
        case 4:
            printf("O jogo foi finalizado pelo jogador.\n");
            return 0;
    }
    return 0;
}

// show the player the menu, and see what they wants to do
int menu(){
    int option;

    printf( "- Bem vindo ao jogo da memória!\n"
            "- Ecolha as opções abaixo:\n\n"
            "1 - Novo jogo\n"
            "2 - Carregar jogo\n"
            "3 - Como jogar\n"
            "4 - Sair\n"
            "-> ");
    scanf("%i", &option);
    while(!(option<=4 && option>=1)){
        printf("Entrada não reconhecida. Por favor, tente novamente: ");
        scanf("%i", &option);
    }
    clean_terminal();
    return option;
}
// creat the main board using dynamic allocation
char **creat_main_board(int i, int j){
    char **board;
    int n;
    board = (char **) malloc(i*sizeof(char *));
    if(board==NULL){
        printf("Erro ao criar tabuleiro!\n");
        return NULL;
    }

    for(n=0; n<j; n++){
        board[n] = (char *) malloc(j*sizeof(char));
        if(board[n]==NULL){
            printf("Erro ao criar as linhas do tabuleiro!");
            return NULL;
        }
    }
    for(int k=0; k<i; k++){
        for(int l=0; l<j; l++){
            board[k][l] = '_';
        }
    }
    return board;
}
// creat the played board using dynamic allocation
char **creat_played_board(int i, int j){
    char **board;
    int n;
    board = (char **) malloc(i*sizeof(char *));
    if(board==NULL){
        printf("Erro ao criar tabuleiro!\n");
        return NULL;
    }

    for(n=0; n<j; n++){
        board[n] = (char *) malloc(j*sizeof(char));
        if(board[n]==NULL){
            printf("Erro ao criar as linhas do tabuleiro!");
            return NULL;
        }
    }

    for(int k=0; k<i; k++){
        for(int l=0; l<j; l++){
            board[k][l] = '_';
        }
    }
    return board;
}
//  select the game difficulty
int select_difficulty(){
    int dif;

    printf("Começando novo jogo\n");
    usleep(500000);
    printf(".\n");
    usleep(500000);
    printf(".\n");
    usleep(500000);
    printf(".\n");
    usleep(500000);
    clean_terminal();

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
    return dif;
}
// clean the terminal
void clean_terminal(){
    printf("\e[1;1H\e[2J");
}

void board_size(int dif, int *i, int *j){
    
    switch(dif){
        case 1:
            *i = 3;
            *j = 4;
            break;
        case 2:
            *i = 4;
            *j = 5;
            break;
        case 3:
            *i = 5;
            *j = 6;
            break;
    }
}

void randon_main_board(char **board, int i, int j){
    int a,
        n,
        k, l;
    char letters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};

     for(n=0; n<(i*j)/2; n++){     
        for(a=0; a<2; a++){
            k=rand()%i;
            l=rand()%j;
            if(board[k][l] == '_'){
                board[k][l] = letters[n];
            }else{
                a = a-1;
            }
        }
    }
}

void print_board(char **board, int i, int j){
    int a, b;

    for(a=0; a<i; a++){
        for(b=0; b<j; b++){
            printf(" %c ", board[a][b]);
        }
        printf("\n");
    }
}

int player_try(char **main_board, char **played_board, int size_i, int size_j){
    int n;

    for(n=0; n<2; n++){
        printf("\nDigite uma casa para revelar a sua carta. (entre %i e %i)\n", size_i, size_j);
        printf("-> ");
        scanf("%i %i", &try[n].i, &try[n].j);
        try[n].i--;
        try[n].j--;
        while((try[n].i>(size_i-1)) || (try[n].j>(size_j-1))){
            printf("Valor não reconhecido, tente novamente. (entre %i e %i)\n", size_i, size_j);
            printf("-> ");
            scanf("%i %i", &try[n].i, &try[n].j);
            try[n].i--;
            try[n].j--;
        }
        printf("Essa carta é: %c\n", main_board[try[n].i][try[n].j]);
    }
    if(try[0].i == try[1].i && try[0].j == try[1].j){
        printf("Voce não pode escolher a mesma carta...\n");
        sleep(1);
        clean_terminal();
        return 2;
    }

    if(main_board[try[0].i][try[0].j]==main_board[try[1].i][try[1].j]){
        played_board[try[0].i][try[0].j] = main_board[try[0].i][try[0].j];
        played_board[try[1].i][try[1].j] = main_board[try[1].i][try[1].j];

        printf("Você acertou!\n");
        sleep(1);
        clean_terminal();
        return 1;
    }else{
        printf("Você errou...\n");
        sleep(2);
        clean_terminal();
        return 0;
    }
}

void show_instructions(){
    printf("Este é um projeto realizado para a disciplina de Algoritmos e Programação, do curso de Engenharia de Software\n\n"
          "-> Para jogar, você deve digitar no terminal as coordenadas da casa que deseja revelar, sendo que entre a coordenada x e j deve existir um 'espaço'.\n"
          "-> Ao revelar duas casas que contêm a mesma carta, essas ficaram salvas pelo resto do jogo.\n\n\n"
          "Dúvidas, críticas e sugestões podem ser enviadas para o email f_radins@hotmail.com\n"
          "Divirta-se!\n");
}
