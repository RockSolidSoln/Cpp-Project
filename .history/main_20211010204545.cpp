#include <iostream>
#include <iomanip>
#include <fstream>
#include <tuple>
#include <vector>
#include <string>
using namespace std;

// -------------------------start of functions defination-------------------------------------
void getchoice(string,int);
int checkadmin(string,string);
void createuser();
void login();
void logout();
void changepass(string);
void deleteuser();
vector<tuple<string,int,string,int>> loadfile(string);
void viewfunc();

//------------------------------------main function-------------------------------------------
int main()
{   
    login();
    return 0;
}
//----------------------This functions takes the input from the user and calls different functions---------------
void getchoice(string name,int status) 
{   
    if(status==1)
    {
        int ch;

        cout << "---------------------------------------------------------\n"
            << "       Hello admin "<<name<<"                             \n"
            << "----------------------------------------------------------\n"
            << "| Please Enter from the choice given below               |\n"
            << "| Enter 1 to Create a New User Account                   |\n"
            << "| Enter 2 to Logout from your User Account               |\n"
            << "| Enter 3 to Login as a User Account to view function    |\n"
            << "| Enter 3 to Delete any User Account                     |\n"
            << "| Enter 4 To Change your Password                        |\n"
            << "| Enter O To Exit                                        |\n"
            << "----------------------------------------------------------\n";
        cin >> ch;
        switch(ch)
        {
            case(1) : createuser();
                        break;
            case(2) :  logout();
                        break;
            case(3) : viewfunc();
                        break;
            case(4) :  deleteuser();
                        break;
            case(5) :  changepass(name);
                        break;
            case(0) : exit(0);
                        break;
            
            default: cout<<"Wrong choice\n"
                         <<"Please try again\n";
                         login();
                     break;
        }
    }
    else
    {   
        if(status==0)
        {   
            int ch;
            cout << "---------------------------------------------------------\n"
                << "        Hello user "<<name<<"                            \n"
                << "---------------------------------------------------------\n"
                << "| Please Enter from the choice given below               |\n"
                << "| Enter 1 to view all the function                       |\n"
                << "| Enter 2 to Logout from your User Account               |\n"
                << "| Enter 3 To Change your Password                        |\n"
                << "| Enter O To Exit                                        |\n"
                << "---------------------------------------------------------\n";
            cin >> ch;
            switch(ch)
            {   case(1) : viewfunc(); 
                            break;
                case(2) : logout();
                            break;
                case(3) : changepass(name);
                            break;
                case(0) : exit(0);
                            break;

                default: cout<<"Wrong choice\n"
                            <<"Please try again\n";
                            login();
                            break;
            }
        }
        else
        {
        cout<<"Either username or password was wrong\n";
        login();
        }
    }
}
//---------------------------This functions checks if the user is admin or not-----------------------
 int checkadmin(string name,string pass)
 {      
    vector<tuple<string,int,string,int>> users;
    string filename ="Users";
    users = loadfile(filename);
     for (int i=0;i<users.size();i++)
    {   
        if(get<0>(users[i])==name && get<2>(users[i])==pass && get<1>(users[i])==1)
            return 1;
        else
        { if(get<0>(users[i])==name && get<2>(users[i])==pass && get<1>(users[i])==1)
            return 0;
            else 
            return 2;
        }
    }
 }
