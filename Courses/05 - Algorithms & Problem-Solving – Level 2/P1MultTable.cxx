#include <iostream>
using namespace std;

void printHeading()
{
	cout << "\n\n\t\t\tMultiplication Table From 1 To 10\n\n";
	cout<<"\t";
	for (int i = 1; i <= 10; i++)
		cout << i<<"\t";

	cout << "\n";
}

void printSeparator()
{
	string sep(84,'_');
	cout << "\n"
		 << sep << "\n";
}

string columnSeprator(int i){
	if(i<10)
	  return "    |";
	 else
	  return"   |";
}

void printMultTable()
{
	printHeading();
	printSeparator();
	for (int i = 1; i <= 10; i++)
	{
		cout <<" "<< i << columnSeprator(i)<<"\t";
		for (int j = 1; j <= 10; j++)
		{
			cout << j * i<<"\t";
		}
		cout << "\n";
	}
}

int main()
{
	
	
	printMultTable();
}