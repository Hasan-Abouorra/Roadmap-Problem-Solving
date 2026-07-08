#include <iostream>
#include <cstdio>
using namespace std;

//c++2
////19
void PrintNumbersFromMtoN(int M, int N)
{
    cout << M << "\n";
    if (M != N)
    {
        PrintNumbersFromMtoN(M - 1, N);
    }
}
////
int MyPower(int Base, int Power)
{
    /*
if(Power == 0)
return 1
else 
return (Base * CalculatePower(Base, Power - 1);)
*/

    if (Power != 0)
        return Base * MyPower(Base, Power - 1);
    return 1;
}


int main()
{
    
    PrintNumbersFromMtoN(10, 1);

    cout << "Ergebnis:  " << MyPower(2, 4) << "\n";
    printf("%0*d\n", 2, 4);
    
 
    return 0;
}