//----------------------------This functions creates the new user---------------------------------
void createuser() 
{   string user,pass;
    cout << "-----------------------------------------------------\n"
        <<"Enter a unique user name -\n";
    cin >> user;
    cout << "-----------------------------------------------------\n"
        <<"Enter your password -\n";
    cin >> pass;
    cout << "-----------------------------------------------------\n"
        <<"Enter 1 for new admin -\n";
    ofstream outfile;
    outfile.open("Users.dat",ios::out|ios::ate|ios::app);
    int status=0;
    int power=1;
    outfile << user << " " << power << " " << pass << " " << status<<endl;
    outfile.close();
    cout<<"Username and password created successfully.\n"<<endl;
}
//----------------------------This functions login the user into the system---------------------------------
void login()
{   
    string username,password;
    int n,s;
    cout<<"---------------------------------------------------\n"
        <<"|      Hello and Welcome to Our System            |\n"
        <<"---------------------------------------------------\n"
        <<"|ENTER 1 TO LOGIN                                 |\n"
        <<"|ENTER 0 TO EXIT                                  |\n"
        <<"---------------------------------------------------\n";
    cin>>n;
    if(n==1)
    { 
            cout<<"-----------------------------------------------------------\n"
                <<"Please enter the username-\n";
        cin>>username;
        cout<<"Please enter the password-\n";
        cin>>password;
        s=checkadmin(username,password);
        getchoice(username,s);
    }
    else
    {
        if(n==0)
            exit(0);
        else
        {
            cout<<"Wrong choice\n"
                <<"Please enter from given choices only\n";
            login();
        }
    }
}
//----------------------------This functions logout the user from the system---------------------------------
void logout()
{   
    system("cls");
    cout<<"Logout was successful.\n";
    main();
}
//----------------------------This functions changes the password-------------------------------------
void changepass(string username) 
{
    vector<tuple<string,int,string,int>> users;
    string filename="Users";
    users=loadfile(filename);
        string newpass1,newpass2,oldpass;           
        cout << "Enter your old password to continue..." << endl;
        cin >> oldpass;       
        for (int i=0;i<users.size();i++)
    {
        if (oldpass == get<2>(users[i]) && username==get<0>(users[i]))
       {    
            cout << "Please enter the new password"
                    << endl;
            cin >> newpass1;
            cout << "Please re-enter your new password"
                    << endl;
            cin >> newpass2;
            if(newpass1==newpass2)
            {
                get<2>(users[i])=newpass1;
                cout << "Password changed you may procced to login"<< endl;
                break;
           }
           else
           {  
               cout <<"You entered incorrect password"<< endl;
           }
       }
    }
            ofstream outfile;
            outfile.open("users.dat" , ios::out);
            for (int i=0;i<users.size();i++)
    { 
        outfile << get<0>(users[i]) << " " 
                << get<1>(users[i]) << " " 
                << get<2>(users[i]) << " " 
                << get<3>(users[i]) <<endl;
    }
            outfile.close();
}
//----------------------------This functions deletes the new user ---------------------------------
void deleteuser() 
{
    vector<tuple<string,int,string,int>> users;
    string filename="Users";
    users=loadfile(filename);
    string name, pass;
                cout << "-----------------------------------------------------\n"
                    << "Enter the Username to delete-\n";
                cin >> name;
                cout << "-----------------------------------------------------\n"
                    << "Enter Password to confirm deletion-\n";
                cin >> pass;
     for (int i=0;i<users.size();i++)
    {   
        if (name==get<0>(users[i]) && pass==get<2>(users[i]) && get<3>(users[i])==1)
             { 
                cout << get<0>(users[i]) << ": "
                    << ((get<1>(users[i])==1)?"admin":"user")
                    << ": " <<get<2>(users[i]) << ": "
                    << ((get<3>(users[i])==1)?"Deleted":"Active")
                    << endl;
                
                get<3>(users[i])=0;
                cout << "---------------------------------------------------\n"
                    <<"Account deletion was successful." << endl;
                    break;
             }       
    }
    ofstream outfile;
    outfile.open("Users.dat",ios::out);
    for (int i=0;i<users.size();i++)
    { 
        outfile << get<0>(users[i]) << " " 
                << get<1>(users[i]) << " " 
                << get<2>(users[i]) << " " 
                << get<3>(users[i]) <<endl;
    }
    outfile.close();
}
// -----------------------------This function loads the file------------------------------------
 vector<tuple<string,int,string,int>> loadfile(string filename)
{   
    vector<tuple<string,int,string,int>> users;
    tuple<string,int,string,int> userdata;
    ifstream file;
    file.open(filename+".dat");
    while (file>>get<0>(userdata))
    {
        file >>get<1>(userdata);
        file >>get<2>(userdata);
        file >>get<3>(userdata);
        users.push_back(userdata);
    }
    file.close();
    return users;
}
// --------------------This function shows different functions for user to perform-------------------------
void viewfunc()
{
    // blank for now
}