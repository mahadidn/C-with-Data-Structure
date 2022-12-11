#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "./menu2.c"
#include "./menu3.c"
#include "./menu4.c"
#include "./menu5.c"
int Nomor_Polisi;
char IDMekanik[3];
char Jam[5];
int tampungNomor;
int x = 0;

struct Customer
{

    int Nomor;
    char Nama[50];

    struct Customer *Next;

} cari, tambah;

struct Mekanik
{
    char ID[5];
    char nama[20];
} add;

struct Services
{
    int nomor_polisi;
    char ID_mekanik[5];
    char jam_masuk[5];

    struct Services *Next;

} *head, *tail, *current, *newNode, *hapus, *Temp;

void cariData();
void create(int nomor_polisi, char ID_mekanik[], char jam_masuk[]);
void addLast(int nomor_polisi, char ID_mekanik[], char jam_masuk[]);
int printServices();
int cariMekanik();
void tampilMekanik();
void inputCustomer(int tampung);
void inputServices();
int waktu();
void append(char subject[], const char insert[], int pos);
int tanya();
struct Services *destroy(struct Services *head);

//======================================================
// FUNGSI UTAMA
int main()
{
    system("cls");
    printf("Task Options:\n");
    printf("\t 1. New Service Entry\n");
    printf("\t 2. Service Finish Entry\n");
    printf("\t 3. Show all Today's Service Data\n");
    printf("\t 4. Overlap Service Data Search\n");
    printf("\t 5. Show all mechanic jobs (sorted)\n");
    printf("\t 6. Quit program\n");
    int optionsMenu;
    printf("\t Your selection: ");
    scanf("%d", &optionsMenu);
    if (optionsMenu == 1)
    {
        do
        {
            cariData();
            printf("\n");
            system("PAUSE");
            system("cls");
            cariMekanik();
            system("PAUSE");
            system("cls");
            waktu();
            system("PAUSE");
            system("cls");
            inputServices();
        } while (tanya());
        printServices();
        head = destroy(head);
    }
    else if (optionsMenu == 2)
    {
        main2();
        system("PAUSE");
        system("cls");
        main();
    }
    else if (optionsMenu == 3)
    {
        main3();
        system("PAUSE");
        main();
    }
    else if (optionsMenu == 4)
    {
        main4();
        system("PAUSE");
        main();
    }
    else if (optionsMenu == 5)
    {
        main5();
        system("PAUSE");
        main();
    }
    else if (optionsMenu == 6)
    {
        printf("Tim #Semampunya\n");
        printf("\t1.   2101020071   Muhammad Rizki Fachriza Bailey\n");
        printf("\t2.   2101020005   Muhamad Nur Syami\n");
        printf("\t3.   2101020065   Mahadi Dwi Nugraha\n");
        printf("\t4.   2101020058   Faujiah Decika\n");
        printf("\t5.   2101020001   Khairunnisa Munawwarah\n");
        printf("\t6.   2101020084   Sahra Fatimah Yasir\n");
        printf("\t7.   2101020010   Novriyanti Rahmadani\n");
        printf("\t8.   2101020002   Ariska Dwi Ambarwati\n");
        printf("\t9.   2101020045   Adityo Khori Ramadhan\n");
        printf("\t10.  2101020099   Fahrizal Fajar Nugroho\n");
        printf("\t11.  2101020049   Apriyansyah Kurniawan\n");
        printf("\t12.  2101020101   Fatur Rachman\n");
        printf("\t13.  2101020012   Rovy Saputra Nugeraha\n");
        printf("\t14.  2101020057   Farel Putra Albana\n");
        printf("\t15.  2101020078   Regina\n");
        printf("\t16.  2101020098   Hardi Prayuda\n");
        printf("\t17.  2101020004   Julian Jau'hari\n");
        printf("\t18.  2101020086   Syi'aruddin\n");
        printf("\t19.  2101020081   Rekha Clarista Amelia\n");
        printf("\t20.  2101020067   Marwan Anshory\n");
        printf("\t21.  2101020006   Amanda Dwi Mulyani\n");
        printf("\t22.  2101020115   Rosiana Oksela Nainggolan\n");
        printf("\t23.  2101020003   Rizka Intan Fagira\n");
        printf("\t24.  2201020144   Alhuwayrist Royhan A.\n");
        printf("\t25.  2101020097   Mohd. Fiqri Raekhal\n");
        exit(0);
    }
    else
    {

        printf("Masukan Menu pilihan dengan benar !\n\n");
        system("PAUSE");
        main();
    }
    return 0;
}

/*=========PROTORYPE==================*/

void cariData()
{

    int a = 0;
    FILE *pF;
    char input;

    pF = fopen("Customer.csv", "r");

    printf("Motobike plate number : ");
    scanf("%d", &cari.Nomor);

    while (fscanf(pF, "%d;%[^;];\n", &tambah.Nomor, tambah.Nama) != EOF)
    {

        if (tambah.Nomor == cari.Nomor)
        {
            a = 1;

            printf("\nOwner : %s\n", tambah.Nama);
            Nomor_Polisi = tambah.Nomor;

            break;
        }
    }
    fclose(pF);

    if (a != 1)
    {
        tampungNomor = cari.Nomor;
        printf("Data Not Found.");
    inputan:
        printf(" New Customer ? (Y/N) : ");
        scanf(" %c", &input);

        switch (input)
        {
        case 'Y':
            inputCustomer(tampungNomor);
            break;
        case 'N':
            main();
            break;
        default:
            printf("Salah inputan!");
            goto inputan;
        }
    }
}

