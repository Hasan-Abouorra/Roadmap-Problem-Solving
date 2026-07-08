#include <iostream>
#include <cstdlib> // Include cstdlib for rand() and srand() functions.
#include <ctime>   // Include ctime for the time() function, used for seeding the random number generator.
#include <cmath>

//struct pints
//
using namespace std;

enum enGameChoice
{
    Stone = 1,
    Paper,
    Scissors
};

//enum enWinner
//{
//    Player1 = 1,
//    Computer = 2,
//    Draw = 3
//};

struct stGameResults
{
    short Rounds = 0;
    short Player = 0;
    short Computer = 0;
    short Draws = 0;
    //enWinner GameWinner;
    string WinnerName = "";
};

string ChoiceName(enGameChoice Choice)
{
    string arrGameChoices[3] = {"Stone", "Paper", "Scissorss"};
    return arrGameChoices[Choice - 1];
}

//string WinnerName(enWinner Winner)
//{
//    string arrWinnerName[3] = {"Player1", "Computer", "No Winner (Draw)"};
//    return arrWinnerName[Winner - 1];
//}

short ReadHowManyRounds(string message = "How many rounds ? \n")
{
    int number = 0;
    do
    {
        cout << message;
        cin >> number;
        cout << "\n";
    } while (number <= 0);

    return number;
}

short ReadPlayerChoice(string message = "Your Choice: [1] :Stone,  [2] :Paper,  [3] :Scissorss ? ")
{
    int number = 0;
    do
    {
        cout << message;
        cin >> number;
        cout << "\n\n";
    } while (number < 1 || number > 3);

    return number;
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

string DetermineGameWinner(stGameResults GameResults)
{
    if (GameResults.Player > GameResults.Computer)
        return "Player1";

    else if (GameResults.Player < GameResults.Computer)
        return "Computer";

    else
        return "No Winner";
}
void PrintGameOverHeader()
{
    cout << "\t\t\t\t____________________________________________\n\n"
         << "\t\t\t\t\t   +++ G a m e O v e r +++\n"
         << "\t\t\t\t____________________________________________\n\n"
         << "\t\t\t\t______________  [Game Results ]_____________\n\n";
}
void ShowFinalGameResults(stGameResults GameResults)
{
    PrintGameOverHeader();
    cout << "\t\t\t\tGame Rounds\t\t\t:" << GameResults.Rounds << "\n";
    cout << "\t\t\t\tPlayer1 won times\t\t:" << GameResults.Player << "\n";
    cout << "\t\t\t\tComputer won times\t\t:" << GameResults.Computer << "\n";
    cout << "\t\t\t\tDraw times\t\t\t:" << GameResults.Draws << "\n";
    cout << "\t\t\t\tFinal Winner\t\t\t:" << DetermineGameWinner(GameResults) << "\n";
    cout << "\t\t\t\t____________________________________________\n\n";
}

string DetermineChoice(enGameChoice choice)
{
    if (choice == 1)
        return "Stone";

    if (choice == 2)
        return "Paper";

    if (choice == 3)
        return "Scissors";
}

short DetermineRoundWinner(stGameResults GameResults, enGameChoice playerChoice, enGameChoice computerChoice)
{
    if ((enGameChoice)playerChoice == (enGameChoice)computerChoice)
    {
        GameResults.Draws++;
        return 0;
    }

    switch ((enGameChoice)playerChoice)
    {
    case Stone:
        if ((enGameChoice)computerChoice == Paper)
        {
            GameResults.Computer++;
            return 2;
        }
        else
        {
            GameResults.Player++;
            return 1;
        }

    case Paper:
        if ((enGameChoice)computerChoice == Scissors)
        {
            GameResults.Computer++;
            return 2;
        }
        else
        {
            GameResults.Player++;
            return 1;
        }
    case Scissors:
        if ((enGameChoice)computerChoice == Stone)
        {
            GameResults.Computer++;
            return 2;
        }

        else
        {
            GameResults.Player++;
            return 1;
        }
    }
}

string GetRoundWinner(stGameResults GameResults, enGameChoice playerChoice, enGameChoice computerChoice)
{
    int roundWinner = DetermineRoundWinner(GameResults, (enGameChoice)playerChoice, (enGameChoice)computerChoice);
    if (roundWinner == 0)
        return "No Winner";

    if (roundWinner == 1)
        return "Player1";

    if (roundWinner == 2)

        return "Computer";
}

void PrintRound(stGameResults GameResults, short playerChoice, short computerChoice)
{
    cout << "__________Round [" << GameResults.Rounds << "] __________\n\n";
    cout << "Player1 Choice:\t" << ChoiceName((enGameChoice)playerChoice) << "\n";

    cout << "Computer Choice:" << ChoiceName((enGameChoice)computerChoice) << "\n";

    cout << "RoundWinner:\t[" << GetRoundWinner(GameResults, (enGameChoice)playerChoice, (enGameChoice)computerChoice) << "]\n";
    cout << "_____________________________\n\n";
};

void GameRound(stGameResults &GameResults, short playerChoice)
{
    short computerChoice = RandomNumber(1, 3);

    GameResults.Rounds++;
    PrintRound(GameResults, playerChoice, computerChoice);

    if ((enGameChoice)playerChoice == (enGameChoice)computerChoice)
    {
        GameResults.Draws++;
        return;
    }

    switch ((enGameChoice)playerChoice)
    {
    case Stone:
        (enGameChoice) computerChoice == Paper ? GameResults.Computer++
                                               : GameResults.Player++;
        break;
    case Paper:
        (enGameChoice) computerChoice == Scissors ? GameResults.Computer++
                                                  : GameResults.Player++;
        break;
    case Scissors:
        (enGameChoice) computerChoice == Stone ? GameResults.Computer++
                                               : GameResults.Player++;
        break;
    }
}

void StartGame()
{
    char answer;
    do
    {
        system("cls");
        stGameResults GameResults;

        short rounds = ReadHowManyRounds();
        for (short i = 1; i <= rounds; i++)
        {
            cout << "Round [" << i << "] \a begins:\n\n";
            short choice = ReadPlayerChoice();
            GameRound(GameResults, choice);
        }
        ShowFinalGameResults(GameResults);

        cout << "Do you want to play again ? Y/N  ";
        cin >> answer;
        cout << "\n\n";
    } while (answer == 'y' || answer == 'Y');
}
int main()
{
    srand((unsigned)time(NULL));
    StartGame();

    return 0;
}