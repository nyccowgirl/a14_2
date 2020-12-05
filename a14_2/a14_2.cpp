/*
 Trang Hoang
 CS110B
 Dave Harden
 12/2/20
 a14_2.cpp
 
 Assignment 14.2
 
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
#include <cctype>
using namespace std;
using namespace cs_mystring;


bool isAPalindrome(MyString str, int left, int right);


int main(int argc, const char * argv[]) {
    MyString str;
    
    // test cases
//    MyString str1 = "Hello, World!";
//    MyString str2 = "racecar";
//    MyString str3 = "x";
//    MyString str4 = "Able was I, ere I saw Elba";
//    MyString str5 = "peanut butter";
//    MyString str6 = "Aa";
//    MyString str7 = "aB";
//    MyString str8 = "Astrologica";

    do {
        cout << "Enter a string: ";
        str.read(cin, '\n');

        if (str != "quit") {
            if (isAPalindrome(str, 0, str.length() - 1)) {
                cout << str + " is a palindrome." << endl;
            } else {
                cout << str + " is not a palindrome." << endl;
            }
        }

    } while (str != "quit");
    
    return 0;
}






/*
 Definition of function isAPalindrome that takes in a string and two integers representing
 left and right bound (inclusive) to determine if the substring is a palindrome, ignoring
 punctuation, whitespace and cases. Returns true if it is a palindrome, and false otherwise.
 */

bool isAPalindrome(MyString str, int left, int right) {
    int length = str.length();
    int idxL = left;
    int idxR = right;
    
    while (ispunct(str[idxL]) || isspace(str[idxL])) {
        idxL++;
    };

    while (ispunct(str[idxR]) || isspace(str[idxR])) {
        idxR--;
    };
    
    if (length == 1 || idxL >= idxR) {
        return true;
    } else if (toupper(str[idxL]) != toupper(str[idxR])) {
        return false;
    } else {
        idxL++;
        idxR--;
        return isAPalindrome(str, idxL, idxR);
    }
}


/*
 Enter a string: Able was I, ere I saw Elba
 Able was I, ere I saw Elba is a palindrome.
 Enter a string: peanut butter
 peanut butter is not a palindrome.
 Enter a string: Hello, World!
 Hello, World! is not a palindrome.
 Enter a string: racecar
 racecar is a palindrome.
 Enter a string: x
 x is a palindrome.
 Enter a string: Aa
 Aa is a palindrome.
 Enter a string: aB
 aB is not a palindrome.
 Enter a string: Astrologica
 Astrologica is not a palindrome.
 Enter a string: quit
 Program ended with exit code: 0
 */
