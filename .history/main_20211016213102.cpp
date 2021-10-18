// -------------------------start of the program---------------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
#include <tuple>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


// -------------------------type definiations used in the function-------------------------------------
typedef  vector<tuple<string,int,string,int>> vec;
typedef vector<array<int,5>> vec1;

// -------------------------start of functions defination-------------------------------------
void getchoice(string,int);
int checkadmin(string,string);
void createuser();
void login();
void logout();
void changepass(string);
void deleteuser();
vec loadfile();
vec1 databaseloadfile();
void savefile();
void savereport();
void saveHTMLreport();
void logrecord(string);
void viewfunc();


//------------------------------------main function-------------------------------------------
int main()
{   
    login();
    return 0;
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
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
        string str=name+" just choose menu option ";
        logrecord(str);
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
            string str=name+" just choose menu option ";
            logrecord(str);
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

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//---------------------------This functions checks if the user is admin or not-----------------------
 int checkadmin(string name,string pass)
 {      
    vec users;
    users = loadfile();
     for (int i=0;i<users.size();i++)
    {   
        if(get<0>(users[i])==name && get<2>(users[i])==pass && get<1>(users[i])==1)
            return 1;
        else if(get<0>(users[i])==name && get<2>(users[i])==pass && get<1>(users[i])==0)   
            return 0;
    }
    return 2;
 }

 //---------------------------------------------Ahmad Ayaan------------------------------------------------------
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
        <<"Enter 1 to create new admin, 0 for reguler user-\n";
    int status;
    cin>>status;
    string str=user+"just created another user with status of ";
    logrecord(str);
    ofstream outfile;
    outfile.open("Users.dat",ios::out|ios::ate|ios::app);
    int activity=1;
    outfile << user << " " << status << " " << pass << " " << activity <<endl;
    outfile.close();
    cout<<"Username and password created successfully.\n"<<endl;
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
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
        string str=username+" just login ";
        logrecord(str);
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

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//----------------------------This functions logout the user from the system---------------------------------
void logout(user)
{   
    string str=name+" just choose menu option ";
    logrecord(str);
    system("cls");
    cout<<"Logout was successful.\n";
    main();
}

//---------------------------------------------Salah Fayeq------------------------------------------------------
//----------------------------This functions changes the password-------------------------------------
void changepass(string username) 
{
    vec users;
    users=loadfile();
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

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//----------------------------This functions deletes the new user ---------------------------------
void deleteuser() 
{
    vec users;
    users=loadfile();
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

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
// -----------------------------This function loads the file------------------------------------
vec loadfile()
{   
    vec users;
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
    return users;
}

//---------------------------------------------Liew ------------------------------------------------------
// -----------------------------This function loads the student database file------------------------------------
vec1 databaseloadfile()
{   
    vec1 array1();
    string arr1[100];
    int arr2[100][5], k=0, i=0;
    ifstream data;
    data.open("StudentDataBase.dat");

    while (!data.eof()){
        string x;
        data >> x;
        arr1[i] = x;
        i++;  
    }

    for (int i=0; i<100; i++){
        string s = arr1[i];
        stringstream string_stream(s);
        int i2 = 0;
        while(string_stream.good()){
            string y;
            getline( string_stream, y, ',' );
            stringstream string_stream2(y);
            string_stream2 >> k;
            arr2[i][i2]=k;
            i2++;
        }
    }

    vec1 vee;
    array <int,5> a;
    for(int i=0;i<100;i++)
    {   
        for(int j=0;j<5;j++)
        {
        get<0>(a)=arr2[i][0];
        get<1>(a)=arr2[i][1];
        get<2>(a)=arr2[i][2];
        get<3>(a)=arr2[i][3];
        get<4>(a)=arr2[i][4];
        vee.push_back(a);
        }   
    }
    data.close();
    return vee;
}

//---------------------------------------------omar------------------------------------------------------
// --------------------This function saves the new file-------------------------------
void savefile()
{       

}

//---------------------------------------------Salah Fayeq------------------------------------------------------
// --------------------This function saves the report of the user choices in a file-------------------------
void savereport()
{

}

//---------------------------------------------Salah Fayeq------------------------------------------------------
// -----------------This function saves the report in HTML of the user choices in a file---------------------
void saveHTMLreport()
{

}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
// -------------------------This function saves the user activity in a file-------------------------------
void logrecord(string str)
{
    ofstream outfile;
    outfile.open("Activity.dat",ios::out|ios::ate|ios::app);
    outfile << "--> " << str << endl;
    outfile.close();
}

//---------------------------------------------Salah Fayeq------------------------------------------------------
// --------------------This function shows different functions for user to perform-------------------------
void viewfunc()
{
    // blank for now
}