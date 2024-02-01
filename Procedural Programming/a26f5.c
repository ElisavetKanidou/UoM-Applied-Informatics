#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    int code;
    int recNo;
}BinTreeElementType;

typedef struct
{
   int code;
    char name[20];
    char epitheto[20];
    char fylo;
    int year;
    float bathmos;
}StudentT;


typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);

int BuildBST(BinTreePointer *Root);
void writeNewStudents(BinTreePointer *Root, int *size);
void printStudentsWithGrade(float theGrade);
void PrintStudent(int recNum);



int main()
{
    BinTreePointer ARoot, LocPtr;
    boolean found;
    float theGrade;
    int size;
    StudentT student;

    printf("Q1. Build BST from a file\n");
    size=BuildBST(&ARoot);
    printf("Q2. Print size and BST\n");
    printf("Size=%d\n", size);
    printf("Nodes of BST\n");
    RecBSTInorder(ARoot);
    printf("\n");
    printf("Q3. Write new students, update file and BST\n");
    writeNewStudents(&ARoot, &size);

    printf("Q4. Print size and BST\n");
    printf("Size=%d\n", size);
    printf("Nodes of BST\n");
    RecBSTInorder(ARoot);
    printf("\n");
    printf("Q5. Search for a student\n");
    printf("Give student's code? ");
    scanf("%d", &LocPtr->Data.code);
    RecBSTSearch(ARoot, LocPtr->Data, &found, &LocPtr);
    if(found)
        PrintStudent(LocPtr->Data.recNo);
    else
        printf("Student with AM %d wasn't found", LocPtr->Data.recNo);

    printf("Q6. Print size and BST\n");
    printf("Size=%d\n", size);
    printf("\nNodes of BST\n");
    RecBSTInorder(ARoot);
    printf("\nQ7. Print students with grades>=given grade\n");
    printf("Give the grade: ");
    scanf("%f", &theGrade);
    printStudentsWithGrade(theGrade);

    return 0;
}
int BuildBST(BinTreePointer *Root)
{
    FILE *fp;
    int   nscan;
    char  termch;
    StudentT  student;
    BinTreeElementType indexRec;
    int size;

    CreateBST(Root);
    fp=fopen("foitites.dat", "r");
    size=0;
    if (fp == NULL)
    {
        printf("Can't open the file\n");
    }
    else
    {
        while(TRUE)
        {
            nscan=fscanf(fp, "%d, %20[^,], %20[^,], %c, %d, %f%c", &student.code, student.name, student.epitheto, &student.fylo, &student.year, &student.bathmos, &termch);
            if(nscan==EOF) break;
            if(nscan!=7 || termch!='\n')
                printf("Error\n");
            else
            {
                indexRec.code=student.code;
                indexRec.recNo=size;
                RecBSTInsert(&(*Root), indexRec);
                size++;
            }
        }
    }

    fclose(fp);
    return size;
}

void writeNewStudents(BinTreePointer *Root, int *size)
{
    FILE *fp;
    StudentT student;
    BinTreeElementType indexRec;
    boolean found;
    BinTreePointer LocPtr;
    char ch;

    fp=fopen("foitites.dat", "a");
    if (fp!=NULL)
    { do
        {
           printf("Give student's AM? ");
           scanf("%d",indexRec.code); getchar();
        RecBSTSearch(*Root,indexRec,&found,&LocPtr);
          if (!found)
          {
              student.bathmos=indexRec.code;
              printf("Give student surname? ");
              scanf("%s",student.epitheto); getchar();
              printf("Give student name?");
              scanf("%s",student.name); getchar();
              printf("Give student sex F/M?");
              scanf("%c",&student.fylo);
              printf("Give student's registration year?");
              scanf("%d",&student.year); getchar();
              printf("Give student's grade?");
              scanf("%f",&student.bathmos); getchar();

               indexRec.code = student.code;
               indexRec.recNo = *size;
               RecBSTInsert(Root, indexRec);

              fprintf(fp,"%d,%s,%s,%c,%d,%.1f\n",student.code,student.name, student.epitheto,student.fylo,student.year,student.bathmos);
              (*size)++;
              printf("Size=%d",*size);
          }
          else
          {
             printf("Student with AM %d already exists\n", indexRec.code);
          }
           printf("Continue Y/N:");
           do
           {
               scanf("%c",&ch);
           } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');

        } while (toupper(ch)!= 'N');
        fclose(fp);
    }
}

void PrintStudent(int recNum)
{
    FILE *fp;
    int nscan;
    char termch;
    StudentT student;
    int lines;

    fp=fopen("foitites.dat", "r");
    lines=0;
    if(fp!=NULL)
    {
        while(lines<=recNum)
        {
            nscan=fscanf(fp, "%d, %20[^,], %20[^,], %c, %d, %f%c", &student.code, student.name, student.epitheto, &student.fylo, &student.year, &student.bathmos, &termch);
            if(nscan==EOF) break;
            if(nscan!=7 || termch!='\n')
                printf("Error\n");
            lines++;
        }
        if(lines==recNum+1)
            printf("%d,%s,%s,%c,%d,%.1f\n", student.code, student.name, student.epitheto, student.fylo, student.year, student.bathmos);
    }
    fclose(fp);
}


void printStudentsWithGrade(float theGrade)
{
    FILE *fp;
    int nscan;
    char termch;
    StudentT student;

    fp=fopen("foitites.dat", "r");
    if(fp!=NULL)
    {
        while(TRUE)
        {
            nscan=fscanf(fp, "%d, %20[^,], %20[^,], %c, %d, %f%c", &student.code, student.name, student.epitheto, &student.fylo, &student.year, &student.bathmos, &termch);
            if(nscan==EOF) break;
            if(nscan!=7 || termch!='\n')
                printf("Error\n");
            else if(student.bathmos>=theGrade)
                printf("%d,%s,%s,%c,%d,%.1f\n", student.code, student.name, student.epitheto, student.fylo, student.year, student.bathmos);
        }
    }

    fclose(fp);
}


void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{
    return (Root==NULL);
}


void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item.code < (*Root)->Data.code)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item.code > (*Root) ->Data.code)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr)
{
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (KeyValue.code < Root->Data.code)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue.code > Root->Data.code)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
{

   BinTreePointer TempPtr;

    if (BSTEmpty(*Root))
        printf("TO STOIXEIO DEN BRE8HKE STO DDA\n");
     else
          if (KeyValue.code < (*Root)->Data.code)
             RecBSTDelete(&((*Root)->LChild), KeyValue);
          else
            if (KeyValue.code > (*Root)->Data.code)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);
            else
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;
                        free(TempPtr);
                   }
                   else
                   {
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
{
    if (Root!=NULL)
    {
        RecBSTInorder(Root->LChild);
        printf("(%d, %d),",Root->Data.code,Root->Data.recNo);
        RecBSTInorder(Root->RChild);
    }
}

void RecBSTPreorder(BinTreePointer Root)
{
    if (Root!=NULL)
    {
        printf("%d ",Root->Data.code);
        RecBSTPreorder(Root->LChild);
        RecBSTPreorder(Root->RChild);
    }
}

void RecBSTPostorder(BinTreePointer Root)
{
    if (Root!=NULL)
    {
        RecBSTPostorder(Root->LChild);
        RecBSTPostorder(Root->RChild);
        printf("%d ",Root->Data.code);
    }
}







