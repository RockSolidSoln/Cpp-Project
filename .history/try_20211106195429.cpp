{
    string filename;
    int column,temp,row;
    string str,strtemp;
    cout<<"Before proceeding enter the name of the data base file with proper extension\n";
    cin>>filename;
    ifstream data;
    data.open(filename);
    if(!data){
        cout<<"file doesn't exist\nTry again\n";
        clearfile();
    }
    else cout<<"File was loaded successfully\n";
    
    data>>column;

    data>>str;

    int compute[column];
    for (int i=0;i<column;i++){
        data >> strtemp;
        stringstream ssstrcompute(strtemp);
        ssstrcompute >> temp;
        compute[i] = temp;
    }
    
    data>>row;

    string arr1[row];
    for(int i=0; i<row; i++){
        string x;
        data >> x;
        arr1[i] = x;
    }
    int **arr2;
    arr2=getArray(row,column);
    database(filename,arr2,arr1,row,column);
    viewfunc(arr2,row,column);
}