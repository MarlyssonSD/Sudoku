#include <stdio.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#define TAMTAB 10

int checkCol(int TAB[TAMTAB][TAMTAB], int posCol, int posLin, int num);
int checkLin(int TAB[TAMTAB][TAMTAB], int posCol, int posLin, int num);
int check3x3(int TAB[TAMTAB][TAMTAB], int posCol, int posLin, int num);
int insereSudoku(int TAB[TAMTAB][TAMTAB], int posCol, int posLin, int num);
void imprimeTab(int tab[TAMTAB][TAMTAB]);
void randomNumberTab(int tab[TAMTAB][TAMTAB]);

int checkCol(int TAB[TAMTAB][TAMTAB], int posCol, int posLin, int num)
{
    for (int coluna = 1; coluna < TAMTAB; coluna++)
    {
        if (TAB[posLin][coluna] == num)
            return 0;
    }
    return 1;
}

int checkLin(int TAB[TAMTAB][TAMTAB], int posCol, int posLin, int num)
{
    for (int linha = 1; linha < TAMTAB; linha++)
    {
        if (TAB[linha][posCol] == num)
            return 0;
    }
    return 1;
}

int check3x3(int TAB[TAMTAB][TAMTAB], int posCol, int posLin, int num)
{
    int temNum = 0;

    if (posCol >= 1 && posCol <= 3)
    {
        if (posLin > 0 && posLin <= 3)
        {
            temNum = percorre3x3(TAB, 1, 1, num);
        }
        else if (posLin > 3 && posLin <= 6)
        {
            temNum = percorre3x3(TAB, 1, 4, num);
        }
        // else = if (posLin > 6 && posLin <= 9)
        else
        {
            temNum = percorre3x3(TAB, 1, 7, num);
        }
    }
    else if (posCol > 3 && posCol <= 6)
    {
        if (posLin > 0 && posLin <= 3)
        {
            temNum = percorre3x3(TAB, 3, 1, num);
        }
        else if (posLin > 3 && posLin <= 6)
        {
            temNum = percorre3x3(TAB, 3, 4, num);
        }
        // else = if (posLin > 6 && posLin <= 9)
        else
        {
            temNum = percorre3x3(TAB, 3, 7, num);
        }
    }
    else //    else if (posCol > 6 && posCol <= 9)
    {
        if (posLin > 0 && posLin <= 3)
        {
            temNum = percorre3x3(TAB, 7, 1, num);
        }
        else if (posLin > 3 && posLin <= 6)
        {
            temNum = percorre3x3(TAB, 7, 4, num);
        }
        // else = if (posLin > 6 && posLin <= 9)
        else
        {
            temNum = percorre3x3(TAB, 7, 7, num);
        }
    }
    return temNum;
}

int percorre3x3(int TAB[TAMTAB][TAMTAB], int posCol, int posLin, int num)
{
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
            if (TAB[posLin + a][posCol + b] == num)
                return 0;
    }
    return 1;
}

int insereSudoku(int TAB[TAMTAB][TAMTAB], int posCol, int posLin, int num)
{
    if (check3x3(TAB, posCol, posLin, num) && checkCol(TAB, posCol, posLin, num) && checkLin(TAB, posCol, posLin, num))
    {
        return num;
    }
    else
    {
        return -1;
    }
}

void randomNumberTab(int tab[TAMTAB][TAMTAB])
{
    for (int a = 1; a < TAMTAB; a++)
    {
        for (int b = 1; b < TAMTAB; b++)
        {
            tab[a][b] = a * b;
        }
    }
}

void imprimeTab(int tab[TAMTAB][TAMTAB])
{
    for (int a = 1; a < TAMTAB; a++)
    {
        for (int b = 1; b < TAMTAB; b++)
        {
            if (b % 3 == 1)
                printf("%3d  ", tab[a][b]);
            else
                printf("%2d  ", tab[a][b]);
        }
        if (a % 3 == 0)
            printf("\n\n");
        else
            printf("\n");
    }
}

int main()
{

    int tab[TAMTAB][TAMTAB];
    memset(tab, -1, sizeof(tab));

    // randomNumberTab(tab);
    int numero, posCol, posLin = -1, verificado;
    do
    {
        printf("Numero: ");
        scanf("%d", &numero);
        printf("linha: ");
        scanf("%d", &posLin);
        printf("coluna: ");
        scanf("%d", &posCol);
        verificado = insereSudoku(tab, posCol, posLin, numero);
        if (verificado && numero > 0 && numero < 10 && tab[posLin][posCol] == -1)
        {
            tab[posLin][posCol] = verificado;
        }
        else
        {

            printf("Nao foi possivel inserir esse numero");
            Sleep(1000);
        }

        system("cls");
        imprimeTab(tab);
    } while (1);
    // tab[1][1] = insereSudoku(tab, 1, 1, 1);
    // if (checkLin(tab, 1, 4, 1))
    //     tab[1][4] = insereSudoku(tab, 1, 4, 1);
    // tab[1][7] = insereSudoku(tab, 1, 7, 1);
    // tab[1][9] = insereSudoku(tab, 1, 9, 1);
    // tab[2][2] = insereSudoku(tab, 2, 2, 1);

    imprimeTab(tab);
    return 0;
}