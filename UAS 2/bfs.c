#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// breadth first search

#define MAX_LINE_LEN 1024

int read_line(FILE *fp, char *line) {
    int len = 0;

    while (fgets(line + len, MAX_LINE_LEN - len, fp)) {
        len = strlen(line);

        if (line[len - 1] == '\n') {

            line[len - 1] = '\0';
            return len - 1;
        }
    }

    return 0;
}

int main() {

    FILE *fp = fopen("DATAUASTHP2.csv", "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }
	int a = 0;
    int b = 0;
    char cari[20];
	
	printf ("Masukkan kata yang ingin dicari :");
	scanf ("%s", cari);

    char *line;
	line = (char*) malloc (sizeof(char));
    while (read_line(fp, line)) {

        if (strstr(line, cari)) {

            printf("Found %s with data on column is %s\n", cari, line);
			a = 1;
            b++;
        }
    }

	if (a != 1){
		printf ("Data tidak ditemukan!");
	}


    fclose(fp);

    printf ("\nData ditemukan sebanyak = %d\n", b+1);
    return 0;
}