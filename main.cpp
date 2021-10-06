#include <iostream>
#include <iomanip>
#include <fstream>
#include <tuple>
#include <vector>
#include <string>
using namespace std;

void createuser();
void loginuser();
void deleteuser();
void changepass();

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
        case(3) :
                    break;
        case(4) :  deleteuser();
                     break;
        case(5) :  changepass();
                     break;

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
        outfile.open("Users.dat",ios::out|ios::ate|ios::app);
        // pos=outfile.tellp();
        // outfile.seekp(pos,ios::cur);

        status=1;
        power=0;
        outfile << user << " " << power << " " << pass << " " << status<<endl;

        outfile.close();

    }
    inputFile.close();
}

void loginuser()
{
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
    cout << "-----------------------------------------------------\n"
        << "Enter Username-\n";
    cin >> name;
    cout << "-----------------------------------------------------\n"
        << "Enter Password-\n ";
    cin >> pass;

    for (auto elem: users)
    {
         if (name == get<0>(elem) &&
             pass == get<2>(elem) &&
             get<3>(elem)==1)
        {
            cout << get<0>(elem) << ": "
                 << ((get<1>(elem)==1)?"admin":"user")
                 << ": " <<get<2>(elem) << ": "
                 << ((get<3>(elem)==1)?"Active":"Deleted")
                 << endl;
                 break;
        }
        else{
            cout << "-----------------------------------------------------\n"
                <<"Wrong username or password\n"
                <<"Please try again\n";
                loginuser();
        }
}
}
void deleteuser()
{
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
    cout << "-----------------------------------------------------\n"
        << "Enter the Username to delete-\n";
    cin >> name;
    cout << "-----------------------------------------------------\n"
        << "Enter Password to confirm deletion-\n";
    cin >> pass;

     for (auto elem: users)
    {   
        if (name == get<0>(elem) &&
             pass == get<2>(elem) &&
             get<3>(elem)==1)
             {  
                cout << get<0>(elem) << ": "
                 << ((get<1>(elem)==1)?"admin":"user")
                 << ": " <<get<2>(elem) << ": "
                 << ((get<3>(elem)==1)?"Deleted":"Active")
                 << endl;
                 
                ofstream outfile;
                outfile.open("Users.dat",ios::out);
                
                get<3>(elem)=0;
                outfile << get<0>(elem) << " " 
                        << get<1>(elem) << " " 
                        << get<2>(elem) << " " 
                        << get<3>(elem) << endl;
                users.push_back(elem);
                outfile.close();

                cout << "---------------------------------------------------\n"
                    <<"Account deletion was successful." << endl;
                    break;
             }
        else {
              cout << "-----------------------------------------------------\n"
                <<"Wrong username or password\n"
                <<"Please try again\n";
                deleteuser();
        }
    }
}
void changepass()
{
    vector<tuple<string,int,string,int>> users;
    tuple<string,int,string,int> userdata;
    ifstream file;
    file.open("users.dat");
    
        while (file>>get<0>(userdata))
    {
        file >>get<1>(userdata);
        file >>get<2>(userdata);
        file >>get<3>(userdata);

        users.push_back(userdata);
    }
    
    
    
        string newpass1,newpass2,oldpass,user;           
        cout <<"Enter user" <<endl;
        cin >> user;
        cout << "Enter your old password to continue..." << endl;
        cin >> oldpass;
        
        for (auto elem: users)
    {
        
        if ( oldpass == get<2>(elem) && user == get<0>(elem))
       {    
            cout << "Please enter the new password"
                 << endl;
             cin >> newpass1;
            cout << "Please re-enter your new password"
                 << endl;
             cin >> newpass2;
                        if(newpass1==newpass2)
                       {
                        cout << "Password changed you may procced to login"
                         << endl;
        
                        ofstream outfile;
                        outfile.open("users.dat" , ios::out);

                            get<2>(elem) = newpass1; 
                            outfile<<get<0>(elem)<<" "
                                   <<get<1>(elem)<<" "
                                   <<get<2>(elem)<<" "
                                   <<get<3>(elem)<<" "
                                   << endl;
                            users.push_back(elem);
                            outfile.close();
                    }

                     else if (newpass1!=newpass2)
                   { 
                    cout <<"The new password that you entered does not match";
                   } 
       }

        else
      {
        cout << "----------------------------" << endl;
        cout <<"Either the username or the password you entered is incorrect," 
             << "please try again"<< endl;
             loginuser();
      }
       file.close();
    }
}

int main()
{
    getchoice();
    return 0;
}