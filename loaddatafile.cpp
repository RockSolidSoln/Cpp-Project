#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("sample.txt");

    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    int col, row;
   cout <<"Enter number of columns"; 
   cin>>col;
   string titles[col];
   cout<<"\nEnter column titles";
   for (int z=0; z<col; z++)
        cin>>titles[z];
   cout<<"\nEnter number of rows ";
   cin>>row;
   //table row 0 = titles[][col]
   int table[row+1][col];
    for (int i=1; i<=row; i++)
    {
        cout<<"\nEnter row "<<i;
        for (int j=0; j<col; j++)
            {
                cin>>table[i][j];
            }
    }

    inFile.close();

    cout<<endl<<col<<endl;
    cout<<row<<endl;
    for (int z=0; z<col; z++)
        cout<<titles[z]<<" ";
    for (int i=1; i<=row; i++)
    {
        cout<<"\nEnter row "<<i<<endl;
        for (int j=0; j<col; j++)
            {
                cout<<table[i][j]<<" ";
            }
    }
       cout<<endl;

   return 0;
}