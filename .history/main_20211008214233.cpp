#include <iostream>
#include <iomanip>
#include <fstream>
#include <tuple>
#include <vector>
#include <string>
using namespace std;

// -------------------------start of functions defination-------------------------------------
// void getchoice(string,int);
// int checkadmin(string,int);
// void createuser();
// void loginuser();
// void deleteuser();
// void changepass();

//---------------------------start of main function-------------------------------------------
int main()
{   
    string username;
    int n,password,status=1;
    cout<<"---------------------------------------------------\n"
        <<"|      Hello and Welcome to Our System            |\n"
        <<"---------------------------------------------------\n"
        <<"|ENTER 1 TO LOGIN                                 |\n"
        <<"|ENTER 0 TO EXIT                                  |\n"
        <<"---------------------------------------------------\n";
    cin>>n;
    {
        if(n==1)
        { 
             cout<<"-----------------------------------------------------------\n"
                 <<"Please enter the username-\n";
            cin>>username;
            cout<<"Please enter the password-\n";
            cin>>password;
            // status=checkadmin(username,password);
            // getchoice(username,status);
        }
        // else
        //     if(n==0)
        //         // exit();
        //     else
        //      {   
        //         cout<<"Wrong chocie Please Try again";
        //         main();         
        //      } 
    //}
    return 0;
}
}
