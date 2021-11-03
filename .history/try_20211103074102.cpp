// ----------------------------------------start of the program---------------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

int main() 
{
    string arr1[100],filename;
    int arr2[100][5],k=0,counter_i=0,counter_j;
    ifstream data;
    // cout<<"Before proceeding enter the name of the data base file with proper extension\n";
    // cin>>filename;
    data.open("StudentDataBase.dat");
    if(!data){
        cout<<"file doesn't exist\nTry again\n";
        // clearfile();
    }
    else cout<<"File was loaded successfully\n";
    while (!data.eof()){
        string x;
        data >> x;
        arr1[counter_i] = x;
        counter_i++;
    }
    cout<<counter_<<endl;
    for (int i=0; i<counter; i++){
        string s = arr1[i];
        stringstream string_stream(s);
        i2 = 0;
        while(string_stream.good()){
            string y;
            getline(string_stream, y, ',' );
            stringstream string_stream2(y);
            string_stream2 >> k;
            arr2[i][i2]=k;
            i2++;
        }
    }
    cout<<i2++<<endl;
    for(int i=0;i<counter_i;i++)
    {
        for(int j=0;j<counter_j;j++)
        {
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
//    database(filename,arr2);
return 0;
}