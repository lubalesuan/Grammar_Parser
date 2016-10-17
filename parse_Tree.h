/*
Your parser should read successive expressions from standard input, construct
a parse tree for the expression if it is well-formed, and then print that
parse tree to standard output (see description below).
 If the input is not well-formed, your parser should print an appropriate message
and resume processing at the next line of input (i.e., skip to the next
newline).
 You may assume that expressions are on a single line of input if you want, or
deal with multi-line input.
 Your program should exit on end-of-file on standard input.
*/
#ifndef _parse_Tree_h
#include <stdio.h> 
#include <stdlib.h>

typedef struct PTree *PTree;
extern PTree makeNode1  (char c, PTree t);
extern PTree makeNode0 (char c);
extern PTree makeNode2 (char c, PTree t1, PTree t2);
extern PTree makeNode3 (char c, PTree t1, PTree t2, PTree t3);
#endif 