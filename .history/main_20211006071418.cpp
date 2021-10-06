#include <iostream>
#include <iomanip>
#include <fstream>
#include <tuple>
using namespace std;


void getchoice()
{
    int ch;
    cout << "-----------------------------------------------------\n"
        << "|         Hello and Welcome to Our System           |\n"
        << "-----------------------------------------------------\n"
        << "| Please Enter from the choice given below          |\n"
        << "| Enter 1 to Create a New User Account              |\n"
        << "| Enter 2 to Login using existing User Account      |\n"
        << "| Enter 3 to Logout from your User Account          |\n"
        << "| Enter 4 to Delete any User Account                |\n"
        << "| Enter 5 TO Change your Password                   |\n"
        << "-----------------------------------------------------\n";

    cin >> ch;
    switch(ch)
    {
        case(1) : createuser();
                    break;
        case(2) : break;
        case(3) : break;
        case(4) : break;
        case(5) : break;

        default:
    }
    
}

void createuser()
{
    ifstream inputFile;
    inputFile.open("User.dat");

    if (!inputFile.is_open()){
        cout << " File not found\n";
        exit(-1);
    }
    else
    {
        cout << "-----------------------------------------------------\n"
            <<""
    }
}

int main()
{
    getchoice();
    return 0;
}