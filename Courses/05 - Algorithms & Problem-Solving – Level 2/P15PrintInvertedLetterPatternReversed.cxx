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


void PrintInvertedLetterPatternReversed(int number){
    for(int i=1; i<=number; i++){
        for(int j=1; j<=i; j++)
         cout<<char('A'+i-1);
        cout<<"\n";
        }
    
}

// other solution
void PrintLetterPattern(int Number)
{
    cout << "\n";  // Print an empty line for formatting.
   
    // Outer loop: Iterates from ASCII value 65 ('A') to (65 + Number - 1).
    // Each iteration corresponds to a row in the pattern.
    for (int i = 65; i <= 65 + Number - 1; i++)
    {
        // Inner loop: Determines the number of times to print the current letter.
        // The expression (i - 65 + 1) calculates the position of the letter in the alphabet,
        // which is also the number of times it should be repeated in the current row.
        for (int j = 1; j <= i - 65 + 1; j++)
        {
            cout << char(i);  // Convert the ASCII value to its corresponding character and print it.
        }
       
        cout << "\n";  // Move to the next line after printing the current row.
    }
}



int main()
{
int number=0;
	do{
	    number=ReadPositiveNumber();
	    PrintInvertedLetterPatternReversed(number);
	}
	while(number>0);

	return 0;
}