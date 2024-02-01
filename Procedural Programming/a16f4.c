#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct{
int code;
int prot;
} QueueElementType;

typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void TraverseQ(QueueType Queue);
void insert_prot(QueueType *Queue, QueueElementType Item);

int main()
{
    QueueType AQueue;
   QueueElementType AnItem;
   int i,pl;

   CreateQ(&AQueue);

   printf("PLITHOS STOIXEIWN: ");
     scanf("%d",&pl);
     for(i=1;i<=pl;i++)
     {
        printf("DWSE TON KODIKO TOU %do KOMVOU: ",i);
        scanf("%d",&AnItem.code);
        printf("DWSE TO VATHMO PROTERAIOTITAS TOU %dou KOMVOU: ",i);
        scanf("%d",&AnItem.prot);
        insert_prot(&AQueue,AnItem);
     }
     printf("----------Priority Queue-------------\n");
     TraverseQ(AQueue);

    return 0;
}
void insert_prot(QueueType *Queue, QueueElementType Item)
{
    QueuePointer TempPtr;
    QueuePointer CurrPtr;
    QueuePointer PredPtr;
    boolean flag;

    TempPtr=(QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data=Item;
    TempPtr->Next=NULL;
   if (EmptyQ(*Queue))
   {
       Queue->Front=TempPtr;
       Queue->Rear=TempPtr;
   }
   else
   {
       PredPtr=Queue->Front;
       CurrPtr=Queue->Front;
       flag=TRUE;
       if(CurrPtr->Data.prot>TempPtr->Data.prot)
       {
           Queue->Front=TempPtr;
            TempPtr->Next=CurrPtr;
       }
       else
       {
           while(CurrPtr!=NULL && flag)
           {
               if(CurrPtr->Data.prot>TempPtr->Data.prot)
               {
                   PredPtr->Next=TempPtr;
                   TempPtr->Next=CurrPtr;
                   flag=FALSE;
               }
               PredPtr=CurrPtr;
               CurrPtr=CurrPtr->Next;
           }
           if(flag)
           {
              PredPtr->Next=TempPtr;
              Queue->Rear=TempPtr;
           }
       }
   }

}

void CreateQ(QueueType *Queue)
/* ����������: ���������� ��� ���� ����������� ����.
   ����������: ��� ���� ����������� ����
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����������� ����.
   ����������: ������� �� � ����������� ���� ����� ����.
   ����������: True �� � ���� ����� ����, false  �����������
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* �������:    ��� ����������� ���� Queue ��� ���  �������� Item.
   ����������: ��������� �� �������� Item ��� ����� ��� ������������ ����� Queue.
   ����������: ��� ������������� ����
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����������� ����.
   ����������: ������� �� �������� Item ��� ���  ������ ��� ������������ �����,
                �� ��� �����  ����.
   ����������: �� �������� Item ��� ��� ������������� ����������� ����.
   ������:     ������ ����� �����, �� � ���� �����  ����
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}
void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d %d\n", CurrPtr->Data.prot,CurrPtr->Data.code);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
