#include <vector>
#include <string>
#include <array>
#include <iostream>
#include <fstream>
using namespace std;

typedef vector<array<int,int,int,int,int>> vec1;
int array1()
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
    
    vec1 data;
    for(int i=0;i<100;i++)
    {
        get<0>(data[i])=arr2[][0];
        get<1>(data[i])=arr2[1][0];
        get<2>(data[i])=arr2[1][0];
        get<3>(data[i])=arr2[1][0];
        get<4>(data[i])=arr2[1][0];
        data.push_back(stdata);
        
    }
    file.close();
    return data;;
}
int main()
{
    array1();
    return 0;
}