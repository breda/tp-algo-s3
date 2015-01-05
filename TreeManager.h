//
//  TreeManager.h
//  TPAlgo
//
//  Created by Reda Bouchaala on 12/28/14.
//  Copyright (c) 2014 Bouchaala.Djelouah. All rights reserved.
//

#ifndef __TPAlgo__TreeManager__
#define __TPAlgo__TreeManager__

#include <stdio.h>
#include <stdbool.h>

typedef struct TreeNode {
    
    char Data;
    struct TreeNode *LeftChild, *RightChild;
    
} *Tree, Node;


Tree *InitEmptyTree();

Tree *CreateNode(char);

bool isLeave(Node *);

Node *CreateLeftNode(Node *, char);

Node *CreateRightNode(Node *, char);

void PrintTree(Node *, char []);

#endif /* defined(__TPAlgo__TreeManager__) */
