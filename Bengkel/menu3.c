#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

struct Selesai
{
    char Nomor[10];
    char Selesai[10];
} CariSelesai, TambahSelesai;

// FUNGSI NAMPILIN SERVICES DAN RELASI KE FILE CUSTOMER CSV
void nampilServices();

//==================main============
int main3()
{
    nampilServices();

    return 0;
}

// =============PROTOTYPE============
void nampilServices()
{

    FILE *pS = fopen("Services.csv", "r");
    if (pS == NULL)
    {
        printf("Error. Services Data not Found !!!\n");
        printf("You should create data first by input new Service Data\n");
    }
    char buffer[1024];
    char buffer2[1024];
    char buffer3[1024];
    // PROGRAM SUDAH MENDAPATKAN IDNYA
    int result;
    printf("\nBikeID\tOwner\tMechanic\tEntry\tFinish\n");
    char *idServices;
    char *mehcanis;
    char *waktu;
    char *idCustomer;
    char *namaCustomer;
    char *idCustomer2;
    char *waktuSelesai;
    char *idMechanic;
    char *namaMechanic;
    char Buffer4[1024];

    while (fgets(buffer, 1024, pS))
    {

        idServices = strtok(buffer, ";");
        mehcanis = strtok(NULL, ";");
        waktu = strtok(NULL, ";");
        printf("%s\t", idServices);

        FILE *pC = fopen("Customer.csv", "r");
        while (fgets(buffer2, 1024, pC))
        {
            idCustomer = strtok(buffer2, ";");
            namaCustomer = strtok(NULL, ";");

            if (strcmp(idCustomer, idServices) == 0)
            {
                printf("%s\t", namaCustomer);
                break;
            }
        }

        FILE *pM = fopen("Mechanics.csv", "r");
        while (fgets(buffer3, 1024, pM))
        {

            idMechanic = strtok(buffer3, ";");
            namaMechanic = strtok(NULL, ";");

            if (strcmp(idMechanic, mehcanis) == 0)
            {
                printf("%s\t\t", namaMechanic);
            }
        }
        fclose(pM);

        fclose(pC);
        //     printf("%s\t\t", mehcanis);
        printf("%s", waktu);

        FILE *pE = fopen("Selesai.csv", "r");
        while (fgets(Buffer4, 1024, pE))
        {

            idCustomer2 = strtok(Buffer4, ";");
            waktuSelesai = strtok(NULL, ";");

            if (strcmp(idCustomer2, idServices) == 0)
            {
                printf("\t%s\n", waktuSelesai);
            }
        }
        fclose(pE);
    }

    fclose(pS);
}