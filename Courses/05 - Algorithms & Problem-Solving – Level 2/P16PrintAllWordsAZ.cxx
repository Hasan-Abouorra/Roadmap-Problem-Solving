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


void PrintAllWordsAZ(){ 
for(int a='A'; a<='Z'; a++)
for(int b='A'; b<='Z'; b++)
for(int c='A'; c<='Z'; c++)
cout<<char(a)<<char(b)<<char(c)<<"\n";
}

int main()
{
	PrintAllWordsAZ();

	return 0;
}