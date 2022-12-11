#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct Node
{
    char data[256];
    struct Node *left, *right;
};

struct Node *newNode2(char *data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(node->data, data);
    node->left = node->right = NULL;
    return node;
}

void insert(struct Node *root, char *data)
{
    if (strcmp(data, root->data) < 0)
    {

        if (root->left == NULL)
            root->left = newNode2(data);
        else
            insert(root->left, data);
    }
    else
    {

        if (root->right == NULL)
            root->right = newNode2(data);
        else
            insert(root->right, data);
    }
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%s\n", root->data);
    inorder(root->right);
}

void cekServis();
void overlappedJobs();
long timediff(clock_t t1, clock_t t2);
int waktu2(void);

int main4()
{
    cekServis();
    overlappedJobs();
    waktu2();

    //=========================================================================

    printf("\n\nUsing Memory Tree");
    struct Node *root = NULL;
    char line[256];
    char line2[256];

    FILE *pM = fopen("Mechanics.csv", "r");
    FILE *pS = fopen("Services.csv", "r");
    if (pM == NULL)
    {
        printf("Error: could not open file for reading\n");
        return 1;
    }

    printf("\n\n===Mekanik===\n");

    while (fgets(line, sizeof(line), pM))
    {

        line[strcspn(line, "\n")] = 0;

        if (root == NULL)
            root = newNode2(line);
        else
            insert(root, line);
    }
    inorder(root);
    free(root);

    printf("\n\n===Services===\n");
    while (fgets(line2, sizeof(line2), pS))
    {

        line2[strcspn(line2, "\n")] = 0;

        if (root == NULL)
            root = newNode2(line2);
        else
            insert(root, line2);
    }

    fclose(pS);
    fclose(pM);

    inorder(root);

    waktu2();

    return 0;
}

void cekServis()
{

    FILE *pS = fopen("Services.csv", "r");

    if (pS == NULL)
    {

        printf("Error. Service data not found !!! \nYou should create data first by input new service data");
    }

    fclose(pS);
}

void overlappedJobs()
{

    printf("\nOverlapped Jobs\n");

    FILE *pS = fopen("Services.csv", "r");

    char buffer[1024];
    char buffer2[1024];
    char buffer3[1024];
    // PROGRAM SUDAH MENDAPATKAN IDNYA
    int result;
    printf("\nBikeID\tOwner\tMechanic\tEntry\tFinish\n");
    char *idServices;
    char *mehcanis;
    char *waktu2;
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
        waktu2 = strtok(NULL, ";");
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
                printf("%s\t", namaMechanic);
            }
        }
        fclose(pM);

        fclose(pC);
        //     printf("%s\t\t", mehcanis);
        printf("\t%s", waktu2);

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

long timediff(clock_t t1, clock_t t2)
{
    long elapsed;
    elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    return elapsed;
}

int waktu2(void)
{
    clock_t t1, t2;
    int i;
    float x = 2.7182;
    long elapsed;

    t1 = clock();
    for (i = 0; i < 1000000; i++)
    {
        x = x * 3.1415;
    }
    t2 = clock();

    elapsed = timediff(t1, t2);
    printf("\nTime Elapsed %ld ms\n", elapsed);

    return 0;
}
