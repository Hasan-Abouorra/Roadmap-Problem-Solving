#include <iostream>
#include <vector>
using namespace std;

//c++2
int ReadPositiveNumber(string message = "Please enter a positive number ? ")
{
    int number = 0;
    do
    {
        cout << message << "\n";
        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (number <= 0);

    return number;
}
////29
void ReadNumbers(vector<int> &vNumbers)
{
    char ReadMore = 'Y';
    int Number;
    while (ReadMore == 'Y' || ReadMore == 'y')
    {
        Number = ReadPositiveNumber("Enter a Number");
        vNumbers.push_back(Number);
        cout << "Do you want to add more? ";
        cin >> ReadMore;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    vector<int> vNumbers;
    ReadNumbers(vNumbers);

    for (int &v : vNumbers)
        cout << v << " ";
    cout << "\n-------------\n";

    cout << numeric_limits<streamsize>::max() << "\t" << numeric_limits<streamsize>::min() << flush << "\n";

    return 0;
}