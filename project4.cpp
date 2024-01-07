
/*
• Student Name: [Johany Acebal]
• Date: [07/22/2022]
• Program Name: Project 4
• Description: Program that automates the process of generating the final student report for MDC
faculty

*/
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
using namespace std;

//define a function to fill the vectors
void fillVectors(string fileName, vector <string> &nameVec,vector <double> &scoreVec){
    ifstream studentsFile;
    studentsFile.open(fileName); // open the file
    string name; //declare a variable to store name
    double score;//declare a variable to store score
    while (studentsFile >> name >> score) // read one name and one score
    {
        nameVec.push_back(name); // add name to name vector
        scoreVec.push_back(score); // add score to score vector
    }
}
//define a function to return the average score in the score vector
double average(vector <double> const&scoreVec){
    if (scoreVec.empty()) {
        return 0; //return 0 if the score vector is empty
    }
    //calculate and return the average
    return accumulate(scoreVec.begin(), scoreVec.end(), 0.0) / scoreVec.size();
}
//define a function to display results
void displayResults(vector <string> &nameVec,vector <double> &scoreVec, double avg){
    //display result on the screen
    cout<<"\nGrade Average: "<<avg;
    cout<<"\nName\tGrade\tDifference";

    for(int i=0;i<nameVec.size();i++){
        double diff=scoreVec[i] - avg;
        cout<<"\n"<<nameVec[i]<<"\t"<<scoreVec[i]<<"\t"<<diff;
    }
    //display result in the output file
    ofstream outputFile("ResultAverage.txt");
    outputFile<<"\nGrade Average: "<<avg;
    outputFile<<"\nName\tGrade\tDifference";

    for(int i=0;i<nameVec.size();i++){
        double diff=scoreVec[i] - avg;
        outputFile<<"\n"<<nameVec[i]<<"\t\t"<<scoreVec[i]<<"\t\t"<<diff;
    }
}

int main()
{
    //input the name of the file from the user
    cout<<"\nEnter the name of the file: ";
    string fileName;
    cin>>fileName;
    //declare two vectors, nameVec and scoreVec
    vector<string> nameVec;
    vector<double> scoreVec;

    fillVectors(fileName,nameVec,scoreVec); //call the fillVectors() function
    //call the average() function and store the return value in a variable avg
    double avg=average(scoreVec);
    displayResults(nameVec,scoreVec,avg);// call the displayResults function

    return 0;
}


