#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

/*
Student Name: Johany Acebal
Date: [07/15/2022]
Program Name: Project 3
Description: Program that automates the process of generating the final student report for MDC
faculty

*/

//declare a function to get Student IDs
void GetStudentID(int studID[]){
    int number=10;
    int minValue = 10000;
    int maxValue = 99999;
    for(int i=0;i<number;i++){
        int randomNumber = (rand() % (maxValue- minValue + 1)) + minValue;
        studID[i] = randomNumber;
    }
}

//declare a function to get student grades from the user
void GetInputGrades(int studGrade[])
{
    int number=10;
    //Ask for students grades.
    for (int index = 0; index < 10; index++)
    {
        do
        {
            cout << "Grade: ";
            cin >> studGrade[index];
        }
        while (studGrade[index] > 100 || studGrade[index] < 0);

    }
}
//declare a function to set grade letter
void SetGradeLetter(int studGrade[], char studGradeLetter[])
{
    //Process the student's grades and assign the letter that corresponds to the grade
    //in a new array (studGradeLetter)
    int number=10;
    for (int index = 0; index < number; index++)
    {
        if (studGrade[index] <= 100 && studGrade[index] >= 90) //90 - 100
            studGradeLetter[index] = 'A';
        else if (studGrade[index] <= 89 && studGrade[index] >= 80) //80-89
            studGradeLetter[index] = 'B';
        else if (studGrade[index] <= 79 && studGrade[index] >= 70) //70-79
            studGradeLetter[index] = 'C';
        else if (studGrade[index] <= 69 && studGrade[index] >= 60) //60-69
            studGradeLetter[index] = 'D';
        else if (studGrade[index] <= 59 && studGrade[index] >= 0) //0-59
            studGradeLetter[index] = 'F';

    }
}

//declare a function to get number of student per grade
void GetStudentsPerGrade(char studGradeLetter[]){
    int count_A=0;
    int count_B=0;
    int count_C=0;
    int count_D=0;
    int count_F=0;
    int number=10;
    for(int i=0;i<number;i++){
        if (studGradeLetter[i] == 'A'){
            count_A +=1;
        }

        else if (studGradeLetter[i] == 'B'){
            count_B +=1;
        }
        else if (studGradeLetter[i] == 'C'){
            count_C +=1;
        }
        else if (studGradeLetter[i] == 'D'){
            count_D +=1;
        }
        else if (studGradeLetter[i] == 'F'){
            count_F +=1;
        }

    }
    cout<<"\n\nGrade\t\t"<<"Total"<<endl;
    cout<<"A\t"<<"|\t"<<count_A<<endl;
    cout<<"B\t"<<"|\t"<<count_B<<endl;
    cout<<"C\t"<<"|\t"<<count_C<<endl;
    cout<<"D\t"<<"|\t"<<count_D<<endl;
    cout<<"F\t"<<"|\t"<<count_F<<endl;
}
//declare a function to get the total number of student approved or failed
void GetStudentApprFail(char studGradeLetter[]){
    int totalApproved=0;
    int totalFailed=0;
    int totalStudents=10;
    for(int i=0;i<totalStudents;i++){
        if (studGradeLetter[i]=='F'){
            totalFailed+=1;
        }
        else{
            totalApproved+=1;
        }
    }
    double totalApprovedPerc = (totalApproved* 100) / totalStudents;
    double totalFailedPerc = (totalFailed * 100) / totalStudents;
    cout<<"\nTotal number of student approved/failed in number and percentage: ";
    cout<<"\nTotal Approved\t|\t"<<totalApproved<<"\t|\t"<<totalApprovedPerc<<"%";
    cout<<"\nTotal Fail\t|\t"<<totalFailed<<"\t|\t"<<totalFailedPerc<<"%";
}
//declare a function to get the highest grade and display the details of the student (s) with the highest grade
void GetHighestGrade(int studID[],string studName[],int studGrade[],char studGradeLetter[]){
    int number=10;
    cout<<"\n\nStudent (s) with the highest grade:";
    cout<<"\n\nStudent ID\tName\tGrade";
    for (int index = 0; index < 10; index++)
    {
        if (studGradeLetter[index] == 'A')
            cout << "\n"<<studID[index] << "\t" << studName[index]<< "\t" << studGrade[index] << "\t" <<studGrade[index]<<" " <<studGradeLetter[index];
    }
}

//declare a function to get the average grade of the course
void GetAverage(int studGrade[]){
    int number=10;
    int sum=0;
    for(int i=0;i<number;i++){
        sum=sum+studGrade[i];
    }
    double average=sum/10.0;
    cout<<"\n\nThe general average of the course: ";
    cout<<"\nGeneral Average: "<<average;
}
int main(){
    srand(time(0));
    string studName[] = { "Adam", "Josue", "Carlos", "Frank", "Alison", "Adrian" , "Candy", "Steven", "Albert", "Alice" };
    int studID[10];
    GetStudentID(studID);
    int studGrade[10];
    GetInputGrades(studGrade);
    char studGradeLetter[10];
    SetGradeLetter(studGrade, studGradeLetter);
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<"\nStudent ID\tName\t\tGrade";

    int number=10;
    for(int i=0;i<number;i++){
        cout<<"\n"<<studID[i]<<"\t\t"<<studName[i]<<"\t\t"<<studGrade[i]<<" "<<studGradeLetter[i];
    }
    GetStudentsPerGrade(studGradeLetter);
    GetStudentApprFail(studGradeLetter);
    GetHighestGrade(studID,studName,studGrade,studGradeLetter);
    GetAverage(studGrade);
    return 0;

}


