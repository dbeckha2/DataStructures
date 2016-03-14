/*
 *This program unscrambles jumbled words to solve a riddle.
 *Programmer: Dalina Beckhams
*/

#include <string.h>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
	using namespace std;
int main(int argc, char *argv[]){
//Main variables
 	int numWord=0;
	string dictArray[98570];
//Function Prototype
	void permutation(string &, BST &);
	void insertWords(string [], int, int, BST &);

//Open dictionary file and read it
	ifstream inFile("words");
	while(getline(inFile, dictArray[numWord])){	
		numWord++;
	}
	inFile.close();

//Creating dictionry	
	BST theDict;
	insertWords(dictArray, 0, numWord-1, theDict);		

//open jumble file
	ifstream jumFile(argv[1]);
//jumFile variables
	string jumWord[4];
	string letter[4];
	string question, next, answer;	
	string tempWord[4];
	string finalAnswer;
	for (int i =0; i <4; i++){
		jumFile >> jumWord[i] >> letter[i];//read word and letter O
		boost::to_lower(jumWord[i]);//function to lowercase string		
		     int jumLength = 0;
			jumLength = jumWord[i].length();
		permutation(jumWord[i], theDict);
		tempWord[i] = jumWord[i];
	
		//swap letter in string
		for (int p=0; p<jumLength; p++){
			if(letter[i][p] == 'O'){
				swap(letter[i][p], tempWord[i][p]); 
				//check if alpha then store the letter
				if(isalpha(letter[i][p])){
					finalAnswer = finalAnswer + letter[i][p];
				}
			}
		}

	}
//getting the question and answer line
		getline(jumFile, next);
		getline(jumFile, question);
		getline(jumFile, answer); 
//permute answer
	permutation(finalAnswer, theDict);
	boost::to_upper(finalAnswer);//function to uppercase string

	     int answerLength = 0;
		answerLength = finalAnswer.length();	
//swap '_' with answer
	int answerL = 0;
	answerL = answer.length();
		for (int p=0; p<answerL; p++){
			for(int q = 0; q < answerLength; q++){			
				if(answer[p]== '_'){ 
					swap(answer[p], finalAnswer[q]);
				}
			}
		}
//print 	
		for (int i =0; i <4; i++){
		boost::to_upper(jumWord[i]);
		 cout << jumWord[i] << endl;
		}
		cout << question << endl;
		cout << answer << endl;
	

	jumFile.close();//closing .jumble file
return 0;
}
//inserting dictionary array
void insertWords(string *dictArray, int begIndex, int endIndex, BST &theDict){
     //middle word insert
	int midWord = (begIndex +endIndex)/2;
	theDict.insert(dictArray[midWord]);
	
	if(begIndex <= midWord -1){
		//inserting left half recursively
		insertWords(dictArray, begIndex, midWord-1, theDict);
	}
	if(midWord + 1 <= endIndex){
		//inserting right half recursively
		insertWords(dictArray, midWord+1, endIndex, theDict);
	}

}
//unjumbleWord
void permutation(string &jumbledWord, BST &theDict){
	int wordGot = 0;
    sort(jumbledWord.begin(), jumbledWord.end());
	while(wordGot ==0){
		next_permutation(jumbledWord.begin(), jumbledWord.end());
		wordGot = theDict.getValue(jumbledWord);
		}
}
