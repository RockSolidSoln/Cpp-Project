include <iostream>
using namespace std;

int main()
{
   vec1 ar;
    ar=array1();
    cout <<"Please choose the column from 2 to 4."<<endl;
    int choice;
    cin>>choice;
    cout<<"Subject"<<"             "<<"Mid-point\n";
    for(int i=0;i< 100; i++)
    {
        if (choice == 2)
       { 
        cout<< get<2>(ar[i])<<"                    "
            <<get<0>(ar[i]);
        for(int j=0;j<  get<2>(ar[i]);j++)
        cout<<"=";
       }
        else if (choice == 3)
        {
        cout<< get<3>(ar[i])<<"                 "
            << get<0>(ar[i]);
         for(int j=0;j<get<3>(ar[i]);j++)
         cout<<"=";   
        }
        else if (choice == 4)
        {
        cout<< get<4>(ar[i])<<"                    "
            << get<0>(ar[i]);
         for(int j=0;j<get<4>(ar[i]);j++)
         cout<<"=";  
        }
        cout<<endl;  
    }
    cout<<"----------------------------0---------10---------"
        <<"20--------30--------40--------50--------"
        <<"60--------70--------80--------90--------100\n";      
    logrecord(" made a Histogram");
    pressenter(2);
    return 0;
}