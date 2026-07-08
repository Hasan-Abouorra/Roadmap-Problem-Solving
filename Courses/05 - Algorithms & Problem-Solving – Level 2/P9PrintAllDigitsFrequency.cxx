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

int CountDigitFrequency(int number, int digit)
{
	int remainder = 0;
	int count = 0;
	do
	{
		remainder = number % 10;

		if (remainder == digit)
			count += 1;

		number = number / 10;
	} while (number > 0);
	return count;
}

bool CheckNumberInArray(int number, int array[50], int size)
{
	for (int i=0; i<=size; i++)
		if (array[i] == number)
			return true;
	return false;
}

void PrintAllDigitsFrequency(int Number)
{
	int prevDigit = 0;
	int digit = 0;
	int number = Number;
	int array[50] = {};
	int count = 0;
	do
	{
		digit = number % 10;
		number = number / 10;
		if (digit == prevDigit || CheckNumberInArray(digit, array,count))
			continue;
		prevDigit = digit;
		array[count] = digit;
		count++;
		cout << "\nDigit " << digit << " Frequency is " << CountDigitInNumber(Number, digit) << " Time(s)\ncount: "<<count;

	} while (number > 0);
} 


//other solution

void PrintAllDigitsFrequencey2(int Number)
{
    cout << endl;  // Print an empty line for formatting.
    
    // Loop through all digits from 0 to 9.
    for (int i = 0; i < 10; i++)
    { 
        short DigitFrequency = 0;                         // Variable to hold frequency for the current digit.
        DigitFrequency = CountDigitFrequency(i, Number);    // Get the frequency of digit 'i' in the number.
        
        // Only print the result if the digit appears at least once.
        if (DigitFrequency > 0)
        {
            cout << "Digit " << i << " Frequencey is "  // Print the digit and its frequency.
                 << DigitFrequency << " Time(s).\n";
        }
    }
}


//better solution
void PrintAllDigitsFrequency3(int Number)
{
    int freq[10] = {0};

    while (Number > 0)
    {
        int digit = Number % 10;
        freq[digit]++;
        Number /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        if (freq[i] > 0)
        {
            cout << "\nDigit " << i 
                 << " Frequency is " 
                 << freq[i] 
                 << " Time(s)\n";
        }
    }
}

int main()
{
	PrintAllDigitsFrequency(ReadPositiveNumber());
}