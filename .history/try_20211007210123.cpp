#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{   
    fstream file;
    file.open(("StudentDataBase.dat",ios::in|ios::out));
    srand (time(NULL))

    return 0;
}