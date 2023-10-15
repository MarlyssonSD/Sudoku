#include "gconio.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

#define Max_col 130
#define Max_lin 35
#define TAMTAB 9

void Cor_Moldura();
void moldura();
void Nome_Do_Jogo();
int Menu_Desenho();
int Escolhas();
int Escolhido(int escolha);
void desenhaSudoku(int tab[TAMTAB][TAMTAB]);
void desenha2Sudoku(int tab[TAMTAB][TAMTAB], int tab2[TAMTAB][TAMTAB]);
int geraNumRandom();

int geraNumRandom()
{
    return rand() % 9 + 1;
}

void desenha2Sudoku(int tab[TAMTAB][TAMTAB], int tab2[TAMTAB][TAMTAB])
{
    // Calcula a posição de início para imprimir o Sudoku centralizado
    int inicio_x = 10; // Calcula a posição x
    int inicio_y = 15; // Calcula a posição y

    clrscr();
    moldura();
    Nome_Do_Jogo();

    for (int a = 0; a < TAMTAB; a++)
    {
        gotoxy(inicio_x, inicio_y);
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
        {
            inicio_y = inicio_y + 2;
        }
        else
        {
            inicio_y = inicio_y + 1;
        }
    }
    //============
    inicio_x = 82; // Calcula a posição x
    inicio_y = 15; // Calcula a posição y

    for (int a = 0; a < TAMTAB; a++)
    {
        gotoxy(inicio_x, inicio_y);
        for (int b = 0; b < TAMTAB; b++)
        {
            if (b % 3 == 0)
            {
                printf("%3d  ", tab2[a][b]);
            }
            else
            {
                printf("%2d  ", tab2[a][b]);
            }
        }
        if (a % 3 == 2)
        {
            inicio_y = inicio_y + 2;
        }
        else
        {
            inicio_y = inicio_y + 1;
        }
    }
}

void desenhaSudoku(int tab[TAMTAB][TAMTAB])
{
    int x = Max_col; // x = Colunas
    int y = Max_lin; // y = Linhas

    // Calcula a posição de início para imprimir o Sudoku centralizado
    int inicio_x = (x - (TAMTAB * 4 - 1)) / 2; // Calcula a posição x
    int inicio_y = (y - (TAMTAB * 2 - 1));     // Calcula a posição y

    clrscr();
    moldura();
    Nome_Do_Jogo();
    for (int a = 0; a < TAMTAB; a++)
    {
        gotoxy(inicio_x, inicio_y);
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
        {
            inicio_y = inicio_y + 2;
        }
        else
        {
            inicio_y = inicio_y + 1;
        }
    }
}

void moldura()
{
    gotoxy(0, 0);
    printf("%c", 201);
    for (int linha = 1; linha < Max_lin - 1; linha++)
    {
        gotoxy(0, linha);
        printf("%c", 186);
        gotoxy(Max_col - 1, linha);
        printf("%c", 186);
    }
    gotoxy(0, Max_lin);
    printf("\n%c", 200);

    for (int coluna = 1; coluna < Max_col - 1; coluna++)
    {
        gotoxy(coluna, 0);
        printf("%c", 205);
    }
    printf("%c", 187);

    for (int coluna = 1; coluna < Max_col - 1; coluna++)
    {
        gotoxy(coluna, Max_lin - 1);
        printf("%c", 205);
    }
    printf("%c", 188);
}

void Cor_Moldura()
{
    textbackground(LIGHTBLUE);
    textcolor(RED);
    clrscr();

    moldura();
}

void Nome_Do_Jogo()
{
    int y = 3, x = 35;

    gotoxy(x, y++);
    printf("  /$$$$$$  /$$   /$$ /$$$$$$$   /$$$$$$  /$$   /$$ /$$   /$$");
    gotoxy(x, y++);

    printf(" /$$__  $$| $$  | $$| $$__  $$ /$$__  $$| $$  /$$/| $$  | $$");
    gotoxy(x, y++);

    printf("| $$  \\__/| $$  | $$| $$  \\ $$| $$  \\ $$| $$ /$$/ | $$  | $$");
    gotoxy(x, y++);

    printf("|  $$$$$$ | $$  | $$| $$  | $$| $$  | $$| $$$$$/  | $$  | $$");
    gotoxy(x, y++);

    printf(" \\____  $$| $$  | $$| $$  | $$| $$  | $$| $$  $$  | $$  | $$");
    gotoxy(x, y++);

    printf(" /$$  \\ $$| $$  | $$| $$  | $$| $$  | $$| $$\\  $$ | $$  | $$");
    gotoxy(x, y++);

    printf("|  $$$$$$/|  $$$$$$/| $$$$$$$/|  $$$$$$/| $$ \\  $$|  $$$$$$/");
    gotoxy(x, y++);

    printf(" \\______/  \\______/ |_______/  \\______/ |__/  \\__/ \\______/ ");
}

