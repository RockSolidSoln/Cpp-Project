#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

typedef vector<int> vec1;
typedef vector<vector<int>> vec2;

void readfileformat(int &totalcol, string &titles, vec1 &computablecols, int &totalrow, vec2 &fulldata);
void askrowcolumn(const int totalrow, const int totalcol,const vec1 computablecols, int &row, int &col,int &roworcol);
void loadmean();
void findmean(const int totalcol,const int totalrow,const int col,const int row, const int roworcol,const vec1 computablecols,const vec2 fulldata,double &sum,double &sumofsq,double &mean, int &count);
void loadvar();
void findvar(const double sum,const double sumofsq,const int count, double &var);
void loadfindstdv();
void asktwocolumn(const int totalcol,const vec1 computablecols, int &col1, int &col2);
void loadfindcorr();


void readfileformat(int &totalcol, string &titles, vec1 &computablecols, int &totalrow, vec2 &fulldata){
  cout<<"Before proceeding enter the name of the data base file with proper extension\n";
    cin>>filename;
    ifstream data;
    data.open(filename);
    if(!data){
        cout<<"file doesn't exist\nTry again\n";
        clearfile();
    }

    data >> totalcol;
    data >> titles;

//find computable column or not like {0,1,1,1,1}
    string compute;
    string temp;
    int temp2;

    for (int i = 0; i < totalcol; i++){
        data >> compute;

        stringstream sscompute(compute);
        getline(sscompute, temp, ',');
        stringstream sstemp(temp);
        sstemp >> temp2;

        computablecols.push_back(temp2); 
    }

    data >> totalrow;

//find main data
    vec1 rowdata;
    string temp3, temp4;
    int temp5;
    
    for (int i = 0; i < totalrow; i++){

        data >> temp3;
        stringstream sstemp3(temp3);
        
        for (int j = 0; j < totalcol; j++){
            getline (sstemp3, temp4,','); //splite comma
            stringstream sstemp4(temp4); //convert into int
            sstemp4 >> temp5;
            rowdata.push_back(temp5); //add into vector
        }

        fulldata.push_back(rowdata); //add into 2d vector
        rowdata.clear();
    }
    
}


void askrowcolumn(const int totalrow, const int totalcol,const vec1 computablecols, int &row, int &col,int &roworcol){

    do{
        cout << endl << "Enter 1 for column or 2 for row" << endl;
        cin >> roworcol;
        if (!(roworcol ==1 || roworcol ==2))
            cout << "Invalid input. Please enter again." << endl;
    }while(!(roworcol ==1 || roworcol ==2));

    if (roworcol == 1){
        do{
            cout << endl << "Enter a column from 0 to " << totalcol - 1 << "." << endl;
            cin >> col;
            if (!(col >= 0 && col < totalcol && computablecols[col] == 1))
                cout << "Invalid input. Please enter a valid and computable column." << endl;
        }while (!(col >= 0 && col < totalcol && computablecols[col] == 1));
    } else{
        do{
            cout << endl << "Enter a row from 0 to " << totalrow - 1 << "." << endl;
            cin >> row;
            if (!(row >= 0 && row < totalrow))
                cout << "Invalid input. Please enter a valid row." << endl;
        }while(!(row >= 0 && row < totalrow));
    }
}


void loadmean(){
    int totalcol,totalrow,row,col,roworcol,count;
    double sum,sumofsq,mean;
    string titles;
    vec1 computablecols;
    vec2 fulldata;
    readfileformat(totalcol, titles, computablecols, totalrow, fulldata); //pass like that using variable above*****************see here impportant
    askrowcolumn(totalrow,totalcol,computablecols,row,col,roworcol);
    findmean(totalcol,totalrow,col,row,roworcol,computablecols,fulldata,sum,sumofsq,mean,count);

    cout << endl << "The mean of ";
    if (roworcol == 1)
        cout << "column " << col;
    else if (roworcol == 2)
        cout << "row " << row;
    cout << " is " << mean << ".";

}

