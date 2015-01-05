#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Utilites.h"




void alert(char *message, bool sortir) {
    
    // Affichage du message d'erreure
    puts("\n****************************************************");
    puts(message);
    if( sortir )
        puts("** Termination Du Programme... ** ");
    puts("****************************************************");
    
    // Sortir du programme
    if( sortir )
        exit(EXIT_FAILURE);
}



bool isOperand(char ch){
    bool isOperand = false;
    switch( ch ) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            isOperand = true; break;
        default: isOperand = false;
    }
    
    return isOperand;
}




bool isOperator(char ch) {
    
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
        return true;
    else
        return false;
    
}



void removeChars(char  *str, char c) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
        pw += (*pw != c);
    }
    *pw = '\0';
}


bool isValid(char *expr){
    char *p = &expr[0];
    int o = 0, c = 0;
    
    if( *p == ')' )
        return false;
    else if ( isOperator(*p) )
        return false;
    
    while( *p != '\0' ) {
        
        if( *p == '(' ) o++; // Opening Parenthesis
        if( *p == ')' ) c++; // Closing Parenthesis
        
        if( *p == '(' && *(p+1) == ')' )
            return false;
        
        if( isOperator(*p) && isOperator(*(p+1)) )
            return false;
        
        p++;
    }
    
    if( o != c ) // If Opening/Closing Parenthesis Number does not match, it's invalid!
        return false;
    
    return true;
}
