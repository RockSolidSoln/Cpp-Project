#include <vector>
#include <string>
#include <array>
#include <
#include <iostream>
#include <fstream>
using namespace std;

typedef vector<array<int,5>> vec1;

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
        //cout << x << endl;
        arr1[i] = x;
        i++;
        
    }

    for (int i=0; i<100; i++){
        string s = arr1[i];
        stringstream string_stream(s);
        int i2 = 0;

        while(string_stream.good()){
            string y;
            getline( string_stream, y, ',' );
            stringstream string_stream2(y);
            string_stream2 >> k;

            arr2[i][i2]=k;
            i2++;
        }
    }

	for(i=0;i<100;i++)
	{
       for (int i3=0;i3<5;i3++){
           cout << arr2[i][i3] << " ";
       }
       cout<<"\n";
	}
    
    vec1 vee;
    array <int,5> a;
    for(int i=0;i<100;i++)
    {   
        for(int j=0;j<5;j++)
        {
        get<0>(a)=arr2[i][0];
        get<1>(a)=arr2[i][1];
        get<2>(a)=arr2[i][2];
        get<3>(a)=arr2[i][3];
        get<4>(a)=arr2[i][4];
        vee.push_back(a);
        }
        
    }
    return vee;
}
int main()
{   
    vec1 ar;
    ar=array1();
    for(int i=0;i<100;i++)
	{
        cout << get<0>(ar[i]) << " "<<"\n";
	}
    return 0;
}