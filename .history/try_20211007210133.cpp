#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{   int
    fstream file;
    file.open(("StudentDataBase.dat",ios::in|ios::out));
    srand (time(NULL));


    return 0;
}