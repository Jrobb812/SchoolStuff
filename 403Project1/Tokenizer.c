//#include <regex.h>
#include <stdio.h>
#include "Givens.h"

_Bool tokenizer(struct lexics *aLex, int *numLex, FILE *inf) {

     fopen(inf, "r");
     int pos = 0;
    
     while (fscanf(inf," %s", LEXEME_MAX) == 1) {

        if (charAt(pos) == '{') {
            aLex[pos].token = "LEFT_BRACKET"; 
            *aLex[pos].lexeme = '{';
        }
        else if (charAt(pos) == '}') {
            *aLex[pos].lexeme = '{';
            aLex[pos].token = "RIGHT_BRACKET";
        }
        else if (charAt(pos) == '(') { 
            *aLex[pos].lexeme = '(';
            aLex[pos].token = "LEFT_PARENTHESIS";
        }
        else if (charAt(pos) == ')') { 
            *aLex[pos].lexeme = ')';
            aLex[pos].token = "RIGHT_PARENTHESIS";
        }
        else if (isAlpha(charAt(pos))) {
            if (charAt(pos) == 'w' && charAt(pos + 1) == 'h' && charAt(pos + 2) == 'i' && charAt(pos + 3) == 'l' && charAt(pos + 4) == 'e') {
                *aLex[pos].lexeme = "while";
                aLex[pos].token = "WHILE_KEYWORD";
                pos =+ 5;
            }
            else if (charAt(pos) == 'r' && charAt(pos + 1) == 'e' && charAt(pos + 2) == 't' && charAt(pos + 3) == 'u' && charAt(pos + 4) == 'r' && charAt(pos + 5) == 'n') {
                *aLex[pos].lexeme = "return"; 
                aLex[pos].token ="RETURN_KEYWORD";
                pos =+ 6;
            }
            else if ((charAt(pos) == 'i' && charAt(pos + 1) == 'n' && charAt(pos + 2) == 't') || (charAt(pos) == 'v' && charAt(pos + 1) == 'o' && charAt(pos + 2) == 'i' && charAt(pos + 3) == 'd')) {
                aLex[pos].token = "VARTYPE";
                if (charAt(pos) == 'v') {
                    pos + 4;
                    *aLex[pos].lexeme = "void";
                }
                else { 
                    pos + 3;
                    *aLex[pos].lexeme = "int";
                }
            }
            else {
                int trackPos = pos;
                while((isAlpha(charAt(pos))) || (isDigit(charAt(pos)))) trackPos++;
                int strSize = trackPos - pos;
                char* buildStr = malloc(strSize * sizeof(char));
                for (int i = 0; i < strSize; i++) {
                     buildStr[i] = charAt(i);
                }
                aLex[pos].token = "IDENTIFIER";
                *aLex[pos].lexeme = buildStr;
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
                for (int i = 0; i < strSize; i++) {
                     buildStr[i] = charAt(i);
                }
                aLex[pos].token = "IDENTIFIER";
                *aLex[pos].lexeme = buildStr;
                pos = trackPos;
            }
            else {
                int strSize = trackPos - pos;   
                char* buildStr = malloc(strSize * sizeof(char));
                for (int i = 0; i < strSize; i++) {
                     buildStr[i] = charAt(i);
                }
                aLex[pos].token = "NUMBER";
                *aLex[pos].lexeme = buildStr;
                pos = trackPos;
            }
        }
        else if (charAt(pos) == '+' || charAt(pos) == '*' || charAt(pos) == '=' || charAt(pos) == '!' || charAt(pos) == '%') {
            if (charAt(pos == '=')) {    
                if (charAt(pos + 1) == '=') {
                    *aLex[pos].lexeme = "==";
                    aLex[pos].token = "BINOP";
                    pos++;
                }
                else {
                    *aLex[pos].lexeme = '='; 
                    aLex[pos].token == "EQUAL";
                }
            }
            else {
                if (charAt(pos) == '!' && charAt(pos + 1) == '=') {
                    *aLex[pos].lexeme = "!=";
                    aLex[pos].token = "BINOP";
                    pos++;
                }
                else { 
                *aLex[pos].lexeme = charAt(pos); 
                aLex[pos].token = "BINOP";
                }            
            }
        } 
        else if (charAt(pos) == ',') { 
            *aLex[pos].lexeme = ','; 
            aLex[pos].token = "COMMA";
        }
        else if (charAt(pos) == ';') {
            *aLex[pos].lexeme = ';';
            aLex[pos].token = "EOL";
        }
        pos++;
     }

     *numLex = pos;

     return TRUE;
}