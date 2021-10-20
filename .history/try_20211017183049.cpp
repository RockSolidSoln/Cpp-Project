#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
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

    vec1 vee;
    array <int,5> a;
    for(int i=0;i<100;i++)
    {
        get<0>(a)=arr2[i][0];
        get<1>(a)=arr2[i][1];
        get<2>(a)=arr2[i][2];
        get<3>(a)=arr2[i][3];
        get<4>(a)=arr2[i][4];
        vee.push_back(a);
    }
    return vee;
}

//============================================================================================
void findrowmean(int ch,int &row,float &rowmean,double &rowsum,double &rowsqsum){
    rowsum = 0;
    rowsqsum = 0;
    rowmean = 0;
    vec1 ar;
    ar=array1();
    if(row==-1){
        cout << "Enter row from 1-100:" << endl;
        cin >> row;
    }
    rowsum = rowsum + get<1>(ar[row-1]);
    rowsum = rowsum + get<2>(ar[row-1]);
    rowsum = rowsum + get<3>(ar[row-1]);
    rowsum = rowsum + get<4>(ar[row-1]);
    rowsqsum = rowsqsum + (get<1>(ar[row-1])*get<1>(ar[row-1]));
    rowsqsum = rowsqsum + (get<2>(ar[row-1])*get<2>(ar[row-1]));
    rowsqsum = rowsqsum + (get<3>(ar[row-1])*get<3>(ar[row-1]));
    rowsqsum = rowsqsum + (get<4>(ar[row-1])*get<4>(ar[row-1]));
    rowmean = rowsum/4;

    if(ch==4)
    cout << "The mean of row " << row << " is " << rowmean << endl;
}

void findcolmean(int ch,int &col,float &colmean,double &colsum,double &colsqsum){
    colsum = 0;
    colsqsum = 0;
    colmean = 0;
    vec1 ar;
    ar=array1();
    if(col==-1){
        cout << "Enter column from 2-5:" << endl;
        cin >> col;
    }
    switch(col){
        case 2: for(int i=0;i<100;i++){
            colsum = colsum + get<1>(ar[i]);
            colsqsum = colsqsum + (get<1>(ar[i])*get<1>(ar[i]));}break;
        case 3: for(int i=0;i<100;i++){
            colsum = colsum + get<2>(ar[i]);
            colsqsum = colsqsum + (get<2>(ar[i])*get<2>(ar[i]));}break;
        case 4: for(int i=0;i<100;i++){
            colsum = colsum + get<3>(ar[i]);
            colsqsum = colsqsum + (get<3>(ar[i])*get<3>(ar[i]));}break;
        case 5: for(int i=0;i<100;i++){
            colsum = colsum + get<4>(ar[i]);
            colsqsum = colsqsum + (get<4>(ar[i])*get<4>(ar[i]));}break;
    }
    colmean = colsum/100;

    if(ch==4)
    cout << "The mean of column " << col << " is " << colmean << endl;
}

void loadmean(int ch){
    int row = -1;
    int col = -1;
    int rc;
    float rowmean,colmean;
    double rowsum,colsum,rowsqsum,colsqsum;
    cout << endl << "Enter 1 to find mean of a row or 2 to find mean of a column:" << endl;
    cin >> rc;
    if (rc==1){
        findrowmean(ch,row,rowmean,rowsum,rowsqsum);
    } else if(rc==2){
        findcolmean(ch,col,colmean,colsum,colsqsum);
    }
}

void findrowvar(int ch,int &row,float &rowmean,double &rowsum,double rowsqsum,double &rowvar){
    rowvar = 0;
    findrowmean(ch,row,rowmean,rowsum,rowsqsum);
    rowvar = ((rowsqsum)-((rowsum*rowsum)/4))/3;
    if(ch==5)
    cout << "The variance of column " << row << " is " << rowvar << endl;
}

void findcolvar(int ch,int &col,float &colmean,double &colsum,double colsqsum,double &colvar){
    colvar = 0;
    findcolmean(ch,col,colmean,colsum,colsqsum);
    colvar = ((colsqsum)-((colsum*colsum)/100))/99;
    if(ch==5)
    cout << "The variance of column " << col << " is " << colvar << endl;
}

void loadvar(int ch){
    int row = -1;
    int col = -1;
    int rc;
    float rowmean,colmean;
    double rowsum,colsum,rowsqsum,colsqsum,rowvar,colvar;
    cout << endl << "Enter 1 to find variance of a row or 2 to find variance of a column:" << endl;
    cin >> rc;
    if (rc==1){
        findrowvar(ch,row,rowmean,rowsum,rowsqsum,rowvar);
    } else if(rc==2){
        findcolvar(ch,col,colmean,colsum,colsqsum,colvar);
    }
}

void findrowstdv(int ch,int &row,float &rowmean,double &rowsum,double rowsqsum,double &rowvar,double &rowstdv){
    rowstdv=0;
    findrowvar(ch,row,rowmean,rowsum,rowsqsum,rowvar);
    rowstdv= sqrt(rowvar);
    cout << "The standard deviation of row " << row << " is " << rowstdv << endl;
}

void findcolstdv(int ch,int &col,float &colmean,double &colsum,double colsqsum,double &colvar, double &colstdv){
    colstdv = 0;
    findcolvar(ch,col,colmean,colsum,colsqsum,colvar);
    colstdv = sqrt(colvar);
    cout << "The standard deviation of column " << col << " is " << colstdv << endl;
}

