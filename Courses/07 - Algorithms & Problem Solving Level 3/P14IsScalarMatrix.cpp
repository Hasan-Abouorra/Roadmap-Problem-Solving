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

bool IsScalarMatrix(int Matrix[][100], short Rows, short Cols)
{
    short number = Matrix[0][0];
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
        {
            if (i == j)
                if (Matrix[i][j] == number)
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
    if (IsScalarMatrix(Matrix, Rows, Cols))
        cout << "YES: matrix is scalar.\n";
    else
        cout << "No: matrix is NOT scalar.\n";
    return 0;
}