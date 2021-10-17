#include <iostream>
#include <string>
#include <fstream>
<<<<<<< Updated upstream
#include <vector>
=======
>>>>>>> Stashed changes
using namespace std;

int main()
{
<<<<<<< Updated upstream
    vector<string> data;
    string str;
    cout<<"enter the file name ";
    cin >> str;

    ifstream infile;
    infile.open(str+".dat");
=======
    ifstream infile;
    infile.open("StudentDataBase.dat");
>>>>>>> Stashed changes

    if(infile.fail())
    {
        cout << "your file didn't work. ";
    }
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
    else{
      string s;
      while(infile>>s)
    {
<<<<<<< Updated upstream
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

=======
        cout<<s<<endl;
    }
    infile.close();
    infile.clear();
    }
    return 0;
}
>>>>>>> Stashed changes
