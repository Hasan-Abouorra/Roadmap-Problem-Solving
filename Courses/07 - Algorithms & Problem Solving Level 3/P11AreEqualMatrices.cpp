#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void Fill3xArrayWithOrderedElements(int array[100][100], short Rows, short Cols)
{
    short start = 0;
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
            array[i][j] = ++start;
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

int SumOfMatrix(int Matrix1[100][100], short Rows, short Cols)
{
    int Sum = 0;
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
            Sum += Matrix1[i][j];
    return Sum;
}

bool AreEqualMatrices(int Matrix1[100][100], int Matrix2[100][100], short Rows, short Cols)
{
    return SumOfMatrix(Matrix1, Rows, Cols) == SumOfMatrix(Matrix2, Rows, Cols);
}

int main()
{
    srand((unsigned)time(NULL));
    int Matrix1[100][100], Matrix2[100][100];
    short Rows = 3, Cols = 3;
    Fill3xArrayWithOrderedElements(Matrix1, Rows, Cols);
    Fill3xArrayWithRandomElements(Matrix2, Rows, Cols);
    Print3xArray(Matrix1, Rows, Cols);
    cout << "-------------\n";
    Print3xArray(Matrix2, Rows, Cols);
    cout << "-------------\n";
    if (AreEqualMatrices(Matrix1, Matrix2, Rows, Cols))
        cout << "YES: both matrices are equal.\n";
    else
        cout << "No: matrices are NOT equal.\n";
    return 0;
}