# C++ Data Analysis program

This is one of the 1st year project for programming fundamentals Students.

Our Data Analysis Software requires some conditions to be able to run optimally. First of all the program needs a database to be able to withdraw and write data into, another database that contains username and passwords to identify who has access to the software, the registry database can be modified within the program after verifying the personnel has the right to modify it if he is an admin.


The program asks the user to input 1 if he wishes to continue and 0 if he wants to exit, based on the user’s choice it directs the user to its desired place.

The program then asks the user to input its a username and then the password.
The program then checks if the username and password match the database and then gives the different menus if the user is an admin or a regular user.
The admin menu contains special functions like the creation of a new user or the deletion of an old one.
The regular user menu does not have special functions.
The user is asked to load the Specified file he wants and to perform the functions with and then is directed to the Statistical Analysis menu if he presses the option so that he can perform a function.
# You can change the program according to your needs and datafields.
After performing a function, the user is directed to the report’s menu and then is asked if he wants to go back to perform more operations. He can generate a report right after performing one function.

Users.dat have the user's info with password, 0 for nornal user and 1 for admin user.

Activity.dat keeps the record of user activity throughout all the choices they made.

Report.dat is to generate the Report .

Report.html is to create in a html report.
