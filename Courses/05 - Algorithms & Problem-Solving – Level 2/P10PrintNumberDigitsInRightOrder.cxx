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

int GetNumberReversed(int number)
{
	int remainder=0;
	int rev=0;
	do
	{
	    remainder = number % 10;
	    rev = rev * 10 + remainder;
		number = number / 10;
	} while (number > 0);
	return rev;
}
void PrintNumberInReversedOrder(int number)
{
	do
	{
		cout << number % 10 << "\n";
		number = number / 10;
	} while (number >0);
}

void PrintNumberDigitsInRightOrder(int number){
    number =GetNumberReversed(number);
    PrintNumberInReversedOrder(number);
}


int main()
{
	
	PrintNumberDigitsInRightOrder(ReadPositiveNumber());
}