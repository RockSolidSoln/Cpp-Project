#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>

using namespace std;

class Users {
public:
    string user;
    string pass;
    int status;
    int type;
};

bool checkUser(vector<Users> &users, string name, string pass){
    bool found = false;
    for (auto elem: users)
    {
        if (name == elem.user &&
            pass == elem.pass &&
            elem.status == 1)
        {
            found  = true;
            break;
        }
    }
return found;
}
int main()
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

    file.close();

    string name, pass;
    cin >> name;
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












        return 0;
    }

















    return 0;
}