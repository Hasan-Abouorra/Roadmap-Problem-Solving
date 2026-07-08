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


int SumOfArray(int array[100], int size){
    int sum=0;
    for (int i = 0; i < size; i++)
    {
        sum+=array[i];
            
    }
    
    return sum;
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
     cout<<" Sum of all numbers is: "<<SumOfArray(array,size)<<"\n";
   

    return 0;
}