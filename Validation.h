#ifndef VALIDATION_H_INCLUDED
#define VALIDATION_H_INCLUDED

/*
 * @nom: alert
 * @param: char *message (Le message d'erreur a etre affiché)
 * @param: int sortir (Determine si on veut sortir du programme ou non)
 * @desc: Affichier un message d'erreur et/ou sortir du programme
 * @return: void
 */
void alert(char *message, int sortir);


/*
 * @nom: estOperande
 * @param: ch (L'operande à tester)
 * @desc: Determine si un caractere est un opérateur
 * @return: bool
 */
bool isOperand(char ch);


/*
 * @nom: estOperateur
 * @param: ch (Le caractere à tester)
 * @desc: Determine si un caractere est un opérateur
 * @return: bool
 */
bool isOperator(char ch);

/*
 * @nom: removeChars
 * @param: char *str ( La chaine de caracteres )
 * @param: char c ( Le caractere a enlever )
 * @desc: Suprimme toutes les ocurrences d'un caractere dans une chaine de caractere.
 * @return: void
 */
void removeChars(char *str, char c);


/*
 * @nom: isValid
 * @param: char *expression (l'expression arithmétique a tester)
 * @desc: Determine si l'expression arithmétique est valid
 * @return: bool
 */
bool isValid(char *expr);


#endif // VALIDATION_H_INCLUDED
