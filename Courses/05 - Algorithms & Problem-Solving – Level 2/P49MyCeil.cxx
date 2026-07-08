#include <iostream>
#include <cstdlib> // Include cstdlib for rand() and srand() functions.
#include <ctime>   // Include ctime for the time() function, used for seeding the random number generator.
#include <cmath>

using namespace std;


float ReadNumber(string message = "Please enter a number ? ")
{
    float number = 0;

    cout << message << "\n";
    cin >> number;

    return number;
}


int MyCeil(float number)
{
    return 
    number < 0 ? (number - (int)number) == 0 ? number : number
    : 
    (number - (int)number) == 0 ? number  : number+1;
}

int main()
{
   
    float number = ReadNumber();
    cout << "My ceil Result : " << MyCeil(number) << "\n";
    cout << "C++ ceil Result : " << ceil(number) << "\n";
    return 0;
}