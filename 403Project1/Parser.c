
int i;

_Bool parser(struct lexics *someLexics, int numberOfLexics) {
    for (i = 0; i < numberOfLexics; i++) {
        function(someLexics);
    }
}
void function(struct lexics *aLex) {
    header(aLex);
    body(aLex);
}
void header(struct lexics *aLex) {
    if (i = 0) {
        if (aLex[i].token == "VARTYPE") {

        }
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