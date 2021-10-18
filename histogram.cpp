#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <array>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;
vec1 array1()
{
    string arr1[100];
    int arr2[100][5];
    int k=0;
    int i=0;
    ifstream data;
    data.open("StudentDataBase.dat");

    while (!data.eof()){
        string x;
        data >> x;
        arr1[i] = x;
        i++;

    }

    for (int i=0; i<100; i++){
        string s = arr1[i];
        stringstream string_stream(s);
        int i2 = 0;

        while(string_stream.good()){
            string y;
            getline(string_stream, y, ',' );
            stringstream string_stream2(y);
            string_stream2 >> k;
            arr2[i][i2]=k;
            i2++;
        }
    }

    vec1 vee;
    array <int,5> a;
    for(int i=0;i<100;i++)
    {
        get<0>(a)=arr2[i][0];
        get<1>(a)=arr2[i][1];
        get<2>(a)=arr2[i][2];
        get<3>(a)=arr2[i][3];
        get<4>(a)=arr2[i][4];
        vee.push_back(a);
    }
    return vee;
}

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