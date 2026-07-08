using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void Fill3xArrayWithRandomElements(int array[100][100], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            array[i][j] = RandomNumber(1, 100);
        }
    }
}

void Print3xArray(int array[100][100], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            //cout << setw(3) << array[i][j] << "   ";
            // printf("%0*d   ", 2, array[i][j] );
            printf("%02d    ", array[i][j]);
        }
        cout << "\n";
    }
}

void PrintMiddleRow(int array[100][100], short Rows, short Cols)
{
    int MiddleRow = Rows / 2;
    for (int j = 0; j < Cols; j++)
    {
        printf("%02d   ", array[MiddleRow][j]);
    }
    cout << "\n";
}

void PrintMiddleCol(int array[100][100], short Rows, short Cols)
{
    int MiddleCol = Cols / 2;
    for (int j = 0; j < Rows; j++)
    {
        printf("%02d   ", array[j][MiddleCol]);
    }
    cout << "\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int array[100][100];

    short Rows = 3, Cols = 3;
    Fill3xArrayWithRandomElements(array, Rows, Cols);
    Print3xArray(array, Rows, Cols);

    cout << "-------------\n";
    cout << "Middle Row of Matrix1 is:\n "; PrintMiddleRow(array, Rows, Cols);
    cout<<"\n";
    cout << "Middle Col of Matrix1 is:\n "; PrintMiddleCol(array, Rows, Cols);
    cout<<"\n";

        return 0;
}
