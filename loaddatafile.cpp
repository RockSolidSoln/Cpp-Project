#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    vector<string> data;
    string str;
    cout<<"enter the file name ";
    cin >> str;

    ifstream infile;
    infile.open(str+".dat");

    if(infile.fail())
    {
        cout << "your file didn't work. ";
    }

    else{
      string s;
      while(infile>>s)
    {
        data.push_back(s);
        cout<<s<<endl;
    }
    }


string newfilename;
cout << " enter the new file name "<< endl;
cin >>newfilename;

ofstream file(newfilename+".dat",ios::app);
    for (int i=0; i<data.size(); i++)
         file << data[i] << endl;
       

}

