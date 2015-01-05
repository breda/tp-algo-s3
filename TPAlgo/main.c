/*
 @ProgrammeName: ArithmeticEvaluator
 @ProgrammeVersion: 1.0
 @ProgrammeDesciption: Receives An Arithmetic Expression, and calculates it's value.
 @ProgrammeAuthors: BOUCHAALA Reda (201300005606) & DJELOUAH Mohammed (201300005133)
 @LastModifiedAt: 4/01/2015
 */
/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Custom Libraries */
#include "Utilites.h"
#include "Validation.h"
#include "StackManager.h"


#define MAX_EXPR_SIZE 100

int main()
{
    char inExp[MAX_EXPR_SIZE],
    postExp[MAX_EXPR_SIZE];
    int result;
    
start:
    /* Get The Expression */
    puts("Entrer L'expression a Evaluer: ");
    fgets(inExp, sizeof(inExp), stdin);
    inExp[strlen(inExp) - 1] = '\0';
    removeChars(inExp, ' '); // Remove White Spaces
    
    
    /* Validate The Expression */
    if( isValid(&inExp[0]) ){
        puts("Expression Valide! \t Transformation En Forme PostFixe...");
        /* Transform To PostFix: */
        InfixToPostfix(&inExp[0], &postExp[0]);
        printf("La Form PostFixe De L'expression Est: %s \n", &postExp[0]);
        
        /* Evaluation En Utilisant Les Piles (Stacks)*/
        result = EvalWithStacks(&postExp[0]);
        printf("Le Resultat De L'expression Est: %d \n", result);
        
        puts("\n\n########################## Fin Du Programme! ##########################");
        exit(EXIT_SUCCESS);
        
    } else {
        system("cls");
        puts("L'expression Donnee Est Non Valide! Veuillez Reessayer!");
        goto start;
    }
    
    system("pause");
    return 0;
}
