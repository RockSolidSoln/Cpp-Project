#include <iostream>
#include <iomanip>
using namespace std;


void getchoice()
{
    int ch;
    cout << "-----------------------------------------------------\n"
        << "         Hello and Welcome to Our System         \n"
        << "-----------------------------------------------------\n"
        |<< "\ Please Enter from the choice given below\n"
        << " Enter 1 to Create a new user account\n"
        << " Enter 2 to login using existing user account\n"
        << " Enter 3 to logout from your user account\n"
        << " Enter 4 to delete any user account\n"
        << " Enter 5 TO Change your password\n";
    
}

int main()
{
    getchoice();
    return 0;
}