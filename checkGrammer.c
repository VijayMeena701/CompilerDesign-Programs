#include<stdio.h>
#include<string.h>

#define SIZE 10

int checkRightRec(int i);
int checkLeft(int i);
int checkGen(int i);

char production[10][SIZE];

int main () {
    int num;
    printf("Enter Number of Production : ");
    scanf("%d",&num);
    printf("Enter the grammar as E=>E-A :\n");
    for(int i=0;i<num;i++){
        scanf("%s",production[i]);
    }
    for(int i=0;i<num;i++){
        printf("\n\tGRAMMAR : %s",production[i]);
        int checkright = checkRightRec(i);
        int checkleft = checkLeft(i);
        int gen =checkGen(i);
        if((checkleft == 1) && (checkright == 1)){
            printf(" is Ambigious Grammer\n");
        }
        else if(checkright == 1){
            printf(" is Right Recursive\n");
        }
        else if(checkleft == 1){
            printf(" is Left Recursive\n");
        }
        else if(gen == 1){
            printf(" is General Recursive\n");
        }
        else {
            printf(" is non-recursive Grammer\n");
        }
    }
}
int checkLeft(int i){
    int non_terminal = production[i][0];
    int flag = 0;
    if(non_terminal == production[i][3]){
        flag= 1;
    }
    return flag;
}

int checkRightRec(int i){
    int flag =0;
    int len = strlen(production[i]);
    char non_terminal= production[i][0];
    char checkSlash = '|';
    for(int j = len; j >= 3 ; j--){
        if(non_terminal == production[i][len-1]){
            flag = 1;
            break;
        }
        else if(checkSlash == production[i][j]){
            if(non_terminal == production[i][j-1]){
                flag=1;
                break;
            }
        }
    }
    return flag;
}
int checkGen(int i){
    int flag =0;
    int len = strlen(production[i]);
    char non_terminal= production[i][0];
    for(int j = len; j >= 3 ; j--){
        if(non_terminal == production[i][j]){
            flag = 1;
            break;
        }
    }
    return flag;
}