#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char BinTreeElementType[20];        /*ο τύπος των στοιχείων του ΔΔΑ
                                        ενδεικτικά τύπου int */
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
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
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
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
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
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s \n",Root->Data);
        InorderTraversal(Root->RChild);
    }
}







