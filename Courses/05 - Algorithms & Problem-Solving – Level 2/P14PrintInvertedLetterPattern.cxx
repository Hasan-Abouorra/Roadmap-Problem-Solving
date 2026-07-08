#include <iostream>
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

void PrintInvertedLetterPattern(int number)
{
    for (int i = number; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
            cout << char('A' + i - 1);//65
        cout << "\n";
    }
}

//other solution
void PrintInvertedLetterPattern(int Number)
{
    cout << "\n";  // Print an empty line for formatting.
  
    // Outer loop: 'i' represents the ASCII code for the current letter.
    // It starts at (65 + Number - 1) which is the highest letter to be printed,
    // and decrements down to 65 ('A').
    for (int i = 65 + Number - 1; i >= 65; i--)
    {
        // Calculate the number of times to print the current letter.
        // When i = 65 + Number - 1, (65 + Number - 1 - i) equals 0,
        // so the inner loop runs 'Number' times.
        // For each subsequent row, this value increases, reducing the count by 1 each time.
        for (int j = 1; j <= Number - ((65 + Number - 1) - i); j++)
        {
            cout << char(i);  // Print the current letter (converted from its ASCII code).
        }
      
        cout << "\n";  // After printing the current row, move to the next line.
    }}

int main()
{
    int number = 0;
    do{
    	    number=ReadPositiveNumber();
    	    PrintInvertedLetterPattern(number);
    	}
    	while(number>0);

    return 0;
}