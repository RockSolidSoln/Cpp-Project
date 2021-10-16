#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

 read(int &arr2[99][5]){
    string arr1[100];
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

            arr1[i][i2]=k;
            i2++;
        }
    }

	// for(int i=0;i<100;i++)
	// {
    //    for (int i3=0;i3<5;i3++){
    //        cout << arr2[i][i3]<<" ";
    //    }
    //    cout<<endl;
	// }
}

int main()
{
    int x[99][4];
    read(x);
    for(int i=0;i<100;i++)
	{
       for (int i3=0;i3<5;i3++)
       {
           cout << x[i][i3]<<" ";
       }
       cout<<endl;
	}
    return 0;
}
