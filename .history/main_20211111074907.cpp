// ----------------------------------------start of the program---------------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


// -------------------------type definiations used in the function-------------------------------------------
typedef vector<tuple<string,int,string,int>> vec;
typedef vector<int> vec1;
typedef vector<vector<int>> vec2;


//----------------------------------------Global variables-----------------------------------------------------
int status=0;
string username,password;

//---------------------------------------Structure for Database------------------------------------------------
struct datavalues
{
    int totalcol;
    int totalrow;
    string titles;
    vec1 computablecols;
    vec2 fulldata;
};

// ----------------------------------Start of functions defination-------------------------------------------
void login();
int checkadmin(string,string);
void getchoice();
void adminmenu();
void usermenu();
void createuser(vec);
void logout();
void changepass(vec);
void deleteuser(vec);
vec loadfile();
void clearfile();
void database(ifstream &data, struct datavalues d,string);//changed
void savefile();
void savereport(int,string,double,double);
void saveHTMLreport(string,double,double);
void clearActivity();
void logrecord(string);
void pressenter(int);
void viewfunc(struct datavalues d);//changed
void loadmin(struct datavalues d);
void findmin(struct datavalues d, const int, const int,const int, double&);
void loadmax(struct datavalues d);
void findmax(struct datavalues d, const int, const int,const int, double&);
void loadmed(struct datavalues d);
void findmedian(struct datavalues d,const int,const int, const int, int);
//changed
void askrowcolumn(struct datavalues d, int&, int&,int&);
void loadmean(struct datavalues d);
void findmean(struct datavalues d,const int,const int, const int,double&,double&,double&, int&);
void loadvar(struct datavalues d);
void findvar(const double,const double,const int, double&);
void loadfindstdv(struct datavalues d);
void asktwocolumn(struct datavalues d, int&, int&);
void loadfindcorr(struct datavalues d);
//till here
void finddistinct(struct datavalues d);
void findhistogram(struct datavalues d);
void findMP();
void reportsmenu();


