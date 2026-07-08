#include <iostream>

using namespace std;

//c++2
//9
void CheckNumberIfZeroOrPositiveOrNegative(int number)
{
    string result = number == 0 ? "Zero" : number < 0 ? "Negative" : "Positive";
    cout << number << " is " << result << "\n";
}



int main()
{
    
    int number = 5;
    CheckNumberIfZeroOrPositiveOrNegative(number);
    
    return 0;
}