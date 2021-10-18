#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <array>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    int col1[100],col2[100],col3[100];
    int num=0;
    ifstream inFile;
    inFile.open("StudentsDataBase.dat");

    while(!inFile < 100)
    {
        inFile >> col1[num] >> col2[num] >> col3[num];
        num++;
        
    }






















return 0;
}