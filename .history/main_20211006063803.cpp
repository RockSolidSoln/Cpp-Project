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
        << "| Enter 1 to Create a New User account              |\n"
        << "| Enter 2 to Login using existing User account      |\n"
        << "| Enter 3 to Logout from your user account          |\n"
        << "| Enter 4 to Delete any User account                |\n"
        << "| Enter 5 TO Change your Password                   |\n"
        << "-----------------------------------------------------\n";
    
}

int main()
{
    getchoice();
    return 0;
}