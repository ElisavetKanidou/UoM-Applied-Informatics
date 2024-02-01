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

int main()
{
    StackElementType an;
    char ch;
    StackType AStack;
    boolean apot,flag;

    CreateStack(&AStack);
    apot=TRUE;
    flag=FALSE;
    printf("Enter string:\n");
      scanf("%c",&ch);getchar();
      if(ch=='#')
      {
         return 0;
      }
      while(ch!='#' && apot==TRUE)
      {
        if(flag==FALSE)
        {
       if(ch=='C')
       {
           flag=TRUE;
        scanf("%c",&ch);getchar();
       }
       else
       {
           Push(&AStack,ch);
           scanf("%c",&ch);getchar();
       }
        }
        else
        {
        if(!EmptyStack(AStack))
        {
         Pop(&AStack, &an);
         if(an!=ch)
         {
             apot=FALSE;

         }
         else
         {
            scanf("%c",&ch);getchar();
         }
       }
       else
       {
           apot=FALSE;
       }
       }
      }
      if(apot==TRUE && EmptyStack(AStack))
        printf("TRUE");
      else
      {
          printf("FALSE");
      }

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


