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



int GetSumOfNumberDigits(int number)
{
	int sum=0;
	do
	{
		sum+= number % 10;
		number = number / 10;
	} while (number > 0);
	return sum;
}

int main()
{
	cout<<GetSumOfNumberDigits(ReadPositiveNumber())<<"\n";
}