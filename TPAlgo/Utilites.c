#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "Validation.h"
#include "StackManager.h"




int charToInt(char ch) {
    return (int)(ch - '0');
}




int Priority(char ch) {
    
    if( ch == '*' || ch == '/' || ch =='%' )
        
        return 2;
    
    else {
        
        if(ch == '+' || ch == '-')
            return 1;
        
    }
    
    return 0;
}




int doOperation(int x, int y, char op) {
    if( ! isOperator(op) )
        alert("Le 3eme argument doit etre l'un des ( / * % + - ). Autre donné", true);
    
    if( op == '/' && y == 0 )
        alert("Divitsion Par Zero! Non Autorise!", true);
    
    switch(op) {
        case '*': return ( x * y ); break;
        case '/': return ( x / y ); break;
        case '%': return ( x % y ); break;
        case '+': return ( x + y ); break;
        case '-': return ( x - y ); break;
            
        default: return 0; break;
    }
}




void InfixToPostfix(char *expr, char *postfixed) {
    
    char *idx = NULL, *post = NULL;
    Stack *P;
    char tmp;
    
    InitStack(&P);
    
    idx = expr;
    post = postfixed;
    
    while( *idx != '\0' )
    {
        
        while(*idx == ' ' || *idx == '\t')
        {
            idx++;
        }
        
        if( isdigit(*idx) || isalpha(*idx)  )
        {
            while( isdigit(*idx) || isalpha(*idx)  )
            {
                *post = *idx;
                post++;
                idx++;
            }
            
            // Adding spaces...
            *post = ' ';
            post++;
            
        }
        
        if( *idx == '(' )
        {
            PushStack(&P, *idx);
            idx++;
            
        }
        
        if( *idx == ')')
            
        {
            PopStack(&P, &tmp);
            while( tmp != '(' )
            {
                *post = tmp;
                post++;
                *post = ' ';
                post++;
                PopStack(&P, &tmp);
            }
            idx++;
        }
        
        
        if( isOperator(*idx) )
        {
            if( EmptyStack(P) )
                PushStack(&P, *idx);
            else {
                PopStack(&P, &tmp);
                while( Priority(tmp) >= Priority(*idx) )
                {
                    *post = tmp;
                    post++;
                    
                    *post = ' ';
                    post++;
                    
                    PopStack(&P, &tmp);
                }
                
                PushStack(&P, tmp);
                PushStack(&P, *idx);
                
            }
            
            idx++;
            
        }
    }
    
    while( !EmptyStack(P) )
    {
        PopStack(&P, &tmp);
        *post = tmp;
        post++;
        *post = ' '; // Adding spaces...
        post++;
    }
    
    *post = '\0'; // Terminate The String:
}




int EvalWithStacks(char *expr) {
    int result = 0;
    char *p, *i;
    IntStack *S;
    int op1, op2;
    int operand = 0,
    coef = 1;
    
    InitIntStack(&S);
    p = &expr[0];
    
    while( *(p+1) != '\0')
    {
        while(*p == ' ' || *p == '\t'){ // Ignore any Tabs Or Spaces...
            p++;
        }
        
        if(isdigit(*p)) {
            i = p;
            while( *i != ' ' ) i++;
            
            p = i;
            i--;
            
            while( *i ){
                operand += ( charToInt(*i) * coef );
                coef = coef * 10;
                if( *(i-1) == ' ' )
                    break;
                else
                    i--;
            }
            // Push To Stack
            PushIntStack(&S, operand);
            // Reset
            operand = 0;
            coef = 1;
        } else {
            op2 = PopIntStack(&S);
            op1 = PopIntStack(&S);
            result = doOperation(op1, op2, *p);
            PushIntStack(&S, result);
        }
        
        p++;
    }
    
    result = PopIntStack(&S);
    return result;
}
