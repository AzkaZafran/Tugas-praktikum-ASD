#include <stdio.h>

int pop(int Data[], int *top)
{
    int newTop = *top;
    int temp = Data[newTop];
    Data[newTop] = 0;
    (*top)--;
    return temp;
}

int peek(int Data[], int top)
{
    return Data[top];
}

int maxSelect(int Data1[], int topIndex1, int Data2[], int topIndex2, int maxSum)
{
    // total nilai yang telah dikeluarkan
    int sum = 0;
    // jumlah nilai yang telah dikeluarkan
    int removed = 0;

    // while loop akan terus berjalan jika belum ada stack yang kosong
    while(topIndex1 >= 0 && topIndex2 >= 0)
    {
        // ada pengecualian jika sum ditambah data teratas dari salah satu stack
        // melebihi maxSum maka while loop akan berhenti
        if(sum + peek(Data1, topIndex1) > maxSum && sum + peek(Data2, topIndex2) > maxSum)
        {
            break;
        }
        // jika kondisi tidak sesuai maka akan lanjut ke pengecekan utama
        // if else ini akan mengecek apabila kondisi antara data teratas stack 1 dengan stack dua
        // 'lebih dari', 'kurang dari', atau 'sama'.
        // jika 'kurang dari' maka program akan mengambil data teratas dari stack 1 dan ditambahkan
        // ke dalam sum
        if(Data1[topIndex1] < Data2[topIndex2])
        {
            sum += pop(Data1, &topIndex1);
            removed++;
        }
        // jika 'lebih dari' maka yang diambil adalah data teratas dari stack 2
        else if(Data2[topIndex2] < Data1[topIndex1])
        {
            sum += pop(Data2, &topIndex2);
            removed++;
        }
        // jika 'sama' maka akan melakukan pengecekan lagi yang hampir sama dengan if else diatas
        // hanya yang dicek adalah data teratas kedua
        else
        {
            if(Data1[topIndex1-1] < Data2[topIndex2-1])
            {
                sum += pop(Data1, &topIndex1);
                removed++;
            }
            else if(Data1[topIndex1-1] > Data2[topIndex2-1])
            {
                sum += pop(Data2, &topIndex2);
                removed++;
            }
        }
    }


    return removed;
}

int main()
{
    int round;
    int hasil;

    // user input berapa ronde game
    scanf("%d", &round);
    // main program
    for(int i = 0; i < round; i++)
    {
        int n, m, maxSum;
        scanf("%d %d %d", &n, &m, &maxSum);

        // stack 1 dan 2
        int stack1[n];
        int stack2[m];

        // input n dan m data berupa integer ke dalam stack 1 dan stack 2
        for(int i = n-1; i >= 0; i--)
        {
            scanf("%d", &stack1[i]);
        }
        for(int i = m-1; i >= 0; i--)
        {
            scanf("%d", &stack2[i]);
        }
        hasil = maxSelect(stack1, n-1, stack2, m-1, maxSum);
        printf("hasil: %d\n", hasil);
    }

    return 0;
}