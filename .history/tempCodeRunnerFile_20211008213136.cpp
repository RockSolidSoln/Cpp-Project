//void createuser() 
// {
//     ifstream file;
//     file.open("Users.dat");
//     vector<tuple<string,int,string,int>> users;
//     tuple<string,int,string,int> userdata;
//      while (file>>get<0>(userdata)){
//         file >>get<1>(userdata);
//         file >>get<2>(userdata);
//         file >>get<3>(userdata);
//         users.push_back(userdata);
//     }

//      for (auto elem: users)
//     {   
//         string user,pass;
//         int status,power;
//         if (!file.is_open())
//         {
//             cout << " File not found\n";
//             exit(-1);
//         }
//         else
//         {   int pos;
//             cout << "-----------------------------------------------------\n"
//                 <<"Enter a unique user name -\n";
//             cin >> user;
//             cout << "-----------------------------------------------------\n"
//                 <<"Enter your password -\n";
//             cin >> pass;
//             ofstream outfile;
//             outfile.open("Users.dat",ios::out|ios::ate|ios::app);
//             status=1;
//             power=0;
//             outfile << user << " " << power << " " << pass << " " << status<<endl;
//             outfile.close();
//             file.close();
//             cout<<"Username and password created successfully.\n"<<endl;
//             break;
//         }
//         }
//     }

// //----------------------------This functions login user in the system---------------------------------
// void loginuser() 
// {
//     vector<tuple<string,int,string,int>> users;
//     tuple<string,int,string,int> userdata;
//     ifstream file;
//     file.open("Users.dat");
//     while (file>>get<0>(userdata))
//     {
//         file >>get<1>(userdata);
//         file >>get<2>(userdata);
//         file >>get<3>(userdata);
//         users.push_back(userdata);
//     }

//     file.close();

//     string name, pass;
//     cout << "-----------------------------------------------------\n"
//         << "Enter Username-\n";
//     cin >> name;
//     cout << "-----------------------------------------------------\n"
//         << "Enter Password-\n ";
//     cin >> pass;

//     for (auto elem: users)
//     {
//          if (name == get<0>(elem) &&
//              pass == get<2>(elem) &&
//              get<3>(elem)==1)
//         {
//             cout << get<0>(elem) << ": "
//                  << ((get<1>(elem)==1)?"admin":"user")
//                  << ": " <<get<2>(elem) << ": "
//                  << ((get<3>(elem)==1)?"Active":"Deleted")
//                  << endl;
//             if(get<1>(elem)==1)
//             {
//                 cout<<"Welcome admin- "<<get<0>(elem)<<endl;
//                 datafilereader();
//             }
//             else{
//                 cout<<"Id- "<<get<0>(elem)<< " is not an admin "<<endl;
//             }
//                  break;
//         }
//         else{
//             cout << "-----------------------------------------------------\n"
//                 <<"Wrong username or password\n"
//                 <<"Please try again\n";
//                 loginuser();
//         }
// }
// }