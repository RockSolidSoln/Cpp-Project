#include <iostream>
#include <iomanip>
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
        case(1) :
        case(2) :
        case(3) :
        case(4) :
        case(5) :
        break;
    
}

int main()
{
    getchoice();
    return 0;
}