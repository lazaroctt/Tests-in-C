#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//////////////////////////////////////////////////////////////////////
//
//                         HANOI CIRCULAR
//
//        Problema das Torres de Hanoi Circular com 3 pinos A,B
//        OBJETIVO: Mover n discos de A p/ C (usando B) no sentido
//		    dos ponteiros do relógio
//
//            Autor: Carlos A. Martinhon
//
//////////////////////////////////////////////////////////////////////


//======================================================================
//====================    Programa Principal   =========================
//======================================================================



// Move n discos de um pino A para um pino D usando B e C
int Hanoi1(int n, char a, char c, char b, int TM)
{
    int Hanoi2(int, char, char, char, int);  // Prototipo de Hanoi2

    if (n==1)             // base da recursão
    {
        printf("Move disco %d de %c para %c \n", n, a, b);  // base da recursao p/ n impar
        printf("Move disco %d de %c para %c \n", n, b, c);  // base da recursao p/ n impar
        TM = TM+2;
    }
    else
    {
        TM = Hanoi1(n-1, a, c, b, TM);
        printf("Move disco %d de %c para %c \n", n, a, b);
        TM = TM+1;
        TM = Hanoi2(n-1, c, a, b, TM);
        printf("Move disco %d de %c para %c \n", n, b, c);
        TM = TM+1;
        TM = Hanoi1(n-1, a, c, b, TM);
    }

    return TM;              // retorna total de movimentos
}
//======================================================================

// Move n discos de um pino A para um pino D usando B e C
int Hanoi2(int n, char a, char b, char c, int TM)
{
    int Hanoi2(int, char, char, char, int);

    if (n==1)          // base da recursão
    {
        printf("Move disco %d de %c para %c \n", n, a, b);
        TM = TM + 1;
    }
    else
    {
        TM = Hanoi1(n-1, a, c, b, TM);
        printf("Move disco %d de %c para %c \n", n, a, b);
        TM = TM + 1;
        TM = Hanoi1(n-1, c, b, a, TM);
    }

    return TM;
}


//======================================================================
//====================    Programa Principal   =========================
//======================================================================

int main()
{
    int N;
    char X = 'A';
    char Y = 'B';
    char Z = 'C';
    int T_movimentos; // inicializa total de movimentos
    char opcao;

    do
    {
        T_movimentos = 0;   // inicializa total de movimentos

        printf("\n***  Executa Hanoi Circular com 3 pinos ***\n");
        printf("\nEntre com o numero de discos = ");
        scanf("%d", &N);

        T_movimentos = Hanoi1(N, X, Z, Y, T_movimentos);

        printf("\nTotal de movimentos = %d \n", T_movimentos);

        printf("\nDeseja continuar (s/n)? ");
        scanf("%s", &opcao);
    }
    while (opcao == 's');

    printf("\nTchau!! Obrigado !\n");

    return 0;
}
//======================================================================
