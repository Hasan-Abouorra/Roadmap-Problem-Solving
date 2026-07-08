#include <iostream>
#include <cmath>

using namespace std;

enum enPrimNotPrime { Prime = 1, NotPrime = 0 };

enPrimNotPrime CheckPrime(int Number){

int M = round(Number / 2);
for (int Counter = 2; Counter <= M; Counter++) 
{

if (Number % Counter == 0) 
return enPrimNotPrime::NotPrime;
}

return enPrimNotPrime::Prime;}


void PrintAllPrimeNumbersToN(int N)
{
	for(int i =1; i<=N; i++){
		if (CheckPrime(i)) { 
		  cout<<i<<"\n";}
		
	}
}

int main(){
	PrintAllPrimeNumbersToN(10);
}