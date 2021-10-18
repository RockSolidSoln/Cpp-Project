#include <iostream>
#include <iomanip>

using namespace std;

int main()
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
     <<"--------------------------------------------------------\n"
     <<endl;
    cin>ch;
    switch(ch)
    {
         case(1)    : findMin()
                         break;
         case(2)    : findMax()
                         break;
         case(3)    : findMed()                
                         break;
         case(4)    : findMean()
                         break;
         case(5)    : findVar()                                
                         break;
         case(6)    : findDev()
                         break;                
    }
    



















return 0;
}