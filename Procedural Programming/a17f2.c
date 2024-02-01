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
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);
StackType CopyStack(StackType *s1);

int main()
{
    StackElementType AnItem,i;
    StackType s1,s2;

    CreateStack(&s1);
    for(i=0;i<20;i++)
    {
        AnItem=i;
        Push(&s1,AnItem);
    }
    printf("Stack s1\n");
    TraverseStack(s1);
    s2=CopyStack(&s1);
    printf("After copying s1 to s2\n");
    printf("Stack s1\n");
    TraverseStack(s1);
    printf("Stack s2\n");
    TraverseStack(s2);
    return 0;
}


void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;
}

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
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

StackType CopyStack(StackType *s1)
{
     StackType s2,helpStack;
     StackElementType AnItem;

     CreateStack(&s2);
     CreateStack(&helpStack);

     AnItem=s1->Top;
     while (!EmptyStack(*s1))
    {
      Pop(&(*s1), &AnItem);
      Push(&helpStack,AnItem);
    }
    while (!EmptyStack(helpStack))
    {
      Pop(&helpStack, &AnItem);
      Push(&s2,AnItem);
      Push(&(*s1),AnItem);
    }
    return s2;
}
