#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

char *jam_masuk;
char *Masukkan;
char *tampungData;
char tulisFile[10];
char Nomor[10];

struct cekServices
{
	char nomorPolisi[4];
	char IDMekanik[3];
	char waktuKedatangan[5];
} CariServices, TambahS;

struct cekCustomer
{
	char nomorCustomer[5];
	char namaCustomer[50];

} CariC, TambahC;

struct cekMekanik
{
	char ID_Mekanik[3];
	char namaMekanik[3];

} CariM, TambahM;

void cekService();
int waktuMenu2();
void appendMenu2(char subject[], const char insert[], int pos);
void printData(int HH, int MM);
void cetakFile(char Tulis[]);

int main2()
{

	cekService();
	waktuMenu2();
	cetakFile(tulisFile);

	return 0;
}

void cekService()
{

	int a = 0;
	int b = 0;
	int c = 0;
	char masukkan[5];
	char ID[3];
	FILE *pS = fopen("Services.csv", "r");
	FILE *pC = fopen("Customer.csv", "r");
	FILE *pM = fopen("Mechanics.csv", "r");

	if (pS == NULL)
	{

		printf("\nError. Service data not found !!! \nYou should create data first by input new service data.");
		fclose(pS);
		exit(1);
	}
	else
	{
		//		printf ("\nSuccsess Opening file!\n");
	}

	printf("Motobike plate number: ");
	scanf("%s", masukkan);
	strcpy(Nomor, masukkan);

	while (fscanf(pC, "%[^;];%[^;];\n", CariC.nomorCustomer, CariC.namaCustomer) != EOF)
	{

		if (strstr(CariC.nomorCustomer, masukkan) != 0)
		{
			printf("\nOwner : %s", CariC.namaCustomer);
			b = 1;
			break;
		}
	}

	if (b == 1)
	{

		while (fscanf(pM, "%[^;];%[^;];\n", CariM.ID_Mekanik, CariM.namaMekanik) != EOF)
		{

			char *token = strtok(CariServices.IDMekanik, CariServices.waktuKedatangan);

			if (strstr(CariM.ID_Mekanik, CariServices.IDMekanik) != 0)
			{
				printf("\nMechanic : %s", CariM.namaMekanik);
				c = 1;
				break;
			}
		}
	}

	while (fscanf(pS, "%[^;];%[^;];%[^;];\n", CariServices.nomorPolisi, CariServices.IDMekanik, CariServices.waktuKedatangan) != EOF)
	{

		if (strstr(CariServices.nomorPolisi, masukkan) != 0)
		{
			a = 1;
			printf("\nTime of Entry : %s", CariServices.waktuKedatangan);

			break;
		}
	}
	if (a, b, c != 1)
	{
		printf("\nNo data found. You should input new service data first !!!");
		exit(1);
	}

	Masukkan = masukkan;

	fclose(pS);
	fclose(pC);
	fclose(pM);
}

int waktuMenu2()
{

	int HH, MM;

	char jam[10];
	char menit[10];
	int x;
	int y;
	char a[5];
	char b[5];

inputan:
	printf("\n\nTime of Finish (HH:MM): ");
	scanf("%02d:%02d", &HH, &MM);

	if (HH >= 24 && MM >= 00 || MM >= 60)
	{
		printf("Error. The maksimum time is 24:00 and minimum is 00:01\n");
		goto inputan;
	}

	FILE *pS = fopen("Services.csv", "r");
	while (fscanf(pS, "%[^;];%[^;];%[^;];\n", CariServices.nomorPolisi, CariServices.IDMekanik, CariServices.waktuKedatangan) != EOF)
	{

		if (strstr(CariServices.nomorPolisi, Masukkan) != 0)
		{

			int idxToDel = 2;
			memmove(&CariServices.waktuKedatangan[idxToDel], &CariServices.waktuKedatangan[idxToDel + 1], strlen(CariServices.waktuKedatangan) - idxToDel);

			strcpy(a, CariServices.waktuKedatangan);
			strcpy(b, CariServices.waktuKedatangan);
			memmove(&a[2], &a[2 + 2], strlen(a) - 2);
			memmove(b, b + 2, strlen(b));

			x = atoi(a);
			sscanf(b, "%d", &y);

			if (HH <= x && MM <= y || HH < x && MM >= y)
			{
				printf("\nError. Finish time can not earlier than entry time !!!");
				goto inputan;
			}
		}
	}

	fclose(pS);

	printData(HH, MM);

	return 0;
}

void printData(int HH, int MM)
{

	char jam[10];
	char menit[10];
	char gg;
	char gg1;
	char *str;
	char ch = ':';

	sprintf(jam, "%02d", HH);
	sprintf(menit, "%02d", MM);
	str = strcat(jam, menit);

	gg = atoi(jam);
	gg1 = atoi(menit);

	appendMenu2(str, &ch, 2);

	strcpy(tulisFile, str);
}

void cetakFile(char Tulis[])
{

	FILE *pS;
	char ch;

	pS = fopen("Selesai.csv", "r+");
	while (1)
	{
		ch = fgetc(pS);
		if (ch == EOF)
			break;
	}
	fprintf(pS, "%s;", Nomor);
	fprintf(pS, "%s;\n", Tulis);

	fclose(pS);
}

void appendMenu2(char subject[], const char insert[], int pos)
{
	char buf[5] = "";

	strncpy(buf, subject, pos);
	int len = strlen(buf);
	strcpy(buf + len, insert);
	len += strlen(insert);
	strcpy(buf + len, subject + pos);

	strcpy(subject, buf);
}
