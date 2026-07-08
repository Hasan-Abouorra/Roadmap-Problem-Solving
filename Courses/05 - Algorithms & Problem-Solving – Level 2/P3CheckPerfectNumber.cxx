#include <iostream>

using namespace std;

enum enPerfectNotPerfect{
Perfect =1,
NotPerfect = 0
};
 
int SumAllDivisorsOfN(int number){
	
	int N = number /2;
	int sum =0;
	for(int i =1; i<=N; i++ ){
		if(number%i==0)
		 sum+=i;
	}
	return sum;
}

enPerfectNotPerfect CheckPerfect(int number){
	if(SumAllDivisorsOfN(number)== number)
	 return enPerfectNotPerfect::Perfect;
	 
	 return enPerfectNotPerfect::NotPerfect;
	 
	 
	
}

void PrintPerfectNumbers(int number){
	if(CheckPerfect(number)==enPerfectNotPerfect::Perfect)
	 cout<<number<<" is perfect.\n";
	 else
	 cout<<number<<" is not perfect.\n";
	 
}

int main()
{
	PrintPerfectNumbers(28);
	PrintPerfectNumbers(12);
	
	
}