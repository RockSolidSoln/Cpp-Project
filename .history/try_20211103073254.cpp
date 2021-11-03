#include <iostream>
#include <fstream>
using namespace std;

void clearfile() 
{
    string arr1[100],filename;
    int arr2[100][5],k=0,counter=0;
    ifstream data;
    // cout<<"Before proceeding enter the name of the data base file with proper extension\n";
    // cin>>filename;
    data.open("");
    if(!data){
        cout<<"file doesn't exist\nTry again\n";
        clearfile();
    }
    else cout<<"File was loaded successfully\n";
    while (!data.eof()){
        string x;
        data >> x;
        arr1[i] = x;
        counter++;
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
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
   database(filename,arr2);
}