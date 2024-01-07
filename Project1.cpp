/*
/*
	Student Name: Johany Acebal
	Date: 06/20/2022
	Program Name: Project 1
	Description: Program that changes the background color of the output screen

*/

#include <iostream>
using namespace std;

int main() {
    //declare three variables to store red, green, and blue values
    int red, green, blue;
    //get inputs from the user
    cout<<"Enter a value (0-255) for red color: ";
    cin>>red;
    cout<<"Enter a value (0-255) for green color: ";
    cin>>green;
    cout<<"Enter a value (0-255) for blue color: ";
    cin>>blue;

    //initialize values for color name, hexcode, and system code
    string colorName = "";
    string hexCode = "";
    int systemCode =-1;

    //check if the values entered are between 0 and 255
    if ((red<0 || red>255)||(green<0 || green>255)||(blue<0 || blue>255)){
        cout<<"\nInvalid values: Red: "<<red<<" Green: "<<green<<" Blue: "<<blue;
    }
    else{
        if (red == 0 && green ==0 && blue==0){
            colorName="Black";
            hexCode="#000000";
            systemCode=0;
            system("color 0");
        }
        else if (red == 255 && green ==255 && blue==255){
            colorName="White";
            hexCode="#FFFFFF";
            systemCode=7;
            system("color 70");
        }
        else if (red == 255 && green ==0 && blue==0){
            colorName="Red";
            hexCode="#FF0000";
            systemCode=4;
            system("color 40");
        }
        else if (red == 0 && green ==255 && blue==0){
            colorName="Lime";
            hexCode="#00FF00";
            systemCode=2;
            system("color 27");
        }
        else if (red == 0 && green ==0 && blue==255){
            colorName="Blue";
            hexCode="#0000FF";
            systemCode=1;
            system("color 10");
        }
        else if (red == 255 && green ==255 && blue==0){
            colorName="Yellow";
            hexCode="#FFFF00";
            systemCode=6;
            system("color 60");
        }
        else if (red == 0 && green ==255 && blue==255){
            colorName="Cyan/Aqua";
            hexCode="#00FFFF";
            systemCode=3;
            system("color 30");
        }
        else if (red == 128 && green ==128 && blue==128){
            colorName="Gray";
            hexCode="#808080";
            systemCode=8;
            system("color 80");
        }
        else if (red == 128 && green ==0 && blue==128){
            colorName="Purple";
            hexCode="#800080";
            systemCode=5;
            system("color 57");
        }

        if(systemCode==-1){
            cout<<"\nCorrect Values!";
            cout<<"\nColors System no defined.";
        }
        else{
            cout<<"\nCorrect Values!";
            cout<<"\nColor\t\tHex Code\t\tDecimal Code\t\tSystem Code\n";
            cout<<colorName<<"\t\t"<<hexCode<<"\t\t\t"<<"("<<red<<","<<green<<","<<blue<<")"<<"\t\t\t"<<systemCode;
        }
    }

    return 0;
}
