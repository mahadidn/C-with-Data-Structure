#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define MAXLINE 1024

int readLine(FILE *pUAS, char *line){
	int x = 0;

	while (fgets(line + x, MAXLINE - x, pUAS)){
		x = strlen(line);

		if (line[x - 1] == '\n'){

			line[x - 1] == '\0';
			return x - 1;
		}
	}

	return 0;
}

long bagiwaktu(clock_t t1, clock_t t2) {
    long x;
    x = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    return x;
}

int waktu(void) {
    clock_t t1, t2;
    int i;
    float x = 2.7182;
    long z;

    t1 = clock();
    for (i=0; i < 1000000; i++) {
           x = x * 3.1415; 
    }
    t2 = clock();

    z = bagiwaktu(t1, t2);
    printf("Time Elapsed %d ms\n", z);


    return 0;
}

int main(int argc, char **argv){

		if (argv[1] == NULL){
			printf ("Mahadi Dwi Nugraha\n");
			printf ("2101020065\n"); 
		}else{

        if (strcmp(argv[1], "-s") == 0)
        {
			//	Scanning Technique

			char *buffer;
			buffer = (char*) malloc (sizeof(char));
			int c = 0;
			int d = 0;
			char *satu;
			char *dua;

			FILE *pFIle = fopen ("DATAUASTHP2.csv", "r");
			if (!pFIle){
				perror ("Error open file"); 
			}

			while (fgets(buffer, 1024, pFIle)){
				satu = strtok(buffer, ",");
				dua = strtok(NULL, "\n");

            	if (strstr(satu, argv[2])){

               		printf("Found %s data on column is %s\n", argv[2] ,dua);
                	c = 1;
					d++;
					break;
            	}

        	}

			if (c != 1){
				printf ("Data tidak ditemukan!\n");
			}
			fclose(pFIle);
			waktu();
			 
        }
        else if (strcmp(argv[1], "-t") == 0){

			// my own technique solution
			// i'm using breadth first search algorithm
			// i think so, but i'm not sure

		/* 
		 	jika dibuka di terminal powershell 
			terkadang tidak bisa dibuka dan menghasilkan 
			error: too many file
			tetapi codingannya bisa di run menggunakan 
			terminal git bash
		*/

			FILE *pUAS = fopen("DATAUASTHP2.csv", "r");
			if (!pUAS){
				perror ("Error open file");

				return 1;
			}

			 int a = 0;
			 int b = 0;

			 char line[100];
			 char *satu;
			 char *dua;
			 while (readLine(pUAS, line)){
				char *satu = strtok(line, ",");
				char *dua = strtok(NULL, "\n");

				if (strstr(satu, argv[2])){
					printf ("Found %s with data on column is %s\n", argv[2], dua);
					a = 1;
					b++;
					break;
				}
			

			 }
			 if (a != 1){
				printf ("\nData tidak ditemukan!\n");
			 }

             fclose (pUAS);

			 waktu();

        }else {
		 	printf ("\nNo method defined error !!!\n");
		 	printf ("Proper Syntax is\n");
		 	printf ("find [ -s | -t ] number\nwhere\n");
		 	printf ("number is the number you are looking for\n");
		 	printf ("-s : search using scanning\n");
		 	printf ("-t : search using my own solution\n");
		 }

		}
    
	return 0;
}
