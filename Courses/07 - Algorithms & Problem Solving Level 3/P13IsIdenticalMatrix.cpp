#include <iostream>
#include <cstdio>

using namespace std;

void Print3xArray(int array[100][100], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
            printf("%02d  ", array[i][j]);
        cout << "\n";
    }
}

bool IsIdenticalMatrix(int Matrix[][100], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
        {
            if (i == j)
                if (Matrix[i][j] == 1)
                    continue;
            if (Matrix[i][j] != 0)
                return false;
        }
    return true;
}

int main()
{
    int Matrix[][100] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    short Rows = 3, Cols = 3;
    Print3xArray(Matrix, Cols, Rows);
    cout << "-------------\n";
    if (IsIdenticalMatrix(Matrix, Rows, Cols))
        cout << "YES: matrix is identical.\n";
    else
        cout << "No: matrix is NOT identical.\n";
    return 0;
}