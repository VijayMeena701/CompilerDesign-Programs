#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 10

char production[10][MAXSIZE];

int main(){
    int i = 1;
    printf("Program works only if given grammer is left recursive \n");
    printf("Enter the grammar as E=>E-A :\n");
    scanf("%s",production[i]);
    char non_terminal = production[i][0];
    int len = strlen(production[i]);
    char last_char = production[i][len-1];
    fflush(stdout);
    
    printf("%c => %c%c'",non_terminal,last_char,non_terminal);
    fflush(stdin);
    char middle_part[10];
    strcpy(middle_part,production[i]);
    for(int k = 0; k<len; k++){
        middle_part[k]=middle_part[k+3];
    }
    printf("\n");
    fflush(stdin);
    printf("%c' => %s%c'|#\n",non_terminal,middle_part,non_terminal);

}