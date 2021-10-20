// ----------------------------------------start of the program---------------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

//----------------------------------------Global variables-----------------------------------------------------
int status=0;
string username,password;

// -------------------------type definiations used in the function-------------------------------------------
typedef  vector<tuple<string,int,string,int>> vec;
typedef vector<array<int,5>> vec1;

// ----------------------------------Start of functions defination-------------------------------------------
void login();
int checkadmin(string,string);
void getchoice();
void adminmenu();
void usermenu();
void createuser();
void logout();
void changepass();
void deleteuser();
vec loadfile();
vec1 databaseloadfile();
void savefile();
void savereport();
void saveHTMLreport();
void clearActivity();
void logrecord(string);
void pressenter(int);
void viewfunc();
void loadmin();
void loadmax();
void loadmed();
void loadmean();
void findrowmean(int,int&, float&, double&, double&);
void findcolmean(int,int&, float&, double&, double&);
void loadvar();
void findrowvar(int,int& ,float& ,double& ,double,double&);
void findcolvar(int,int& ,float& ,double& ,double,double&);
void loadstdv();
void findrowstdv(int,int& ,float& ,double& ,double ,double&, double&);
void findcolstdv(int,int& ,float& ,double& ,double ,double&, double&);
void loadcorr();
void findcolsum12(int ,int ,double&);
void findcorrelation(int& ,float& ,double& ,double& ,double&);
void finddistinct();
void findhistogram();
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

        cout<<"Please enter the password-\n";
        cin>>password;
        status=checkadmin(username,password);
        string str=" just login ";
        logrecord(str);
        getchoice();
    }
    else
    {
        if(n=='0')
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
        << "|---------------------------------------------------------|\n"
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
    logrecord(str);
    switch(ch)
    {
        case('1') : viewfunc();
                    break;
        case('2') :  createuser();
                    break;
        case('3') : logout();
                    break;
        case('4') :  deleteuser();
                    break;
        case('5') :  changepass();
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
    cout << "|--------------------------------------------------------|\n"
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
    logrecord(str);
    switch(ch)
    {   case('1') : viewfunc(); 
                    break;
        case('2') : logout();
                    break;
        case('3') : changepass();
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
void createuser() 
{   vec users;
    users=loadfile();
    string user,pass;
    cout <<"Enter a unique user name -\n";
    cin >> user;
    cout << "Enter your password -\n";
    cin >> pass;
    cout <<"Enter 1 to create new admin, 0 for reguler user-\n";
    int s, flag,f;
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
void changepass() 
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
            cout << "Please enter the new password"<< endl;
            cin >> newpass1;
            cout << "Please re-enter your new password"<< endl;
            cin >> newpass2;
            if(newpass1==newpass2)
            {
                get<2>(users[i])=newpass1;
                cout << "Password changed you may procced to login"<< endl;
           }
            string str=" just changed his password ";
            logrecord(str);
       }
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
    string str=" deleted an user";
    logrecord(str);
    pressenter(1);
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
// ---------------------------------This function loads Users.dat the file-----------------------------------------
vec loadfile() //needs debugging
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
// -----------------------------This function loads the student database file------------------------------------
vec1 array1() //need debugging
{
    string arr1[100];
    int arr2[100][5];
    int k=0;
    int i=0;
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
            getline(string_stream, y, ',' );
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
        get<0>(a)=arr2[i][0];
        get<1>(a)=arr2[i][1];
        get<2>(a)=arr2[i][2];
        get<3>(a)=arr2[i][3];
        get<4>(a)=arr2[i][4];
        vee.push_back(a);
    }
    return vee;
}

//---------------------------------------------omar------------------------------------------------------
// -------------------------------This function saves the new file----------------------------------------
void savefile()
{       
    vec1 vee;
    vee=array1();
    string newfilename;
    cout << "Enter the new file name "<< endl;
    cin >> newfilename; 
    ofstream file(newfilename+".dat",ios::app);
    for(int i=0;i<100;i++)
    {
        file<<get<0>(vee[i]) <<", "
            <<get<1>(vee[i]) <<", "
            <<get<2>(vee[i]) <<", "
            <<get<3>(vee[i]) <<", "
            <<get<4>(vee[i]) << endl;
    }
    string str=" Created and saved a newfile as "+newfilename+"\n";
    logrecord(str);
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
// -----------------This function clears the user activity in a file before function starts--------------------------
void clearActivity()
{
    ofstream outfile;
    outfile.open("Activity.dat",ios::out|ios::trunc);
    outfile.close();
}

//---------------------------------------------Salah Fayeq------------------------------------------------------
// --------------------This function saves the report of the user choices in a file-------------------------
void savereport()
{
    logrecord(" saved the report");
    reportsmenu();
}

//---------------------------------------------Salah Fayeq------------------------------------------------------
// -----------------This function saves the report in HTML of the user choices in a file---------------------
void saveHTMLreport()
{
    logrecord(" saved the HTML report");
    reportsmenu();
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
        viewfunc();
    }
    else
    {
        cout<<"Wrong selection\n";
        pressenter(flag);
    }
}

//---------------------------------------------Salah Fayeq------------------------------------------------------
// --------------------This function shows different functions for user to perform------------------------------
void viewfunc()
{
    char ch;
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
        <<"|  Enter S to save the StudentDatabase.dat file with a newname|\n"  
        <<"|  Enter 0 to exit                                            |\n"     
        <<"|-------------------------------------------------------------|\n"
        <<endl;
    cin>>ch;
    cin.ignore(' ','\n');
    string word= " just choose a menu option from all the functions ";
    logrecord(word);
    switch(ch)
    {
         case('1')    : loadmin();
                         break;
         case('2')    : loadmax();
                         break;
         case('3')    : loadmed();               
                         break;
         case('4')    : loadmean();
                         break;
         case('5')    : loadvar();
                         break;
         case('6')    : loadstdv();
                         break;                
         case('7')    : loadcorr();
                         break;     
         case('8')    : finddistinct();
                         break;
         case('9')    : findhistogram();
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
                viewfunc();
                break;         
    }
}

//---------------------------------------------Omar ------------------------------------------------------
//------------------------------This functions loads the minimum function-------------------------------------
void loadmin()
{   
    int ch;
    cout <<"Please enter the 1 to find minimum for the specific row and 2 for the column"<<endl;
    if(ch==1)
        minrow;
    else if(ch==2)
        mincolumn;
    logrecord(" calculated the minimum");
    pressenter(2);
}

//---------------------------------------------Omar ------------------------------------------------------
//------------------------------This function prints minimum from a row-------------------------------------
void minrow()
{   
    double min=0.0;
    int choice;
    vec1 ar;
    ar=array1();
    cout<<"Enter the row number from 1 to 100 to find the minimum from 3 subjects"<<endl;
    cin>>choice;
    for(int i=0;i<ar.size();i++)
    {   
        if((i-1)==min)
        {   
            min=get<2>(ar[i]);
            if(get<3>(ar[i])<get<2>(ar[i]) && get<3>(ar[i])<get<4>(ar[i]))
                min=get<2>(ar[i]);
            else if(get<4>(ar[i])<get<2>(ar[i]) && get<4>(ar[i])<get<3>(ar[i]))
                min=get<2>(ar[i]);
            cout<<"The minimum value is "<<min<<endl;
            break;
        }
        else{
            cout<<"Wrong selection of rows "<<endl
                <<"try again"<<endl;
            minrow();
        }
    }
    pressenter(2);
}


//---------------------------------------------Omar ------------------------------------------------------
//------------------------------This function print the minimum from a column-------------------------------------
void mincolumn()
{   
    double min=0.0;
    int choice;
    vec1 ar;
    ar=array1();
    cout<<"Enter the column number from 2 to 4"<<endl;
    cin>>choice;    
    if(choice==2)
    
        if(min<get<2>(ar[i]))
            min=get<2>(ar[i]);
    else if(choice==3)
        if(min<get<3>(ar[i]))
            min=get<3>(ar[i]);
    else if(choice==4)
        if(min<get<4>(ar[i]))
            min=get<4>(ar[i]);

    pressenter(2);
}

//---------------------------------------------Omar ------------------------------------------------------
//------------------------------This functions loads the maximum function-------------------------------------
void loadmax()
{   
    logrecord(" calculated the maximum");
    pressenter(2);
}

//---------------------------------------------Omar ------------------------------------------------------
//------------------------------This functions loads the median function-------------------------------------
void loadmed()
{   
    logrecord(" calculated the median");
    pressenter(2);
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions loads the mean function-----------------------------------------
void loadmean()
{   
    int flag=0;
    int row = -1;
    int col = -1;
    int rc;
    float rowmean,colmean;
    double rowsum,colsum,rowsqsum,colsqsum;
    cout << endl << "Enter 1 to find mean of a row or 2 to find mean of a column:" << endl;
    cin >> rc;
    cin.ignore(' ','\n');
    if (rc==1)
    {
        findrowmean(flag,row,rowmean,rowsum,rowsqsum);
    } 
    else if(rc==2)
    {
        findcolmean(flag,col,colmean,colsum,colsqsum);
    }
    else
    {
        cout<<"Wrong choice\n"
             <<"Enter again\n";
        loadmean();
    }
    pressenter(2);
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions finds the mean of the row-----------------------------------------
void findrowmean(int flag,int &row,float &rowmean,double &rowsum,double &rowsqsum){
    rowsum = 0;
    rowsqsum = 0;
    rowmean = 0;
    vec1 ar;
    ar=array1();
    if(row==-1){
        do{
            cout << endl << "Enter row from 1-100:" << endl;
            cin >> row;
            if (row <1 || row > 100)
            cout << "Invalid row" << endl;
        }while (row <1 || row > 100);
    }
    rowsum = rowsum + get<1>(ar[row-1]);
    rowsum = rowsum + get<2>(ar[row-1]);
    rowsum = rowsum + get<3>(ar[row-1]);
    rowsum = rowsum + get<4>(ar[row-1]);
    rowsqsum = rowsqsum + (get<1>(ar[row-1])*get<1>(ar[row-1]));
    rowsqsum = rowsqsum + (get<2>(ar[row-1])*get<2>(ar[row-1]));
    rowsqsum = rowsqsum + (get<3>(ar[row-1])*get<3>(ar[row-1]));
    rowsqsum = rowsqsum + (get<4>(ar[row-1])*get<4>(ar[row-1]));
    rowmean = rowsum/4;

    if(flag==0){
        cout << endl << "The mean of row " << row << " is " << rowmean << endl;
        logrecord(" calculated the mean of the row ");
    }
}


//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions finds the mean of the cloumn-----------------------------------------
void findcolmean(int flag,int &col,float &colmean,double &colsum,double &colsqsum)
{
    colsum = 0;
    colsqsum = 0;
    colmean = 0;
    vec1 ar;
    ar=array1();
    if(col==-1){
        do{
            cout << endl << "Enter column from 2-5:" << endl;
            cin >> col;
            if (col <2 || col > 5)
            cout << "Invalid column" << endl;
        }while (col <2 || col > 5);
    }
    switch(col)
    {
        case (2): for(int i=0;i<100;i++){
            colsum = colsum + get<1>(ar[i]);
            colsqsum = colsqsum + (get<1>(ar[i])*get<1>(ar[i]));}break;
        case (3): for(int i=0;i<100;i++){
            colsum = colsum + get<2>(ar[i]);
            colsqsum = colsqsum + (get<2>(ar[i])*get<2>(ar[i]));}break;
        case (4): for(int i=0;i<100;i++){
            colsum = colsum + get<3>(ar[i]);
            colsqsum = colsqsum + (get<3>(ar[i])*get<3>(ar[i]));}break;
        case (5): for(int i=0;i<100;i++){
            colsum = colsum + get<4>(ar[i]);
            colsqsum = colsqsum + (get<4>(ar[i])*get<4>(ar[i]));}break;
    }
    colmean = colsum/100;
    if(flag==0)
    {
        cout << endl << "The mean of the column " << col << " is " << colmean << endl;
        logrecord(" calculated the mean of the column ");
    }
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This function loads the variance function------------------------------------
void loadvar()
{
    int flag = 1;
    int row = -1;
    int col = -1;
    int rc;
    float rowmean,colmean;
    double rowsum,colsum,rowsqsum,colsqsum,rowvar,colvar;
    cout << endl << "Enter 1 to find variance of a row or 2 to find variance of a column:" << endl;
    cin >> rc;
    cin.ignore(' ','\n');
    if (rc==1){
        findrowvar(flag,row,rowmean,rowsum,rowsqsum,rowvar);
    } else if(rc==2)
    {
        findcolvar(flag,col,colmean,colsum,colsqsum,colvar);
    }
    else
    {
        cout<<"Wrong choice\n"
             <<"Enter again\n";
        loadvar();
    }
    pressenter(2);
}

//---------------------------------------------Liew ------------------------------------------------------
//--------------------------This functions finds the variance of the row-----------------------------------
void findrowvar(int flag,int &row,float &rowmean,double &rowsum,double rowsqsum,double &rowvar)
{   
    rowvar = 0;
    findrowmean(flag,row,rowmean,rowsum,rowsqsum);
    rowvar = ((rowsqsum)-((rowsum*rowsum)/4))/3;
    if (flag ==1){
        cout << endl << "The variance of row " << row << " is " << rowvar << endl;
        logrecord(" calculated the variance of the row ");
    }
}

//---------------------------------------------Liew ------------------------------------------------------
//---------------------------This functions finds the variance of the column-----------------------------------
void findcolvar(int flag,int &col,float &colmean,double &colsum,double colsqsum,double &colvar)
{   
    colvar = 0;
    findcolmean(flag,col,colmean,colsum,colsqsum);
    colvar = ((colsqsum)-((colsum*colsum)/100))/99;
    if (flag ==1){
        cout << endl << "The variance of column " << col << " is " << colvar << endl;
        logrecord(" calculated the variance of the column ");
    }
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------This functions loads the standard deviation function----------------------------------
void loadstdv()
{
    int flag =2;
    int row = -1;
    int col = -1;
    int rc;
    float rowmean,colmean;
    double rowsum,colsum,rowsqsum,colsqsum,rowvar,colvar,rowstdv,colstdv;
    cout << endl << "Enter 1 to find standard deviation of a row or 2 to find standard deviation of a column:" << endl;
    cin >> rc;
    cin.ignore(' ','\n');
    if (rc==1){
        findrowstdv(flag,row,rowmean,rowsum,rowsqsum,rowvar,rowstdv);
    } else if(rc==2){
        findcolstdv(flag,col,colmean,colsum,colsqsum,colvar,colstdv);
    }
    else
    {
        cout<<"Wrong choice\n"
             <<"Enter again\n";
        loadstdv();
    }
    pressenter(2);
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------This functions finds the standard deviation of row----------------------------------
void findrowstdv(int flag,int &row,float &rowmean,double &rowsum,double rowsqsum,double &rowvar,double &rowstdv)
{
    rowstdv=0;
    findrowvar(flag,row,rowmean,rowsum,rowsqsum,rowvar);
    rowstdv= sqrt(rowvar);
    cout << endl << "The standard deviation of row " << row << " is " << rowstdv << endl;
    logrecord(" calculated the standard deviation of the row ");
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions the standard deviation of column----------------------------------------
void findcolstdv(int flag,int &col,float &colmean,double &colsum,double colsqsum,double &colvar, double &colstdv)
{
    colstdv = 0;
    findcolvar(flag,col,colmean,colsum,colsqsum,colvar);
    colstdv = sqrt(colvar);
    cout << endl << "The standard deviation of column " << col << " is " << colstdv << endl;
    logrecord(" calculated the standard deviation of the column ");
}

//---------------------------------------------Liew ------------------------------------------------------
//-------------------------This function loads the find correlation function--------------------------------
void loadcorr()
{
    int row = -1;
    int col = -1;
    float rowmean,colmean;
    double rowsum,colsum,rowsqsum,colsqsum,corr;
    findcorrelation(col,colmean,colsum,colsqsum,corr);
    pressenter(2);
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions finds the correlation----------------------------------------
void findcorrelation(int &col,float &colmean,double &colsum,double &colsqsum,double &corr)
{   
    int flag=3;
    int col2;
    float colmean2;
    double colsum2,colsqsum2,colsum12;
    do {   
        cout << endl << "Enter a column from 2-5:" << endl;
        cin >> col;
        if (col <2 || col> 5)
            cout << "Invalid column" << endl;
    }while(col <2 || col> 5);
    findcolmean(flag,col,colmean,colsum,colsqsum);
    do {   
        cout << endl << "Enter a different column from 2-5:" << endl;
        cin >> col2;
        if (col2 <2 || col2> 5 || col2 == col)
            cout << "Invalid column" << endl;
    }while(col2 <2 || col2> 5 || col2 == col);   
    findcolmean(flag,col2,colmean2,colsum2,colsqsum2);
    findcolsum12(col,col2,colsum12);
    corr = (colsum12-(100*colmean*colmean2))/(sqrt(colsqsum-(100*colmean*colmean))*sqrt(colsqsum2-(100*colmean2*colmean2)));
    cout << endl << "The correlation between column " << col << " and " << col2 << " is " << corr << endl;
    logrecord(" calculated the correlation between two columns ");
}

//---------------------------------------------Liew ------------------------------------------------------
//---------------------This functions finds multiples of 2 element in a same row----------------------------
void findcolsum12(int col,int col2,double &colsum12)
{
    vec1 ar;
    ar=array1();
    colsum12 = 0;
    if((col==2 && col2==3)||(col==3 && col2==2)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<1>(ar[i])*get<2>(ar[i]));
    }
    if((col==2 && col2==4)||(col==4 && col2==2)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<1>(ar[i])*get<3>(ar[i]));
    }
    if((col==2 && col2==5)||(col==5 && col2==2)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<1>(ar[i])*get<4>(ar[i]));
    }
    if((col==3 && col2==4)||(col==4 && col2==3)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<2>(ar[i])*get<3>(ar[i]));
    }
    if((col==3 && col2==5)||(col==5 && col2==3)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<2>(ar[i])*get<4>(ar[i]));
    }
    if((col==4 && col2==5)||(col==5 && col2==4)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<3>(ar[i])*get<4>(ar[i]));
    }
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions finds distinct member-----------------------------------------
void finddistinct()
{
    vec1 ar;
    ar=array1();
    int min = 1; //should be find min
    int max = 1000; //should be find max
    cout << "     Distinct Numbers Table    " << endl;
    cout << "---------------+---------------" << endl;//15-+15-
    cout << "|    Number    |   Frequency  |" << endl;
    cout << "---------------+---------------" << endl;
    for (int k=min;k<=max;k++){
        int f = 0;
        for (int i=0;i<100;i++){
            if (k == get<1>(ar[i]))
                f++;
            if (k == get<2>(ar[i]))
                f++;
            if (k == get<3>(ar[i]))
                f++;
            if (k == get<4>(ar[i]))
                f++;
        }
        if (f!=0){
            cout << "|" << setw(7) << right << k;
            cout << setw(8) << right <<"|";
            cout << setw(8) <<right << f;
            cout << setw(7) << right <<"|" << endl;
            cout << "---------------+---------------" << endl;
        }
    }
    logrecord(" found out the distinct member ");
    pressenter(2);
}


//---------------------------------------------------------------------------------------------------
//------------------------------This function finds the histogram-----------------------------------------
void findhistogram()
{
    vec1 ar;
    ar=array1();
    cout <<"Please choose the column from 2 to 4."<<endl;
    int choice;
    cin>>choice;
    cout<<"Subject"<<"             "<<"Mid-point\n";
    for(int i=0;i< 100; i++)
    {
        if (choice == 2)
       { 
        cout<< get<2>(ar[i])<<"                    "
            <<get<0>(ar[i]);
        for(int j=0;j<  get<2>(ar[i]);j++)
        cout<<"=";
       }
        else if (choice == 3)
        {
        cout<< get<3>(ar[i])<<"                 "
            << get<0>(ar[i]);
         for(int j=0;j<get<3>(ar[i]);j++)
         cout<<"=";   
        }
        else if (choice == 4)
        {
        cout<< get<4>(ar[i])<<"                    "
            << get<0>(ar[i]);
         for(int j=0;j<get<4>(ar[i]);j++)
         cout<<"=";  
        }
        cout<<endl;  
    }
    cout<<"----------------------------0---------10---------"
        <<"20--------30--------40--------50--------"
        <<"60--------70--------80--------90--------100\n";      
    logrecord(" made a Histogram");
    pressenter(2);
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//------------------------------This functions shows the report menu-----------------------------------------
void reportsmenu()
{
    char ch;
    cout <<"--------------------------------------------------------\n"
        <<"          "<<username<<" ,Please enter a number to procced:\n"
        <<"--------------------------------------------------------\n"
        <<"|  Enter 1 to create a report as a text file           |\n"
        <<"|  Enter 2 to create a HTML report                     |\n"
        <<"|  Enter B to go back to perform more functions        |\n"
        <<"|  Enter U to go back to User's settings menu          |\n"
        <<"|  Enter 0 to exit                                     |\n"
        <<"--------------------------------------------------------\n";
    cin>>ch;
    cin.ignore(' ','\n');
    string str=" choose the report's menu option ";
    logrecord(str);
    switch(ch)
    {
         case('1')    : savereport();
                         break;
         case('2')    : saveHTMLreport();
                         break;
         case('B')    : viewfunc();
                         break;
         case('U')    : getchoice();
                         break;
         case('0')    : exit(0);
                         break;               
         default: cout<<"Wrong choice------------->\n"
                        <<"Please Enter from the choice given below\n";
                reportsmenu();
                break;         
    }
}