void create(int nomor_polisi, char ID_mekanik[], char jam_masuk[])
{

    head = (struct Services *)malloc(sizeof(struct Services));

    head->nomor_polisi = nomor_polisi;
    strcpy(head->ID_mekanik, ID_mekanik);
    strcpy(head->jam_masuk, jam_masuk);

    head->Next = NULL;
    tail = head;
}

void addLast(int nomor_polisi, char ID_mekanik[], char jam_masuk[])
{
    newNode = (struct Services *)malloc(sizeof(struct Services));

    newNode->nomor_polisi = nomor_polisi;
    strcpy(newNode->ID_mekanik, ID_mekanik);
    strcpy(newNode->jam_masuk, jam_masuk);

    newNode->Next = NULL;
    tail->Next = newNode;
    tail = newNode;
}

void inputCustomer(int tampung)
{

    int x = 0;
    char dimana;
    char input;
    int nomor;
    char nama[50];
    int a = 0;
    char str[10];

nomor:
    a = 0;
    nomor = tampung;
    printf("Enter Customer Name : ");
    scanf("%*c%[^\n]", nama);

    FILE *pC;

    Nomor_Polisi = nomor;

    //   fclose(pC);

    pC = fopen("Customer.csv", "a");

    itoa(nomor, str, 10);
    fprintf(pC, str);
    fprintf(pC, ";");
    fprintf(pC, nama);
    fprintf(pC, ";\n");

    fclose(pC);
}

int printServices()
{

    FILE *pF = fopen("Services.csv", "a");
    char str[10];

    current = head;
    while (current != NULL)
    {

        itoa(current->nomor_polisi, str, 10);
        fprintf(pF, str);
        fprintf(pF, ";");
        fprintf(pF, current->ID_mekanik);
        fprintf(pF, ";");
        fprintf(pF, current->jam_masuk);
        fprintf(pF, ";\n");
        current = current->Next;
    }
    fclose(pF);

    return 0;
}

int cariMekanik()
{

    FILE *pM;

    pM = fopen("Mechanics.csv", "r");

    char mekanik[5];
    int a = 0;
    char input;

    printf("\nEnter Mechanic ID : ");
    scanf("%s", mekanik);

    while (fscanf(pM, "%[^;];%[^;];\n", add.ID, add.nama) != EOF)
    {

        if (strstr(add.ID, mekanik) != 0)
        {
            a = 1;
            break;
        }
    }
    if (a == 1)
    {
        printf("\nMechanics : %s\n", add.nama);
        strcpy(IDMekanik, mekanik);
    }
    else
    {
        printf("\nError. Mechanic's ID Not Found. !!!");
    inputan:
        printf("\nDo you need to see the list of Mechanics ID ? (Y/N)? : ");
        scanf(" %c", &input);

        switch (input)
        {
        case 'Y':
            tampilMekanik();
            break;
        case 'N':
            break;
        default:
            printf("Inputan Salah!");
            goto inputan;
        }
    }
    fclose(pM);
    return 0;
}

void tampilMekanik()
{

    FILE *pM = fopen("Mechanics.csv", "r");
    char buffer[500];
    char *idmchanis;
    char *namamchanis;
    printf("\nID\tNama\n");
    while (fgets(buffer, 500, pM) != NULL)
    {
        printf("%s\t", strtok(buffer, ";"));
        printf("%s\n", strtok(NULL, ";"));
    }
    fclose(pM);
    printf("\n");
    cariMekanik();
}

void inputServices()
{

    char input;

    if (x == 0)
    {
        create(Nomor_Polisi, IDMekanik, Jam);
    }
    else if (x > 0)
    {
        addLast(Nomor_Polisi, IDMekanik, Jam);
    }
    x++;
}

int waktu()
{

    int HH, MM;
    char gg;
    char gg1;
    char jam[10];
    char menit[10];
    char *str;
    char ch = ':';

inputan:
    printf("Time of Entry (HH:MM): ");
    scanf("%02d:%02d", &HH, &MM);

    if (HH >= 24 && MM >= 00 || HH >= 00 && MM >= 60)
    {
        printf("Error. The maksimum time is 24:00 and minimum is 00:01\n");
        goto inputan;
    }

    sprintf(jam, "%02d", HH);
    sprintf(menit, "%02d", MM);
    str = strcat(jam, menit);

    gg = atoi(jam);
    gg1 = atoi(menit);

    append(str, &ch, 2);

    return 0;
}

void append(char subject[], const char insert[], int pos)
{
    char buf[5] = "";

    strncpy(buf, subject, pos);
    int len = strlen(buf);
    strcpy(buf + len, insert);
    len += strlen(insert);
    strcpy(buf + len, subject + pos);

    strcpy(subject, buf);

    strcpy(Jam, subject);
}

int tanya()
{
    char in;
    while (1)
    {
        while (getchar() != '\n')
            ;
        printf("Input another data ? (Y/N) : ");
        in = getchar();
        if (in == 'Y')
            return 1;
        if (in == 'N')
            printServices();
        main();
    }
    return 0;
}

struct Services *destroy(struct Services *head)
{
    struct Services *current = head;
    struct Services *Next;

    while (current != NULL)
    {
        Next = current->Next;
        free(current);
        current = Next;
    }
    head = NULL;
    return head;
}