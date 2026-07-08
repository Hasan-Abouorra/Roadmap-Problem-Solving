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
//int
double MySqrt(float number)
{
    //for (double i = 0.0; i < (number / 2); i++)
    //    {
    //        if(i*i==number)
    //        return i;
    //
    //    }=
    return pow(number, 0.5);
}

//Newton-Verfahren
//double MySqrt(double number)
//{
//    double guess = number / 2.0;
//    double epsilon = 0.00001; // Genauigkeit

//    while (abs(guess * guess - number) > epsilon)
//    {
//        guess = (guess + number / guess) / 2.0;
//    }

//    return guess;
//}

int main()
{
    float number = ReadNumber();
    cout << "My sqrt Result : " << MySqrt(number) << "\n";
    cout << "C++ sqrt Result : " << sqrt(number) << "\n";
    return 0;
}