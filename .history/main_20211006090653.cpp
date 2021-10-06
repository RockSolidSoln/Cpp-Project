#include <iostream>
#include <iomanip>
#include <fstream>
#include <tuple>
#include <vector>
#include <string>
using namespace std;

void createuser();
void loginuser();

void getchoice()
{   //try
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
        case(2) : loginuser();
                    break;
        case(3) : break;
        case(4) : break;
        case(5) : break;

        // default:
    }
    
}


void createuser()
{
    ifstream inputFile;
    inputFile.open("Users.dat");
    string user,pass;
    int status,power;
    if (!inputFile.is_open()){
        cout << " File not found\n";
        exit(-1);
    }
    else
    {   int pos;
        cout << "-----------------------------------------------------\n"
            <<"Enter a unique user name -\n";
        cin >> user;
        cout << "-----------------------------------------------------\n"
            <<"Enter your password -\n";
        cin >> pass;
        ofstream outfile;
        outfile.open("Users.dat",);
        pos=outfile.tellp();
        outfile.seekp(pos+'/0');
        status=1;
        power=0;
        outfile << user << " " << power << " " << pass << " " << status<<endl;

        outfile.close();

    }
    inputFile.close();
}

void loginuser()
{// fix overwriting issue
    vector<tuple<string,int,string,int>> users;
    tuple<string,int,string,int> userdata;

    ifstream file;
    file.open("Users.dat");
    while (file>>get<0>(userdata))
    {
        file >>get<1>(userdata);
        file >>get<2>(userdata);
        file >>get<3>(userdata);

        users.push_back(userdata);

    }

    file.close();

    string name, pass;
    cout << " Username-\n";
    cin >> name;
    cout<< " Password-\n ";
    cin >> pass;

    for (auto elem: users)
    {
         if (name == get<0>(elem) &&
             pass == get<2>(elem) &&
             get<3>(elem)==1)
        {
            cout << get<0>(elem) << "; "
                 << ((get<1>(elem)==1)?"admin":"user")
                 << ": " <<get<2>(elem) << ": "
                 << ((get<3>(elem)==1)?"Active":"Deleted")
                 << endl;


        }
}
}

int main()
{
    getchoice();
    return 0;
}