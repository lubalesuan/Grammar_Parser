#include <stdio.h> 
#include "parse_Tree.h"
#include "arithm_Exp.h"

char *nextInputChar;
char *term;
PTree tree;

void arithmExp_new (char *argv) {
term = termDigit();
nextInputChar = argv;
exec();
}

PTree exec () {
	term = termDigit();
	printf("%s",nextInputChar);
	if (*nextInputChar == '(') {
		tree  = F();
	} else {
     for (int i = 1; i <sizeof(term); i++) {
    	printf("%d",i);
    }
    //call E()
		tree = E();
    if (tree == FAILED) {
	    //call T()
	   //  tree = T();
    //   if (tree == FAILED) {
  	 //    //call N()
  	 //    tree = N();
    //     if (tree == FAILED) {
    // 	    //Call D()
    // 	    tree = D();
    //       if (tree == FAILED) {
    //         return FAILED;
    //       }
    //    } else {
    //     return tree;
    //    }
    //   } else {
    //     return tree;
    //   }
    // } else {
    //   return tree;
    // }
	}
}
  return FAILED;
}


  // <E> -> <T><K>
  //multiplication and division production 
PTree E() {
	PTree t, k;
	t = T();
  if (t != FAILED) {
  	k = K();
  	if (k != FAILED) {
  		return makeNode2('E',t,k);//TODO makeNode2
  	} else {
  		return FAILED;
  	}
  } else {
  	return FAILED;
  }
}



//<K> -> +<T><K> | -<T><K> | e
  //improve this method
PTree K () {
   PTree t,k;
   if (*nextInputChar == '+') {
   	 t = T();
   	if (t != FAILED) {
   		k = K();
   		if (k != FAILED) {
   			return makeNode3('K',makeNode0('+'),t,k);
   		} else {
   			return FAILED;
   		} 
   	} else {
   			return FAILED;
   		}	
   } else if (*nextInputChar == '-') {
   	 t = T();
   	if (t != FAILED) {
   		k = K();
   		if (k != FAILED) {
   			return makeNode3('K',makeNode0('-'),t,k);
   		} else {
   			return FAILED;
   		} 
   	} else {
   			return FAILED;
   		}
   } else {
   	  return makeNode1 ('K',makeNode0('e'));
   }
}

//<T> -> <F><M>
PTree T () {
 PTree f,m;
 f =  F();
 if (f != FAILED) {
 	m =  M();
 	if (m!= FAILED){
 		return makeNode2('T',f,m);
 	} else {
 		return FAILED;
 	}
 } else {
  return FAILED;
 }
}

//<M> -> *<F><M> | /<F><M> | e
PTree M() {
	PTree f,m;
   if (*nextInputChar == '*') {
    f = F();
    if (f != FAILED) {
    	m = M();
    	if (m!=FAILED) {
    		return makeNode3('M',makeNode0('*'),f,m);
    	} else {
        return FAILED;
      }
    } else {
      return FAILED;
    }
   } else if (*nextInputChar == '/') {
     f = F();
    if (f != FAILED) {
    	m = M();
    	if (m!=FAILED) {
    		return makeNode3('M',makeNode0('/'),f,m);
    	} else {
        return FAILED;
      }
    } else {
      return FAILED;
    }
   } else {
   	return makeNode1('M',makeNode0('e')); //TODO check here
   }
  }


//<F> -> (<E>) | <N>
PTree F() {
	PTree e,n;
 if (*nextInputChar == '(') {
   e=E();
   if (e != FAILED) {
   	 if (*nextInputChar == ')') {
   	 	return makeNode3('F',makeNode0('('),e,makeNode0(')'));
   	 } else {
   	 	return FAILED;
   	 }
   } else {
   	return FAILED;
   }
 } else {
   n = N();
   if (n != FAILED) {
    return makeNode1('N',n);
   } else {
   	return FAILED;
   }
 }
}

//<N> -> <D><X>
PTree N() {
 PTree d,x;
 d = D();
 if (d != FAILED) {
 	x = X();
 	if (x != FAILED) {
 		return makeNode2 ('N',d,x);
 	} else {
 		return FAILED;
 	}
 } else {
 	return FAILED;
 }
}

//<X> -> <N> | e
PTree X() {
 PTree n;
 n = N();
 if (n!= FAILED) {
  return makeNode1('X',n);
 } else {
  return makeNode1('X',makeNode0('e'));
 }
}

// char is Digit from 0 to 9
PTree D () {
	for (int i = 1; i < sizeof(term); i++) {
		if (*nextInputChar == term [i]) {
			return makeNode1 ('D',makeNode0(term[i])); //TODO
		}
	}
	return FAILED;
}

////array of terminals with which productinos start
char* termDigit () {
term = malloc(sizeof(char)*11); 
int count = 0;
term[0] = '('; 
for (int i = 1; i < sizeof(term); i++) { //
   term[i]= count;
   count++;
}
return term;

}

int matchTerminal(char c) {
 if (*nextInputChar == c) {
 nextInputChar++;
 return 1;
 } else {
 return 0;
 }
}

int lookahed (char c) {
 return *nextInputChar == c;
} 



