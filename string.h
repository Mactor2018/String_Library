#ifndef STRING_H
#define STRING_H

#include<conio.h>
#include<cstring>
#include<iostream>

using namespace std;

class String {
	 // think about the private data members...
	int Size = 0;
	char *  OriginalString;
		 public:
			 // provide definitions of following functions...         
			 char * getOriginalString() const;//for Original string
			 void setOriginalString(char * TempString);			
			 int getSize() const; //For getting the size of array			 
			 void setSize(int size);//For setting the size of array			 
			 int Strlen(char * TempString);//to find the lenght of string 
			 String();// default constructor
			 String(char *str);// initializes the string with constant cstring
			 String(const String &);// copy constructor to initialize the string fromexisting!string
			 String(int x);// initializes a string of pre-defined size
			 char getAt(int i);// returns the character at index [x]
			 void setAt(int i, char c);// set the character at index [x]
			 String substr(int pos, int len);// returns a substring of length len startingfrom!location 'pos'
			 String substr(int pos);// returns substring from the given position to the end.
			 void append(char a);// append a char at the end of string
			 void append(const String & str);// append a String at the end of string
			 void append(char *str);// append a constant c string at the end of string
			 int length();// returns the length of string
			 char * tocstring();// converts a String to c-string
			 void display();// displays the string ..
			 bool isEmpty();// returns true if string is empty..
			 void copy(const String&);// Copy one string to another ...
			 void copy(const char *);// copy cstring to String...
			 int find(char);// returns the index of character being searched.
			 bool equal(const String&);// should return true if both strings are same
			 int stoi();// function for converting a string to integer.
			 void split(char token, string *&, int &ntokens); // should split the stringaccording to given token and store all substrings in a dynamic arraypassed as second argument, and return ntokens in third argument.
			 bool isanagram(const String &);// return true if the given string is anagram of theinput string, an string is called anagram of another string if it containsexactly same characters but might be different order of appearance.
			 ~String();// destructor...			
};
#endif STRING_H