//------------------------------------------main function------------------------------------------------------
int main()
{   
    clearActivity();
    login();
    return 0;
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//----------------------------This functions login the user into the system-------------------------------------
void login()
{   
    int s;
    char n;
    cout<<"|-------------------------------------------------|\n"
        <<"|      Hello and Welcome to Our System            |\n"
        <<"|-------------------------------------------------|\n"
        <<"|ENTER 1 TO LOGIN                                 |\n"
        <<"|ENTER 0 TO EXIT                                  |\n"
        <<"|-------------------------------------------------|\n";
    cin>>n;
    cin.ignore(25,'\n');
    if(n=='1')
    { 
        cout<<"-----------------------------------------------------------\n"
            <<"Please enter the username-\n";
        cin>>username;
        cin.ignore(25,'\n');
        cout<<"Please enter the password-\n";
        cin>>password;
        cin.ignore(25,'\n');
        status=checkadmin(username,password);
        logrecord(" just logged in");
        getchoice();
    }
    else if(n=='0')
            exit(0);
    else
    {
        cout<<"Wrong choice\n"
            <<"Please enter from given choices only\n";
        login();
    }
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//---------------------------This functions checks if the user is admin or not----------------------------------
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
//----------------------This functions takes the input from the user and calls different functions---------------
void getchoice() 
{   
    if(status==1)
        adminmenu();
    else
    {   
        if(status==0)
        usermenu();
        else
        {
        cout<<"Either username or password was wrong\n";
        login();
        }
    }
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//----------------------------------This function shows the menu for the admin----------------------------------
void adminmenu()
{
    char ch;
    cout << "|--------------------------------------------------------|\n"
        << "       Hello admin "<<username<<"                         \n"
        << "|--------------------------------------------------------|\n"
        << "| Please Enter from the choice given below               |\n"
        << "| Enter 1 to Login as a User Account to view FUNCTION    |\n"
        << "| Enter 2 to Create a New User Account                   |\n"
        << "| Enter 3 to Logout from your User Account               |\n"
        << "| Enter 4 to Delete any User Account                     |\n"
        << "| Enter 5 To Change your Password                        |\n"
        << "| Enter O To Exit                                        |\n"
        << "|--------------------------------------------------------|\n";
    cin >> ch;
    cin.ignore(' ','\n');
    string str=" just choose menu option ";
    str.push_back(ch);
    logrecord(str);
    vec users;
    users=loadfile();
    switch(ch)
    {
        case('1') : clearfile();
                    break;
        case('2') : createuser(users);
                    break;
        case('3') : logout();
                    break;
        case('4') :  deleteuser(users);
                    break;
        case('5') :  changepass(users);
                    break;
        case('0') : exit(0);
                    break;
        default: cout<<"Wrong choice\n"
                     <<"Please try again\n";
                        adminmenu();
                        break;    
    }
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//--------------------------This function shows the menu for a regular user-------------------------------------
void usermenu()
{
    char ch;
    cout <<"|--------------------------------------------------------|\n"
        << "        Hello user "<< username<<"                        \n"
        << "|--------------------------------------------------------|\n"
        << "| Please Enter from the choice given below               |\n"
        << "| Enter 1 to view all the FUNCTION                       |\n"
        << "| Enter 2 to Logout from your User Account               |\n"
        << "| Enter 3 To Change your Password                        |\n"
        << "| Enter O To Exit                                        |\n"
        << "|--------------------------------------------------------|\n";
    cin >> ch;
    cin.ignore(' ','\n');
    string str=" just choose menu option "+ch;
    str.push_back(ch);
    logrecord(str);
    vec users;
    users=loadfile();
    switch(ch)
    {   case('1') : clearfile(); 
                    break;
        case('2') : logout();
                    break;
        case('3') : changepass(users);
                    break;
        case('0') : exit(0);
                    break;

        default: cout<<"Wrong choice\n"
                    <<"Please try again\n";
                    usermenu();
                    break;
    }
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//----------------------------This functions creates the new user-----------------------------------------------
void createuser(vec users) 
{   
    string user,pass;
    int s, flag=0,f;
    cout <<"Enter a unique user name -\n";
    cin >> user;
    cout << "Enter your password -\n";
    cin >> pass;
    cout <<"Enter 1 to create new admin, 0 for reguler user-\n";
    cin>>s;
    for(int i=0; i<users.size(); i++)
    {if(get<0>(users[i])==user)
    {
        flag = 1;
        break;
    }}
    if(flag!=1)
    {ofstream outfile;
    outfile.open("Users.dat",ios::ate|ios::app);
    int activity=1;
    outfile << user << " " << s << " " << pass << " " << activity <<endl;
    outfile.close();
    cout << "-----------------------------------------------------\n"
         << "Username and password created successfully.\n"<<endl;
    string str=" just created another user as "+user;
    logrecord(str);}
    else 
    cout<<"The username already exists\n";
    pressenter(f==1);
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//----------------------------This functions logout the user from the system---------------------------------
void logout()
{   
    string str=" logged out from the system ";
    logrecord(str);
    system("cls");
    cout<<"Logout was successful.\n";
}

//---------------------------------------------Salah Fayeq------------------------------------------------------
//----------------------------This functions changes the password-------------------------------------
void changepass(vec users) 
{
    string newpass1,newpass2,oldpass;           
    cout << "Enter your old password to continue..." << endl;
    cin >> oldpass;       
    for (int i=0;i<users.size();i++)
    {
        if (oldpass == get<2>(users[i]) && username==get<0>(users[i]))
       {    
            cout << "Please enter the new password"<< endl;
            cin >> newpass1;
            cout << "Please re-enter your new password"<< endl;
            cin >> newpass2;
            if(newpass1==newpass2)
            {
                get<2>(users[i])=newpass1;
                cout << "Password changed you may procced to login"<< endl;
            }
                else
                cout <<"passwords don't match try again"<<endl;
            string str=" just changed his password ";
            logrecord(str);       
       }
         else
            cout <<"password is wrong"<<endl;
                break;  
    }
    ofstream outfile;
    outfile.open("Users.dat" , ios::out);
    for (int i=0;i<users.size();i++)
    { 
        outfile << get<0>(users[i]) << " " 
                << get<1>(users[i]) << " " 
                << get<2>(users[i]) << " " 
                << get<3>(users[i]) <<endl;
    }
    outfile.close();
    pressenter(status);
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//----------------------------This functions deletes the user--------------------------------------
void deleteuser(vec users) 
{
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
    cout << "---------------------------------------------------\n"
                    <<"Account deletion was successful.\n" << endl;
    string str=" deleted the user "+name;
    logrecord(str);
    pressenter(1);
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
// ---------------------------------This function loads Users.dat the file-----------------------------------------
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

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
// ---------------------This function loads the student database file and clears the comma----------------------
void clearfile() 
{    
    struct datavalues d;
    string filename;
    cout<<"Before proceeding enter the name of the data base file with proper extension\n";
    cin>>filename;
    ifstream data;
    data.open(filename);
    if(!data){
        cout<<"file doesn't exist\nTry again\n";
        clearfile();
    }
    data >> d.totalcol;
    data >> d.titles;

    string compute,temp;
    int temp2;
    for (int i = 0; i < d.totalcol; i++){
        data >> compute;
        stringstream sscompute(compute);
        getline(sscompute, temp, ',');
        stringstream sstemp(temp);
        sstemp >> temp2;
        d.computablecols.push_back(temp2); 
    }
    data >> d.totalrow;
    database(data,d,filename);
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
// -----------------------------This function stores the data base file in the vector------------------------------------
void database(ifstream &data, struct datavalues d,string filename)
{   
    if(!data){
        cout<<"file doesn't exist\nTry again\n";
        clearfile();
    }
    vec1 rowdata;
    string temp3, temp4;
    int temp5;
    for (int i = 0; i < d.totalrow; i++){
        data >> temp3;
        stringstream sstemp3(temp3);
        for (int j = 0; j < d.totalcol; j++){
            getline (sstemp3, temp4,','); //splite comma
            stringstream sstemp4(temp4); //convert into int
            sstemp4 >> temp5;
            rowdata.push_back(temp5); //add into vector
        }
        d.fulldata.push_back(rowdata); //add into 2d vector
        rowdata.clear();
    }
    cout<<"File was loaded successfully\n"
        <<"-------------------------------------------\n";
    data.close();
    // for(int i=0;i<d.totalrow;i++)
    // {
    //     for(int j=0;j<d.totalcol;j++)
    //     cout<<d.fulldata[i][j]<<" ";
    // cout<<endl;}
    viewfunc(d);
}

//---------------------------------------------omar------------------------------------------------------
// -------------------------------This function saves the new file----------------------------------------
void savefile()
{       
    string newfilename;
    cout << "Enter the new file name "<< endl;
    cin >> newfilename; 
    ofstream file(newfilename+".dat",ios::app);
    for(int i=0;i<100;i++)
    {
        // file<<get<0>(student[i]) <<", "
        //     <<get<1>(student[i]) <<", "
        //     <<get<2>(student[i]) <<", "
        //     <<get<3>(student[i]) <<", "
        //     <<get<4>(student[i]) << endl;
    }
    string str=" Created and saved a newfile as "+newfilename+"\n";
    logrecord(str);
}

//---------------------------------------------Ahmad Ayaan/Salah Fayeq------------------------------------------------------
// -----------------This function clears the user activity in a file before function starts--------------------------
void clearActivity()
{
    ofstream file;
    file.open("Report.dat",ios::out|ios::trunc);
    file.close();
    ofstream outfile;
    outfile.open("Activity.dat",ios::out|ios::trunc);
    outfile.close();
    ofstream hfile;
    hfile.open("Report.html" ,ios::out|ios::trunc);
}

//---------------------------------------------Salah Fayeq------------------------------------------------------
// --------------------This function saves the report of the user choices in a file-------------------------
void savereport(int flag,string str, double col,double results)
{
    ofstream outFile;
    outFile.open("Report.dat",ios::out|ios::app);
    outFile << "you just"<<" " << str << " "<< col <<" and the result is: " << results<< endl;
    outFile.close();
    if(flag==1)
    {
    logrecord(" saved the report");
    cout<<"Created the report successfully\n";
    }
    pressenter(3);
}

//---------------------------------------------Salah Fayeq------------------------------------------------------
// -----------------This function saves the report in HTML of the user choices in a file---------------------
void saveHTMLreport(int flag,string str, double col,double results)
{      
    ofstream file;
    file.open("a.html");

    file << "<html>" << endl;
    file << "<body>" << endl;
    file << "<h1>" << "Testing HTML " << "</h1>" << endl;
    file << "<table style=\"width:50%\"> " << endl;

    for (int i=1; i<11; i++)
    {
        file << "<tr>";
        file << "<td style=\"background-color:#F100FF\"> " << i << " </td> "
             << "<td style=\"background-color:#FFFF00\"> " << 'x' << " </td>"
             << "<td> " << 8 << " </td> "
             << "<td> " << '=' << " </td>"
             << "<td style=\"font-size:20px\"> " << 8*i << " </td>" << endl;          
        file << "</tr>" << endl;
    }

    file << "</table>" << endl;
    file << "</body>" << endl;
    file << "</html>" << endl;
    file.close();

    system("chrome a.html");
    if(flag==1) {
        logrecord(" saved the HTML report");
        cout<<"Created the HTML report successfully\n";
    }
    
    pressenter(3);
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
// -------------------------This function saves the user activity in a file-------------------------------------
void logrecord(string str)
{
    ofstream outfile;
    outfile.open("Activity.dat",ios::out|ios::app);
    outfile << "--> " << username << " " << str << endl;
    outfile.close();
}
//---------------------------------------------Liew ------------------------------------------------------
//----------------------This functions asks the user to press enter to continue---------------------------------
void pressenter(int flag)
{
    char temp = 'x';
    cout << "Press enter to continue...." << endl;
    cin.get(temp);
    cin.ignore(20,'\n');
    if(temp=='\n')
    {
        if(flag==0)
        usermenu();
        else if(flag==1)
        adminmenu();
        else if(flag==2)
        reportsmenu();
    }
    else
    {
        cout<<"Wrong selection\n";
        pressenter(flag);
    }
}

//---------------------------------------------Salah Fayeq------------------------------------------------------
// --------------------This function shows different functions for user to perform------------------------------
void viewfunc(struct datavalues d)
{   
    char temp = 'x',ch;
    cout << "Press enter to continue...." << endl;
    cin.get(temp);
    cin.ignore(20,'\n');
    cout <<"|------------------------------------------------------------|\n"
        <<"              "<<username<<" ,Please enter a number to procced:\n"
        <<"|-------------------------------------------------------------|\n"
        <<"|  Enter 1 to find the minmum value:                          |\n"
        <<"|  Enter 2 to find the maximum value:                         |\n"
        <<"|  Enter 3 to find the median of the value:                   |\n"
        <<"|  Enter 4 to find the mean of the value:                     |\n"
        <<"|  Enter 5 to find the variance of the value:                 |\n"
        <<"|  Enter 6 to find the standard deviation of the value        |\n"   
        <<"|  Enter 7 to find the correlation between the values         |\n"   
        <<"|  Enter 8 to find the distinct data members                  |\n"
        <<"|  Enter 9 to plot a histogram                                |\n"
        <<"|  Enter R to proceed to the Reports menu                     |\n" 
        <<"|  Enter B to go back to User's menu                          |\n"
        <<"|  Enter S to save the file with a newname                    |\n"  
        <<"|  Enter 0 to exit                                            |\n"     
        <<"|-------------------------------------------------------------|\n"
        <<endl;
    cin>>ch;
    cin.ignore(' ','\n');
    string word= " Just choose a Statystical menu option ";
    word.push_back(ch);
    logrecord(word);
    switch(ch)
    {
         case('1')    : loadmin(d);
                         break;
         case('2')    : loadmax(d);
                         break;
         case('3')    : loadmed(d);               
                         break;
         case('4')    : loadmean(d);
                         break;
         case('5')    : loadvar(d);
                         break;
         case('6')    : loadfindstdv(d);
                         break;                
         case('7')    : loadfindcorr(d);
                         break;     
         case('8')    : finddistinct(d);
                         break;
         case('9')    : findhistogram(d);
                         break;
         case('R')    : reportsmenu();
                         break;
         case('B')    : getchoice();
                         break;
         case('S')    : savefile();
                         break;
         case('0')    : exit(0);
                         break;               
         default: cout<<"Wrong choice\n"
                        <<"Please Enter from the choice given below\n";
                // viewfunc();
                break;         
    }
}
//--------------------------------------------- ------------------------------------------------------
//------------------------------This functions loads the minimum function-------------------------------------
void loadmin(struct datavalues d)
{
    int row=0,col=0,roworcol;
    double min=0;
    askrowcolumn(d, row, col, roworcol);
    findmin(d, col, row, roworcol, min);

    cout<<"\nThe minimum of ";
    if (roworcol == 1)
        cout << "column " << col;
    else if (roworcol == 2)
        cout << "row " << row;
    cout << " is " << min << "."<<endl;
    viewfunc(d);
}

//--------------------------------------------- ------------------------------------------------------
//------------------------------This function prints minimum from a row-------------------------------------
void findmin(struct datavalues d,const int col,const int row, const int roworcol,double &min)
{   
    if(roworcol==1)
    {   
        min=d.fulldata[0][col];
        for (int i=1;i<d.totalrow;i++)
        {
            if((d.fulldata[i][col])<min)
                min=d.fulldata[i][col];
        }
    }
    else if(roworcol==2)
    {   
        min=d.fulldata[row][0];
        for(int j=0;j<d.totalcol;j++)
        {   
            if(d.computablecols[j]==1)
            {
                if((d.fulldata[row][j])<min)
                    min=d.fulldata[row][j];
            }
        }
    }
}

//-------------------------------------------- ------------------------------------------------------
//------------------------------This functions loads the maximum function-------------------------------------
void loadmax(struct datavalues d)
{
    int row=0,col=0,roworcol;
    double max=0;
    askrowcolumn(d, row, col, roworcol);
    findmax(d, col, row, roworcol, max);

    cout<<"\nThe maximum of ";
    if (roworcol == 1)
        cout << "column " << col;
    else if (roworcol == 2)
        cout << "row " << row;
    cout << " is " << max <<"."<<endl;
    viewfunc(d);
}
 
//---------------------------------------------  ------------------------------------------------------
//------------------------------This function print the maximum from a row-------------------------------------
void findmax(struct datavalues d,const int col,const int row, const int roworcol,double &max)
{
     if(roworcol==1)
    {   
        max=d.fulldata[0][col];
        for (int i=1;i<d.totalrow;i++)
        {
            if((d.fulldata[i][col])>max)
                max=d.fulldata[i][col];
        }
    }
    else if(roworcol==2)
    {   
        for(int j=0;j<d.totalcol;j++)
        {   
            if(d.computablecols[j]==1)
            {
                if((d.fulldata[row][j])>max)
                    max=d.fulldata[row][j];
            }
        }    
    }
}
         
//---------------------------------------------Salah Fayeq---------------------------------------------------
//------------------------------This functions loads the median function-------------------------------------
void loadmed(struct datavalues d)
{   
    int row,col,roworcol,count;
    int med;
    askrowcolumn(d,row,col,roworcol);
    findmedian(d,col,row,roworcol,med);

    cout << endl << "The Median of ";
    if (roworcol == 1)
        cout << "column " << col;
    else if (roworcol == 2)
        cout << "row " << row;
    cout << " is " << med << ".";

}

//--------------------------------------------Salah Fayeq-----------------------------------------------------
//--------------------------------This function sorts the numbers in col and row------------------------------
void sortnum(struct datavalues d,const int col,const int row,const int roworcol,int med){
    int minipos;
    double temp;
    if(roworcol==2)
    {   
        int ar[d.totalcol];
        for(int i=0; i<d.totalcol;i++)
        {
            minipos = i;
            if(d.computablecols[i]==1)
            {
                ar[i]=d.fulldata[row][i];
            }
        }
        int t= sizeof(ar)/sizeof(ar[0]);
        sort(ar, ar+t);
    }
    else if(roworcol==1)
    {   
        int ar[d.totalrow];
        for(int i=0; i<d.totalrow;i++)
        {
            minipos = i;
            ar[i]= d.fulldata[i][col];
        }
        int t= sizeof(ar)/sizeof(ar[0]);
       
    }
}
void *getarray(int n)
{
    return new int[n];
}
void deletearray(int *ptr1)
{
    delete[] ptr1;
}
// 
//-----------------------------------------------------------------------------------------------------------------
void findmedian(struct datavalues d,const int col,const int row,const int roworcol,int med)
{
    double median = 0;
    sortnum(d,col,row,roworcol,med);
    int count = 0;
    int size = d.fulldata.size();
    int *ar=nullptr;
    if (roworcol==1)
    {   
        ar=getarray(d.totalrow);
        for (int i=0;i<d.totalrow;i++){
            if(d.fulldata[i][col] % 2==0){
                med =  (d.fulldata[i][col]+(size/2-1));
            }
            else {
                med =  (d.fulldata[i][col]+(size/2));
            }    
        }
    }
    else if (roworcol==2)
    {   
        ar=getarray(d.totalcol);
        for (int j=0;j<d.totalcol;j++){
            if (d.computablecols[j]==1){
               if(d.fulldata[j][row] % 2==0){
                   med = (d.fulldata[j][row]+(size/2-1));
               } 
                else
                med = (d.fulldata[j][row]+(size/2));

            }
        }  
    }
    deletearray(ptr)
}

//-----------------------------------------------------------------------------------------------------------------------
void printnotcomputable(const int totalcol, const vec1 computablecols){
    cout << endl << "Column ";
    for (int i=0; i<totalcol; i++){
        if (computablecols[i] == 0){
            cout << i << " ,";
        }
    }
    cout << "are not computable."; 
}
//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions ask for row or column -----------------------------------------
void askrowcolumn(struct datavalues d, int &row, int &col,int &roworcol)
{
    do
    {
        cout << endl << "Enter 1 for column or 2 for row" << endl;
        cin >> roworcol;
        if (!(roworcol ==1 || roworcol ==2))
            cout << "Invalid input. Please enter again." << endl;
    }while(!(roworcol ==1 || roworcol ==2));

    if (roworcol == 1){
        do{
            printnotcomputable(d.totalcol,d.computablecols);
            cout << endl << "Enter the column from 0 to " << d.totalcol - 1 << " which is computable." << endl;
            cin >> col;
            if (!(col >= 0 && col < d.totalcol && d.computablecols[col] == 1))
                cout << "Invalid input. Please enter a valid and computable column." << endl;
        }while (!(col >= 0 && col < d.totalcol && d.computablecols[col] == 1));
    } else{
        do{
            cout << endl << "Enter the row from 0 to " << d.totalrow - 1 << "." << endl;
            cin >> row;
            if (!(row >= 0 && row < d.totalrow))
                cout << "Invalid input. Please enter a valid row." << endl;
        }while(!(row >= 0 && row < d.totalrow));
    }
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions loads the mean function-----------------------------------------
void loadmean(struct datavalues d)
{
    int row,col,roworcol,count;
    double sum,sumofsq,mean;

    askrowcolumn(d,row,col,roworcol);
    findmean(d,col,row,roworcol,sum,sumofsq,mean,count);

    cout << endl << "The mean of ";
    if (roworcol == 1)
        cout << "column " << col;
    else if (roworcol == 2)
        cout << "row " << row;
    cout << " is " << mean << ".";

}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions finds the mean -----------------------------------------
void findmean(struct datavalues d,const int col,const int row, const int roworcol,double &sum,double &sumofsq,double &mean,int &count)
{
    sum = 0;
    sumofsq = 0;
    count = 0;
    if (roworcol==1){
        for (int i=0;i<d.totalrow;i++){
            sum = sum + d.fulldata[i][col];
            sumofsq = sumofsq + ((d.fulldata[i][col])*(d.fulldata[i][col]));
            count++;
        }
    } else if (roworcol==2){
        for (int i=0;i<d.totalcol;i++){
            if (d.computablecols[i]==1){
                sum = sum + d.fulldata[row][i];
                sumofsq = sumofsq + ((d.fulldata[row][i])*(d.fulldata[row][i]));
                count++;
            }
        }
    }
    mean = sum/count;
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This function loads the variance function------------------------------------
void loadvar(struct datavalues d){
    int row,col,roworcol,count;
    double sum,sumofsq,mean,var;

    askrowcolumn(d,row,col,roworcol);
    findmean(d,col,row,roworcol,sum,sumofsq,mean,count);
    findvar(sum,sumofsq,count,var);

    cout << endl << "The variance of ";
    if (roworcol == 1)
        cout << "column " << col;
    else if (roworcol == 2)
        cout << "row " << row;
    cout << " is " << var << ".";
}

// //---------------------------------------------Liew ------------------------------------------------------
// //--------------------------This functions finds the variance-----------------------------------
void findvar(const double sum,const double sumofsq,const int count, double &var){
    var = (sumofsq - ((sum*sum)/count)) / (count - 1);
}


//---------------------------------------------Liew ------------------------------------------------------
//------------------------This functions loads and finds the standard deviation function----------------------------------
void loadfindstdv(struct datavalues d){
    int row,col,roworcol,count;
    double sum,sumofsq,mean,var,stdv;

    askrowcolumn(d,row,col,roworcol);
    findmean(d,col,row,roworcol,sum,sumofsq,mean,count);
    findvar(sum,sumofsq,count,var);
    stdv = sqrt(var);

    cout << endl << "The standard deviation of ";
    if (roworcol == 1)
        cout << "column " << col;
    else if (roworcol == 2)
        cout << "row " << row;
    cout << " is " << stdv << ".";
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------This functions asks user to input two column----------------------------------
void asktwocolumn(struct datavalues d, int &col1, int &col2){
    
    do{
        cout << endl << "Enter a column from 0 to " << d.totalcol - 1 << " for the first column." << endl;
        cin >> col1;
        if (!(col1 >= 0 && col1 < d.totalcol && d.computablecols[col1] == 1))
            cout << "Invalid input. Please enter a valid and computable column." << endl;
    }while (!(col1 >= 0 && col1 < d.totalcol && d.computablecols[col1] == 1));

    do{
        cout << endl << "Enter a column from 0 to " << d.totalcol - 1 << " for the second column." << endl;
        cin >> col2;
        if (!(col2 >= 0 && col2 < d.totalcol && d.computablecols[col2] == 1))
            cout << "Invalid input. Please enter a valid and computable column." << endl;
    }while (!(col2 >= 0 && col2 < d.totalcol && d.computablecols[col2] == 1));

}

//---------------------------------------------Liew ------------------------------------------------------
//-------------------------This function loads and finds the correlation--------------------------------
void loadfindcorr(struct datavalues d){
    int roworcol,count,row,col1,col2;
    double sum1,sum2,sumofsq1,sumofsq2,mean1,mean2,sumofcol1x2,corr;
    roworcol = 1;
    sumofcol1x2 = 0;
    printnotcomputable(d.totalcol,d.computablecols);
    asktwocolumn(d,col1,col2);
    findmean(d,col1,row,roworcol,sum1,sumofsq1,mean1,count);
    findmean(d,col2,row,roworcol,sum2,sumofsq2,mean2,count);
    for (int i = 0; i < d.totalrow;i++){
        sumofcol1x2 = sumofcol1x2 + (d.fulldata[i][col1]*d.fulldata[i][col2]);
    }
    double doublerow = (double)d.totalrow;
    corr = (sumofcol1x2-(doublerow*mean1*mean2))/(sqrt(sumofsq1-(doublerow*mean1*mean1))*sqrt(sumofsq2-(doublerow*mean2*mean2)));    
    cout << "The correlation between column " << col1 << " and " << col2 << " is " << corr << endl;
}


//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions finds distinct member-----------------------------------------
void finddistinct(struct datavalues d)
{
    int row,col,roworcol;
    double max,min;
    askrowcolumn(d, row, col, roworcol);
    findmax(d, col, row, roworcol, max);
    findmin(d, col, row, roworcol, min);
    cout << "     Distinct Numbers Table    " << endl;
    cout << "---------------+---------------" << endl;//15-+15-
    cout << "|    Number    |   Frequency  |" << endl;
    cout << "---------------+---------------" << endl;
    for (int i=min;i<=max;i++){
        int frequency = 0;
        if (roworcol == 1){
            for (int k=0; k<d.totalrow;k++){
                if (i==d.fulldata[k][col])
                frequency++;
            }
        } else if (roworcol == 2){
            for (int k=0; k<d.totalcol;k++){
                if (i==d.fulldata[row][k] && d.computablecols[k]==1)
                frequency++;
            }
        }
        if (frequency != 0){
            cout << "|" << setw(7) << right << i;
            cout << setw(8) << right <<"|" << setw(8) <<right << frequency << setw(7) << right <<"|" << endl;
            cout << "---------------+---------------" << endl;
        }
    }
}

//------------------------------------------Salah Fayeq---------------------------------------------------
//------------------------------This function finds the histogram-----------------------------------------
void findhistogram(struct datavalues d)
{
    
//     srand(time(NULL));
//     vector<int> v(100);
//     set<int> s;

//     for (auto item : v){
//          item =  rand()%10;
//     }
//     for (auto item : v){

//       cout << item << ":";
//       cout << endl;
//     }
    
    
//     vector<int> v2(s.begin(),s.end());
//     vector<int> hist (v2.size(),0);

//     for (int j=0; j<v.size(); j++){
//         for (int i=0;i<v2.size(); i++){
//             if(v[j] == v2[i])
//                 hist[i]++;
//         }
//     }

//     for (int i=0; i<v.size(); i++){
//         cout << v2[i] << "-->";
//         for(int k=0;k<hist[i];k++)
//             cout << "=";
//         cout <<endl;       
//     }
 }
// void initVector(vector<int> &v)
// {
//     for (auto item : v)
//         item =  rand()%10;

// }
// void printVector(const vector<int> &v)
// {
//      for (auto item : v)
//      cout << item << ":";
//      cout << endl;
// }     
// void findUnique(const vector<int> &v, set<int> &s)
// {
//     for (auto item : v)
//         s.insert(item);
// }
//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//------------------------------This functions shows the report menu-----------------------------------------
void reportsmenu()
{   
    // string str1;
    // double db=0;
    // double ds=0;
    // char ch;
    // cout <<"--------------------------------------------------------\n"
    //     <<"          "<<username<<" ,Please enter a number to procced:\n"
    //     <<"--------------------------------------------------------\n"
    //     <<"|  Enter 1 to create a report as a text file           |\n"
    //     <<"|  Enter 2 to create a HTML report                     |\n"
    //     <<"|  Enter B to go back to perform more functions        |\n"
    //     <<"|  Enter U to go back to User's settings menu          |\n"
    //     <<"|  Enter 0 to exit                                     |\n"
    //     <<"--------------------------------------------------------\n";
    // cin>>ch;
    // cin.ignore(' ','\n');
    // string str=" choose the report's menu option ";
    // str.push_back(ch);
    // logrecord(str);
    // switch(ch)
    // {
    //      case('1')    : savereport(1,str1,db,ds);
    //                      break;
    //      case('2')    : saveHTMLreport(1,str1,db,ds);
    //                      break;
    //      case('B')    : //viewfunc();
    //                      break;
    //      case('U')    : getchoice();
    //                      break;
    //      case('0')    : exit(0);
    //                      break;               
    //      default: cout<<"Wrong choice------------->\n"
    //                     <<"Please Enter from the choice given below\n";
    //             reportsmenu();
    //             break;         
    // }
    
}