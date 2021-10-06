#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // bool checkUser(vector<Users> &users, string name, string pass){
    // bool found = false;
//     class Users {
// public:
//     string user;
//     string pass;
//     int status;
//     int type;
// };
    
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
        cout << "Enter your old password to continue..." << endl;
        cin >> oldpass;
        

        for (auto elem: users)
    {
        
        if ( oldpass == get<2>(elem))
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
       }

        else
      {
        cout << "----------------------------" << endl;
        cout <<"Please try again" << endl;
      }
       file.close();
    }

    return 0;
}