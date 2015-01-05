#ifndef STACKMANAGER_H_INCLUDED
#define STACKMANAGER_H_INCLUDED


/* ############# Pile Defenitions ############# */
typedef struct eltChar {
    char Data;
    struct eltChar *Next;
} Stack;

typedef struct eltInt {
    int Data;
    struct eltInt *Next;
} IntStack;


/*
 * @nom: InitPile
 * @param: Pile **Sommet( Le sommet de la pile a intialiser )
 * @desc: intialiser une Pile
 * @return: void
 */
void InitStack(Stack **Head);
void InitIntStack(IntStack **Head);

/*
 * @nom: InitPile
 * @param: Pile **Sommet( Le sommet de la pile a intialiser )
 * @desc: intialiser une Pile
 * @return: void
 */
void PrintStack(Stack *Head);
void PrintIntStack(IntStack *Head);


/*
 * @nom: PileVide
 * @param: Pile *Sommet( Le sommet de la pile a intialiser )
 * @desc: Verifier si une pile est vide.
 * @return: bool
 */
bool EmptyStack(Stack *Head);
bool EmptyIntStack(IntStack *Head);

/*
 * @nom: SommetPile
 * @param: Pile *Sommet( Le sommet de la pile a intialiser )
 * @desc: Retourne le Sommet de la pile
 * @return: char
 */
char StackHead(Stack *Head);
int IntStackHead(IntStack *Head);

/*
 * @nom: Depiler
 * @param: Pile **Sommet ( Le sommet de la pile a dépiler )
 * @param: char *data ( La valeur de l'element dépilé )
 * @desc: Dépiler un element de la pile
 * @return: void
 */
void PopStack(Stack **Head, char *data);
int PopIntStack(IntStack **Head);

/*
 * @nom: initPile
 * @param: Pile *Sommet( Le sommet de la pile a empiler )
 * @param: char data ( La valeur de l'element a empiler )
 * @desc: Empiler un element dans la pile
 * @return: void
 */
void PushStack(Stack **Head, const char data);
void PushIntStack(IntStack **Head, const int data);

#endif // STACKMANAGER_H_INCLUDED
