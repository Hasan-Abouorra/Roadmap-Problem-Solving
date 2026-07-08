#include <iostream>
#include <cstdlib> // Include cstdlib for rand() and srand() functions.
#include <ctime>   // Include ctime for the time() function, used for seeding the random number generator.
#include <cmath>

using namespace std;

int ReadNumber(string message = "Please enter a number ? ")
{
    int number = 0;

    cout << message << "\n";
    cin >> number;

    return number;
}

int MyABS(int number)
{
    return number < 0 ? number * -1 : number;
}

int main()
{
    int number = ReadNumber();
    cout << "My abs Result : " << MyABS(number) << "\n";
    cout << "C++ abs Result : " << abs(number) << "\n";
    return 0;
}