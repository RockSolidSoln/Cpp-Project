#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main()
{   
    int S-id;
    int age,m1=0,m2,m3;
    fstream file;
    file.open(("StudentDataBase.dat",ios::in|ios::out));
    srand (time(NULL));
    age = rand() % 15 + 22;
    cout << age;
    return 0;
}