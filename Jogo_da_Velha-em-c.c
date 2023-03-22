#include <stdio.h>

void imprime_tabuleiro(char tabuleiro[3][3])
{
    printf("\t\t\t \t 0   1   2\n");
    printf("\n");
    printf("\t\t\t \t===========\n");
    printf("\t\t\t0\t %c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("\t\t\t \t---+---+---\n");
    printf("\t\t\t1\t %c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("\t\t\t \t---+---+---\n");
    printf("\t\t\t2\t %c | %c | %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\t\t\t \t===========\n");
}

int ganhador(char tabuleiro[3][3], char simbolo)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        if ((tabuleiro[i][0] == simbolo) && (tabuleiro[i][1] == simbolo) && (tabuleiro[i][2] == simbolo))
            return 1;
        if ((tabuleiro[0][i] == simbolo) && (tabuleiro[1][i] == simbolo) && (tabuleiro[2][i] == simbolo))
            return 1;
    }
    if ((tabuleiro[0][0] == simbolo) && (tabuleiro[1][1] == simbolo) && (tabuleiro[2][2] == simbolo))
        return 1;
    if ((tabuleiro[0][2] == simbolo) && (tabuleiro[1][1] == simbolo) && (tabuleiro[2][0] == simbolo))
        return 1;
    return 0;
}

int main()
{
    printf("=================================================================================\n");
    printf("                                      JOGO DA VELHA                              \n");
    printf("=================================================================================\n");
    printf("1 - O jogador deverá acertar o par ou impar para começar o jogo.\n");
    printf("2 - Vocẽ podera escolher entre X ou O para inserir no tabuleiro.\n");
    printf("3 - Cada jogador terá 1 jogada por vez.\n");
    printf("4 - O termino acontecera quando preenchida com X ou O toda linha,coluna.\n");
    printf("5 - Tambem quando for preenchidas com X ou O diagonais principal e secundaria.\n");
    printf("6 - O jogador que conseguir a condição acima se tornará o vencedor\n");
    printf("=================================================================================\n");
    printf("=================================================================================\n");
    printf("                             BEM VINDOS AO JOGO !!!                              \n");
    printf("=================================================================================\n");
    char jogador1[50];
    char jogador2[50];
    printf("=================================================================================\n");
    printf("                           BOM JOGO AOS PARTICIPANTES !!!                        \n");
    printf("=================================================================================\n");
    printf("Informe o nome do jogador 1 = ");
    scanf("%s", &jogador1);
    printf("\nInforme o nome do jogador 2 = ");
    scanf("%s", &jogador2);
    printf("\n");
    printf("=================================================================================\n");
    int jogador;

    // semente para gerar números aleatórios
    srand(time(NULL));

    // sorteia dois números entre 1 e 100
    jogador = rand() % 2 + 1;
    // imprime os números sorteados
    printf("Iniciara o jogo o jogador [[[ %d ]]]\n", jogador);
    printf("=================================================================================\n");
    char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};
    int i, j, linha, coluna, vez = 0;
    char simbolo;
    imprime_tabuleiro(tabuleiro);
    for (i = 0; i < 9; i++)
    {
        if (vez % 2 == 0)
            simbolo = 'X';
        else
            simbolo = 'O';
    printf("=================================================================================\n");
        printf("Jogador %d [%c], digite a linha (0-2) e coluna (0-2): ", vez % 2 + 1, simbolo);
        scanf("%d %d", &linha, &coluna);
    printf("=================================================================================\n");
        if ((linha < 0) || (linha > 2) || (coluna < 0) || (coluna > 2))
        {
            printf("Entrada invalida, tente novamente !!!\n");
            vez--;
        }
        else if (tabuleiro[linha][coluna] != ' ')
        {
            printf("Essa posição, esta ocupada !!!\n");
            vez--;
        }
        else
        {
            tabuleiro[linha][coluna] = simbolo;
            imprime_tabuleiro(tabuleiro);
            if (ganhador(tabuleiro, simbolo))
            {
    printf("=================================================================================\n");
            printf("Jogador %d  [%c] {{{ venceu }}} o jogo parabéns!\n", vez % 2 + 1, simbolo);
    printf("=================================================================================\n");
    printf("                    FIM DE JOGO - COMPILAR O JOGO NOVAMENTE                      \n");
    printf("=================================================================================\n");
    printf("                               BY MAICON NUNES !!!                               \n");
    printf("=================================================================================\n");
    return 0;
            }
        }
        vez++;
    }
    printf("=================================================================================\n");
    printf("Jogo empatado !!! ninguem ganhou\n");
    printf("=================================================================================\n");
    printf("                    FIM DE JOGO - COMPILAR O JOGO NOVAMENTE                      \n");
    printf("=================================================================================\n");
    printf("                               BY MAICON NUNES !!!                               \n");
    printf("=================================================================================\n");
    return 0;
}
