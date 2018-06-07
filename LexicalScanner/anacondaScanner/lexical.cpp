//File: lexical.cpp
//Name: Gabriel Kilungya
//Date: 10/06/2017
//Email: kilgab1@umbc.edu


#include <iostream>
using namespace std;

int main(){


  char myChar[100];
  cout << "Enter a string of characters: ";
  cin >> myChar;

  int firstIndex = 0;
  if(myChar[0] == '-' || myChar[0] == '+'){
    firstIndex++;
  }
  
  if(myChar[firstIndex] == '0' && (myChar[firstIndex + 1] == 'x' || myChar[firstIndex + 1] == 'X')){
    if(myChar[firstIndex + 2] == '0'){
      if(myChar[firstIndex + 3] == '\0'){
	cout << "Hexadecimal number" << endl;
	cout << myChar << endl;
      }
      else{
	cout << "Nonsense" << endl;
      }
      return 0;
    }
    for(int i = firstIndex + 2; myChar[i] != '\0'; i++){
      char c= myChar[i];
      if(!(c >= '0' && c <= '9') && !(c >= 'A' && c <= 'F') && !(c >= 'a' && c <= 'f')){
	cout << "Nonsense" << endl;
	return 0;
      }
    }
    cout << "Hexidecimal number" << endl;
    cout << myChar << endl;
  }
  else if(myChar[firstIndex] == '0'){
    if(myChar[firstIndex + 1] == '0'){
      if(myChar[firstIndex + 2] == '\0'){
	cout << "Octal Number" << endl;
	cout << myChar << endl;
      }
      else{
	cout << "Nonsense" << endl;
      }
      return 0;
    }
    if(myChar[firstIndex + 1] == '\0'){
      cout << "Decimal number" << endl;
      cout << myChar << endl;
      return 0;
    }
    for(int i = firstIndex + 1; myChar[i] != '\0'; i++){
      char c = myChar[i];
      if(!(c >= '0' && c <= '7')){
	cout << "Nonsense" << endl;
	return 0;
      }
    }
    cout << "Octal Number" << endl;
    cout << myChar << endl;

  }
  else if(myChar[firstIndex] > '0' && myChar[firstIndex] <= '9'){
    for(int i = firstIndex + 1; myChar[i] != '\0'; i++){
      char c = myChar[i];
      if(!(c >= '0' && c <= '9')) {
	cout << "Nonsense" << endl;
      }
    }
    cout << "Decimal number" << endl;
    cout << myChar << endl;
  }


  return 0;


}
