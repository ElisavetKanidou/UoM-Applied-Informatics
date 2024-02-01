#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define QueueLimit 10

typedef int QueueElementType;


typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
	int count;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void TraverseQ(QueueType Queue);

int main()
{
    QueueType AQueue;
   QueueElementType AnItem,i;

   CreateQ(&AQueue);

   printf("---a---");
   for(i=0;i<=9;i++)
   {
       AnItem=i;
       AddQ(&AQueue,AnItem);
   }
    TraverseQ(AQueue);
    printf("Front=%d Rear=%d Count=%d\n",AQueue.Front,AQueue.Rear,AQueue.count);

    printf("---b---\n");
    AnItem=25;
    AddQ(&AQueue,AnItem);
    TraverseQ(AQueue);
    printf("Front=%d Rear=%d Count=%d\n",AQueue.Front,AQueue.Rear,AQueue.count);

    printf("---c---");
    RemoveQ(&AQueue, &AnItem);
    TraverseQ(AQueue);
    printf("Remove item=%d Front=%d Rear=%d Count=%d\n",AnItem,AQueue.Front,AQueue.Rear,AQueue.count);

    printf("---d---");
    AnItem=25;
    AddQ(&AQueue,AnItem);
    TraverseQ(AQueue);
    printf("Front=%d Rear=%d Count=%d\n",AQueue.Front,AQueue.Rear,AQueue.count);

    printf("---e---\n");
    AnItem=25;
    AddQ(&AQueue,AnItem);
    TraverseQ(AQueue);
    printf("Front=%d Rear=%d Count=%d\n",AQueue.Front,AQueue.Rear,AQueue.count);

    printf("---f---");
    while(!EmptyQ(AQueue))
    {
         RemoveQ(&AQueue, &AnItem);
         TraverseQ(AQueue);
         printf("Remove item=%d Front=%d Rear=%d Count=%d",AnItem,AQueue.Front,AQueue.Rear,AQueue.count);

    }

    return 0;
}

void TraverseQ(QueueType Queue) {
	int current,i;

	printf("\nQueue: ");
	 if (EmptyQ(Queue)) printf("Empty Queue");
    current = Queue.Front;
	for(i=0;i<Queue.count;i++) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}

void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->count = 0;
}

boolean EmptyQ(QueueType Queue)
{
	return ((Queue.count) == 0);
}

boolean FullQ(QueueType Queue)
{
	return ((Queue.count) == QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		Queue ->count = Queue ->count - 1;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
		Queue ->count = Queue ->count + 1;
	}
	else
		printf("Full Queue");
}






