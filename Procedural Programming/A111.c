#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char BinTreeElementType[20];        /*� ����� ��� ��������� ��� ���
                                        ���������� ����� int */
typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void InorderTraversal(BinTreePointer Root);

int SpellingCheck(BinTreePointer Root, FILE* fp);
void CreateDictionary(BinTreePointer *Root, FILE* fp);


int main()
{
   BinTreePointer ARoot;
   FILE* fp1;
   FILE* fp2;
   int i;

   fp1 = fopen("i112f5.txt", "r");
   fp2 = fopen("i111f5.txt", "r");

   CreateBST(&ARoot);
   CreateDictionary(&ARoot, fp1);
   printf("**********Dictionary**********\n");
   InorderTraversal(ARoot);
    printf("**********Not in Dictionary**********\n");
    i=SpellingCheck(ARoot, fp2);
   printf("Number of words not in Dictionary: %d \n",i);
   return 0;
}
void CreateDictionary(BinTreePointer *Root, FILE* fp)
{
  BinTreeElementType Item;
  if (fp==NULL)
     printf ("Problem openning file\n");
    else
    {
  while(!feof(fp))
  {
      fscanf(fp,"%s",Item);
      BSTInsert(Root, Item);
  }
    }
}

int SpellingCheck(BinTreePointer Root, FILE *fp){
    boolean found;
    BinTreePointer LocPtr;
    BinTreeElementType Item;
    int count;

    count=0;

    while(!feof(fp)){
        fscanf(fp, "%s", Item);
        BSTSearch(Root, Item, &found, &LocPtr);
        if(found==FALSE){
            printf("%s \n", Item);
            count++;
        }
    }
    return count;
}

void CreateBST(BinTreePointer *Root)
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item){
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (strcmp(Item, LocPtr->Data) < 0){
            LocPtr = LocPtr ->LChild;
        }
        else if (strcmp(Item, LocPtr->Data) > 0){
                 LocPtr = LocPtr ->RChild;
        }
        else{
            Found = TRUE;
        }
    }
    if (Found)
        printf("To %s EINAI HDH STO DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy(LocPtr ->Data,Item);
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item,Parent ->Data) < 0)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE
*/
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (strcmp(KeyValue, (*LocPtr)->Data)==-1)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue ,(*LocPtr)->Data)==-1)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}



void InorderTraversal(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s \n",Root->Data);
        InorderTraversal(Root->RChild);
    }
}







