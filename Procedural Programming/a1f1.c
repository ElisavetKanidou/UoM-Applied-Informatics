#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define megisto_plithos 201

 typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);

void displaySet(typos_synolou S, stoixeio_synolou first, stoixeio_synolou last);
boolean isPrime(stoixeio_synolou n);
void createPrimeSet(typos_synolou s, stoixeio_synolou first, stoixeio_synolou last);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);


int main()
{
     stoixeio_synolou first,last;
     typos_synolou set;
     do{
    printf("Dwse ton prwto thetiko akeraio: ");
    scanf("%d", &first);
    }while(first<2 || last>200);
    do{
    printf("Dwse ton teleytaio thetiko akeraio: ");
    scanf("%d", &last);
     }while(first<2 || last>200 || first>=last);

    createPrimeSet(set, first, last);
    displaySet(set, first, last);
   return 0;
}

void createPrimeSet(typos_synolou s, stoixeio_synolou first, stoixeio_synolou last)
{
     Dimiourgia(s);

    stoixeio_synolou i;

     Dimiourgia(s);

for(i=first;i<=last;i++)
{
    if(isPrime(i))
    {
  Eisagogi(i,s);
    }
}
}

boolean isPrime(stoixeio_synolou n)
{
    stoixeio_synolou i,limit;

    if(n==2) return TRUE;
    if(n%2==0) return FALSE;
     limit=sqrt(n);
     for(i=3;i<=limit;i+=2)
    {
        if(n%i==0) return FALSE;
    }
    return TRUE;
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


void displaySet(typos_synolou S, stoixeio_synolou first, stoixeio_synolou last)
{
     stoixeio_synolou i;
    for(i=first;i<=last;i++)
	{
		if(Melos(i,S))
			printf("%d ",i);
	}
	printf("\n");
}
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    return synolo[stoixeio];
}
