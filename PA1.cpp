//CS216 - 002
//Taylor Smith
//Project 1


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include"MathOperations.h"
#include"MathReport.h"

using namespace std;
int main() {

srand(time(0));

int userOption; //Creates variable the user's option
MathReport report; //The user's report

while (userOption != 4) { //Repeats the program until the user enters 4 to quit

int num1; //The first number
int num2; //The second number
int answer; //The answer to the question
MathOperations question; //Makes a question for the user to solve

cout << "        Math Tutor   " << endl;
cout << "-------------------------" << endl;
cout << "1. Addition problem" << endl; //Displays the menu of options
cout << "2. Subtraction problem" << endl;
cout << "3. Multiplication problem" << endl;
cout << "4. Quit this program" << endl;
cout << "-------------------------" << endl;
cout << "Enter an option (1-4): ";
cin >> userOption; //Allows the user to input their option
cin.ignore(256,'\n');

while (cin.fail() || (userOption != 1 && userOption != 2 && userOption != 3 && userOption != 4)) { //Continually asks the user to input a value if the value they inputed is not (1-4)
    if (cin.fail()){
        cin.clear();
        cin.ignore(256,'\n');
        }
    else 
        cin.clear();
    cout << "Invalid input please choose an option (1-4): ";
    cin >> userOption;
    cin.ignore(256,'\n');
}


if (userOption == 1) { //Does an addition problem if the user inputs a 1
    num1 = 1 + rand() % 500; //Creates a number from 1 - 500
    num2 = 1 + rand() % 500; //Creates a number from 1 - 500
    question.setOperands(num1,num2); //Sets the operand for the question
    question.Addition(); //Creates an addition question
    question.print(); //Prints the question on the screen
    cout << "Your answer is: "; //Asks the user to input their answer
    cin >> answer;
    cin.ignore(256,'\n');
    while (cin.fail()){ //Checks to see if the users answer is valid
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Invalid input please try again" << endl; //Asks the user to input their answer
        cout << "Your answer is: ";
        cin >> answer;
        cin.ignore(256,'\n');
    }
    if (question.checkAnswer(answer))  //If the answer is correct a message will appear
        cout << "Congratulations! " << answer << " is the correct answer" << endl;
    else //if the answer is incorrect a message will appear
        cout << "Sorry the correct answer is " << question.getAnswer() << endl;

    report.insert(question, answer); //Adds the question and the students answer to the report
}

else if (userOption == 2) { //Does a subtraction problem if the user inputs a 2
    num1 = 1 + rand() % 500; //Creates a number from 1 - 500
    num2 = 2 + rand() % 500; //Creates a number from 1 - 500
    if (num2 > num1) { //Checks to see if the second number is greater than the first. If the so the numbers are swapped
        int temp = num2; //Creates a temporary number and sets it to num2
        num2 = num1;
        num1 = temp; 
    }
    question.setOperands(num1,num2); //Sets the operand for the question
    question.Subtraction(); //Creates a subtraction question
    question.print(); //Prints the question on the screen
    cout << "Your answer is: "; //Asks the user to input their answer
    cin >> answer;
    cin.ignore(256,'\n');
    while (cin.fail()){ //Checks to see if the users answer is valid
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Invalid input please try again" << endl;
        cout << "Your answer is: "; //Asks the user to input their answer
        cin >> answer;
        cin.ignore(256,'\n');
    }
    if (question.checkAnswer(answer)) //If the answer is correct a message will appear
         cout << "Congratulations! " << answer << " is the correct answer" << endl;
    else //If the answer is incorrect a message will appear
        cout << "Sorry the correct answer is " << question.getAnswer() << endl;

    report.insert(question, answer); //Adds the question and the students answer to the report
}
 
else if (userOption == 3) { //Does a multiplication problem if the user inputs a 3
    num1 = 1 + rand() % 100; //Creates a number from 1 - 100
    num2 = 1 + rand() % 9; //Creates a number from 1 - 9
    question.setOperands(num1,num2); //Sets the operand for the question
    question.Multiplication(); //Creates a multiplication question
    question.print(); //Prints the question on the screen
    cout << "Your answer is: "; //Asks the user to input their answer
    cin >> answer;
    cin.ignore(256,'\n');
    while (cin.fail()){ //Checks to see if the users answer is valid
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Invalid input please try again" << endl;
        cout << "Your answer is: "; //Asks the user to input their answer
        cin >> answer;
        cin.ignore(256,'\n');
     }
    if (question.checkAnswer(answer)) //If the answer is correct a message will appear
         cout << "Congratulations! " << answer << " is the correct answer" << endl;
    else //If the answer is incorrect a message will appear
        cout << "Sorry the correct answer is " << question.getAnswer() << endl;
    
    report.insert(question, answer); //Adds the question and the students answer to the report
}

}
report.generateReport(); //Generates a report of all the users questions
cout << "Thank you for using Math Tutor" << endl; //Prints a message to the user
return 0;
}
