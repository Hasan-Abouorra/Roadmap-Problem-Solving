#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void Fill3xArrayWithRandomElements(int array[100][100], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
            array[i][j] = RandomNumber(1, 100);
}

void Print3xArray(int array[100][100], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
            printf("%02d  ", array[i][j]);
        cout << "\n";
    }
}

int CountNumberInMatrix(int Matrix[][100], short Rows, short Cols, int number)
{
    int count = 0;
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
            if (Matrix[i][j] == number)
                count += 1;
    return count;
}

bool IsMatrixSparce(int Matrix[][100], short Rows, short Cols)
{
    return CountNumberInMatrix(Matrix, Rows, Cols, 0) > (Rows * Cols) / 2
               ? true
               : false;
}

int main()
{
    srand((unsigned)time(NULL));
    int Matrix[100][100];
    short Rows = 3, Cols = 3;
    Fill3xArrayWithRandomElements(Matrix, Rows, Cols);
    Print3xArray(Matrix, Cols, Rows);
    cout << "-------------\n";
    if (IsMatrixSparce(Matrix, Rows, Cols))
        cout << "YES: matrix is Sparce.\n";
    else
        cout << "No: matrix is NOT Sparce.\n";
    return 0;
}