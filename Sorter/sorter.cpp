/*
 *Program to compare bubbble, heap, and bucket/counting sort.
 *Programmer: Dalina Beckhams
*/

#include <string.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
        using namespace std;
int main(int argc, char *argv[]){
//Main variables
	string sorter;
	string element;

//Function protoypes
	string searchSort(string);
	void doSort(string, int [], int);
	bool checkSort(string, int[], int);

//Search for sorter and element
	sorter = argv[1];
	string foundSort = searchSort(sorter);//search sort
     
     if(argv[2] == NULL){
	cout << "Please insert number of elements." << endl;
	exit(EXIT_FAILURE);
     }	
	element = argv[2];
	int intElement = 0;
	    intElement = atoi(element.c_str());//convert string to int

//found sort and correct number of element	
	int intArray[intElement];//create array of ints of requested size
	
	for(int i =0; i < intElement; i++){
		intArray[i] = rand()%1000000;//insert random numbers into array
	}

cout << "\nUnsorted int array" << endl;
	for(int i = 0; i< intElement; i++){
		cout << intArray[i] << " ";
	}
//open outputfile and calculate runtime
	ofstream outFile;
	outFile.open("output.txt",std::ios::app);//append to end of file
		clock_t t1, t2;
		t1 = clock();
     //Do the sorting algorithm
	doSort(foundSort, intArray, intElement);
	bool check;
	     check = checkSort(foundSort, intArray, intElement);	
		t2 = clock();
		float diff((float)t2-(float)t1);
		float seconds = diff/CLOCKS_PER_SEC;
		float ms = seconds*1000;
     //writing to output file
	outFile << foundSort << " " << intElement << " " << ms << " milliseconds"<< endl;
	outFile.close();

//printing
cout << "\n\n" << foundSort << " array" << endl;
	for(int i = 0; i< intElement; i++){
		cout << intArray[i] << " ";
	}
	cout << "\n" << endl;
	if(check == true){
		cout << "Yea" << endl;	
	}
	else{
		cout << "Nay" << endl;
	}

 return 0;
}
string searchSort(string theSort){
//Check sorter	
     string sortArray[] = {"bubble", "heap", "bucket"};
	int sortSize = 3;

	for (int i =0; i<sortSize; i++){
		if(theSort.find(sortArray[i])!=-1){
			return theSort;
		}
	}
		cout << "Incorrect sorter." << endl;
		exit(EXIT_FAILURE);
}

void doSort(string sortFound, int *arrayInt, int elementInt){
     //function prototype sorting algorithms	
	void bubbleSort(int [], int);
	void heapSort(int [], int);
	void bucketSort(int [], int);

	if (sortFound == "bubble"){
		bubbleSort(arrayInt, elementInt);
	}
	else if(sortFound == "heap"){
		heapSort(arrayInt, elementInt);
	}
	else if (sortFound == "bucket") {
		bucketSort(arrayInt, elementInt);
	}
}
//Bubble Sort
void bubbleSort(int *integerArray, int integerElement){
	for (int j = 0; j<integerElement; j++){
		for (int i =0; i <integerElement-1; i++){
			if(integerArray[i] > integerArray[i+1]){
				swap(integerArray[i], integerArray[i+1]);
			}
		}
	}
}
//heapify
void heapSort( int *integerArray, int integerElement){       
     //functoin prototype to heap
     void heapify( int [], int, int);   
	for (int j = integerElement/2; j >= 0; j--) { 
		heapify( integerArray, j, integerElement);    
	}     

	while (integerElement-1 > 0) {  
	//swap the parent root with the last child
		swap(integerArray[integerElement-1], integerArray[0]); 
		heapify(integerArray, 0, integerElement-1);  
			integerElement--;//decrement by one so max stays

	}
}  
void heapify( int *integerArray, int j, int integerElement){     
	while ( j*2 + 1 < integerElement ) { 
		int child = 2*j + 1;    

	//Find bigger child to swap
		if ((child + 1 < integerElement) && (integerArray[child] < integerArray[child+1])){
			 child++;        
       		}
		if (integerArray[j] < integerArray[child]) {//swap if child > parent        
			swap( integerArray[child], integerArray[j] );  
			//continue heapifying          
			j = child;  
		}        
		else {           
			return;
		}    
	}
} 
//Bucket Sort
void  bucketSort(int *integerArray, int integerElement){
	int pos = 0;
	int theBucket[1000000];
		for(int i =0; i <1000000; i++){
			theBucket[i] = 0;
		}
		for(int i =0; i<integerElement; i++){
			theBucket[integerArray[i]] = theBucket[integerArray[i]]+1;
		}
			for(int i =0;i<1000000; i++){
				while(theBucket[i]--){
					integerArray[pos]=i;
					pos++;
				}
			}
}
//checkSort
bool checkSort(string algorithm, int *algorArray, int algorEle){
	for (int j = 0; j<algorEle-1; j++){
			if (algorArray[j] >algorArray[j+1]){
				return false; 
			}
		}
	return true;
}
