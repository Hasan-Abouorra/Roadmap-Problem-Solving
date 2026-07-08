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


void PrintAllWordsZA(){ 
for(int a='Z'; a>='A'; a--)
for(int b='Z'; b>='A'; b--)
for(int c='Z'; c>='A'; c--)
cout<<char(a)<<char(b)<<char(c)<<"\n";
}

int main()
{
	PrintAllWordsZA();

	return 0;
}