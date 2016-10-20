#include <stdio.h> 
#include <stdlib.h>
#include "parse_Tree.h"
#define FAILED NULL

extern void arithmExp_new (char *argv);
extern PTree exec();
extern PTree E();
extern PTree K ();
extern PTree T ();
extern PTree M();
extern PTree F();
extern PTree N();
extern PTree X();
extern PTree D ();
extern char* termDigit ();
extern int matchTerminal(char c);
extern int lookahead (char c);
