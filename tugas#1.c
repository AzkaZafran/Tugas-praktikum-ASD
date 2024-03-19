#include <stdio.h>
#include <stdlib.h>

typedef struct card
{
    char ABC[2];
    int value;
}card;

void sortCard(card Data[], int size)
{
    card temp;
    for(int i = 0; i < size; i++)
    {
        int poin = 0;
        for(int j = 0; j < size - 1; j++)
        {
            if(Data[j].value > Data[j+1].value)
            {
                temp = Data[j];
                Data[j] = Data[j+1];
                Data[j+1] = temp;
            }
            else
            {
                poin++;
            }
        }
        if(poin == (size-1))
        {
            printf("%d", i);
            break;
        }
        printf("PERTUKARAN %d:\n", i+1);
        for(int j = 0; j < size; j++)
        {
            printf("%s ", Data[j].ABC);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Berapa kartu yang diinginkan: ");
    scanf("%d", &n);
    card deck[n];
    printf("Masukkan baris kartu anda: ");
    for(int i = 0; i < n; i++)
    {
        scanf(" %s", &deck[i].ABC);
    }
    for(int i = 0; i < n; i++)
    {
        deck[i].value = atoi(deck[i].ABC);
        if(deck[i].value == 0)
        {
            switch(deck[i].ABC[0])
            {
            case 'J':
                deck[i].value = 11;
                break;
            case 'Q':
                deck[i].value = 12;
                break;
            case 'K':
                deck[i].value = 13;
                break;
            default:
                break;
            }
        }
    }
    sortCard(deck, n);

    return 0;
}