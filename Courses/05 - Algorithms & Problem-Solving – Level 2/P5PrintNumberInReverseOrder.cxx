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

void PrintNumberInReversedOrder(int number)
{
	do
	{
		cout << number % 10 << "\n";
		number = number / 10;
	} while (number >= 10);
	cout<<number;
}

int main()
{
	PrintNumberInReversedOrder(ReadPositiveNumber());
}