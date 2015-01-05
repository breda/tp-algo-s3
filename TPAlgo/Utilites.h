#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED


/*
 * @nom: charToInt
 * @param: char ch ( Le caractere a transformer )
 * @desc: transformer un caractere en un entier
 * @return: int
 */
int charToInt(char ch);



/*
 * @nom: Priority
 * @param: char ch
 * @desc: Retourner La Priorité d'un Operateur
 * @return: int
 */
int Priority(char ch);

/*
 * @nom: doOperation
 * @param: int x (Le premier opérande)
 * @param: int y (Le deuxieme opérande)
 * @param: char op ( l'opérateur )
 * @desc: Effectue l'opération (x op y) et retourne le resultat
 * @return: int
 */
int doOperation(int x, int y, char op);

/*
 * @nom: InfixToPostfix
 * @param: char *expr
 * @param: char *postfixed
 * @desc: Transformer une expression infixé en postfixé
 * @return: void
 */
void InfixToPostfix(char *expr, char *postfixed);


/*
 * @nom: EvalWithStacks
 * @param: char *expr
 * @desc: Evalue une Expression Postfixé et retourne le resultas.
 * @return: int
 */
int EvalWithStacks(char *expr);

#endif // UTILITIES_H_INCLUDED
