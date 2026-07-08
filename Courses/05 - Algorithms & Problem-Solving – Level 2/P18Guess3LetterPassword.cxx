#include <iostream>
#include <cstdlib>
//#include <string>
using namespace std;


void Guess3LetterPassword(string password)
{
    string word="";
    int count=0;
    for (int a = 'A'; a <= 'Z'; a++)
        for (int b = 'A'; b <= 'Z'; b++)
            for (int c = 'A'; c <= 'Z'; c++)
            {count++;
                word += char(a);
                word += char(b);
                word += char(c);
                //cout<<word<<"\n";
                cout <<"Trail["<< ++count<<"] : "<< char(a) << char(b) << char(c) << "\n";

                if (word==password)
                {
                    cout << "Password is " << word << "\n";
                    cout<< "Found after "<<Counter<<" Trial(s)\n";
                    return;
                }
                else
                word="";
            }
}

int main()
{
    
   Guess3LetterPassword("BCD");


    return 0;
}