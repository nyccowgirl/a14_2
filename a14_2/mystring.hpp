/*
 Trang Hoang
 CS110B
 Dave Harden
 12/2/20
 a14_2.cpp
 
 Assignment 14.1
 
 In this assignment you will use the MyString class that you wrote earlier in this course.

 A palindrome is a string that reads the same forward and backward. Write a program that
 reads in any number of MyStrings from the user and determines if each MyString is a
 palindrome. The user will terminate each MyString by pressing the return (or enter)
 button. The user will indicate that there are no more MyStrings by entering "quit".

 To do this you must write a recursive function named isAPalindrome that takes a single
 MyString argument and two arguments that are bounds on MyString indices. The function must
 examine the part of the argument between the two bounds (including the bounds) and return
 true if this part of the argument is a palindrome, false if it is not a palindrome. The
 function must be recursive and must not call any other functions except ispunct(),
 isspace(), and toupper() (described below).

 Do not make any changes to the MyString class (except, if necessary, to correct errors in
 your MyString class). In particular, note that the isAPalindrome() function is not part of
 the MyString class. You will be submitting only your client file containing your main()
 function and your isAPalindrome() function. Do not submit your MyString class. Do not use
 the C++ string class.

 Follow this sample output closely:

 Enter a string: Able was I, ere I saw Elba
 Able was I, ere I saw Elba is a palindrome.
 Enter a string: peanut butter
 peanut butter is not a palindrome.
 Enter a string: quit
 
 In determining whether a string is a palindrome, this function must consider uppercase and
 lowercase letters to be the same and ignore punctuation characters and whitespace
 characters. You must not modify the argument in any way or make a copy of the argument to
 accomplish this. The simplest way to handle uppercase/lowercase issues is to make
 everything uppercase on the fly, right at the instant that you are comparing the two
 characters.
 
 Created by nyccowgirl on 12/2/20.
 Copyright © 2020 nyccowgirl. All rights reserved.
 */

#ifndef mystring_hpp
#define mystring_hpp

#include <iostream>

namespace cs_mystring {

/*
 
 The MyString class can be used to create objects that store a cstring. The following
 functions are available:

 MyString();
 post: The** calling object has been created and initialized to empty MyString object.
 
 MyString(const char *inCstring);
  post: The calling object has been created and initialized so that the cstring is the
        inCstring parameter.
 
 MyString(const MyString &str);
  post: The calling object has been created and initialized so that the cstring is the value
        of MyString str parameter.
 
 ~MyString();
  post: Destructor for the class.
 
 int length() const;
  post: Returns the length of MyString object.
 
 char operator[](int index) const;
  pre: Paramenter must be 0 or positive value.
  post: Returns the character at the index specified of the calling object. If index is not
        between 0 and one less than the length of the calling object, the program is
        aborted.
 
 char& operator[](int index);
  pre: Parameter must be 0 or positive value.
  post: Returns reference to a variable at the index specified of the calling object. If the
        index is not between 0 and one less than the length of the calling object, the
        program is aborted.
 
 MyString operator=(const char *inCstring);
  post: Returns the value of inCstring that was assigned to the calling object.
 
 MyString operator=(const MyString &right);
  post: Returns the value of the MyString object that was assigned to the calling object.
 
 MyString operator+=(const char *inCstring);
  post: Returns the value of the calling object combined with the value of inCstring that
        was assigned to the calling object.
 
 MyString operator+=(const MyString &right);
  post: Returns the value of the calling object combined with the MyString object that was
        assigned to the calling object.
 
 void read(istream &in, char deliminator);
  pre: Client programmer specifies appropriate deliminating character.
  post: Uses in.getline() function to read line from file into non-dynamic array up to the
        deliminating character and converts each line to the data member of calling object.
 
 friend MyString operator+(const MyString &left, const MyString &right);
  post: The calling object is created and initialized to combine the MyString of the
        parameter "left" with the MyString of the parameter "right".
 
 friend bool operator<(const MyString &left, const MyString &right);
  post: Returns true if the MyString of the parameter "left" is less than the MyString of
        the parameter "right" based on ASCII values. Otherwise, returns false.
 
 friend bool operator<=(const MyString &left, const MyString &right);
  post: Returns true if the MyString of the parameter "left" is less than or equal to the
        MyString of the parameter "right" based on ASCII values. Otherwise, returns false.
 
 friend bool operator>(const MyString &left, const MyString &right);
  post: Returns true if the MyString of the parameter "left" is greater than the MyString of
        the parameter "right" based on ASCII values. Otherwise, returns false.
 
 friend bool operator>=(const MyString &left, const MyString &right);
  post: Returns true if the MyString of the parameter "left" is greater than or equal to the
        MyString of the parameter "right" based on ASCII values. Otherwise, returns false.

 friend bool operator==(const MyString &left, const MyString &right);
  post: Returns true if the MyString of the parameter "left" is equal to the MyString of
        the parameter "right" based on ASCII values. Otherwise, returns false.

 friend bool operator!=(const MyString &left, const MyString &right);
  post: Returns true if the MyString of the parameter "left" is not equal to the MyString
        of the parameter "right". Otherwise, returns false.
 
 friend std::istream &operator>>(std::istream &in, MyString &right);
  post: Skips leading spaces and reads characters into a string up to first whitespace
        character and converts each line to MyString object.

 friend std::ostream &operator<<(std::ostream &out, const MyString &right);
  post: The calling object has been printed to the console window in the formats of string.
         
*/

    class MyString {
        public:
            static const int MAX_SIZE = 127;
            MyString();
            MyString(const char *inCstring);
            MyString(const MyString &str);
            ~MyString();
            int length() const;
            char operator[](int index) const;
            char& operator[](int index);
            MyString operator=(const char *inCstring);
            MyString operator=(const MyString &right);
            MyString operator+=(const char *inCstring);
            MyString operator+=(const MyString &right);
            void read(std::istream &in, char deliminator);
            friend MyString operator+(const MyString &left, const MyString &right);
            friend bool operator<(const MyString &left, const MyString &right);
            friend bool operator<=(const MyString &left, const MyString &right);
            friend bool operator>(const MyString &left, const MyString &right);
            friend bool operator>=(const MyString &left, const MyString &right);
            friend bool operator==(const MyString &left, const MyString &right);
            friend bool operator!=(const MyString &left, const MyString &right);
            friend std::istream &operator>>(std::istream &in, MyString &right);
            friend std::ostream &operator<<(std::ostream &out, const MyString &right);

        private:
            char *cstring;
    };
}



#endif /* mystring_hpp */
