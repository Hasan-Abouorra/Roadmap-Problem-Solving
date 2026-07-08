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


int MyFloor(float number)
{
    return 
    number < 0 ? (number - (int)number) == 0 ? number : number-1
    : 
    (number - (int)number) == 0 ? number  : number;
}

int main()
{
   
    float number = ReadNumber();
    cout << "My floor Result : " << MyFloor(number) << "\n";
    cout << "C++ floor Result : " << floor(number) << "\n";
    return 0;
}