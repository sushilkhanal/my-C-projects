#include <iostream>

#include<cstring>

using namespace std;

string Sort(string);
bool Anagram(string, string);


int main() //the main function
{
  string x = " "; //variable for input 1.
  string y = " "; //variable for input 2.
  bool check = true; //declaring a boolean value.
  do { //starting the loop.

    cout << "Enter two line that might be anagrams: " << endl; //asking the input from users
    cout << "--> ";
    getline(cin, x); //storing the input to x variable.

    if (x.length() >= 60) { //checking if the string is greater then 60 or not..
      cout << "Error: Only the strings less than or equal to 60 characters are accepted" << endl; //error message
      check = false; //set the value to false
    } else { //if condition is false
      check = true; //set value to true
      cout << "--> "; //asking another strings
      getline(cin, y);
      if (y.length() >= 60) { ////checking if the string is greater then 60 or not..
        cout << "Error: Only the strings less than or equal to 60 characters are accepted" << endl; //error message.
        check = false;
      } else {
        check = true;
      } //if statement is false
    }

  } while (check == false); //ending the loop with condition.

  if (Anagram(x, y) == true) //calling the Anagram() function
    cout << "The two strings ARE anagram"; //print this value if true
  else
    cout << "The two strings are NOT anagram"; //print this value if false
  return 0;
}
//This function sorts the formatted strings taken from user.
string Sort(string x) {

  for (int index = 0; index < x.size() - 1; index++) { //Outer loop
    for (int i = index + 1; i < x.size(); i++) { //Inner loop

      if (x[index] > x[i]) // comparing two characters
        swap(x[i], x[index]); //swaps if conditions are met

    }
  }

  return x; //returns sorted value to "Anagram" function
}
bool Anagram(string x, string y) //function to find if the lines are anagram or not
{

  string Str1, Str2;
  char Str1[60];
  char Star2[60];

  for (int i = 0; i < x.length(); i++) //starting the loop
  {
    if ((x[i] >= 'A' && x[i] <= 'Z') || (x[i] >= 'a' && x[i] <= 'z')) {
      Srt1[i]=x[i];
    }

  }

  for (int i = 0; i < y.length(); i++) {
    if ((y[i] >= 'A' && y[i] <= 'Z') || (y[i] >= 'a' && y[i] <= 'z')) {
      Str2[i]=x[i];
    }

  }

  Str1 = Sort(Str1[x.length()]);
  Str2 = Sort(Str2[y.length()]);
  //sorting the string using "Sort" function

  if (Str1 == Str2) { //checking if two strings are same or not
    return true;
  } // returning the boolean value if true.
  else {
    return false;
  }

}

