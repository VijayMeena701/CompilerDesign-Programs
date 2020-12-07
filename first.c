#include<stdio.h> 
#include<ctype.h> 
#include<string.h>

void findfirst(char, int, int);

/* Global Variables */
int count, n = 0;
char storeFirstArr[10][100]; // Stores the final result of the First Sets
char production[10][10]; // Stores the production rules 
char first[10];


void findfirst(char c, int q1, int q2){
	// The case where we encounter a Terminal
	if(!(isupper(c))) {
		first[n++] = c;
	}
	for(int j = 0; j < count; j++){
		if(production[j][0] == c){
			if(production[j][2] == '#'){
				if(production[q1][q2] == '\0')
					first[n++] = '#';
				else if(production[q1][q2] != '\0' && (q1 != 0 || q2 != 0)){
					// Recursion to calculate First of New Non-Terminal we encounter after epsilon 
					findfirst(production[q1][q2], q1, (q2+1));
				}
				else
					first[n++] = '#';
			}
			else if(!isupper(production[j][2])){
				first[n++] = production[j][2];
			}
			else{
				// Recursion to calculate First of New Non-Terminal we encounter at the beginning
				findfirst(production[j][2], j, 3);
			}
		}
	}
}

int main(){
	int jm = 0; 
	char c, input[10];
    printf("-----------------------------------------------\n");
    printf("-----------------------------------------------\n\n");
    printf("\n ===C PROGRAM TO FIND FIRST OF ALL NON-TERMINALS IN A GRAMMER=== \n");
    printf("\n\tEnter the Grammer: \n");
    printf("\tThe escape sequence to terminate entering grammer is => 'done' \n");
    fflush(stdin);
    fflush(stdout);
    for(int i = 0; i<10; i++){
        scanf("%s",input);
        if(strcmp(input,"done")==0){
            break;
        }
        else {
            strcpy(production[i], input);
            count = i+1;
        }
    }
	int kay; 
	char completedArr[count]; 
	int ptr = -1; 
	
	// Initializing the storeFirstArr array 
	for(int k = 0; k < count; k++) { 
		for(kay = 0; kay < 100; kay++) { 
			storeFirstArr[k][kay] = '!'; 
		} 
	} 
	int point1 = 0, point2, arbit; 
	
	for(int k = 0; k < count; k++) 
	{ 
		c = production[k][0]; 
		point2 = 0; 
		arbit = 0; 
		
		// Checking if First of c has already been calculated 
		for(kay = 0; kay <= ptr; kay++) 
			if(c == completedArr[kay]) 
				arbit = 1; 
				
		if (arbit == 1) 
			continue; 

		findfirst(c, 0, 0); 
		ptr += 1; 
		printf("\n");
		// Add c after done to the calculated list
		completedArr[ptr] = c;
		printf("\n First(%c) => { ", c);
		storeFirstArr[point1][point2++] = c;

		for(int i = 0 + jm; i < n; i++) {
			int tempL = 0, chk = 0;
			for(tempL = 0; tempL < point2; tempL++) {
				if (first[i] == storeFirstArr[point1][tempL]){
					chk = 1;
					break;
				}
			}
			if(chk == 0){
				printf("%c, ", first[i]);
				storeFirstArr[point1][point2++] = first[i];
			}
		}
		printf("}\n");
		jm = n;
		point1++;
	}
	printf("\n");
	printf("-----------------------------------------------\n");
    printf("-----------------------------------------------\n\n");
}