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
    string filename;
    int counter=0,column,temp,row;
    ifstream data;
    string str,strtemp;
    // cout<<"Before proceeding enter the name of the data base file with proper extension\n";
    // cin>>filename;
    data.open("StudentDataBase.dat");
    if(!data){
        cout<<"file doesn't exist\nTry again\n";
        // clearfile();
    }
    else cout<<"File was loaded successfully\n";
    
    data>>column;
    cout<<column<<endl;

    data>>str;
    cout<<str<<endl;

    int compute[column];
    for (int i=0;i<column;i++){
        data >> strtemp;
        stringstream ssstrcompute(strtemp);
        ssstrcompute >> temp;
        compute[i] = temp;
        counter++;
        cout<<compute[i]<<" ";
    }
    
    data>>row;
    cout<<row<<endl;

    string arr1[row];
    int arr2[100][5],k=0;
    for(int i=0; i<row; i++){
        string x;
        data >> x;
        arr1[counter] = x;
        counter++;
        cout<<x<<endl;
    }
    cout<<counter<<endl;//gives number of rows in any file
    for (int i=4; i<counter; i++){
        string s = arr1[i];
        stringstream string_stream(s);
        int counter2 = 0;
        while(string_stream.good()){
            string y;
            getline(string_stream, y, ',' );
            stringstream string_stream2(y);
            string_stream2 >> k;
            arr2[i][counter2]=k;
        }
    }
    for(int i=4;i<counter;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
//    database(filename,arr2);

return 0;
}
