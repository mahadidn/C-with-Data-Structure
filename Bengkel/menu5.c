#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main5()
{
    FILE *inf = fopen("Mechanics.csv", "r");
    if (inf == NULL)
    {
        printf("ERROR: No name file detected.");
        return 0;
    }
    char *idServices;
    char *waktuServices;
    char *waktuSelesaiServices;
    char *idMechanisServices;
    char *idCustomer;
    char *namaCustomer;
    char temp[100];
    char Mechanis[125];
    char *idMechanis;
    int namaMechanics, c = 0;
    char *array1[20];
    char *array2[1024];
    char buffer[1024];
    char buffer2[1024];
    char buffer3[1024];
	char Buffer4[1024];
	char *waktuSelesai;
	char *idCustomer2;
    const int TopNameNumberN = 10;
    const int TopNameNumberI = 10;
    char *namaM[TopNameNumberN];
    char *idM[TopNameNumberI];

    int i = 0;
    //  BUAT AMBIL NAMA DAN ID MECHANIS
    for (int i = 0; i < TopNameNumberN; i++)
    {
        namaMechanics = fscanf(inf, " %124s", Mechanis);
        if (namaMechanics == EOF)
            break;

        namaM[c] = malloc(strlen(Mechanis) + 1);
        idM[c] = malloc(strlen(Mechanis) + 1);
        if (namaM[c] == NULL)
        {
            printf("ERROR: Memory allocation failed.");
            break;
        }
        if (idM[c] == NULL)
        {
            printf("ERROR: Memory allocation failed.");
            break;
        }

        array2[i] = strtok(Mechanis, ";");
        array1[i] = strtok(NULL, ";");
        strcpy(idM[c], array2[i]);
        strcpy(namaM[c], array1[i]);

        ++c;
    }
    fclose(inf);
    // SORT
    for (int i = 0; i < c - 1; i++)
    {
        for (int j = 0; j < c - 1 - i; j++)
        {
            if (strcmp(namaM[j], namaM[j + 1]) > 0)
            {
                strcpy(temp, namaM[j]);
                strcpy(namaM[j], namaM[j + 1]);
                strcpy(namaM[j + 1], temp);
            }
        }
    }
    // NAMPILIN DAN AMBIL ID SERVICES DAN CUSTOMER
    for (int i = 0; i < c; i++)
    {

        printf("\nMechanis: %s\n", namaM[i]);

        FILE *inf = fopen("Mechanics.csv", "r");
        if (inf == NULL)
        {
            printf("ERROR: No name file detected.");
            return 0;
        }
        FILE *pS = fopen("Services.csv", "r");

        printf("BikeID\tOwner\tEntry\tFinish\n");
        while (fgets(buffer2, 1024, pS)) // LOOPING SERVICES
        {
            idServices = strtok(buffer2, ";");
            idMechanisServices = strtok(NULL, ";");
            waktuServices = strtok(NULL, ";");

            if (strcmp(idM[i], idMechanisServices) == 0)
            {
                printf("%s\t", idServices);
                FILE *pC = fopen("Customer.csv", "r");
                while (fgets(buffer3, 1024, pC)) // LOOPING CUSTOMER
                {
                    idCustomer = strtok(buffer3, ";");
                    namaCustomer = strtok(NULL, ";");
                    if (strcmp(idServices, idCustomer) == 0)
                        printf("%s\t", namaCustomer);
                }
                fclose(pC);
                printf("%s\t", waktuServices);

				FILE *pE = fopen("Selesai.csv", "r"); 
 	    		while (fgets(Buffer4, 1024, pE)){

            	idCustomer2 = strtok(Buffer4, ";");
            	waktuSelesai = strtok(NULL, ";");

 				if(strstr(idServices, idCustomer2) != 0){
                	printf ("%s\n", waktuSelesai);
         	      	break;
             	}
        
         	}
        	fclose(pE);

            }

			
        }
        fclose(pS);
    }
    // BIAR DAtA NAMA dan id itu bebas
    for (int i = 0; i < c; i++)
    {
        free(namaM[i]);
        free(idM[i]);
    }

    return 0;
}
