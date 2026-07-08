#include <iostream>
#include <cstdlib> // Include cstdlib for rand() and srand() functions.
#include <ctime>   // Include ctime for the time() function, used for seeding the random number generator.
#include <cmath>

using namespace std;

int ReadPositiveNumber(string message = "Please enter a positive number ? ")
{
    int number = 0;
    do
    {
        cout << message << "\n";
        cin >> number;
    } while (number <= 0);

    return number;
}


int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomElements(int array[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = RandomNumber(-100, 100);
    }
}

void PrintArray(int array[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}




int PositiveCount(int array[100], int size)
{
    int count=0;
    for (int i = 0; i < size; i++)
    {
        if (array[i]>= 0)
            count++;
    }
    return count;
}



int main()
{
    srand((unsigned)time(NULL));

    int array[100];
    int size = ReadPositiveNumber();
    
    FillArrayWithRandomElements(array,size);

    cout << "Array elements: \n";
    PrintArray(array, size);

    cout<<"Positive numbers count is: "<<PositiveCount(array,size)<<"\n";

    return 0;
}