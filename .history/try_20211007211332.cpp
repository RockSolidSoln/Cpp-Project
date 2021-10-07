#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main()
{   
    int Sid=1191300001;
    int a=0,m1=0,m2=0,m3=0;
    fstream file;
    file.open(("StudentDataBase.dat",ios::in|ios::out));
    srand (time(NULL));

    for(int i = 0; i <100;i++)
    {
        a = rand() % 10 + 22;
        m1= rand() % 1 +100;
        m2= rand() % 1 +100;
        m3= rand() % 1 +100;
        file.out<< Sid <<","<<a<<","<<m1<<","<<m2<<","<<m3<<endl;
        S_id += 10;
    }
    file.close();
    return 0;
}