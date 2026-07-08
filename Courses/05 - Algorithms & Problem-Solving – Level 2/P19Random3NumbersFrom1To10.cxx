#include <iostream>
#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
#include <ctime>      // Include ctime for the time() function, used for seeding the random number generator.

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

int RandomNumber(int From, int To)
{
    //srand((unsigned)time(NULL));

    return rand() % (To - From + 1) + From;
}

int main()
{
    srand((unsigned)time(NULL));

    cout << RandomNumber(1, 10) << "\n";
    cout << RandomNumber(1, 10) << "\n";
    cout << RandomNumber(1, 10) << "\n";

    //cout<<rand()%10+10<<"\t"<<rand()%100+1<<"\n";

    return 0;
}