#include <iostream>
#include <cstdlib> // Include cstdlib for rand() and srand() functions.
#include <ctime>   // Include ctime for the time() function, used for seeding the random number generator.
#include <cmath>

//struct pints
//
using namespace std;

enum enQuestionsLevel
{
    Easy = 1,
    Med,
    Hard,
    MIX

};

enum enOperationsType
{

    Add = 1,
    Sub,
    Mul,
    Div,
    Mix
};

struct stQuestion
{
    short QuestionsNumber = 0, Operand1 = 0, Operand2 = 0, Result = 0;
    enOperationsType OperationsType;
    enQuestionsLevel QuestionsLevel;
    bool RightAnswer;
};

struct stQuizz
{
    short NumberOfQuestions = 0, NumberOfRightAnswers = 0, NumberOfWrongAnswers = 0;
    enQuestionsLevel QuestionsLevel;
    enOperationsType OperationsType;
    bool Pass;
};

string QuestionsLevelName(enQuestionsLevel QuestionsLevel)
{
    string arrQuestionsLevel[4] = {"Easy", "Med", "Hard", "Mix"};
    return arrQuestionsLevel[QuestionsLevel - 1];
}

string OperationsTypeName(enOperationsType OperationsType)
{
    string arrOperationsType[5] = {"Add", "Sub", "Mul", "Div", "Mix"};
    return arrOperationsType[(int)OperationsType - 1];
}

string OperationsTypeSign(enOperationsType OperationsType)
{
    string arrOperationsType[5] = {"+", "-", "*", "/", "Mix"};
    return arrOperationsType[(int)OperationsType - 1];
}

void ScreenColor(stQuestion Question)
{
    if (Question.RightAnswer)
        system("color 20");
    else
        system("color 40");
}

short ReadHowManyQuestions(string message = "How many Questions do you want to answer ? \n")
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

enQuestionsLevel ReadPlayerLevel(string message = "Enter Questions Level: [1] :Easy,  [2] :Med,  [3] :Hard,  [4] :Mix  ? ")
{
    int number = 0;
    do
    {
        cout << message;
        cin >> number;
        cout << "\n\n";
    } while (number < 1 || number > 4);

    return (enQuestionsLevel)number;
}

enOperationsType ReadPlayerType(string message = "Enter Operations Type: [1] Add,  [2] Sub,  [3] :Mul,  [4] :Div  [5] :Mix  ? ")
{
    int number = 0;
    do
    {
        cout << message;
        cin >> number;
        cout << "\n\n";
    } while (number < 1 || number > 5);

    return (enOperationsType)number;
}

bool IsTheAnswerRight(stQuestion Question)
{
    short Answer;
    cout << Question.Operand1 << "\n"
         << Question.Operand2 << " " << OperationsTypeSign(Question.OperationsType) << "\n"
         << "______________________\n";
    cin >> Answer;
    return Answer == Question.Result;
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

bool PassTheQuestions(short NumberOfRightAnswers, short NumberOfWrongAnswers)
{
    return NumberOfRightAnswers >= NumberOfWrongAnswers;
}

void PrintGameOverHeader(bool Pass)
{
    string Result = Pass ? "PASS : - )" : " FAIL : - )";
    cout << "____________________________________________\n\n"
         << "\tFinal Results is " << Result << "\n"
         << "____________________________________________\n\n";
    //   << "______________  [Game Results ]_____________\n\n";
}
void ShowFinal(stQuizz )
{
    PrintGameOverHeader(.Pass);
    cout << "Number Of Questions:\t" << .NumberOfQuestions << "\n";
    cout << "Questions Level:\t" << QuestionsLevelName(.QuestionsLevel) << "\n";
    cout << "OpType:\t\t\t" << OperationsTypeName(.OperationsType) << "\n";
    cout << "Number Of Right Answers:" << .NumberOfRightAnswers << "\n";
    cout << "Number Of Wrong Answers:" << .NumberOfWrongAnswers << "\n";
    cout << "____________________________________________\n\n";
}

void FillQuestion(stQuestion &Question, short From, short To)
{
    Question.Operand1 = RandomNumber(From, To);
    Question.Operand2 = RandomNumber(From, To);

    if (Question.OperationsType == (enOperationsType)Mix)
        Question.OperationsType = (enOperationsType)RandomNumber(1, 4);

    if (Question.OperationsType == Add)
        Question.Result = Question.Operand1 + Question.Operand2;

    if (Question.OperationsType == Sub)
        Question.Result = Question.Operand1 - Question.Operand2;

    if (Question.OperationsType == Mul)
        Question.Result = Question.Operand1 * Question.Operand2;

    if (Question.OperationsType == Div)
        Question.Result = Question.Operand1 / Question.Operand2;
}

void FillQuestions(stQuestion Questions[100], short Length, enQuestionsLevel Level, enOperationsType Type)
{
    for (short Question = 0; Question < Length; Question++)
    {
        Questions[Question].QuestionsLevel = Level;
        Questions[Question].OperationsType = Type;

        if (Questions[Question].QuestionsLevel == Easy)
            FillQuestion(Questions[Question], 1, 10);

        if (Questions[Question].QuestionsLevel == Med)
            FillQuestion(Questions[Question], 10, 50);

        if (Questions[Question].QuestionsLevel == Hard)
            FillQuestion(Questions[Question], 50, 100);

        if (Questions[Question].QuestionsLevel == MIX)
            FillQuestion(Questions[Question], 1, 100);
    }
}

void PrintQuestionResult(stQuestion Question)
{
    if (Question.RightAnswer)
        cout << "Right Answer : - ) \n\n";
    else
        cout << "Wrong Answer : - ) \n\n";
}

stQuizz PlayMathGame(short HowManyQuestions)
{
    stQuestion Questions[100];
    enQuestionsLevel Level = ReadPlayerLevel();
    enOperationsType Type = ReadPlayerType();
    FillQuestions(Questions, HowManyQuestions, Level, Type);
    short RightAnswers = 0, WrongAnswers = 0;

    for (short Question = 0; Question < HowManyQuestions; Question++)
    {
        cout << "Question [" << Question + 1 << "/" << HowManyQuestions << "\n\n";

        Questions[Question].RightAnswer = IsTheAnswerRight(Questions[Question]);

        ScreenColor(Questions[Question]);

        if (Questions[Question].RightAnswer)
            RightAnswers++;
        else
            WrongAnswers++;

        PrintQuestionResult(Questions[Question]);
        cout << "The right answer is  " << Questions[Question].Result << "\n\n";
    }

    return {
        HowManyQuestions,
        RightAnswers,
        WrongAnswers,
        Level,
        Type,
        PassTheQuestions(RightAnswers, WrongAnswers)};
}

void StartMathGame()
{
    char PlayAgain = 'Y';

    do
    {
        system("cls");
        //system("color 0F");

        stQuizz  = PlayMathGame(ReadHowManyQuestions());

        ShowFinal();

        cout << "Do you want to play again ? Y/N  ";
        cin >> PlayAgain;
        cout << "\n\n";
    } while (PlayAgain == 'y' || PlayAgain == 'Y');
}
int main()
{
    srand((unsigned)time(NULL));
    StartMathGame();

    return 0;
}
