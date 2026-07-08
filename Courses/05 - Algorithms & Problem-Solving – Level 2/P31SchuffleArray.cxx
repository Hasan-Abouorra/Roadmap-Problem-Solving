 #include <iostream>
#include <cstdlib> // Include cstdlib for rand() and srand() functions.
#include <ctime>   // Include ctime for the time() function, used for seeding the random number generator.
#include<cmath>

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



void Swap(int& A, int& B)
{
    int Temp;    // Temporary variable to hold the value of A.
    Temp = A;    // Save the value of A in Temp.
    A = B;       // Copy the value of B into A.
    B = Temp;    // Copy the value of Temp (original A) into B.
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

    


void FillArrayWithRandomElements(int array[100], int size){
    for (int i = 0; i < size; i++)
    {
        array [i]=RandomNumber(1,100);
        }
    
    }
    
    void FillArrayWithOrderd1ToNElements(int array[100], int size){
    for (int i = 0; i < size; i++)
    {
        array [i]=i+1;
        }
    
    }


    
    void SchuffleArray(int array[100], int size){
    
    
    for (int i = 0; i < size; i++)
    {
     Swap(array[RandomNumber(1,size)-1], array[RandomNumber(1,size)-1]);
            
    }
    
    

    }



int main()
{
    srand((unsigned)time(NULL));

    
    int array[100];
    int size = ReadPositiveNumber();
    
    FillArrayWithOrderd1ToNElements(array,size);
    cout<<"Array elements before schuffle: \n"; PrintArray(array,size);
 
     SchuffleArray(array,size);
     cout<<"Array elements after schuffle: \n"; PrintArray(array,size);
     
     
    return 0;
}