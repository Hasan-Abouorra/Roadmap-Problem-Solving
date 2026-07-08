#include <iostream>
// Inspired by: https://youtu.be/66hDgWottdA?si=pRPupBH9iGF47eUj
using namespace std;
void Fill3xArraySidesWith1s(int array[100][100], short Rows, short Cols)
{
    // short start = 0;
    for (int i = 0; i < Rows; i++)
        array[i][0] = 1;
    for (int j = 0; j < Cols; j++)
        array[0][j] = 1;
}

int UniquePath(int array[100][100], short Rows, short Cols)
{
    short start = 0;
    for (int i = 1; i < Rows; i++)
    {
        for (int j = 1; j < Cols; j++)
        {
            array[i][j] = array[i - 1][j] + array[i][j - 1];
        }
    }
    return array[Rows - 1][Cols - 1];
}

void Print3xArray(int array[100][100], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            // cout << setw(3) << array[i][j] << "   ";
            //  printf("%0*d   ", 2, array[i][j] );
            printf("%02d  ", array[i][j]);
        }
        cout << "\n";
    }
}

int main()
{
    // dynamic programm
    Rows = 9, Cols = 9;
    Fill3xArraySidesWith1s(Matrix2, Rows, Cols);
    Print3xArray(Matrix2, Rows, Cols);
    cout << "-------------\n";

    UniquePath(Matrix2, Rows, Cols);
    Print3xArray(Matrix2, Rows, Cols);
    cout << "-------------\n";

    return 0;
    ;
}