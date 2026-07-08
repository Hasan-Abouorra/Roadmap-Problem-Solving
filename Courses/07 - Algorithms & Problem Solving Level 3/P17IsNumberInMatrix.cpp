#include <iostream>

using namespace std;

int IsNumberInMatrix(int Matrix[][100], short Rows, short Cols, int number)
{
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
            if (Matrix[i][j] == number)
                return true;
    return false;
}

int main()
{
    int Matrix[][100] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    short Rows = 3, Cols = 3;
    int search = 1;
    if (IsNumberInMatrix(Matrix, Rows, Cols, search))
        cout << "YES: " << search << " is in the matrix.\n";
    else
        cout << "No: " << search << " is NOT in the matrix.\n";
    return 0;
}