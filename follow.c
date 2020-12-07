// C program to calculate the First and 
// Follow sets of a given grammar 
#include<stdio.h> 
#include<ctype.h> 
#include<string.h> 

void followfirst(char, int, int); // Functions to calculate Follow 
void follow(char c); 

void findfirst(char, int, int); // Function to calculate First 

/* Global Variables */

int count, n = 0;
int m = 0; 
char storeFirstArr[10][100]; // Stores the final result of the First Sets
char calc_follow[10][100]; // Stores the final result of the Follow Sets 
char production[10][10]; // Stores the production rules 
char f[10], first[10]; 
char ck;

int main(){
	int jm = 0; 
	int km = 0;
	char c;
    char input[10];
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
	
	for(int k = 0; k < count; k++){
		c = production[k][0];
		point2 = 0;
		arbit = 0;
		for(kay = 0; kay <= ptr; kay++)
			if(c == completedArr[kay])
				arbit = 1;
		if (arbit == 1)
			continue;
		findfirst(c, 0, 0);
		ptr += 1;
		completedArr[ptr] = c;
		storeFirstArr[point1][point2++] = c;
		for(int i = 0 + jm; i < n; i++) {
			int lark = 0, chk = 0;
			for(lark = 0; lark < point2; lark++) {
				if (first[i] == storeFirstArr[point1][lark]){
					chk = 1;
					break;
				}
			}
			if(chk == 0){
				storeFirstArr[point1][point2++] = first[i];
			}
		}
		jm = n;
		point1++;
	}
	char doneArr[count];
	ptr = -1;
	
	// Initializing the calc_follow array
	for(int k = 0; k < count; k++) {
		for(kay = 0; kay < 100; kay++) {
			calc_follow[k][kay] = '!';
		}
	}
	point1 = 0;
	int land = 0;
	for(int e = 0; e < count; e++){
		ck = production[e][0]; 
		point2 = 0;
		arbit = 0;
		for(kay = 0; kay <= ptr; kay++)
			if(ck == doneArr[kay])
				arbit = 1;
		if (arbit == 1)
			continue;
		land += 1;
		follow(ck);
		ptr += 1;
		doneArr[ptr] = ck;
		printf(" Follow(%c) = { ", ck);
		calc_follow[point1][point2++] = ck;
		for(int i = 0 + km; i < m; i++) {
			int lark = 0, chk = 0;
			for(lark = 0; lark < point2; lark++){
				if (f[i] == calc_follow[point1][lark]){
					chk = 1;
					break;
				}
			}
			if(chk == 0){
				printf("%c, ", f[i]);
				calc_follow[point1][point2++] = f[i];
			}
		}
		printf(" }\n\n");
		km = m;
		point1++;
	}
	printf("\n");
	printf("-----------------------------------------------\n");
    printf("-----------------------------------------------\n\n");
}

void follow(char c){
	int i, j;
	
	// Adding "$" to the follow set of the start symbol 
	if(production[0][0] == c) {
		f[m++] = '$';
	}
	for(i = 0; i < 10; i++){
		for(j = 2;j < 10; j++){
			if(production[i][j] == c){
				if(production[i][j+1] != '\0'){
					// Calculate the first of the next Non-Terminal in the production 
					followfirst(production[i][j+1], i, (j+2));
				}
				
				if(production[i][j+1]=='\0' && c!=production[i][0]){
					// Calculate the follow of the Non-Terminal in the L.H.S. of the production 
					follow(production[i][0]);
				}
			}
		}
	}
}

void findfirst(char c, int q1, int q2){
	if(!(isupper(c))) { 
		first[n++] = c; 
	} 
	for(int j = 0; j < count; j++) 
	{ 
		if(production[j][0] == c) 
		{ 
			if(production[j][2] == '#') 
			{ 
				if(production[q1][q2] == '\0') 
					first[n++] = '#'; 
				else if(production[q1][q2] != '\0'
						&& (q1 != 0 || q2 != 0)){
					findfirst(production[q1][q2], q1, (q2+1));
				}
				else
					first[n++] = '#';
			}
			else if(!isupper(production[j][2])){
				first[n++] = production[j][2];
			}
			else{
				findfirst(production[j][2], j, 3);
			}
		}
	}
}

void followfirst(char c, int c1, int c2){
	
	// The case where we encounter a Terminal 
	if(!(isupper(c))) 
		f[m++] = c; 
	else{
		int i = 0, j = 1;
		for(i = 0; i < count; i++){
			if(storeFirstArr[i][0] == c)
				break;
		}
		
		//Including the First set of the Non-Terminal in the Follow of the original array
		while(storeFirstArr[i][j] != '!'){
			if(storeFirstArr[i][j] != '#'){
				f[m++] = storeFirstArr[i][j];
			}
			else{
				if(production[c1][c2] == '\0'){
					// Case where we reach the end of a production 
					follow(production[c1][0]);
				}
				else{
					// Recursion to the next symbol in case we encounter a "#"
					followfirst(production[c1][c2], c1, c2+1);
				}
			}
			j++;
		}
	}
}