// Project 1 - CS 116 - Fall 2024 - Jean Paul Collazo Arguedas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Project 1 completed by Jean Paul Collazo Arguedas - CS 116 - Fall 2024.

#include <iostream>
#include <string>  // Including <string> to use to_string function

using namespace std;

/*
This function is returning a float and is taking a string as its input parameter.
I am using this to get user input.
*/
float requestAFloat(const string& msg)
{
    float input;
    // I am asking the user to input a value with the provided message.
    cout << msg;
    cin >> input;
    // I am returning the float to the function that called this one.
    return input;
}

double calculateAverageProjectPercentage()
{
    // Declaring my variables within this function.
    double result;
    float project1, project2, project3, project4;

    /* Initializing each project grade by asking the user for input */
    project1 = requestAFloat("Please enter the grade for Project 1 (out of 10) followed by the enter key: ");
    project2 = requestAFloat("Please enter the grade for Project 2 (out of 10) followed by the enter key: ");
    project3 = requestAFloat("Please enter the grade for Project 3 (out of 10) followed by the enter key: ");
    project4 = requestAFloat("Please enter the grade for Project 4 (out of 10) followed by the enter key: ");

    // I am calculating the average by summing all grades and dividing by the number of projects.
    result = (project1 + project2 + project3 + project4) / 4;

    // I am returning the result.
    return result;
}

double calculateAverageCengageHomework()
{
    double result;
    float homework[7];

    // Initializing each homework grade by prompting the user for input.
    for (int i = 0; i < 7; i++) {
        homework[i] = requestAFloat("Please enter the grade for Homework " + to_string(i + 1) + " (out of 10): ");
    }

    // I am calculating the average by summing all grades and dividing by the number of homework assignments.
    result = (homework[0] + homework[1] + homework[2] + homework[3] + homework[4] + homework[5] + homework[6]) / 7;

    return result;
}

double calculateAverageMidtermPercentage()
{
    // Declaring the variables within this function.
    double result;
    float midterm1, midterm2;

    /* Initializing each midterm grade by prompting the user for input. */
    midterm1 = requestAFloat("Please enter the grade for Midterm 1 (out of 40) followed by the enter key: ");
    midterm2 = requestAFloat("Please enter the grade for Midterm 2 (out of 40) followed by the enter key: ");

    // I am calculating the average by summing both midterms and dividing by 2.
    result = (midterm1 + midterm2) / 2;

    return result;
}

double calculateAverageQuizPercentage()
{
    double result;
    float quiz[6];

    // Initializing each quiz grade by asking the user for input.
    for (int i = 0; i < 6; i++) {
        quiz[i] = requestAFloat("Please enter the grade for Quiz " + to_string(i + 1) + " (out of 10): ");
    }

    // I am calculating the average by summing all quiz grades and dividing by the number of quizzes.
    result = (quiz[0] + quiz[1] + quiz[2] + quiz[3] + quiz[4] + quiz[5]) / 6;

    return result;
}

double calculateGrade(double midtermsAverage, double quizzesAverage, double projectsAverage, double homeworkAverage)
{
    // Calculating the total percentage based on weighted values:
    // 40% for midterms, 15% for quizzes, 30% for projects, and 15% for homework.
    // Normalizing each component to its weight in the grading system.

    double midtermScore = (midtermsAverage / 40) * 40; // Midterms contribute 40%
    double quizScore = (quizzesAverage / 10) * 15;     // Quizzes contribute 15%
    double projectScore = (projectsAverage / 10) * 30; // Projects contribute 30%
    double homeworkScore = (homeworkAverage / 10) * 15; // Homework contributes 15%

    double result = midtermScore + quizScore + projectScore + homeworkScore;

    return result;
}

int main()
{
    double gradeTotal, midtermAverage, homeworkAverage, quizzesAverage, projectsAverage;

    // Starting the program by explaining its purpose.
    cout << "Hello, the purpose of this program is to calculate your grade percentage!\n";

    // Calling functions to get each grade component average.
    midtermAverage = calculateAverageMidtermPercentage();
    quizzesAverage = calculateAverageQuizPercentage();
    projectsAverage = calculateAverageProjectPercentage();
    homeworkAverage = calculateAverageCengageHomework();

    // Calculating the total grade percentage by calling calculateGrade.
    gradeTotal = calculateGrade(midtermAverage, quizzesAverage, projectsAverage, homeworkAverage);

    // Displaying the total grade percentage.
    cout << "Your total grade percentage in the class is " << gradeTotal << "%!\n";

    return 0;
}
