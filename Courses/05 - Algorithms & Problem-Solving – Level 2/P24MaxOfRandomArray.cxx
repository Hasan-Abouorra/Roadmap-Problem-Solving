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

enum enCharType
{
    smallLetter = 1,
    capitalLetter,
    specialLetter,
    digit

};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

char GetRandomChar(enCharType ch)
{
    switch (ch)
    {
    case enCharType::smallLetter:
        return char(RandomNumber(97, 122));

    case enCharType::capitalLetter:
        return char(RandomNumber(65, 90));

    case enCharType::specialLetter:
        return char(RandomNumber(33, 38));
        break;

    case enCharType::digit:
        return char(RandomNumber(48, 57));
    }
}

void ReadArrayElements(int array[100], int size)
{
    cout << "Enter array elements:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Element[" << i+1 << "]: ";
        cin >> array[i];
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


int MaxNumberInArray(int array[100], int size){
    int maxNumber=0;
    for (int i = 0; i < size; i++)
    {
        if(array[i]>maxNumber)
         maxNumber=array[i];
        
            
    }
    return maxNumber;
    
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
     cout<<"Max Number is: "<<MaxNumberInArray(array,size)<<"\n";
   

    return 0;
}