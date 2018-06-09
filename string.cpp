#include "string.h"

int String::Strlen(char * TempString)
{
	int Lenght = 0;
	for (int  i = 0; TempString[i] != '\0'; i++)
	{
		Lenght++;
	}
	return Lenght;
}
char * String::getOriginalString() const //for Original string
{
	return OriginalString;
}
void String::setOriginalString(char * TempString)
{
	OriginalString = TempString;
}
int String::getSize() const //For getting the size of array
{
	int size = 0;
	for (int i = 0; OriginalString[i] != '0'; i++)
	{
		size++;
	}
	return size;
}
void String::setSize(int size)//For setting the size of array
{
	size = Size;
}
String::String()// default constructor
{
	char * OriginalString = "";
}
String::String(char *str)// initializes the string with constant cstring
{
	OriginalString = str;
}
String::String(const String & ObjectOfString)// copy constructor to initialize the string from existing string
{
	int size = 0;
	char * TempNewString = ObjectOfString.getOriginalString();
	for (int i = 0; TempNewString[i] != '\0'; i++)
	{
		size++;
	}	
	OriginalString =new char[size];
	OriginalString = TempNewString;
}
String::String(int x)// initializes a string of pre-defined size
{
	char * OriginalString = new char[x];
}
char String::getAt(int i)// returns the character at index [x]
{
	return OriginalString[i];
}
void String::setAt(int i, char c)// set the character at index [x]
{
	OriginalString[i] = c;
}
String String::substr(int pos, int len)// returns a substring of length len starting from location 'pos'
{
	if (pos < len)
	{
		int TempCountForSubString = 0;
		char * TempSubString = new char[len];
		for (int i = pos; OriginalString[i] != '\0'; i++)
		{
			TempSubString[TempCountForSubString] = OriginalString[i];
			TempCountForSubString++;
		}
		TempSubString[TempCountForSubString] = '\0';
		return TempSubString;
	}
	else
	{
		cout << "Initial Postion is out of range";
	}
}
String String::substr(int pos)// returns substring from the given position to the end.
{
	if (pos < Strlen(OriginalString))
	{
	
		int TempCountForSubString = 0;
		for (int i = pos; OriginalString[i] != '\0'; i++, TempCountForSubString++)
		{
			TempCountForSubString++;
		}
		char * TempSubString = new char[TempCountForSubString];
		int index = 0;
		for (int i = pos; OriginalString[i] != '\0'; i++)
		{
			TempSubString[index] = OriginalString[i];
			index++;
		}
		TempSubString[index] = '\0';
		return TempSubString;
	}
	else
	{
		cout << "Initial Postion is out of range";
	}
}
void String::append(char a)// append a char at the end of string
{
	char * NewOriginalString = new char[Strlen(OriginalString) + 1];
	int index = 0;
	for (int i = 0; OriginalString[i] != '\0'; i++)
	{
		NewOriginalString[i] = OriginalString[i];		
		index++;
	}
	NewOriginalString[index] = a;
	NewOriginalString[index + 1] = '\0';
	OriginalString = "";
	OriginalString = new char[Strlen(NewOriginalString)];
	int count=0;
	for (int i = 0; NewOriginalString[i] != '\0'; i++)
	{
		 OriginalString[i] = NewOriginalString[i];		
		 count++;
	}
	OriginalString[count] = '\0';
	
}
void String::append(const String & str)// append a String at the end of string
{
	
	int index = 0;
	int strSize = str.getSize();
	char * TempInComingString = str.getOriginalString();
	char * NewOriginalString = new char[Strlen(OriginalString) + strSize];
	for (int i = 0; OriginalString[i] != '\0'; i++)
	{
		NewOriginalString[i] = OriginalString[i];
		index++;
	}
	for (int i = 0; TempInComingString[i] != '\0'; i++)
	{
		NewOriginalString[index] = TempInComingString[i];
		index++;
	}
	NewOriginalString[index] = '\0';
	OriginalString = "";
	OriginalString = new char[Strlen(NewOriginalString)];
	int count = 0;
	for (int i = 0; NewOriginalString[i] != '\0'; i++)
	{
		OriginalString[i] = NewOriginalString[i];
		count++;
	}
	OriginalString[count] = '\0';
}
void String::append(char *str)// append a constant c string at the end of string
{
	int index = 0;
	char * NewOriginalString = new char [Strlen(OriginalString) + Strlen(str)];        //isko baad mn dekhna hai
	for (int i = 0; OriginalString[i] != '\0'; i++)
	{
		NewOriginalString[i] = OriginalString[i];
		index++;
	}
	for (int i = 0; str[i] != '\0'; i++)
	{
		NewOriginalString[index] = str[i];
		index++;
	}
	NewOriginalString[index] = '\0';
	OriginalString = "";
	OriginalString = new char[Strlen(NewOriginalString)];
	int count = 0;
	for (int i = 0; NewOriginalString[i] != '\0'; i++)
	{
		OriginalString[i] = NewOriginalString[i];
		count++;
	}
	OriginalString[count] = '\0';
}
int String::length()// returns the length of string
{
	return Strlen(OriginalString);
}
char * String::tocstring()// converts a String to c-string
{
	char * NewTempCString = new char[Strlen(OriginalString)];
	int index = 0;
	for (int i = 0; OriginalString[i] != '\0'; i++)
	{
		NewTempCString[i] = OriginalString[i];
		index++;
	}
	NewTempCString[index] = '\0';
	return NewTempCString;
}
void String::display()// displays the string ..
{
	cout << OriginalString;
}
bool String::isEmpty()// returns true if string is empty..
{
	if (OriginalString == "")
	{
		return false;
	}
	return true;
}
void String::copy(const String & InComingObject)// Copy one string to another ...
{
	int index = 0;
	int size = InComingObject.getSize();
	OriginalString = new char[size];
	char * InComingString = InComingObject.getOriginalString();
	for (int i = 0; InComingString[i] != '\0'; i++)
	{
		OriginalString[i] = InComingString[i];
		index++;
	}
	OriginalString[index] ='\0';
}
void String::copy(const char * NewString)// copy cstring to String...
{
	int size = 0;	
	for (int i = 0; NewString[i] != '\0'; i++)
	{
		size++;
	}
	OriginalString = "";
	OriginalString = new char[size];
	int index = 0;
	for (int i = 0; NewString[i] != '\0'; i++)
	{
		OriginalString[i] = NewString[i];
		index++;
	}
	OriginalString[index] = '\0';
}
int String::find(char CHAR)// returns the index of character being searched.
{
	int i;
	int flag = 0;
	for ( i = 0; OriginalString[i] != '\0'; i++)
	{
		if (OriginalString[i] == CHAR)
		{
			flag = 1;
			return i;
		}
	}
	if (flag==0)
	{
		cout << "This letter was not found";
		return -1;
	}	
}
bool String::equal(const String & InComingObject)// should return true if both strings are same
{
	int InComingStringsize = InComingObject.getSize();
	char * InComingString = InComingObject.getOriginalString();
	if (Strlen(OriginalString) == InComingStringsize)
	{
		for (int  i = 0; OriginalString[i] != '\0'; i++)
		{
			if (OriginalString[i] != InComingString[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
int String::stoi()// function for converting a string to integer.
{
	int Variable = 0;
	int result = 0;
	char * string = "";
	int size = Strlen(string);
	for (int  i = 0; string[i] != '\0' ; i++)
	{
		Variable = string[i] - 48;
		result = Variable + (result * 10);
	}	
		return result;
}
void String::split(char token, string *& str, int &ntokens) // should split the string according to given token and store all substrings in a dynamic array passed as second argument, and return ntokens in third argument.
{
	int indexi = 0;
	int indexj = 0;
	for (int i = 0; OriginalString[i] != '\0'; i++)
	{		
		if (OriginalString[i] == token)
		{
			ntokens++;
			str[indexi][indexj] = '\0';
			indexi++;
			indexj = 0;
		}
		else
		{			
			str[indexi][indexj] = OriginalString[i];
			indexj++;
		}		
	}
	str[indexi][indexj] = '\0';
}
bool String::isanagram(const String & InComingString)// return true if the given string is anagram of the input string, an string is called anagram of another string if it contains exactly same characters but might be different order of appearance.
{
	char Const = 'X';
	char * NewInComingString = InComingString.getOriginalString();
	if (Strlen(OriginalString) == Strlen(NewInComingString))
	{
		for (int  i = 0; OriginalString[i] != '\0' ; i++)
		{
			for (int j = 0; NewInComingString[j] != '\0'; j++)
			{
				if (OriginalString[i] == NewInComingString[j])
				{
					NewInComingString[j] = NULL;
					break;
				}
				if (j==Strlen(NewInComingString) -1 )
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
String:: ~String()// destructor...
{
	delete []OriginalString;
}