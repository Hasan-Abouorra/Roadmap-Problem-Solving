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

string GenerateWord(enCharType ch,int numberOfLetters){
    string word="";
     for(int i=1; i<=numberOfLetters; i++){
         word+=GetRandomChar(ch);
         
         }
    return word;
    }


string GenerateKey(int numberOfFields,int numberOfLetters) {
    string key="";
    int count=0;
    for(int i=1; i<=numberOfFields;i++){
        count++;
        key+= GenerateWord(enCharType::capitalLetter,numberOfLetters);
         if(count<numberOfFields)
         key+="-";
        }
    return key;
    
    }
    
    void GenerateKeys(int numberOfKeys=4){
        int numberOfFields=4;
        int numberOfLetters=4;
        for(int i=1; i<=numberOfKeys;i++){
            
            cout<<"Key["<<i<<"]: "<<GenerateKey(numberOfFields,numberOfLetters) <<"\n";
            }
        
        
        
        
        
        }

int main()
{
    srand((unsigned)time(NULL));

    GenerateKeys(ReadPositiveNumber());


    return 0;
} 