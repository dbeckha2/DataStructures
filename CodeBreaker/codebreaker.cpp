/* This program cracks a cyphertext in order to translate it to originial text.
 *Programmer: Dalina Beckham
*/

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]){
//Function Protocol
	string codebreaker(string &, int);
	int search(string &);
//Main variablesq
	string phrase;
	string decrypted;
	int resultSearch;
//File variables
	ifstream inFile(argv[1]);//open file

//Check for file 
	if(!inFile){
		cout << "Error: File not found." << endl;
		return 2;
	}//end if	
 	 
//Read the line
	getline(inFile, phrase);
	cout << "\n\ncipher :" << phrase << endl;	
//rotate letters
	int length = phrase.length();
	//cout << "length of string :"<< length << endl;			
	
	do {
	decrypted = codebreaker(phrase, length);
	int decryptedLength = decrypted.length();
	resultSearch = search(decrypted);
	} while (resultSearch < 2);	
 	cout << "decrypted :"<<  decrypted << endl;
	cout << "\n" << endl;
	inFile.close();
	return 0;
}
//searching for common words
int search(string &cstring){
	string common[] = {" THE ", " BE ", " TO ", " OF ", " AND ", " A", " IN ", " THAT ", " HAVE ", " I ", " IT ", " FOR ", " NOT ", " ON ", " WITH ", " HE ", " AS ", " YOU ", " DO ", " AT "};
	int numWords = 0;		
	int commonSize = 20;	

	for (int i= 0; i <commonSize; i++)
		if(cstring.find(common[i])!=-1){
			numWords++;
	}
	return numWords;	
}
//deccrypting algorithm
string codebreaker(string &letters, int lettersLength){

	for (int j = 0; j <= lettersLength; j++){
		if ((isalpha(letters[j])) && (letters[j] != 'A') && (letters[j] != ' ')){	
			letters[j] = letters[j] - 1;
		}
		else if (letters[j] == ' '){
			letters[j] = 'Z';
		}
		else if (letters[j] == 'A'){
			letters[j] = ' ';
		}
			
	}
return letters;
}	
