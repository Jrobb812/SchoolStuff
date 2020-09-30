
#include "Tokenizer.h"


_Bool tokenizer(struct lexics *aLex, int *numLex, FILE *inf) {

     fopen(inf, "r");
     int pos = 0;
     int lexPos = 0;
    
     while (fscanf(inf," %s", LEXEME_MAX) == 1) {

        if (charAt(pos) == '{') {
            aLex[lexPos].token = "LEFT_BRACKET"; 
            *aLex[lexPos].lexeme = '{';
            pos++;
        }
        else if (charAt(pos) == '}') {
            *aLex[lexPos].lexeme = '{';
            aLex[lexPos].token = "RIGHT_BRACKET";
            pos++;
        }
        else if (charAt(pos) == '(') { 
            *aLex[lexPos].lexeme = '(';
            aLex[lexPos].token = "LEFT_PARENTHESIS";
            pos++;
        }
        else if (charAt(pos) == ')') { 
            *aLex[lexPos].lexeme = ')';
            aLex[lexPos].token = "RIGHT_PARENTHESIS";
            pos++;
        }
        else if (isAlpha(charAt(pos))) {
            if (charAt(pos) == 'w' && charAt(pos + 1) == 'h' && charAt(pos + 2) == 'i' && charAt(pos + 3) == 'l' && charAt(pos + 4) == 'e') {
                *aLex[lexPos].lexeme = "while";
                aLex[lexPos].token = "WHILE_KEYWORD";
                pos =+ 5;
            }
            else if (charAt(pos) == 'r' && charAt(pos + 1) == 'e' && charAt(pos + 2) == 't' && charAt(pos + 3) == 'u' && charAt(pos + 4) == 'r' && charAt(pos + 5) == 'n') {
                *aLex[lexPos].lexeme = "return"; 
                aLex[lexPos].token ="RETURN_KEYWORD";
                pos =+ 6;
            }
            else if ((charAt(pos) == 'i' && charAt(pos + 1) == 'n' && charAt(pos + 2) == 't') || (charAt(pos) == 'v' && charAt(pos + 1) == 'o' && charAt(pos + 2) == 'i' && charAt(pos + 3) == 'd')) {
                aLex[lexPos].token = "VARTYPE";
                if (charAt(pos) == 'v') {
                    *aLex[lexPos].lexeme = "void";
                    pos + 4;
                }
                else { 
                    *aLex[lexPos].lexeme = "int";
                    pos + 3;
                }
            }
            else {
                int trackPos = pos;
                while((isAlpha(charAt(pos))) || (isDigit(charAt(pos)))) trackPos++;
                int strSize = trackPos - pos;
                char* buildStr = malloc(strSize * sizeof(char));
                for (int i = pos; i < trackPos; i++) {
                     buildStr[i] = charAt(i);
                }
                aLex[lexPos].token = "IDENTIFIER";
                *aLex[lexPos].lexeme = buildStr;
                pos = trackPos;
            }
        }
        else if (isDigit(charAt(pos))) { 
            int trackPos = pos;
            while (isDigit(charAt(pos))) trackPos++;
            if (isAlpha(charAt(trackPos))) {
                trackPos++;
                int strSize = trackPos - pos;
                char* buildStr = malloc(strSize * sizeof(char));
                for (int i = pos; i < trackPos; i++) {
                     buildStr[i] = charAt(i);
                }
                aLex[lexPos].token = "IDENTIFIER";
                *aLex[lexPos].lexeme = buildStr;
                pos = trackPos;
            }
            else {
                int strSize = trackPos - pos;   
                char* buildStr = malloc(strSize * sizeof(char));
                for (int i = lexPos; i < trackPos; i++) {
                     buildStr[i] = charAt(i);
                }
                aLex[lexPos].token = "NUMBER";
                *aLex[lexPos].lexeme = buildStr;
                pos = trackPos;
            }
        }
        else if (charAt(pos) == '+' || charAt(pos) == '*' || charAt(pos) == '=' || charAt(pos) == '!' || charAt(pos) == '%') {
            if (charAt(pos == '=')) {    
                if (charAt(pos + 1) == '=') {
                    *aLex[lexPos].lexeme = "==";
                    aLex[lexPos].token = "BINOP";
                    pos =+ 2;
                }
                else {
                    *aLex[lexPos].lexeme = '='; 
                    aLex[lexPos].token == "EQUAL";
                    pos++;
                }
            }
            else {
                if (charAt(pos) == '!' && charAt(pos + 1) == '=') {
                    *aLex[lexPos].lexeme = "!=";
                    aLex[lexPos].token = "BINOP";
                    pos += 2;
                }
                else { 
                *aLex[lexPos].lexeme = charAt(pos); 
                aLex[lexPos].token = "BINOP";
                pos++;
                }            
            }
        } 
        else if (charAt(pos) == ',') { 
            *aLex[lexPos].lexeme = ','; 
            aLex[lexPos].token = "COMMA";
            pos++;
        }
        else if (charAt(pos) == ';') {
            *aLex[lexPos].lexeme = ';';
            aLex[lexPos].token = "EOL";
            pos++;
        }
        else {
            pos++;
        }
        lexPos++;
     }

     *numLex = pos;

     return TRUE;
}