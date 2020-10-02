#include "Parser.h"
int i;
int flag = 0;

_Bool parser(struct lexics *someLexics, int numberOfLexics) {
    for (i = 0; i < numberOfLexics; i++) {
        function(someLexics);
        if (flag = 1) return FALSE;
    }
}
void function(struct lexics *aLex) {
    header(aLex);
  //  body(aLex);
}
void header(struct lexics *aLex) {
    if (i = 0) {
        if (aLex[i].token == VARTYPE);
        else flag = 1;
    }
    if (i = 1) {
        if (aLex[i].token == IDENTIFIER);
        else flag = 1;
    }
    if (i = 2) {
        if (aLex[i].token == LEFT_PARENTHESIS);
        else flag = 1;
    }
    if (i > 2) {
        argDec(aLex);
    }
}
void argDec(struct lexics *aLex) {
    //arg-decl
}
void body(struct lexics *aLex) {
    
} 
void statementList(struct lexics *aLex) {

}
void statement(struct lexics *aLex) {

}
void whileLoop(struct lexics *aLex) {

}
void returnStatement(struct lexics *aLex) {

}
void assignment(struct lexics *aLex) {

}
void expression(struct lexics *aLex) {

}
void term(struct lexics *aLex) {

}