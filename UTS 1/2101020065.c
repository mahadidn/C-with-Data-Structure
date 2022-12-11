#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nama : mahadi dwi nugraha
// NIM : 2101020065

char *stack;
int stackindex = 0;

int push(char in){
	if (stack == NULL){
		stack = (char *) malloc (sizeof(char));
	}
	else {
		stack = (char *) realloc (stack, sizeof(char)* ++stackindex);
	}
	stack[stackindex] = in;
	return 1;
}


void sortbig(char *stack, int stackindex){
	for (int i = 0; i < stackindex; i++){

		for (int j = 0; j < stackindex; j++){
			if (stack[j] > stack[j+1]){
				
				char temp = stack[j];
				stack[j] = stack[j+1];
				stack [j+1] = temp;
			}
		}
	}
}

char pop(){
	return stack[stackindex--];
}

void tampil(char *stack, int stackindex){
	for (int i = stackindex; i >= 0; i--){
		pop();
		sortbig(stack, stackindex);
		printf ("%c", stack[i]);
	}
}

int main(int argc, char**argv){

	for (int i = 1; i < argc; i++){
		int k = strlen (argv[i]);
		for (int j = 0; j < k; j++){
			char in = argv[i][j];
			push (in);
		}
		if (i < argc-1) push (' ');
	}
	sortbig(stack, stackindex);
	tampil(stack, stackindex);

	return 0;

}