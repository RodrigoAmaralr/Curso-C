#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // imprime cabecalho do nosso jogo com ascii art
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n          Bem vindo ao    \n");
    printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinhação!\n");
    printf("    |" "  |  |_|  |"  " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    int segundos = time(0);
    srand(segundos);

    int numeroGrande = rand();

    int numerosecreto = numeroGrande % 100;

    int chute;

    int ganhou = 0;
    int tentativas = 1;

    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nivel de dificuldade?\n");
    printf("(1) Facil. (2) Medio. (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numeroDeTentativas;
    switch (nivel)
    {
    case 1:
        numeroDeTentativas = 20;
        break;
    case 2:
        numeroDeTentativas = 15;
        break;
    default:
        numeroDeTentativas = 6;
        break;
    }        

    for(int i = 1; i <= numeroDeTentativas;i++){
        printf("Tentativa %d \n", tentativas);
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0){
            printf("Voce nao pode chutar numeros negativos!\n");
            continue;
        }
        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou){
            break;
        }
        else if(maior){
            printf("Seu chute foi maior que o numero secreto\n");
        }
        else{
            printf("Seu chute foi menor que o numero secreto\n");
        }
        tentativas++;

        double pontosPerdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosPerdidos;

    }
    printf("Fim de Jogo! ");

    if(acertou){
        printf("\n\n");
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");

        printf("Parabéns! Você ganhou!\n");
        printf("Voce acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos : %.1f\n", pontos);
    }else{
        printf("\n\n");
        printf("Você perdeu! tente de novo!\n");
        printf("\n\n");
        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
        printf("\n\n");
    }

}