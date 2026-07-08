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
    short QuestionsNumber = 0, Operand1 = 0, Operand2 = 0, PlayerAnswer = 0, RightAnswer = 0;
    enOperationsType OperationsType;
    enQuestionsLevel QuestionsLevel;
    bool IsRight;
};

struct stQuizz
{
    stQuestion QuestionList[100];
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
    if (Question.IsRight)
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

bool IsTheAnswerRight(stQuestion &Question)
{
    short Answer;
    cout << Question.Operand1 << "\n"
         << Question.Operand2 << " " << OperationsTypeSign(Question.OperationsType) << "\n"
         << "______________________\n";
    cin >> Answer;
    Question.PlayerAnswer = Answer;
    return Question.PlayerAnswer == Question.RightAnswer;
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
    string RightAnswer = Pass ? "PASS : - )" : " FAIL : - )";
    cout << "____________________________________________\n\n"
         << "\tFinal RightAnswers is " << RightAnswer << "\n"
         << "____________________________________________\n\n";
    //   << "______________  [Game RightAnswers ]_____________\n\n";
}
void PrintQuizzRightAnswers(stQuizz Quizz)
{
    PrintGameOverHeader(Quizz.Pass);
    cout << "Number Of Questions:\t" << Quizz.NumberOfQuestions << "\n";
    cout << "Questions Level:\t" << QuestionsLevelName(Quizz.QuestionsLevel) << "\n";
    cout << "OpType:\t\t\t" << OperationsTypeName(Quizz.OperationsType) << "\n";
    cout << "Number Of Right Answers:" << Quizz.NumberOfRightAnswers << "\n";
    cout << "Number Of Wrong Answers:" << Quizz.NumberOfWrongAnswers << "\n";
    cout << "____________________________________________\n\n";
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionsLevel, enOperationsType OperationsType, short From, short To)
{
    stQuestion Question;
    Question.Operand1 = RandomNumber(From, To);
    Question.Operand2 = RandomNumber(From, To);

    Question.QuestionsLevel = QuestionsLevel;
    Question.OperationsType = OperationsType;

    if (Question.OperationsType == (enOperationsType)Mix)
        Question.OperationsType = (enOperationsType)RandomNumber(1, 4);

    if (Question.OperationsType == Add)
        Question.RightAnswer = Question.Operand1 + Question.Operand2;

    if (Question.OperationsType == Sub)
        Question.RightAnswer = Question.Operand1 - Question.Operand2;

    if (Question.OperationsType == Mul)
        Question.RightAnswer = Question.Operand1 * Question.Operand2;

    if (Question.OperationsType == Div)
        Question.RightAnswer = Question.Operand1 / Question.Operand2;

    return Question;
}

void GenerateQuizzQuestions(stQuizz &Quizz)
{
    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {
        if (Quizz.QuestionsLevel == enQuestionsLevel::Easy)
            Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OperationsType, 1, 10);

        if (Quizz.QuestionsLevel == enQuestionsLevel::Med)
            Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OperationsType, 10, 50);

        if (Quizz.QuestionsLevel == enQuestionsLevel::Hard)
            Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OperationsType, 50, 100);

        if (Quizz.QuestionsLevel == enQuestionsLevel::MIX)
            Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OperationsType, 1, 100);
    }
}

void PrintQuestionRightAnswer(stQuestion Question)
{
    if (Question.IsRight)
        cout << "Right Answer : - ) \n\n";
    else
        cout << "Wrong Answer : - ) \n\n";
}

void AskAndCorrectQuestionListAnswers(stQuizz &Quizz)
{
    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {
        cout << "Question [" << Question + 1 << "/" << Quizz.NumberOfQuestions << "]\n\n";

        Quizz.QuestionList[Question].IsRight = IsTheAnswerRight(Quizz.QuestionList[Question]);

        ScreenColor(Quizz.QuestionList[Question]);

        if (Quizz.QuestionList[Question].IsRight)
            Quizz.NumberOfRightAnswers++;
        else
            Quizz.NumberOfWrongAnswers++;

        PrintQuestionRightAnswer(Quizz.QuestionList[Question]);
        cout << "The right answer is  " << Quizz.QuestionList[Question].RightAnswer << "\n\n";
    }
}

void PlayMathGame()
{
    short HowManyQuestions = ReadHowManyQuestions();
    stQuizz Quizz;

    stQuestion Questions[100];
    Quizz.NumberOfQuestions = HowManyQuestions;
    Quizz.QuestionsLevel = ReadPlayerLevel();
    Quizz.OperationsType = ReadPlayerType();
    GenerateQuizzQuestions(Quizz);
    AskAndCorrectQuestionListAnswers(Quizz);
    PrintQuizzRightAnswers(Quizz);
}

void StartMathGame()
{
    char PlayAgain = 'Y';

    do
    {
        system("cls");
        //system("color 0F");

        PlayMathGame();

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

//make the programm to end
//start ur BA abd make appoinments with ur prof
//start the next course+ the over next with the algorithmus
