#include <iostream>
#include <fstream>
#include <
int main()
{   
    fstream file;
    file.open(("StudentDataBase.dat",ios::in|ios::out));


    return 0;
}