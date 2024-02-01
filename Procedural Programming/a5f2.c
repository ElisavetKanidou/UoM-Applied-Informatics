#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define StackLimit 80

typedef int StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
void TraverseStack(StackType Stack);
void Pop(StackType *Stack, StackElementType *Item);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);


int main()
{
    StackElementType AnItem,i,n,x,temp;
    StackType AStack,decstac;

    CreateStack(&AStack);
    for(i=0;i<15;i++)
    {
        AnItem=i*10;
      Push(&AStack,AnItem);
    }
       TraverseStack(AStack);
    printf("Give nth element (n<=6) ");
    scanf("%d", &n);

    printf("\nQuestion a: ");
    if (!EmptyStack(AStack))
    {
        Pop(&AStack, &AnItem);
    }
    if (!EmptyStack(AStack))
    {
        Pop(&AStack, &AnItem);
        printf("x=%d\n",AnItem);
        TraverseStack(AStack);
    }

    printf("\nQuestion b: ");
    if (!EmptyStack(AStack))
        {
        (Pop(&AStack, &AnItem));
        }
        temp=AnItem;
    if (!EmptyStack(AStack))
        {
        (Pop(&AStack, &AnItem));
        }
        x=AnItem;

     Push(&AStack,x);
     Push(&AStack,temp);

    printf("x=%d\n",x);
    if (EmptyStack(AStack))
        printf("Empty Stack\n");
    else TraverseStack(AStack);


    printf("\nQuestion c: ");
  for(i=0;i<n;i++)
  {
       if (!EmptyStack(AStack))
    {
        Pop(&AStack, &AnItem);
    }
  }
  if (EmptyStack(AStack))
  {
    printf("Empty Stack\n");
  }
    else
    { printf("x=%d\n",AnItem);
    TraverseStack(AStack);
    }


     printf("\nQuestion d: ");
     CreateStack(&decstac);

    for(i=0;i<n;i++)
  {
       if (!EmptyStack(AStack))
    {
        Pop(&AStack, &AnItem);
        x=AnItem;
          Push(&decstac,x);
    }
  }
    printf("x=%d\n",x);

    while(!EmptyStack(decstac))
    {
        Pop(&decstac, &AnItem);
        Push(&AStack,AnItem);
    }
    if (EmptyStack(AStack))
        printf("Empty Stack\n");
    else TraverseStack(AStack);


    printf("\nQuestion e: ");
    while(!EmptyStack(AStack))
   {
       Pop(&AStack, &AnItem);
        Push(&decstac,AnItem);
   }
   printf("x=%d\n",AnItem);
  while(!EmptyStack(decstac))
   {
       Pop(&decstac, &AnItem);
        Push(&AStack,AnItem);
   }
  if (EmptyStack(AStack))
        printf("Empty Stack\n");
    else TraverseStack(AStack);



    printf("\nQuestion f: ");
    while(AStack.Top >=2)
    {
         Pop(&AStack, &AnItem);
        Push(&decstac,AnItem);
    }
    printf("x=%d\n",AnItem);

    while(!EmptyStack(decstac))
    {
        Pop(&decstac, &AnItem);
        Push(&AStack,AnItem);
    }
    if (EmptyStack(AStack))
        printf("Empty Stack\n");
    else TraverseStack(AStack);

    printf("\nQuestion g: ");

      if (EmptyStack(AStack))
            printf("Empty Stack\n");
     else
        while (!EmptyStack(AStack))
                {
                Pop(&AStack, &AnItem);
                }
       printf("x=%d\n",AnItem);
    TraverseStack(AStack);
    return 0;
}


void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

