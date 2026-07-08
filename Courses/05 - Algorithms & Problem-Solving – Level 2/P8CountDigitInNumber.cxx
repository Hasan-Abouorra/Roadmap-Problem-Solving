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



int CountDigitInNumber(int number, int digit)
{
	int remainder=0;
	int count=0;
	while (number > 0)
	{
	    remainder = number % 10;
	    number = number / 10;
	    
	    if(remainder == digit)
	    count += 1;
	    
		
	} 
	return count;
}

int main()
{
	cout<<CountDigitInNumber(ReadPositiveNumber("Please enter the main number?"),ReadPositiveNumber("Please enter one digit to check?"))<<"\n";
}