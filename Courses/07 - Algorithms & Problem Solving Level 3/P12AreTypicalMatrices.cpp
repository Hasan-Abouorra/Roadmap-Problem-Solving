#include <iostream>
#include <cstdio>

using namespace std;

void Fill3xArrayWithOrderedElements(int array[100][100], short Rows, short Cols)
{
    short start = 0;
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
            array[i][j] = ++start;
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

bool AreTypicalMatrices(int Matrix1[100][100], int Matrix2[100][100], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
            if (Matrix1[i][j] != Matrix2[i][j])
                return false;
    return true;
}

int main()
{
    int Matrix1[100][100], Matrix2[100][100];
    short Rows = 3, Cols = 3;
    Fill3xArrayWithOrderedElements(Matrix1, Rows, Cols);
    Fill3xArrayWithOrderedElements(Matrix2, Rows, Cols);
    Print3xArray(Matrix1, Rows, Cols);
    cout << "-------------\n";
    Print3xArray(Matrix2, Rows, Cols);
    cout << "-------------\n";
    if (AreTypicalMatrices(Matrix1, Matrix2, Rows, Cols))
        cout << "YES: both matrices are typical-equal.\n";
    else
        cout << "No: matrices are NOT typical-equal.\n";
    return 0;
}