int Menu_Desenho()
{
    Cor_Moldura();
    Nome_Do_Jogo();

    int x = 45, y = 16;

    gotoxy(x, y);
    printf("%c", 201);

    for (int linha = y; linha < 24; linha += 2)
    {
        gotoxy(x, linha + 2);
        printf("%c", 204);
        gotoxy(x, linha + 1);
        printf("%c", 186);
        if (linha == 22)
        {
            gotoxy(x, linha + 2);
            printf("%c", 200);
            gotoxy(x + 40, linha + 2);
            printf("%c", 188);
            gotoxy(x + 40, y);
            printf("%c", 187);
        }
    }

    for (int coluna = x + 1; coluna < 85; coluna++)
    {
        gotoxy(coluna, y);
        printf("%c", 205);
        gotoxy(coluna, y + 2);
        printf("%c", 205);
        gotoxy(coluna, y + 4);
        printf("%c", 205);
        gotoxy(coluna, y + 6);
        printf("%c", 205);
        gotoxy(coluna, y + 8);
        printf("%c", 205);
    }

    for (int linha = y; linha < 22; linha += 2)
    {
        gotoxy(x + 40, linha + 2);
        printf("%c", 185);
        gotoxy(x + 40, linha + 1);
        printf("%c", 186);
        if (linha == 20)
        {
            gotoxy(x + 40, linha + 3);
            printf("%c", 186);
        }
    }

    gotoxy(x + 18, y += 1);
    printf("JOGAR");

    gotoxy(x + 16, y += 2);
    printf("COMO JOGAR");

    gotoxy(x + 13, y += 2);
    printf("GERADOR DE SUDOKU");

    gotoxy(x + 19, y += 2);
    printf("SAIR");
    return Escolhido(Escolhas());
}

int Escolhido(int escolha)
{
    int x = 60, y = 30;
    if (escolha == 1)
    {
        gotoxy(x, y);
        printf("Voce escolheu: JOGAR!!!");

        Cor_Moldura();
        return escolha;
    }
    else if (escolha == 2)
    {
        gotoxy(x, y);
        printf("Voce escolheu: COMO JOGAR!!!");
        return escolha;
    }
    else if (escolha == 3)
    {
        gotoxy(x, y);
        printf("Voce escolheu: OPCAO!!!");
        return escolha;
    }
    else if (escolha == 4)
    {
        gotoxy(x, y);
        printf(" tchau ;-; :'( ");
        return escolha;
    }
    return 0;
}

int Escolhas()
{
    int coluna = 86, linha = 17, escolha = 1;
    char letra;

    gotoxy(100, 2);
    textcolor(BLACK);
    printf("MOVA COM 'W' E 'S'");
    gotoxy(100, 3);
    printf("OU UTILIZE AS SETAS");
    textcolor(RED);

    gotoxy(coluna, linha);
    printf("<========");
    do
    {
        gotoxy(130, 35);
        letra = getch();

        if (linha != 17)
        {
            if (letra == 72 || toupper(letra) == 87)
            {
                gotoxy(coluna, linha -= 2);
                printf("<========");
                escolha -= 1;
            }
            if (linha != 25)
            {
                gotoxy(coluna, linha + 2);
                printf("         ");
            }
        }
        if (linha != 23)
        {
            if (letra == 80 || toupper(letra) == 83)
            {
                gotoxy(coluna, linha += 2);
                printf("<========");
                escolha += 1;
            }
            if (linha != 25)
            {
                gotoxy(coluna, linha - 2);
                printf("         ");
            }
        }
        gotoxy(129, 34);

    } while (letra != 13 && letra != ' ');
    return escolha;
}

void tela_gameover()
{
    textbackground(BLACK);
    textcolor(RED);
    clrscr();
    gotoxy(0, 0);
    printf("%c", 201);
    for (int linha = 1; linha < Max_lin - 1; linha++)
    {
        gotoxy(0, linha);
        printf("%c", 186);
        gotoxy(Max_col - 1, linha);
        printf("%c", 186);
    }
    gotoxy(0, Max_lin);
    printf("\n%c", 200);

    for (int coluna = 1; coluna < Max_col - 1; coluna++)
    {
        gotoxy(coluna, 0);
        printf("%c", 205);
    }
    printf("%c", 187);

    for (int coluna = 1; coluna < Max_col - 1; coluna++)
    {
        gotoxy(coluna, Max_lin - 1);
        printf("%c", 205);
    }
    printf("%c", 188);

    int y = 14, x = 20;

    gotoxy(x, y++);
    printf("   .::::         .:       .::       .::. ::::::::     .::::     .::         .::.::::::::.:::::::    ");

    gotoxy(x, y++);
    printf(" .:    .::      .: ::     .: .::   .:::. ::         .::    .::   .::       .:: .::      .::    .::  ");

    gotoxy(x, y++);
    printf(".::            .:  .::    .:: .:: . .::. ::       .::        .::  .::     .::  .::      .::    .::  ");

    gotoxy(x, y++);
    printf(".::           .::   .::   .::  .::  .::. ::::::   .::        .::   .::   .::   .::::::  .: .::      ");

    gotoxy(x, y++);
    printf(".::   .::::  .::::::::::. .::   .:  .::. ::       .::        .::    .:: .::    .::      .::  .::    ");

    gotoxy(x, y++);
    printf(" .::    .:  .::       .:: .::       .::. ::         .::     .::      .::::     .::      .::    .::  ");

    gotoxy(x, y++);
    printf("  .:::::   .::         .::.::       .::. ::::::::     .::::           .::      .::::::::.::      .::");
}
