#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <array>
using namespace std;

typedef vector<array<int,int,int,int,int> vec1;

void array1()
{
    vec1 users;
    array<int,int,int,int,int> userdata;
    ifstream file;
    file.open("Users.dat");
    while (file>>get<0>(userdata))
    {
        file >>get<1>(userdata);
        file >>get<2>(userdata);
        file >>get<3>(userdata);
        file >>get<4>(userdata);
        users.push_back(userdata);
    }
    file.close();

    // for (int i=0; i<100; i++){
    //     string s = arr1[i];
    //     stringstream string_stream(s);
    //     int i2 = 0;

    //     while(string_stream.good()){
    //         string y;
    //         getline( string_stream, y, ',' );
    //         stringstream string_stream2(y);
    //         string_stream2 >> k;

    //         arr2[i][i2]=k;
    //         i2++;
    //     }
    // }
    for (int i=0;i<users.size();i++){
        cout<<get<0>(users[i])<<endl;
    }
}

int main()
{
    array1();
    return 0;
}