#include <iostream>
#include <iomanip>
#include <fstream>
#include <tuple>
#include <vector>
#include <string>
using namespace std;

// -------------------------start of functions defination-------------------------------------
void createuser();
void loginuser();
void deleteuser();
void changepass();
void datafilereader();

//----------------------This functions takes the input from the user and calls different functions---------------
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

 checkadmin(string name,string pass,int status) //this functions checks if the given data is of admin or not
 {
        string adminu,adminp;
    cout<<"-----------------------------------------------------------\n"
        <<"ALERT: *Only Admin have the authority for such actions*\n"
        <<"Please enter the username-\n";
    cin>>adminu;
    cout<<"Please enter the password-\n";
    cin>>adminp;
    if(adminu==name && adminp==pass && status==1)
    return true;
    else 
    return false;
}

void createuser() // this function creates new users
{
    ifstream file;
    file.open("Users.dat");
    vector<tuple<string,int,string,int>> users;
    tuple<string,int,string,int> userdata;
     while (file>>get<0>(userdata)){
        file >>get<1>(userdata);
        file >>get<2>(userdata);
        file >>get<3>(userdata);
        users.push_back(userdata);
    }

     for (auto elem: users)
    {   
        if(checkadmin(get<0>(elem),get<2>(elem),get<1>(elem))==true)
        {   
            string user,pass;
            int status,power;
            if (!file.is_open())
            {
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
                status=1;
                power=0;
                outfile << user << " " << power << " " << pass << " " << status<<endl;
                outfile.close();
                file.close();
                cout<<"Username and password created successfully."<<endl;
                break;
            }
        }
        else
        {
            cout << "-----------------------------------------------------\n"
                <<"Please enter the correct admin username or password\n";
                createuser();
        }
    }
}

void loginuser() // this function helps user s and admin to login in the system
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
            if(get<1>(elem)==1)
            {
                cout<<"Welcome admin- "<<get<0>(elem)<<endl;
                datafilereader();
            }
            else{
                cout<<"Id- "<<get<0>(elem)<< " is not an admin "<<endl;
            }
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
void changepass() // this function changes the password of the user
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
        cout <<"Enter username" <<endl;
        cin >> user;
        cout << "Enter your old password to continue..." << endl;
        cin >> oldpass;       
        for (auto elem: users)
    {
        if (oldpass == get<2>(elem) && user == get<0>(elem))
       {    
            cout << "Please enter the new password"
                    << endl;
            cin >> newpass1;
            cout << "Please re-enter your new password"
                    << endl;
            cin >> newpass2;
            if(newpass1==newpass2)
            {
            cout << "Password changed you may procced to login"<< endl;
                get<2>(elem) = newpass1;
            ofstream outfile;
            outfile.open("users.dat" , ios::out);
            outfile<<get<0>(elem)<<" "
                <<get<1>(elem)<<" "
                <<get<2>(elem)<<" "
                <<get<3>(elem)<<" "
                << endl;
            users.push_back(elem);
            outfile.close();
                break;
           }
           else
           {  
               cout <<"You entered incorrect password"<< endl;
           }
       }
        else
        {
            cout << "--------------------------------------------------------" << endl;
            cout <<"Either the username or the password you entered is incorrect," 
                << "please try again"<< endl;
                changepass();
        }
       file.close();
    }
}
void deleteuser() // this function delets a user from the database
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
  
     for (auto elem: users)
    {   
        if (checkadmin(get<0>(elem),get<2>(elem),get<1>(elem))==true)
             {  string name, pass;
                cout << "-----------------------------------------------------\n"
                    << "Enter the Username to delete-\n";
                cin >> name;
                cout << "-----------------------------------------------------\n"
                    << "Enter Password to confirm deletion-\n";
                cin >> pass;
                cout << get<0>(elem) << ": "
                 << ((get<1>(elem)==1)?"admin":"user")
                 << ": " <<get<2>(elem) << ": "
                 << ((get<3>(elem)==1)?"Deleted":"Active")
                 << endl;
                
                get<3>(elem)=0;
                ofstream outfile;
                outfile.open("Users.dat",ios::out);
                outfile << get<0>(elem) << " " 
                        << get<1>(elem) << " " 
                        << get<2>(elem) << " " 
                        << get<3>(elem) <<endl;
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
void datafilereader()
{
    
}
int main()
{   
    int n;
    cout<<"---------------------------------------------------\n"
        <<"|      Hello and Welcome to Our System            |\n"
        <<"---------------------------------------------------\n"
        <<"|ENTER 1 TO LOGIN                                 |\n"
        <<"|ENTER  TO EXIT                                  |\n"
        <<"---------------------------------------------------\n";
    cin>>n;
    {
        if(n==1)
        {

        }
        else
            if(n==0)
    }
    getchoice();

    return 0;
}