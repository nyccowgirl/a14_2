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

#include "mystring.hpp"
#include <iostream>
#include <cassert>
using namespace std;

namespace cs_mystring {

/*
  
 Class Invariant: a MyString object has one char data member - cstring, which stores an
 array of characters.
    
*/

    MyString::MyString() {
        cstring = new char[1];
        strcpy(cstring, "");
    }






    MyString::MyString(const char *inCstring) {
        cstring = new char[strlen(inCstring) + 1];
        strcpy(cstring, inCstring);
    }






    MyString::MyString(const MyString &str) {
        cstring = new char[str.length() + 1];
        strcpy(cstring, str.cstring);
    }






    MyString::~MyString() {
        delete [] cstring;
    }






    int MyString::length() const {
        return (int)strlen(cstring);
    }






    char MyString::operator[](int index) const {
        assert(index >= 0 && index < strlen(cstring));
        return cstring[index];
    }






    char& MyString::operator[](int index) {
        assert(index >= 0 && index < strlen(cstring));
        return cstring[index];
    }






    MyString MyString::operator=(const char *inCstring) {
        if (strcmp(cstring, inCstring) != 0) {
            delete [] cstring;
            cstring = new char[strlen(inCstring) + 1];
            strcpy(cstring, inCstring);
        }
        return *this;
    }






    MyString MyString::operator=(const MyString &right) {
        if (this != &right){
            delete [] cstring;
            cstring = new char[strlen(right.cstring) + 1];
            strcpy(cstring, right.cstring);
        }
        return *this;
    }





    MyString MyString::operator+=(const char *inCstring) {
        *this = *this + inCstring;
        return *this;
    }






    MyString MyString::operator+=(const MyString &right) {
        *this = *this + right;
        return *this;
    }






    void MyString::read(std::istream &in, char deliminator) {
        char temp[MyString::MAX_SIZE + 1];
        in.getline(temp, MyString::MAX_SIZE, deliminator);
        delete [] cstring;
        cstring = new char[strlen(temp) + 1];
        strcpy(cstring, temp);
    }






    MyString operator+(const MyString &left, const MyString &right) {
        MyString temp;
        temp.cstring = new char[left.length() + right.length() + 1];
        strcpy(temp.cstring, left.cstring);
        strcat(temp.cstring, right.cstring);
        return temp;
    }






    bool operator<(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) < 0;
    }






    bool operator<=(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) <= 0;
    }






    bool operator>(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) > 0;
    }






    bool operator>=(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) >= 0;
    }






    bool operator==(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) == 0;
    }






    bool operator!=(const MyString &left, const MyString &right) {
        return strcmp(left.cstring, right.cstring) != 0;
    }






    istream &operator>>(istream &in, MyString &right) {
        while (isspace(in.peek())){
            in.ignore();
        }
        
        char temp[MyString::MAX_SIZE + 1];
        in >> temp;
        delete [] right.cstring;
        right.cstring = new char[strlen(temp) + 1];
        strcpy(right.cstring, temp);
        return in;
    }






    ostream &operator<<(ostream &out, const MyString &right) {
        out << right.cstring;
        return out;
    }
}
