#include <stdio.h>
#define MAX_LENGTH 20

struct Node
{
    struct Node *link;
    char alphabet;
};
typedef struct Node Node;

int main()
{
    // inisialisasi struct yang akan dikaitkan
    Node l1, l2, l3, l4, l5, l6, l7, l8, l9;
    
    l1.link = NULL;
    l1.alphabet = 'F';
    l2.link = NULL;
    l2.alphabet = 'M';
    l3.link = NULL;
    l3.alphabet = 'A';
    l4.link = NULL;
    l4.alphabet = 'I';
    l5.link = NULL;
    l5.alphabet = 'K';
    l6.link = NULL;
    l6.alphabet = 'T';
    l7.link = NULL;
    l7.alphabet = 'N';
    l8.link = NULL;
    l8.alphabet = 'O';
    l9.link = NULL;
    l9.alphabet = 'R';

    // mengurutkan posisi struct di dalam array
    Node *arrayNode[9] = {&l7, &l1, &l8, &l2, &l5, &l3, &l6, &l9, &l4};

    // mengaitkan semua struct
    for(int i = 0; i < 9 - 1; i++)
    {
        arrayNode[i]->link = arrayNode[i+1];
    }
    arrayNode[8]->link = arrayNode[0];

    // insialisasi variabel pondasi yang mencakup semua struct yang berkaitan
    Node *current = arrayNode[0];
    // variabel yang menyimpan rangkaian kata yang dibuat user
    char kalimat[MAX_LENGTH];

    int state = 1;
    int count = 0, choice, posChar = -1;

    // main program
    printf("Rangkai sebuah kata!\n");
    while(state)
    {
        printf("Rangkaian kata (%d/%d):", posChar+1, MAX_LENGTH);
        for(int i = 0; i < posChar+1; i++)
        {
            printf("%c", kalimat[i]);
        }
        printf("\nRute: ");
        for(int i = 0; i <= count; i++)
        {
            printf("Link%d->", i+1);
        }
        printf("%c\n", current->alphabet);
        printf("1. Insert character\n2. Next node\n3. Exit program\nPilih menu: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            posChar++;
            if(posChar < MAX_LENGTH)
            {
                kalimat[posChar] = current->alphabet;
            }
            else
            {
                printf("ERROR: Jumlah karakter mencapai batas maksimal.\n");
                state = 0;
            }
            break;
        case 2:
            count++;
            current = current->link;
            if(current->alphabet == 'N')
            {
                count = 0;
            }
            break;
        case 3:
            state = 0;
            break;
        default:
            break;
        }
    }
    printf("\nHasil akhir rangkaian kata: ");
    for(int i = 0; i < posChar+1; i++)
    {
        printf("%c", kalimat[i]);
    }
    return 0;
}