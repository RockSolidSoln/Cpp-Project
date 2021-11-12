// ----------------------------------------start of the program---------------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main()
{   
    int ar=[3,2,2,3,6];
    for(int i=0;i<5;i++)
    {
        cout<<ar[i]<<" ";
    }
    
    int t= sizeof(ar)/sizeof(ar[0]);
    sort(ar, ar+t);
    for(int i=0;i<5;i++)
    {
        cout<<ar[i]<<" ";
    }
    return 0;
}