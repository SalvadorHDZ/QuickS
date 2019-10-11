#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 10000

int GeneraNumeros(int Arreglo[N]);
void Imprimir(int Arreglo[N]);
void QuickSort(int Arreglo[N],int inicio,int fin);
void Intercambio(int *A, int*B);

int main()
{
    srand(time(0));
    int Arreglo[N],inicio,fin;
    int d,e,f;
    //Inicio y fin, estos indican el primer digito de la array y el ultimo para poder usarlos como el tope inicial y el final.
    printf("Intercambio Directo(Metodo de QUICKSORT)\n");

    inicio = 0;
    fin = N-1;

    GeneraNumeros(Arreglo);
    d=time(0);
    //Imprimir(Arreglo);
    QuickSort(Arreglo,inicio,fin);
    e=time(0);
    f=e-d;
    printf("\n --------\n");
    printf(" El tiempo es: %d",f);
    //Imprimir(Arreglo);
    printf("\n --------\n");
    getch();
}

int GeneraNumeros(int Arreglo[N])
{
    int x;
    for(x=0;x<N;x++)
    {
        Arreglo[x] = rand()%25;
    }
}

void Imprimir(int Arreglo[N])
{
    int x;
    for(x=0;x<N;x++)
    {
        printf("El arreglo es: %d\n",Arreglo[x]);
    }
}

void QuickSort(int Arreglo[N],int inicio,int fin)
{
    int pivote=inicio,izq=inicio,der=fin,band=1;

    while(band==1)
    {
        band=0;
        while(Arreglo[der]>=Arreglo[pivote]&&der>pivote)
        {
            der--;
        }
        if(der>pivote)
        {
            Intercambio(&Arreglo[pivote], &Arreglo[der]);
            pivote=der;

            while(Arreglo[izq]<=Arreglo[pivote]&&izq<pivote)
            {
                izq++;
            }
            if(izq<pivote)
            {
                Intercambio(&Arreglo[pivote], &Arreglo[izq]);
                pivote=izq;
                band=1;
            }
        }
        if(pivote>inicio+1)
        {
            QuickSort(Arreglo,inicio,pivote-1);
        }
        if(pivote<fin-1)
        {
            QuickSort(Arreglo,pivote+1,fin);
        }
    }
}

void Intercambio(int *A, int*B)
{
    int cambio;
    cambio = *A;
    *A = *B;
    *B = cambio;
}

