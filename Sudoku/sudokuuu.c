#include <stdio.h>
#include "Desenhos.h"
// #include "dificuldade.h"

#define TAMTAB 9

int checkLinCol(int TAB[TAMTAB][TAMTAB], int posCol, int posLin, int num);
int check3x3(int TAB[TAMTAB][TAMTAB], int posCol, int posLin, int num);
int insereSudoku(int TAB[TAMTAB][TAMTAB], int posCol, int posLin, int num);
int backSudoku(int sudoku[TAMTAB][TAMTAB]);
void imprimeTab(int tab[TAMTAB][TAMTAB]);
int brincaSu();

int checkLinCol(int TAB[TAMTAB][TAMTAB], int posCol, int posLin, int num)
{
    for (int i = 0; i < TAMTAB; i++)
    {
        if (TAB[posLin][i] == num || TAB[i][posCol] == num)
            return 0;
    }
    return 1;
}

int check3x3(int TAB[TAMTAB][TAMTAB], int posCol, int posLin, int num)
{
    int linResult, colResult;
    linResult = posLin - (posLin % 3);
    colResult = posCol - (posCol % 3);
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            if (TAB[linResult + a][colResult + b] == num)
                return 0;
        }
    }
    return 1;
}

int insereSudoku(int TAB[TAMTAB][TAMTAB], int posCol, int posLin, int num)
{
    if (check3x3(TAB, posCol, posLin, num) && checkLinCol(TAB, posCol, posLin, num))
    {
        return 1;
    }

    return 0;
}

int backSudoku(int sudoku[TAMTAB][TAMTAB])
{
    int linha, coluna;

    int faltaCelula = 0;
    for (linha = 0; linha < TAMTAB; linha++)
    {
        for (coluna = 0; coluna < TAMTAB; coluna++)
        {
            if (sudoku[linha][coluna] == 0)
            {
                faltaCelula = 1;
                break;
            }
        }
        if (faltaCelula)
            break;
    }
    if (!faltaCelula)
    {
        return 1;
    }

    for (int numero = 1; numero <= TAMTAB; numero++)
    {
        // printf("teste");
        if (insereSudoku(sudoku, coluna, linha, numero))
        {
            sudoku[linha][coluna] = numero;
            // Recursão para resolver outras células
            if (backSudoku(sudoku))
            {
                return 1;
            }
            sudoku[linha][coluna] = 0;
        }
    }
    return 0;
}

void imprimeTab(int tab[TAMTAB][TAMTAB])
{

    for (int a = 0; a < TAMTAB; a++)
    {
        for (int b = 0; b < TAMTAB; b++)
        {
            if (b % 3 == 0)
            {
                printf("%3d  ", tab[a][b]);
            }
            else
            {
                printf("%2d  ", tab[a][b]);
            }
        }
        if (a % 3 == 2)
            printf("\n\n");
        else
            printf("\n");
    }
}

int brincaSu()
{
    int tab[TAMTAB][TAMTAB] =
        {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9},
        };

    if (backSudoku(tab))
    {
        printf("Sudoku resolvido\n");
        imprimeTab(tab);
    }
    else
    {
        printf("Nao foi possivel resolver\n");
    }
    return 1;
};

int newGame(int tab[TAMTAB][TAMTAB], int tab2[TAMTAB][TAMTAB])
{

    srand((unsigned)time(NULL));

    int numero, posCol, posLin, verificado;
    int possivel = 1;
    do
    {
        for (int a = 0; a < TAMTAB; a++)
        {
            for (int b = 0; b < TAMTAB; b++)
            {
                tab[a][b] = 0;
            }
        }
        for (int a = 0; a < 20;)
        {

            numero = geraNumRandom();
            posLin = geraNumRandom();
            posCol = geraNumRandom();

            verificado = insereSudoku(tab, posCol - 1, posLin - 1, numero);
            if (verificado && numero > 0 && numero < 10 && tab[posLin][posCol] == 0)
            {
                a++;
                tab[posLin - 1][posCol - 1] = numero;
            }
            else
            {

                printf("Nao foi possivel inserir esse numero");
                Sleep(100);
            }
            system("cls");
            desenhaSudoku(tab);
            for (int a = 0; a < TAMTAB; a++)
            {
                for (int b = 0; b < TAMTAB; b++)
                {
                    tab2[a][b] = tab[a][b];
                }
            }
        }
        if (backSudoku(tab))
        {
            possivel = 0;
        }
    } while (possivel);
    return 1;
}

int main()
{

    int tab[TAMTAB][TAMTAB];
    int tabJogo[TAMTAB][TAMTAB];
    memset(tab, 0, sizeof(tab));
    memset(tabJogo, 0, sizeof(tabJogo));

    system("mode con:cols=130 lines=35"); // Controlar tamanho do cmd
                                          // brincaSu();

    // do
    // {
    //     printf("Numero: ");
    //     scanf("%d", &numero);
    //     printf("linha: ");
    //     scanf("%d", &posLin);
    //     printf("coluna: ");
    //     scanf("%d", &posCol);

    //     // numero = geraNumRandom();
    //     // posLin = geraNumRandom();
    //     // posCol = geraNumRandom();

    //     verificado = insereSudoku(tab, posCol - 1, posLin - 1, numero);
    //     if (verificado && numero > 0 && numero < 10 && tab[posLin][posCol] == 0)
    //     {
    //         tab[posLin - 1][posCol - 1] = verificado;
    //     }
    //     else
    //     {

    //         printf("Nao foi possivel inserir esse numero");
    //         Sleep(100);
    //     }

    //     system("cls");
    //     imprimeTab(tab);
    // } while (1);

    int verificador = 0;

    switch (Menu_Desenho())
    {
    case 1:
        desenha2Sudoku(tab, tabJogo);
        break;
    case 2:
        break;
    case 3:
        do
        {
            if (newGame(tab, tabJogo))
            {
                verificador = 1;
            }
            else
            {
                memset(tab, 0, sizeof(tab));
            }

        } while (!verificador);

        break;
    default:
        break;
    }

    desenha2Sudoku(tabJogo, tab);

    // system("pause");
    getch();
    return 0;
}