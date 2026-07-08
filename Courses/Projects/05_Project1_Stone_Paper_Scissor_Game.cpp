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

enum enWinner
{
    Player1 = 1,
    Computer = 2,
    Draw = 3
};

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResults
{
    short Rounds = 0;
    short Player = 0;
    short Computer = 0;
    short Draws = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

string ChoiceName(enGameChoice Choice)
{
    string arrGameChoices[3] = {"Stone", "Paper", "Scissorss"};
    return arrGameChoices[Choice - 1];
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = {"Player1", "Computer", "No Winner (Draw)"};
    return arrWinnerName[Winner - 1];
}

void ScreenColor(enWinner Winner)
{
    if (Winner == Player1)
        system("color 20");
    if (Winner == Computer)
        system("color 40");
    if (Winner == Draw)
        system("color 60");
}

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

enGameChoice ReadPlayerChoice(string message = "Your Choice: [1] :Stone,  [2] :Paper,  [3] :Scissorss ? ")
{
    int number = 0;
    do
    {
        cout << message;
        cin >> number;
        cout << "\n\n";
    } while (number < 1 || number > 3);

    return (enGameChoice)number;
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes)
        return enWinner::Player1;

    else if (Player1WinTimes < ComputerWinTimes)
        return enWinner::Computer;

    else
        return enWinner::Draw;
    ;
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
    cout << "\t\t\t\tFinal Winner\t\t\t:" << GameResults.WinnerName << "\n";
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

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    // If both choices are the same, it's a draw.
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
        return enWinner::Draw;

    // Determine the winner based on game rules.
    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        return (RoundInfo.ComputerChoice == enGameChoice::Paper) ? enWinner::Computer : enWinner::Player1;
    case enGameChoice::Paper:
        return (RoundInfo.ComputerChoice == enGameChoice::Scissors) ? enWinner::Computer : enWinner::Player1;
    case enGameChoice::Scissors:
        return (RoundInfo.ComputerChoice == enGameChoice::Stone) ? enWinner::Computer : enWinner::Player1;
    }
}

void PrintRoundResult(stRoundInfo RoundInfo)
{
    cout << "__________Round [" << RoundInfo.RoundNumber << "] __________\n\n";
    cout << "Player1 Choice:\t" << ChoiceName(RoundInfo.Player1Choice) << "\n";

    cout << "Computer Choice:" << ChoiceName(RoundInfo.ComputerChoice) << "\n";

    cout << "RoundWinner:\t[" << RoundInfo.WinnerName << "]\n";
    cout << "_____________________________\n\n";
}

stGameResults PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;

    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "Round [" << GameRound << "] \a begins:\n\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayerChoice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        ScreenColor(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player1)
            Player1WinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        PrintRoundResult(RoundInfo);
    }

    return {
        HowManyRounds,
        Player1WinTimes,
        ComputerWinTimes,
        DrawTimes,
        WhoWonTheGame(Player1WinTimes, ComputerWinTimes),
        WinnerName(WhoWonTheGame(Player1WinTimes, ComputerWinTimes))};
}

void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        system("cls");

        stGameResults GameResults = PlayGame(ReadHowManyRounds());

        ShowFinalGameResults(GameResults);

        cout << "Do you want to play again ? Y/N  ";
        cin >> PlayAgain;
        cout << "\n\n";
    } while (PlayAgain == 'y' || PlayAgain == 'Y');
}
int main()
{
    srand((unsigned)time(NULL));
    StartGame();

    return 0;
}