#include <iostream>
#include "MyFunctions.h"
using namespace std;
/*
Student Name: Johany Acebal
• Date: 07/07/2022
• Program Name: Project 2
• Description: Program to calculate the mathematical functions of power, e ^ x, and sine
*/
// define a function to display the functions
void menuOptions(){
    int option;
    do{
        cout<<"\nMath Functions";
        cout<<"\n##########################################################################################################";
        cout<<"\n1. Power";
        cout<<"\n2. e^x";
        cout<<"\n3. Sine (x)";
        cout<<"\n4. Quit";
        cout<<"\nOption: ";
        cin>>option;
        int terminate=0;
        switch(option){
            case 1:
                double base;
                int exponent;
                cout<<"\nEnter a base: ";
                cin>>base;
                cout<<"\nEnter an exponent: ";
                cin>>exponent;
                cout<<"\n"<<base<<" ^ "<<exponent<<" = "<<mypow(base, exponent);
                break;
            case 2:
                int x;
                int n;
                cout<<"\nEnter a value integer for x: ";
                cin>>x;
                cout<<"\nNumber of terms for series e^x: ";
                cin>>n;
                cout<<"\ne ^ "<<x<<" = "<<exponential(x,n);
                break;
            case 3:
                int x2;
                int n2;
                cout<<"\nEnter a value for x in degrees: ";
                cin>>x2;
                cout<<"\nNumber of terms for series sin(x): ";
                cin>>n2;
                cout<<"\nsin( "<<x<<" ) = "<<sine(x2,n2);
                break;
            case 4:
                terminate=1;
                break;
            default:
                break;
        }
        if (terminate==1){//break out of the loop
            break;
        }
    }
    while(true);
}
int main(){
    //call the menuOption function
    menuOptions();
    return 0;
}

