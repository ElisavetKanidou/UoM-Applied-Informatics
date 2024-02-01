#include <stdlib.h>
#include "string.h"
#include <stdio.h>
#include <ctype.h>

#define HMax 5              /*     �� ������� ��� ������ HashTable
                                ���������� ��� �� 5 */
#define VMax 30             /*�� ������� ��� ������,
                                ���������� ��� �� 30 */
#define EndOfList -1        /* ������ ��� ����������� �� ����� ��� ������
                                ��� ��� ���� ��������� ��������� */

typedef int ListElementType;  /*����� ��������� ��� �� �������� ��� ������
                               * ���������� ����� int */
typedef char KeyType[32];

typedef struct {
	KeyType RecKey;
	int Link;
	char phone[11];
    ListElementType type;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // ������� ������� ���� ��� ��������� ���������
    int Size;                // ������ �������� ��� ������ List
	int SubListPtr;          // D������� �� ��� �������� ���������
    int StackPtr;           // ������� ���� ��� ����� �������� ���� ��� ������ List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);


void PrintPinakes(HashListType HList);

void BuildHashList(HashListType *HList);
void Search_HashList_By_Subject(HashListType HList,int code);
int findAverage(KeyType s);

int main(){

   char ch;
   char surname[20];
   HashListType HList;
   ListElm AnItem;
   KeyType AKey;
   int Loc, Pred,type;

   printf("1. Create HashList\n");
   CreateHashList(&HList);
   PrintPinakes(HList);

   printf("2. Insert new member\n");
    do
   {
       printf("Enter teacher's name: ");
       scanf("%s",AnItem.RecKey),getchar();
       printf("Enter teacher's surname: ");
        scanf("%s",surname),getchar();
       strcat(AnItem.RecKey," ");
       strcat(AnItem.RecKey,surname);
      printf("Enter teacher's phone: ");
       scanf("%s",AnItem.phone),getchar();
       printf("Enter teacher code: ");
       scanf("%d", &AnItem.type);

       AddRec(&HList,AnItem);

      printf("\nContinue Y/N:");
       do
        {
            scanf("%c",&ch);
        }while ((ch != 'Y') && (ch != 'N'));
    }while ((ch == 'Y'));

    PrintPinakes(HList);


    printf("3. Delete a teacher\n");

    printf("Enter teacher's name: ");
    scanf("%s",AKey),getchar();
    printf("Enter teacher's surname: ");
    scanf("%s",surname),getchar();

    strcat(AKey," ");
    strcat(AKey,surname);

    SearchHashList(HList,AKey,&Loc,&Pred);

    if (Loc != -1)
    {
        DeleteRec(&HList,AKey);
    }
    else
    {
        printf("DEN YPARXEI EGGRAFH ME KLEIDI %s",AKey);
    }

    printf("\n");

    PrintPinakes(HList);


    printf("4. Search for a teacher\n");
      printf("Enter teacher's name: ");
      scanf("%s",AKey),getchar();
    printf("Enter teacher's surname: ");
    scanf("%s",surname),getchar();
    strcat(AKey," ");
    strcat(AKey,surname);

    SearchHashList(HList,AKey,&Loc,&Pred);


  if (Loc != -1)
    {
        printf("[%s,%s,%d]",AKey,HList.List[Loc].phone,HList.List[Loc].type);
    }
  else
    {
        printf("DEN YPARXEI EGGRAFH ME KLEIDI %s",AKey);
    }

    printf("\n");

    printf("\n5.Search by subject\n");
    printf("Enter code: ");
    scanf("%d",&type);
    printf("List of teachers with subject code 1:\n");

    Search_HashList_By_Subject(HList,type);

	return 0;

}

int HashKey(KeyType Key)
{
    int avg;
	avg = findAverage(Key);
	return avg%HMax;


}
int findAverage(KeyType s)
{
   int first, last;
   first = (toupper(s[0])-64);
   last = (toupper(s[strlen(s)-1])-64);

   return((first+last)/2);

}
void Search_HashList_By_Subject(HashListType HList, int code)
{
   int i, SubIndex;

   for(i=0;i<HMax; i++)
   {
       SubIndex=HList.HashTable[i];

       while(SubIndex!=EndOfList)
       {
             if (code == HList.List[SubIndex].type)
         {
                    printf("%d:[%s,%s,%d]\n",SubIndex,HList.List[SubIndex].RecKey,HList.List[SubIndex].phone,HList.List[SubIndex].type);
         }
           SubIndex=HList.List[SubIndex].Link;
       }
   }
}
void BuildHashList(HashListType *HList)
{
   ListElm AnItem;
    FILE* fp;
    int nscan;
    char surname[20], termch;

    CreateHashList(HList);

    fp = fopen("i4f6.txt","r");

    if (fp != NULL)
    {
        while (TRUE)
        {
           nscan = fscanf(fp,"%10[^,],%20[^,],%11[^,],%d%c",AnItem.RecKey,surname,AnItem.phone,&AnItem.type,&termch);
           if (nscan == EOF) break;
           if (nscan != 5 || termch != '\n')
           {
                printf("Error");

                exit(1);
           }
           else
           {
                strcat(AnItem.RecKey," ");
                strcat(AnItem.RecKey,surname);

                AddRec(HList,AnItem);
           }
        }
    }
    fclose(fp);
}




void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
    {
        printf("%d,",HList.HashTable[i]);
    }
    printf("\n");
	printf("Hash List\n");
    for (i=0;i<HList.Size;i++)
	   printf("%d) %s, %d\n",i,HList.List[i].RecKey,HList.List[i].Link);
	printf("\n");
}



void CreateHashList(HashListType *HList)
/* ����������: ���������� ��� ���� HList.
   ����������: ��� ���� HList
*/
{
	int index;

	HList->Size=0;           //���������� ��� ���� �����
	HList->StackPtr=0;       //������� ��� ������ ��� ������� ��� ��������� ������

    /*����������� ��� ������ HashTable ��� ����� HList ���� ���� ��������� ���
        �� ���� �� ���� EndOfList (-1)*/
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

     //���������� ��� ������� ��� ��������� ������ ��� ����� HList
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}

boolean FullHashList(HashListType HList)
/* �������:    ��� ���� HList.
   ����������: ������� �� � ����� List ��� ����� HList ����� ������.
   ����������: TRUE �� � ����� List ����� ������, FALSE �����������.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ���� �������� ���������.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ��� ������������
                �������� ���� ��������
*/
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (strcmp(HList.List[Next].RecKey,KeyArg) == 0)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ��� ���� HList.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ���
                ������������ �������� ��� ��������� ���� ����� ������.
                �� ��� ������� ������� �� ������ KeyArg ���� Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* �������:    ��� ���� HList ��� ��� ������� InRec.
   ����������: ������� ��� ������� InRec ��� ����� List, �� ��� ����� ������,
                ��� ���������� �� ���� HList.
   ����������: ��� ������������� ���� HList.
   ������:     ������ ������� ������, �� � List ����� ������, �����������,
                �� ������� ��� ������� �� �� ���� ������,
                �������� ����������� ���������
*/
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %s \n",DelKey);
	}
}


