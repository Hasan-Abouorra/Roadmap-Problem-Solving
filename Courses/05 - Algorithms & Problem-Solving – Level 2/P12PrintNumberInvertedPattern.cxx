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


void PrintInvertedNumberPattern(int number){
    for(int i=number; i>0; i--){
        for(int j=1; j<=i; j++)
         cout<<i;
        cout<<"\n";
        }
    
}

int main()
{
int number=0;
	do{
	    number=ReadPositiveNumber();
	    PrintInvertedNumberPattern(number);
	}
	while(number>0);

	return 0;
}