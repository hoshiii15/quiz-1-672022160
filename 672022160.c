#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void panah(int posisiMenu, int posisiPanah)
{
    if (posisiPanah == posisiMenu)
        printf("==> ");
    else
        printf("   ");
}

void delay()
{
    for (int di = 1; di <= 20000; di++)
    {
        for (int dj = 1; dj <= 8500; dj++)
        {
        }
    }
}

int getPilihan()
{
    int posisi = 1;
    int keyPressed = 0;
    while (keyPressed != 27)
    {
        system("cls");
        gotoxy(40, 1);
        printf("<============================>\n");
        gotoxy(48, 3);
        printf("TUGAS QUIZ ASD");
        gotoxy(40, 5);
        printf("<============================>\n");
        gotoxy(47, 7);
        panah(1, posisi);
        printf("1. Level 1");
        gotoxy(47, 8);
        panah(2, posisi);
        printf("2. Level 2");
        gotoxy(47, 9);
        panah(3, posisi);
        printf("3. Level 3");
        gotoxy(47, 10);
        panah(4, posisi);
        printf("4. Keluar");
        gotoxy(40, 12);
        printf("<============================>\n");

        if (kbhit())
        {
            keyPressed = getch();
        }
        if (keyPressed == 72)
        {
            posisi--;
        }
        else if (keyPressed == 80)
        {
            posisi++;
        }
        else if (keyPressed == 13)
        {
            return posisi;
        }
        if (posisi < 1)
        {
            posisi = 4;
        }
        else if (posisi > 4)
        {
            posisi = 1;
        }
        keyPressed = 'a';
        delay();
    }
}

void lvl1()
{
    int i, j, n;
    system("cls");
    printf("masukkan bilangan = ");
    scanf("%i", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            int b = i + j - 2;
            if (b < 10)
            {
                printf("%d  ", b);
            }
            else
            {
                printf("%d ", b);
            }
        }
        printf("\n");
    }
    system("pause");
}

void lvl2()
{
    int i, j, n;
    system("cls");
    printf("masukkan bilangan = ");
    scanf("%i", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            int b = i * j;
            if (b < 10)
            {
                printf("%d  ", b);
            }
            else
            {
                printf("%d ", b);
            }
        }
        printf("\n");
    }
    system("pause");
}

void lvl3()
{
    int n, a = 1;
    system("cls");
    printf("Masukan Jumlah : ");
    scanf("%d", &n);
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = i; j <= n; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            if (k < i)
                printf("%d", a++);
            else if (k == i)
                printf("%d", a);
            else
                printf("%d", --a);
        }
        printf("\n");
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j >= i; j--)
        {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            if (k < i)
                printf("%d", a++);
            else if (k == i)
                printf("%d", a);
            else
                printf("%d", --a);
        }
        printf("\n");
    }
    system("pause");
}

int main()
{
    system("color 4");
    char lanjut;
    int bilangan[2];
    int pilihan = getPilihan();

    while (pilihan != 4)
    {
        switch (pilihan)
        {
        case 1:
            lvl1();
            main();
            break;
        case 2:
            lvl2();
            main();
            break;
        case 3:
            lvl3();
            main();
            break;
        case 4:
            exit(1);
        }
    }
}
