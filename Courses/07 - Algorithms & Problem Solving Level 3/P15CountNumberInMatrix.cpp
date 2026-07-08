#include <iostream>

using namespace std;

int CountNumberInMatrix(int Matrix[][100], short Rows, short Cols, int number)
{
    int count = 0;
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
            if (Matrix[i][j] == number)
                count += 1;
    return count;
}

int main()
{
    int Matrix[][100] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    short Rows = 3, Cols = 3;
    cout << CountNumberInMatrix(Matrix, Cols, Rows, 1) << endl;
    return 0;
}