void loadstdv(int ch){
    int row = -1;
    int col = -1;
    int rc;
    float rowmean,colmean;
    double rowsum,colsum,rowsqsum,colsqsum,rowvar,colvar,rowstdv,colstdv;
    cout << endl << "Enter 1 to find standard deviation of a row or 2 to find standard deviation of a column:" << endl;
    cin >> rc;
    if (rc==1){
        findrowstdv(ch,row,rowmean,rowsum,rowsqsum,rowvar,rowstdv);
    } else if(rc==2){
        findcolstdv(ch,col,colmean,colsum,colsqsum,colvar,colstdv);
    }
}

void findcolsum12(int col,int col2,double &colsum12){
    vec1 ar;
    ar=array1();
    colsum12 = 0;
    if((col==2 && col2==3)||(col==3 && col2==2)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<1>(ar[i])*get<2>(ar[i]));
    }
    if((col==2 && col2==4)||(col==4 && col2==2)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<1>(ar[i])*get<3>(ar[i]));
    }
    if((col==2 && col2==5)||(col==5 && col2==2)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<1>(ar[i])*get<4>(ar[i]));
    }
    if((col==3 && col2==4)||(col==4 && col2==3)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<2>(ar[i])*get<3>(ar[i]));
    }
    if((col==3 && col2==5)||(col==5 && col2==3)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<2>(ar[i])*get<4>(ar[i]));
    }
    if((col==4 && col2==5)||(col==5 && col2==4)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<3>(ar[i])*get<4>(ar[i]));
    }
}

void findcorrelation(int ch,int &col,float &colmean,double &colsum,double &colsqsum,double &corr){
    int col2;
    float colmean2;
    double colsum2,colsqsum2,colsum12;
    cout << "Enter the first column from 2-5:" << endl;
    cin >> col;
    findcolmean(ch,col,colmean,colsum,colsqsum);
    cout << "Enter the second column from 2-5:" << endl;
    cin >> col2;
    findcolmean(ch,col2,colmean2,colsum2,colsqsum2);
    findcolsum12(col,col2,colsum12);
    corr = (colsum12-(100*colmean*colmean2))/(sqrt(colsqsum-(100*colmean*colmean))*sqrt(colsqsum2-(100*colmean2*colmean2)));
    cout << "The correlation between column " << col << " and " << col2 << " is " << corr << endl;
}

void loadcorr(int ch){
    int row = -1;
    int col = -1;
    float rowmean,colmean;
    double rowsum,colsum,rowsqsum,colsqsum,corr;
    findcorrelation(ch,col,colmean,colsum,colsqsum,corr);
}

void finddistinct(){
    vec1 ar;
    ar=array1();
    int min = 1; //should be find min
    int max = 1000; //should be find max
    cout << "     Distinct Numbers Table    " << endl;
    cout << "---------------+---------------" << endl;//15-+15-
    cout << "|    Number    |   Frequency  |" << endl;
    cout << "---------------+---------------" << endl;
    for (int k=min;k<=max;k++){
        int f = 0;
        for (int i=0;i<100;i++){
            if (k == get<1>(ar[i]))
                f++;
            if (k == get<2>(ar[i]))
                f++;
            if (k == get<3>(ar[i]))
                f++;
            if (k == get<4>(ar[i]))
                f++;
        }
        if (f!=0){
            cout << "|" << setw(7) << right << k;
            cout << setw(8) << right <<"|";
            cout << setw(8) <<right << f;
            cout << setw(7) << right <<"|" << endl;
            cout << "---------------+---------------" << endl;
        }
    }

}
//==================================================================================================
void viewfunc()
{
    int ch;

cout <<"--------------------------------------------------------\n"
     <<"|        please enter a number to procced:             |\n"
     <<"--------------------------------------------------------\n"
     <<"|  Enter 1 to find the minmum value:                   |\n"
     <<"|  Enter 2 to find the maximum value:                  |\n"
     <<"|  Enter 3 to find the median of the value:            |\n"
     <<"|  Enter 4 to find the mean of the value:              |\n"
     <<"|  Enter 5 to find the variance of the value:          |\n"
     <<"|  Enter 6 to find the standard deviation of the value |\n"   
     <<"|  Enter 7 to find the correlation between the values  |\n"   
     <<"|  Enter 8 to find the distinct data members           |\n"   
     <<"--------------------------------------------------------\n"
     <<endl;
    cin>>ch;
    switch(ch)
    {
         //case(1)    : findMin()
         //                break;
         //case(2)    : findMax()
          //               break;
         //case(3)    : findMed()                
         //                break;
         case(4)    : loadmean(ch);
                         break;
         case(5)    : loadvar(ch);
                         break;
         case(6)    : loadstdv(ch);
                         break;                
         case(7)    : loadcorr(ch);
                         break;     
         case(8)    : finddistinct();
                         break;   
    }
}

int main()
{
    //int row = -1;
    //int col = -1;
    //float rowmean,colmean;
    //double rowsum,colsum,rowsqsum,colsqsum,rowvar,colvar,rowstdv,colstdv,corr;
    //findrowmean(row,rowmean,rowsum,rowsqsum);
    //cout << rowmean << " "<< rowsqsum << " "<< rowsum << endl;
    //findcolmean(col,colmean,colsum,colsqsum);
    //cout << colmean << " "<< colsqsum << " "<< colsum<< endl;
    //findrowstdv(row,rowmean,rowsum,rowsqsum,rowvar,rowstdv);
    //cout << rowmean << " "<< rowmean*rowmean << " "<< rowsqsum << " "<< rowsqsum/4 << " "<< (rowsqsum/4)-(rowmean*rowmean) << " "<< rowvar << " "<< rowstdv << endl; 
    //findcorrelation(col,colmean,colsum,colsqsum,corr);
    //cout <<  colmean<<" "<<colsum<<" "<<colsqsum<< "corr "<< corr <<endl;
    //finddistinct();
    viewfunc();
    return 0;
}
