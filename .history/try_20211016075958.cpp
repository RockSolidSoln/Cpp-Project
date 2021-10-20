#include <iostream>
#include <iomanip>
#include <fstream>
#include <tuple>
#include <vector>
#include <string>
using namespace std;

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <tuple>
#include <string>

using namespace std;


typedef vector<tuple<int,int,int,int,int>> vec1;
typedef  vector<tuple<string,int,string,int>> vec;

vec loadfile()
{   
    vec users;
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
    return users;
}
vec1 databaseloadfile()
{   
    vec1 data;
    tuple<int,int,int,int,int> stdata;
    ifstream file;
    file.open("StudentDataBase.dat");
    while (file >> get<0>(stdata))
    {
        file >> get<1>(stdata);
        file >> get<2>(stdata);
        file >> get<3>(stdata);
        file >> get<4>(stdata);
        data.push_back(stdata);
    }
    file.close();
    return data;
}

int main ()
{
    vec1 data = databaseloadfile();
    for (int i = 0; i <100; i++){
        cout << get<0>(data[i]) << endl;
    }

    return 0;
}