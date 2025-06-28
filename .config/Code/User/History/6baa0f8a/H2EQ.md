# Library Management System

This is a tool built in Java, that emulates a Library <br>
Management System. <br>

The User can add or remove books, issue books to Users <br>
and keep track of all transactions, and the state of the <br>
library as well as those of individual users.

# Features 

- View Books <br>
- Add Book <br>
- Remove Book
- 

# Project Structure

Library.java :-
- This is our program entry point and has a main method. <br>
- A printMenu() function prints the user menu. <br>
- The main function has an infinite while loop. Inside, it <br> 
calls printMenu() and takes the user choice in variable choice. <br>
If choice==0 > break out of loop and end program.
Else If choice==1 > 

Book.java :- <br>
- Serves as the holder of all information regarding one book. <br>
- Has attributes bookID, title, author, totalCopies, availCopies. <br>
- Has parameterised constructor for bookID, title and author. <br>
- Has getters for everything, and setters for totalCopies and availCopies.

User.java :-
- 