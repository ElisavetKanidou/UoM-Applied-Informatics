#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define StackLimit 80

typedef struct  {
    int  price;
    char  size;
}StackElementType;

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
    StackElementType AnItem;
    char si;
    int pl,i;
    StackType AStack,secStack;
    boolean found;

     CreateStack(&AStack);
     CreateStack(&secStack);


    printf("Give number of items ");
     scanf("%d",&pl);
     printf("Give the items to store\n");
     for(i=0;i<pl;i++)
     {
     printf("Give price ");
     scanf("%d",&AnItem.price);getchar();
     printf("Give size ");
     scanf("%c",&AnItem.size);getchar();

     Push(&AStack,AnItem);
     }
     printf("Items in the box");
     TraverseStack(AStack);

   printf("What size do you want? ");
   scanf("%c",&si);getchar();
   found=FALSE;
   while(!EmptyStack(AStack) && found==FALSE)
   {
       Pop(&AStack, &AnItem);
       if(AnItem.size==si)
       {
          found=TRUE;
       }
       else
       {
           Push(&secStack,AnItem);
       }
   }
   if(found==TRUE)
   {
       printf("Found the size %c \n",si);
   }
   else
   {
       printf("Not Found the size %c \n",si);
   }
   printf("Items in the box");
   TraverseStack(AStack);
   printf("Items out of the box");
   TraverseStack(secStack);
   while(!EmptyStack(secStack))
   {
       Pop(&secStack, &AnItem);
        Push(&AStack,AnItem);
   }
   printf("Items in the box");
   TraverseStack(AStack);
   printf("Items out of the box");
   TraverseStack(secStack);

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
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%c, ",Stack.Element[i].size);
        printf("%d \n",Stack.Element[i].price);
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

