#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define megisto_plithos 1001

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
void Dimiourgia(typos_synolou synolo);

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void displayset(typos_synolou set, stoixeio_synolou maxx );
boolean isFibonacci(stoixeio_synolou n, typos_synolou synolo);
void createFibonacciSet(stoixeio_synolou threshold, typos_synolou synolo);

int main()
{
     stoixeio_synolou max, ar;
     typos_synolou set;
    do{
    printf("Dwse to megistoarithmo. ");
    scanf("%d", &max);
    }while(max<2 || max>1000);

    createFibonacciSet(max, set);
    displayset(set, max);
    do{

    printf("Enter number to check: ");
    scanf("%d", &ar);
        if(ar>=0 && ar<=1000)
           {
    if(isFibonacci(ar, set))
    {
        printf("Fibonacci!\n");
    }
    else
    {
        printf("Not Fibonacci...\n");
    }
           }
    }while(ar>=0);

    return 0;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    return synolo[stoixeio];
}

void Dimiourgia(typos_synolou synolo)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}


void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    synolo[stoixeio] = TRUE;
}


boolean isFibonacci(stoixeio_synolou n, typos_synolou synolo)
{
    if(Melos(n,synolo))
    {
    return TRUE;
    }
    else
    {
    return FALSE;
    }
}

 void createFibonacciSet(stoixeio_synolou threshold, typos_synolou synolo)
 {
     Dimiourgia(synolo);
     stoixeio_synolou x,y,z,i;

     synolo[0] = TRUE;
     x=0;
     y=1;
     z=0;
     for(i=0;z<=threshold;++i)
     {
         z=x+y;
         x=y;
         y=z;
         Eisagogi(x, synolo);

     }
 }

void displayset(typos_synolou set, stoixeio_synolou maxx )
{
	stoixeio_synolou i;

	for (i=0;i <=maxx;i++)
	{
		if(Melos(i,set))
			printf("%d ",i);
	}
	printf("\n");
}
