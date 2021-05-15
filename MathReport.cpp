/* course: CS216-00x
 * Project: Lab 6 (as part of Project 1)
 * Purpose: Provide the implementation of member functions for  the class named MathReport
 * Author: (your name)
 */

#include <iostream>
#include <iomanip>
#include "MathReport.h"

using namespace std;

// default constructor
MathReport::MathReport()
{
    numCorrectAnswers = 0; //Sets the number of correct answers to 0
    numWrongAnswers = 0;  //Sets the number of wrong answers to 0
    mathQuestions.clear(); //Sets the vector mathQuestions to empty
}

// add a MathOperations object into the vector named mathQuestions
// and the response to check with the correct answer: 
//    if response is correct, increase numCorrectAnswers
//    otherwise, increase numWrongAnswers
void MathReport::insert(MathOperations newQuestion, int response)
{
    mathQuestions.push_back(newQuestion); //Adds a new MathOperations object into the vector mathQuestions
    if (response == newQuestion.getAnswer()) //Increase the number of correct answers if the answer is correct
        numCorrectAnswers++;
    else // Increase the number of incorrect answers if the answer is incorrect
        numWrongAnswers++;
}

// return the value of numCorrectAnswers
int MathReport::getNumOfCorrectAnswers() const
{
    return numCorrectAnswers; //returns the number of correct answers
}

// return the value of numWrongAnswers
int MathReport::getNumOfWrongAnswers() const
{
    return numWrongAnswers; //returns the number of wrong answers
}

// generate a brief report:
//   the total number of math problems has been solved;
//   the list of math problems solved with correct answers
//   the total number of correctly answered questions
//   the toal number of questions with wrong answers
//   if numCorrectAnswers > numWrongAnswers, display message of "Great job!"
//   otherwise display message of "You will do better next time..."
void MathReport::generateReport() const
{
    cout << "Total Number of Questions: " << mathQuestions.size() << endl; //Prints the total amount of questions
    for (int i = 0; i < mathQuestions.size(); i++){ //Prints each questions and the correct answer
        cout << "Question: " << i + 1 << endl;
        mathQuestions[i].print();
        cout << setw(6) << right << mathQuestions[i].getAnswer() << endl << endl;
    }
    cout << "----------------------------" << endl;
    cout <<"Number of Correct Answers: " << getNumOfCorrectAnswers() << endl; //Prints the number of correct answers
    cout << "Number of Incorrect Answers: " << getNumOfWrongAnswers() << endl; //Prints the number of wrong answers
    if (numCorrectAnswers > numWrongAnswers) 
        cout << "Great job!" << endl; //Prints a message if the number of correct answers is greater than the wrong answers
    else
        cout << "You will do better next time..." << endl; //Prints a message if the number of wrong answers is greater than the number of correct answers
}
