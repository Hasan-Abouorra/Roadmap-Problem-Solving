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

enum enPerfectNotPerfect
{
	Perfect = 1,
	NotPerfect = 0
};

int SumAllDivisorsOfN(int number)
{
	int N = number / 2;
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		if (number % i == 0)
			sum += i;
	}
	return sum;
}

enPerfectNotPerfect CheckPerfect(int number)
{
	if (SumAllDivisorsOfN(number) == number)
		return enPerfectNotPerfect::Perfect;

	return enPerfectNotPerfect::NotPerfect;
}

void PrintAllPerfectNumbersUntilN(int N)
{
	for (int i = 1; i <= N; i++)
	{
		if (CheckPerfect(i) == enPerfectNotPerfect::Perfect)
			cout << i << "\n";
	}
}6

int main()
{
	PrintAllPerfectNumbersUntilN(ReadPositiveNumber());
}