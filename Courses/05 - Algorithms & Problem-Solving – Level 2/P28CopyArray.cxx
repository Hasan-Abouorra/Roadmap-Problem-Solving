 #include <iostream>
#include <cstdlib> // Include cstdlib for rand() and srand() functions.
#include <ctime>   // Include ctime for the time() function, used for seeding the random number generator.

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



void PrintArray(int array[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

    
    void CopyArray(int orginal[100], int copy[100], int size){
    for (int i = 0; i < size; i++)
    {
     copy[i]=orginal[i];
            
    }
    
    
    } 


void FillArrayWithRandomElements(int array[100], int size){
    for (int i = 0; i < size; i++)
    {
        array [i]=RandomNumber(1,100);
        }
    
    }





int main()
{
    srand((unsigned)time(NULL));

    //cout<<rand()%10+10<<"\t"<<rand()%100+1<<"\n";
    int array[100];
    int size = ReadPositiveNumber();
    FillArrayWithRandomElements(array,size);
    cout<<"Array Elements: "; PrintArray(array,size);
     int copy[100];
     CopyArray(array,copy,size);
     cout<<"Copied Array Elements: "; PrintArray(copy,size);
    return 0;
}