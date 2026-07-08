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

int MyRound(float number)
{
    return 
    number < 0 ? (number - (int)number) >= -0.5 ? number : number-1 
    : 
    (number - (int)number) >= 0.5 ? (int)number + 1 : number;
}

//alternative solution

// Function: GetFractionPart
// Purpose: Extracts the fractional part of a floating-point number.
// Parameters:
//   - Number: A floating-point number.
// Returns: The fractional part of the input number.
float GetFractionPart(float Number)
{
    // Subtract the integer part of the number from the original number to get the fractional part.
    return Number - int(Number);
}

// Function: MyRound
// Purpose: Rounds a floating-point number to the nearest integer.
// Parameters:
//   - Number: A floating-point number to be rounded.
// Returns: The rounded integer value of the input number.
//int MyRound(float Number)
//{
//    int IntPart;  // Variable to store the integer part of the number.
//    IntPart = int(Number);  // Extract the integer part.

//    // Compute the fractional part using the GetFractionPart function.
//    float FractionsPart = GetFractionPart(Number);

//    // If the absolute value of the fractional part is 0.5 or more, round the number accordingly.
//    if (abs(FractionsPart) >= 0.5)
//    {
//        // If the number is positive, round up.
//        if (Number > 0)
//            return ++IntPart;  
//        // If the number is negative, round down.
//        else
//            return --IntPart;
//    }
//    else
//    {
//        // If the fractional part is less than 0.5, keep the integer part as is.
//        return IntPart;
//    }
//}

int main()
{
    
    float number = ReadNumber();
    cout << "My round Result : " << MyRound(number) << "\n";
    cout << "C++ round Result : " << round(number) << "\n";
    return 0;
}