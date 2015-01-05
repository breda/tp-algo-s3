#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Validation.h"
#include "Utilites.h"
#include "StackManager.h"




void InitStack(Stack **Head) {
    *Head = NULL;
}

void InitIntStack(IntStack **Head) {
    *Head = NULL;
}





void PrintStack(Stack *Head){
    Stack *tmp = NULL;
    int counter = 1;
    
    if( ! EmptyStack(Head) ) {
        
        tmp = Head;
        
        while( tmp != NULL ) {
            
            printf("Stack Node Number %d Has: %c \n", counter++, tmp->Data);
            
            tmp = tmp->Next;
        }
        
    } else {
        alert("The Given Stack Is Empty!", false);
        return;
    }
}

void PrintIntStack(IntStack *Head){
    IntStack *tmp = NULL;
    int counter = 1;
    
    if( ! EmptyIntStack(Head) ) {
        
        tmp = Head;
        
        while( tmp != NULL ) {
            
            printf("Stack Node Number %d Has: %d \n", counter++, tmp->Data);
            
            tmp = tmp->Next;
        }
        
    } else {
        alert("The Given Stack Is Empty!", false);
        return;
    }
}





bool EmptyStack(Stack *Head) {
    if( Head == NULL )
        return true;
    else
        return false;
}

bool EmptyIntStack(IntStack *Head) {
    if( Head == NULL )
        return true;
    else
        return false;
}





char StackHead(Stack *Head) {
    return (char)(Head->Data);
}

int IntStackHead(IntStack *Head) {
    return (int)(Head->Data);
}




void PopStack(Stack **Head, char *data){
    Stack *tmp = *Head;
    
    if( !EmptyStack(*Head) ) {
        
        
        *data = (*Head)->Data;
        (*Head) = (*Head)->Next;
        free(tmp);
        tmp = NULL;
        
    } else {
        alert("La Pile Est Vide", true);
    }
}

int PopIntStack(IntStack **Head){
    IntStack *tmp = *Head;
    int data = 0;
    
    if( !EmptyIntStack(*Head) ) {
        data = (*Head)->Data;
        (*Head) = (*Head)->Next;
        free(tmp);
        tmp = NULL;
        
    } else {
        alert("La Pile Est Vide", true);
    }
    
    return data;
}




void PushStack(Stack **Head, const char data) {
    Stack *Node = NULL;
    
    Node = (Stack *)malloc(sizeof(Stack));
    if( Node != NULL ) {
        
        Node->Data = data;
        Node->Next = *Head;
        *Head = Node;
        
    } else {
        alert("Out Of Memory!", true);
    }
    
}

void PushIntStack(IntStack **Head, const int data) {
    IntStack *Node = NULL;
    
    Node = (IntStack *)malloc(sizeof(IntStack));
    if( Node != NULL ) {
        
        Node->Data = data;
        Node->Next = *Head;
        *Head = Node;
        
    } else {
        alert("Out Of Memory!", true);
    }
    
}
