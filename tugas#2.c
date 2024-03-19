#include <stdio.h>

void koboImaginaryChess(int i, int j, int size, int chessBoard[8][8])
{
    if(j-2 >= 0)
    {
        if(i+1 < size)
        {
            chessBoard[i+1][j-2] = 1;
        }
        if(i-1 >= 0)
        {
            chessBoard[i-1][j-2] = 1;
        }
    }
    if(j+2 < size)
    {
        if(i+1 < size)
        {
            chessBoard[i+1][j+2] = 1;
        }
        if(i-1 >= 0)
        {
            chessBoard[i-1][j+2] = 1;
        }
    }
    if(i-2 >= 0)
    {
        if(j+1 < size)
        {
            chessBoard[i-2][j+1] = 1;
        }
        if(j-1 >= 0)
        {
            chessBoard[i-2][j-1] = 1;
        }
    }
    if(i+2 < size)
    {
        if(j+1 < size)
        {
            chessBoard[i+2][j+1] = 1;
        }
        if(j-1 >= 0)
        {
            chessBoard[i+2][j-1] = 1;
        }
    }
}

int main()
{
    int COL = 8, ROW = 8;
    int chessBoard[ROW][COL];
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            chessBoard[i][j] = 0;
        }
    }
    int x, y;
    printf("Masukkan koordinat x: ");
    scanf("%d", &x);
    printf("Masukkan koordinat y: ");
    scanf("%d", &y);
    koboImaginaryChess(y, x, ROW, chessBoard);
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("%d ", chessBoard[i][j]);
        }
        printf("\n");
    }
    return 0;
}