#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 10

char production[10][MAXSIZE];

int main(){
    int num = 0;
    printf("Enter Number of Production : ");
    scanf("%d",&num);
    printf("Program works only if given grammer is left recursive : ");
    printf("Enter the grammar as E=>E-A :\n");
    for(int i=0;i<num;i++){
        scanf("%s",production[i]);
    }
    
}