void findmean(const int totalcol,const int totalrow,const int col,const int row, const int roworcol,const vec1 computablecols,const vec2 fulldata,double &sum,double &sumofsq,double &mean,int &count){
    sum = 0;
    sumofsq = 0;
    count = 0;
    if (roworcol==1){
        for (int i=0;i<totalrow;i++){
            sum = sum + fulldata[i][col];
            sumofsq = sumofsq + (fulldata[i][col]*fulldata[i][col]);
            count++;
        }
    } else if (roworcol==2){
        for (int i=0;i<totalcol;i++){
            if (computablecols[i]==1){
                sum = sum + fulldata[row][i];
                sumofsq = sumofsq + (fulldata[row][i]*fulldata[row][i]);
                count++;
            }
        }
    }
    mean = sum/count;
}

void loadvar(){
    int totalcol,totalrow,row,col,roworcol,count;
    double sum,sumofsq,mean,var;
    string titles;
    vec1 computablecols;
    vec2 fulldata;
    readfileformat(totalcol, titles, computablecols, totalrow, fulldata);
    askrowcolumn(totalrow,totalcol,computablecols,row,col,roworcol);
    findmean(totalcol,totalrow,col,row,roworcol,computablecols,fulldata,sum,sumofsq,mean,count);
    findvar(sum,sumofsq,count,var);

    cout << endl << "The variance of ";
    if (roworcol == 1)
        cout << "column " << col;
    else if (roworcol == 2)
        cout << "row " << row;
    cout << " is " << var << ".";
}

void findvar(const double sum,const double sumofsq,const int count, double &var){
    var = (sumofsq - ((sum*sum)/count)) / (count - 1);
}


void loadfindstdv(){
    int totalcol,totalrow,row,col,roworcol,count;
    double sum,sumofsq,mean,var,stdv;
    string titles;
    vec1 computablecols;
    vec2 fulldata;
    readfileformat(totalcol, titles, computablecols, totalrow, fulldata);
    askrowcolumn(totalrow,totalcol,computablecols,row,col,roworcol);
    findmean(totalcol,totalrow,col,row,roworcol,computablecols,fulldata,sum,sumofsq,mean,count);
    findvar(sum,sumofsq,count,var);
    stdv = sqrt(var);

    cout << endl << "The standard deviation of ";
    if (roworcol == 1)
        cout << "column " << col;
    else if (roworcol == 2)
        cout << "row " << row;
    cout << " is " << stdv << ".";
}

void asktwocolumn(const int totalcol,const vec1 computablecols, int &col1, int &col2){
    
    do{
        cout << endl << "Enter a column from 0 to " << totalcol - 1 << " for the first column." << endl;
        cin >> col1;
        if (!(col1 >= 0 && col1 < totalcol && computablecols[col1] == 1))
            cout << "Invalid input. Please enter a valid and computable column." << endl;
    }while (!(col1 >= 0 && col1 < totalcol && computablecols[col1] == 1));

    do{
        cout << endl << "Enter a column from 0 to " << totalcol - 1 << " for the second column." << endl;
        cin >> col2;
        if (!(col2 >= 0 && col2 < totalcol && computablecols[col2] == 1))
            cout << "Invalid input. Please enter a valid and computable column." << endl;
    }while (!(col2 >= 0 && col2 < totalcol && computablecols[col2] == 1));

}


void loadfindcorr()
{
    int totalcol,totalrow,roworcol,count,row,col1,col2;
    string titles;
    vec1 computablecols;
    vec2 fulldata;
    double sum1,sum2,sumofsq1,sumofsq2,mean1,mean2,sumofcol1x2,corr;
    roworcol = 1;
    sumofcol1x2 = 0;
    readfileformat(totalcol, titles, computablecols, totalrow, fulldata);
    asktwocolumn(totalcol,computablecols,col1,col2);
    findmean(totalcol,totalrow,col1,row,roworcol,computablecols,fulldata,sum1,sumofsq1,mean1,count);
    findmean(totalcol,totalrow,col2,row,roworcol,computablecols,fulldata,sum2,sumofsq2,mean2,count);
    for (int i = 0; i < totalrow;i++){
        sumofcol1x2 = sumofcol1x2 + (fulldata[i][col1]*fulldata[i][col2]);
    }
    double doublerow = (double)totalrow;
    corr = (sumofcol1x2-(doublerow*mean1*mean2))/(sqrt(sumofsq1-(doublerow*mean1*mean1))*sqrt(sumofsq2-(doublerow*mean2*mean2)));    
    cout << "The correlation between column " << col1 << " and " << col2 << " is " << corr << endl;
}

int main(){

    loadfindcorr();
    return 0;
}