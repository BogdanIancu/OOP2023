#include <stdio.h>
#include <math.h>

int main()
{
    printf("Hello World!\n");
    //implicit tipurile de date au semn
    //tipul char ocupa 1 byte
    char c = -7;
    //doar daca declaram implicit unsigned atunci valorile sunt pozitive
    unsigned char d = 65;
    printf("%d\n", d);
    printf("%c\n", d);

    //valorile intregi din C/C++ fac overflow
    char t = 129;
    printf("%d\n", t);

    short x = 130;
    printf("%d\n", x);
    //tipul short ocupa 2 bytes
    printf("%d\n", (int)sizeof(x));

    int y = 2312344;
    //tipul int ocupa 4 bytes
    printf("%d\n", (int)sizeof(y));

    long z = 2387423;
    //long pe compilatorul Visual C++ ocupa tot 4 bytes
    printf("%d\n", (int)sizeof(z));

    long long w = 1237123763123;
    //long long ocupa 8 bytes pe acest compilator
    printf("%d\n", (int)sizeof(w));

    //conditia din if va fi evaluata ca true de fiecara data
    //deoarece s-a utilizat operatorul de atribuire nu cel de egalitate
    //(in x se va copia valoarea 120 care fiind diferita de 0 va fi true)
    if (x = 120)
    {
        printf("x este 120\n");
    }
    else
    {
        printf("x este diferit de 120\n");
    }

    float q = 8.4f;
    printf("%d\n", (int)sizeof(q));

    double o = 8.4;
    printf("%d\n", (int)sizeof(o));

    //conditia va fi evaluata ca false
    //deoarece numerele in virgula mobila sunt aproximari
    if (q == 8.4)
    {
        printf("Sunt egale!\n");
    }
    else
    {
        printf("Nu sunt egale!\n");
    }

    //asa efectuam corect comparatia a doua numere cu zecimale
    if (fabs(q - 8.4) < 0.01)
    {
        printf("Acum sunt egale!\n");
    }
}