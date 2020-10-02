
#include "Tokenizer.h"

_Bool isDigit(char *buf, int pos) {
    if (buf[pos] == 1 || buf[pos] == 2 || buf[pos] == 3 || buf[pos] == 4 || buf[pos] == 5 || buf[pos] == 6 || buf[pos] == 7 || buf[pos] == 8 || buf[pos] == 9 || buf[pos] == 0) return TRUE;
    else return FALSE;
}
_Bool isAlpha(char *buf, int pos) {
    if ((buf[pos] >= 65 && buf[pos] <= 90) || (buf[pos] <= 97 && buf[pos] >= 122)) return TRUE;
    else return FALSE;
}
_Bool tokenizer(struct lexics *aLex, int *numLex, FILE *inf) {

     int pos = 0;
     int lexPos = 0;
     char *buf[LEXEME_MAX];
    
     while (fgets(buf, LEXEME_MAX, inf) != NULL) {

        if ((buf[pos]) == '{') {
            aLex[lexPos].token = LEFT_BRACKET; 
            *aLex[lexPos].lexeme = '{';
            pos++;
        }
        else if ((buf[pos]) == '}') {
            *aLex[lexPos].lexeme = '{';
            aLex[lexPos].token = RIGHT_BRACKET;
            pos++;
        }
        else if ((buf[pos]) == '(') { 
            *aLex[lexPos].lexeme = '(';
            aLex[lexPos].token = LEFT_PARENTHESIS;
            pos++;
        }
        else if ((buf[pos]) == ')') { 
            *aLex[lexPos].lexeme = ')';
            aLex[lexPos].token = RIGHT_PARENTHESIS;
            pos++;
        }
        else if (isAlpha(*buf, pos)) {
            if ((buf[pos]) == 'w' && (buf[pos + 1]) == 'h' &&  (buf[pos + 2]) == 'i' &&  (buf[pos + 3]) == 'l' &&  (buf[pos + 4]) == 'e') {
                *aLex[lexPos].lexeme = "while";
                aLex[lexPos].token = WHILE_KEYWORD;
                pos =+ 5;
            }
            else if ((buf[pos]) == 'r' &&  (buf[pos + 1]) == 'e' &&  (buf[pos + 2]) == 't' &&  (buf[pos + 3]) == 'u' &&  (buf[pos + 4]) == 'r' &&  (buf[pos + 5]) == 'n') {
                *aLex[lexPos].lexeme = "return"; 
                aLex[lexPos].token = RETURN_KEYWORD;
                pos =+ 6;
            }
            else if (((buf[pos]) == 'i' &&  (buf[pos + 1]) == 'n' &&  (buf[pos + 2]) == 't') || ((buf[pos]) == 'v' &&  (buf[pos + 1]) == 'o' &&  (buf[pos + 2]) == 'i' &&  (buf[pos + 3]) == 'd')) {
                aLex[lexPos].token = VARTYPE;
                if ((buf[pos]) == 'v') {
                    *aLex[lexPos].lexeme = "void";
                    pos =+ 4;
                }
                else { 
                    *aLex[lexPos].lexeme = "int";
                    pos =+ 3;
                }
            }
            else {
                int trackPos = pos;
                while(isAlpha(*buf, pos) || (isDigit(*buf, pos))) {
                    trackPos++;
                }
                int strSize = trackPos - pos;
                char* buildStr = malloc(strSize * sizeof(char));
                for (int i = pos; i < trackPos; i++) {
                     buildStr[i] = buf[i];
                }
                aLex[lexPos].token = IDENTIFIER;
                *aLex[lexPos].lexeme = buildStr;
                pos = trackPos;
            }
        }
        else if (isDigit(*buf, pos)) { 
            int trackPos = pos;
            while (isDigit(*buf, pos)) trackPos++;
            if (isAlpha(*buf, trackPos)) {
                trackPos++;
                int strSize = trackPos - pos;
                char* buildStr = malloc(strSize * sizeof(char));
                for (int i = pos; i < trackPos; i++) {
                     buildStr[i] = buf[i];
                }
                aLex[lexPos].token = IDENTIFIER;
                *aLex[lexPos].lexeme = buildStr;
                pos = trackPos;
            }
            else {
                int strSize = trackPos - pos;   
                char* buildStr = malloc(strSize * sizeof(char));
                for (int i = lexPos; i < trackPos; i++) {
                     buildStr[i] = buf[i];
                }
                aLex[lexPos].token = NUMBER;
                *aLex[lexPos].lexeme = buildStr;
                pos = trackPos;
            }
        }
        else if ((buf[pos]) == '+' || (buf[pos]) == '*' || (buf[pos]) == '=' || (buf[pos]) == '!' || (buf[pos]) == '%') {
            if ((pos == '=')) {    
                if ((buf[pos + 1]) == '=') {
                    *aLex[lexPos].lexeme = "==";
                    aLex[lexPos].token = BINOP;
                    pos =+ 2;
                }
                else {
                    *aLex[lexPos].lexeme = '='; 
                    aLex[lexPos].token == EQUAL;
                    pos++;
                }
            }
            else {
                if ((buf[pos]) == '!' && (buf[pos + 1]) == '=') {
                    *aLex[lexPos].lexeme = "!=";
                    aLex[lexPos].token = BINOP;
                    pos =+ 2;
                }
                else { 
                *aLex[lexPos].lexeme = (buf[pos]); 
                aLex[lexPos].token = BINOP;
                pos++;
                }            
            }
        } 
        else if ((buf[pos]) == ',') { 
            *aLex[lexPos].lexeme = ','; 
            aLex[lexPos].token = COMMA;
            pos++;
        }
        else if ((buf[pos]) == ';') {
            *aLex[lexPos].lexeme = ';';
            aLex[lexPos].token = EOL;
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