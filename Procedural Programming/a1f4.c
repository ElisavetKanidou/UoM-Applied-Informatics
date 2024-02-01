#include <stdio.h>
#include <stdlib.h>

#define NumberOfNodes 10 /*���� �������� ��� ������������ ������,
                            ���������� ������ ��� �� 50*/
#define NilValue -1       // ������ �������� ���� ������� �� ����� ��� ����.������

typedef int ListElementType; /*����� ��������� ��� �� �������� ���
                                ������������ ������ char */
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;


typedef enum {
    FALSE, TRUE
} boolean;


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void TraverseLinked(ListPointer List, NodeType Node[]);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item,
ListPointer *PredPtr);

int main()
{
     ListPointer AList;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr,PredPtr;

    ListElementType AnItem;

   char ch;
    boolean found;
    int i;

   InitializeStoragePool(Node, &FreePtr);
   CreateList(&AList);
    printf("---------------Question C--------------------\n");
  printf("--------------Storage pool------------------\n");
   printAll(AList, FreePtr, Node);
   printf("---------------Question D--------------------\n");
  printf("--------------Linked list--------------------\n");
    TraverseLinked(AList, Node);
  printf("---------------Question E--------------------\n");
            do
                    {

                        printf("Give a number: ");
                        scanf("%d",&AnItem);
                        found=Search(FreePtr,AList,Node,AnItem,&PredPtr);
                        Insert(&AList,Node,&FreePtr,PredPtr,AnItem);
                        printf("\nContinue Y/N: ");
                        do
                        {
      	                     scanf("%c", &ch);
                        }while (ch!='Y'&&ch!='n'&&ch!='N'&&ch!='y');
                     }while (ch!='N'&&ch!='n');

      printf("---------------Question F--------------------\n");
    printf("--------------Storage pool------------------\n");
    printAll(AList, FreePtr, Node);

    printf("---------------Question G--------------------\n");
    printf("--------------Linked list--------------------\n");
    TraverseLinked(AList, Node);
    printf("---------------Question H--------------------\n");
     if (EmptyList(AList))
    printf("Empty List\n");
    else
   printf("Not an Empty List\n");
   printf("---------------Question I--------------------\n");
    if (FullList(FreePtr))
        printf("Full List\n");
   else printf("Not a Full List\n");
   printf("---------------Question J--------------------\n");
   printf("-----------------Search for a number-----------------\n");
   for(i=0;i<2;i++)
   {
        printf("Give a number ");
        scanf("%d", &AnItem);
        found=Search(FreePtr,AList, Node, AnItem,&PredPtr);
        if(found)
            printf("The number is in the list and its predecessor is in position %d\n",PredPtr);
         else
            printf("The number is not in the list");
    }


	return 0;
}

boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, ListPointer *PredPtr){

    ListPointer CurrPtr;
    boolean stop, found;

	found = FALSE;
	stop = FALSE;

	*PredPtr = NilValue;
    if(!EmptyList(List))
	{

      CurrPtr = List;
      while(CurrPtr!=NilValue&&!stop)
	  {
          if(Node[CurrPtr].Data>=Item)
		  {
              stop = TRUE;
              found = (Node[CurrPtr].Data==Item);
          }
		  else
		  {
              *PredPtr = CurrPtr;
              CurrPtr = Node[CurrPtr].Next;
          }
       }
    }
	else found = FALSE;
    return found;
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d->%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
}




void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* �������:   ��� ������ Node ��� ��� ������ FreePtr ��� ������� ����
                ����� ��������� �����.
  ����������: ����������� ��� ������ Node �� ����������� ����� ���������� ������
                ���� ���������� �������� ��� ������,
                ��� ����������� ��� ������ FreePtr .
  ����������: ��� ������������� ������ Node ��� ���
                ������ FreePtr ��� ������ ���������� ������
*/
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;    /* ��� ����� �������� � ������� ������� ����� ��� ����� ��� ���������, ������� ���� �������� */
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=-1;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
/* ����������: ���������� ��� ���� ����������� �����.
   ����������: ���� (��������) ������ ��� ������� �� ���� �����
*/
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
/* �������:    ���� ������ List ��� ������� �� ��� ����������� �����.
   ����������: ������� �� � ����������� ����� ����� ����.
   ����������: True �� � ����������� ����� ����� ���� ��� false �����������
*/
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
/* �������:    ��� ����������� �����.
   ����������: ������� �� � ����������� ����� ����� ������.
   ����������: True �� � ���������������� ����� ������, false �����������
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* �������:   ��� ������ Node ��� ��� ������ FreePtr.
  ����������: ������ ���� "��������" ����� ��� ��� ������� � ������� P.
  ����������: ��� ������ P ��� ��� �������������  ������ FreePtr
                ��� ����������� ��� ����� ��������� �����
*/
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}



void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* �������:    ��� ����������� �����, ��� ������ Node, ��� ������ PredPtr ���
                ��� �������� Item.
  ����������: ������� ��� ����������� �����, �� ��� ����� ������, �� ��������
                Item ���� ��� ��� ����� ���� ����� ������� � ������� PredPtr.
  ����������: ��� ������������� ����������� �����, ��� ������������� ������ Node
                ��� ��� ������ FreePtr.
  ������:     ������ ������� ������, �� � ����������� ����� ����� ������
*/
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}



void TraverseLinked(ListPointer List, NodeType Node[])
/* �������:    ��� ����������� �����.
   ����������: ����� �������� ��� ������������ ������, �� ��� ����� ����.
   ������:     ��������� ��� ��� �����������
*/
{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d: %d->%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}





