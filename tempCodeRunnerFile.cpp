void reportsmenu()
// {
//     char ch;
//     cout <<"--------------------------------------------------------\n"
//         <<"          "<<username<<" ,Please enter a number to procced:\n"
//         <<"--------------------------------------------------------\n"
//         <<"|  Enter 1 to create a report as a text file           |\n"
//         <<"|  Enter 2 to create a HTML report                     |\n"
//         <<"|  Enter B to go back to perform more functions        |\n"
//         <<"|  Enter U to go back to User's settings menu          |\n"
//         <<"|  Enter 0 to exit                                     |\n"
//         <<"--------------------------------------------------------\n";
//     cin>>ch;
//     cin.ignore(' ','\n');
//     string str=" choose the report's menu option ";
//     logrecord(str);
//     switch(ch)
//     {
//          case('1')    : savereport();
//                          break;
//          case('2')    : saveHTMLreport();
//                          break;
//          case('B')    : viewfunc();
//                          break;
//          case('U')    : getchoice();
//                          break;
//          case('0')    : exit(0);
//                          break;               
//          default: cout<<"Wrong choice------------->\n"
//                         <<"Please Enter from the choice given below\n";
//                 reportsmenu();
//                 break;         
//     }