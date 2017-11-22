
//include nextinputchar as a parameter? so that you didnt have to increment the pointer for real
///should I nest if statements?
#include <stdio.h> 
#include "parse_Tree.h"
#include <string>


 struct PTree {
	PTree leftChild, rightSib;
	char label;
};



PTree makeNode1  (char c, PTree t) {
 PTree root;
 root = makeNode0(c);
 root->leftChild = t;
 return root;
}

//make root
PTree makeNode0 (char c) {
 PTree root;
 root = (PTree)malloc(sizeof(struct PTree));
 root->label = c;
 root->leftChild = NULL;
 root->rightSib = NULL;
 return root;
}

PTree makeNode2 (char c, PTree t1, PTree t2) {
PTree root;

root = makeNode1(c,t1);
t1->rightSib = t2;
return root;
}
 
PTree makeNode3 (char c, PTree t1, PTree t2, PTree t3) {
PTree root;

root = makeNode1(c,t1);
t1->rightSib = t2;
t2->rightSib = t3;
return root;
}
