#include "BigNum.h"
#include <stdio.h>
#include <string.h>
#include <fstream>
//Default constructor
BigNum::BigNum(){
	numDigits = 1;
	digits = new int[numDigits];
	isPositive = true;
}
//Integer Constructor
BigNum::BigNum(int num){
	int number = 0;
	numDigits = 0;
	if(num < 0){
		isPositive = false;	
		num *=-1;
		number = num;
	}
	else{
		isPositive = true;
		number = num;
	}

		while (num!=0){
			num /=10;
		 	numDigits++;
		}
 			
		digits = new int[numDigits];
		for (int i=0; i<numDigits; i++){
			int modNum=0; 
			modNum = number%10;
			digits[i] = modNum;
		number = (number/10);
		}
}

//Character string constructor
BigNum::BigNum(const char string[]){
	numDigits = 0;
	int numberDigits = 0;
//checking isPositive
	if (string[0] == '-'){
		isPositive = false;		
		for (int k=1;string[k] != '\0'; k++){
			numDigits++;
		}
		numberDigits = numDigits;
		digits = new int[numDigits];
//moving string[] into digits[]
		for (int l=0;l < numDigits; l++){	
			digits[l] =  string[numberDigits]-'0';
			numberDigits--;
		}

	}
//positive sign
	else if(string[0]=='+'){
		isPositive = true;
		for (int k=1;string[k] != '\0'; k++){
			numDigits++;
		}
		numberDigits = numDigits;		
		digits = new int[numDigits];
//moving string[] into digits[]
		for (int l=0;l < numDigits; l++){	
			digits[l] =  string[numberDigits]-'0';
			numberDigits--;
		}
	}
//not negative or positive sign
	else if((string[0] != '-') || (string[0]!= '+')){
		isPositive = true;
		for (int k=0;string[k] != '\0'; k++){
			numDigits++;
		}
		numberDigits = numDigits;		
		digits = new int[numDigits];
//moving string[] into digits[]
		for (int l=0;l < numDigits; l++){
			digits[l] =  string[numberDigits-1]-'0';
			numberDigits--;
		}
	}
}
//Destructor
BigNum::~BigNum(){
	delete [] digits;
}
// Assignment operator
BigNum &BigNum::operator=(const BigNum &anotherBigNum){
	if (&anotherBigNum != this){
		delete[] digits;
		digits = new int[anotherBigNum.numDigits];
		isPositive = anotherBigNum.isPositive;
		numDigits = anotherBigNum.numDigits;
	
		for(int o = 0; o < anotherBigNum.numDigits; o++){
			digits[o] = anotherBigNum.digits[o];
		}
	}
	return *this; 
}

//Copy Constructor
BigNum::BigNum(const BigNum &anotherBigNum){
		digits = NULL;
		*this = anotherBigNum;
}
//isEqualTo return true if BigNum is equal to argument passed
bool BigNum::isEqualTo(const BigNum &anotherBigNum)const{
	if((isPositive == anotherBigNum.isPositive) && (numDigits == anotherBigNum.numDigits)){
		for(int p = 0; p<numDigits; p++){
			if(digits[p] != anotherBigNum.digits[p]){
				return false;		
			}
		}		
		return true;		
	}
	else{
		return false;
	}
}
//isLessThan return true if BigNum is less than argument passed
bool BigNum::isLessThan(const BigNum &anotherBigNum)const{
	//this digit is negative and another is positive
	if ((isPositive == false) && (anotherBigNum.isPositive == true)){
		return true;
	}
	//this digit is positive and anoher is negative
	else if((isPositive == true) && (anotherBigNum.isPositive == false)){
		return false;
	}
	//both digits are positive
	else if ((isPositive == true) && (anotherBigNum.isPositive == true)){
		//this digiit has less numDigits
		if(numDigits < anotherBigNum.numDigits){
			return true;
		}
		else if (numDigits > anotherBigNum.numDigits){
			return false;
		}
		//both have same numDigits check each element
		else if(numDigits == anotherBigNum.numDigits){
			for (int s = numDigits-1; s>=0; s--){
				if(digits[s] > anotherBigNum.digits[s]){
					return false;
				}
				else if(digits[s] < anotherBigNum.digits[s]){
					return true;
				}
			}	
		}
	}
	//both digits are negative
	else if ((isPositive ==false) && (anotherBigNum.isPositive == false)){
		//this digit has more numDigits
		if(numDigits > anotherBigNum.numDigits){
			return true;
		}
		else if(numDigits < anotherBigNum.numDigits){
			return false;
		}
		//both have same numDigits check each element
		else if(numDigits == anotherBigNum.numDigits){
			for (int s = numDigits-1; s>=0; s--){
				if(digits[s] < anotherBigNum.digits[s]){
					return false;
				}
				else if(digits[s] > anotherBigNum.digits[s]){
					return true;
				}
			}		
		}
	}
}
//isGreater return true if BigNum is greater than argument passed
bool BigNum::isGreaterThan(const BigNum &anotherBigNum)const{
	//this digit is positive and another is negative
	if ((isPositive == true) && (anotherBigNum.isPositive == false)){
		return true;
	}
	//this digit is negative and another is positive
	else if((isPositive == false) && (anotherBigNum.isPositive ==true)){
		return false;
	}
	//both digits are positive
	if ((isPositive == true) && (anotherBigNum.isPositive == true)){
		//this digit has more numDigits
		if (numDigits > anotherBigNum.numDigits){
			return true;
		}
		//this numDigits positive number is less than
		else if (numDigits < anotherBigNum.numDigits){
			return false;
		}
		//both have same numDigits check each element
		else if(numDigits == anotherBigNum.numDigits){
			for (int s = numDigits-1; s>=0; s--){
				if(digits[s] < anotherBigNum.digits[s]){
					return false;
				}
				else if(digits[s] > anotherBigNum.digits[s]){
					return true;
				}
			}
		}
	}
	//both digits are negative
	else if ((isPositive == false) && (isPositive == false)){
		//this digit has less numDigits
		if(numDigits < anotherBigNum.numDigits){
			return true;
		}
		//this numDigits negative number is greater
		else if (numDigits > anotherBigNum.numDigits){
			return false;
		}
		//both has same numDigits check each element
		else if(numDigits == anotherBigNum.numDigits){
			for (int t = numDigits -1; t>=0; t--){
				if(digits[t] > anotherBigNum.digits[t]){
					return false;
				}
				else if(digits[t] < anotherBigNum.digits[t]){
					return true;
				}
			}
		}
	}
}
//plus
BigNum BigNum::plus(const BigNum &addend)const{
BigNum newDigits;
BigNum newAdd;
	int extraSD=0;
	int totalSD = 0;
	int carryNum = 0;
	int tempNum=0;
//same signs	
	if(isPositive == addend.isPositive){
		if (numDigits > addend.numDigits){//this greater than that
			extraSD = numDigits - addend.numDigits;
			totalSD = extraSD + addend.numDigits;
			newAdd.digits = new int[totalSD];
			newAdd.isPositive = addend.isPositive;
			newAdd.numDigits = totalSD;
			for (int k = 0; k<addend.numDigits; k++){
				newAdd.digits[k] = addend.digits[k];
			}
			for(int j = newAdd.numDigits; j > extraSD+1; j--){
					newAdd.digits[j] = 0;
				}
		
		newDigits.digits = new int[numDigits];
		newDigits.numDigits = numDigits;
		newDigits.isPositive = isPositive;
		for(int i = 0; i<numDigits; i++){
			tempNum = digits[i] + newAdd.digits[i] + carryNum;
				carryNum=0;
				if (tempNum >9){
					tempNum = tempNum%10;
					carryNum = 1;
				}
				newDigits.digits[i] = tempNum;
		}
	 	if(carryNum ==1) {
			delete[] newDigits.digits;
			newDigits.digits = new int[numDigits+1];
			newDigits.numDigits = numDigits+1;
			newDigits.isPositive = isPositive;
			carryNum = 0;
			for(int i = 0; i<numDigits+1; i++){
				tempNum = digits[i] + newAdd.digits[i] + carryNum;
					carryNum=0;
					if (tempNum >9){
						tempNum = tempNum%10;
						carryNum = 1;
					}
				newDigits.digits[i] = tempNum;
			}
		}
	//delete[] newAdd.digits;
		return newDigits;
		}	
		else if (numDigits < addend.numDigits){//this less than that
			extraSD = addend.numDigits-numDigits;
			totalSD = extraSD + numDigits;
			newAdd.digits = new int[totalSD];
			newAdd.isPositive = isPositive;
			newAdd.numDigits = totalSD;
			for (int k = 0; k<numDigits; k++){
				newAdd.digits[k] = digits[k];
			}
			for(int j = newAdd.numDigits; j > extraSD+1; j--){
					newAdd.digits[j] = 0;
				}

		newDigits.digits = new int[addend.numDigits];
		newDigits.numDigits = addend.numDigits;
		newDigits.isPositive = isPositive;
		for(int i = 0; i<addend.numDigits; i++){
		      tempNum = addend.digits[i] + newAdd.digits[i] + carryNum;
				carryNum=0;
				if (tempNum >9){
					tempNum = tempNum%10;
					carryNum = 1;
				}
				newDigits.digits[i] = tempNum;
		}
		if(carryNum ==1) {
			delete[] newDigits.digits;
			newDigits.digits = new int[addend.numDigits+1];
			newDigits.numDigits = addend.numDigits+1;
			newDigits.isPositive = isPositive;
			carryNum = 0;
			for(int i = 0; i<addend.numDigits+1; i++){
				tempNum = addend.digits[i] + newAdd.digits[i] + carryNum;
					carryNum=0;
					if (tempNum >9){
						tempNum = tempNum%10;
						carryNum = 1;
					}
				newDigits.digits[i] = tempNum;
			}
		}
	//delete[]newAdd.digits;
		return newDigits;
		}
		else if(numDigits == addend.numDigits){//same numDigits
		newDigits.digits = new int[addend.numDigits];
		newDigits.numDigits = addend.numDigits;
		newDigits.isPositive = isPositive;
		for(int i = 0; i<addend.numDigits; i++){
		      tempNum = digits[i] + addend.digits[i] + carryNum;
				carryNum=0;
				if (tempNum >9){
					tempNum = tempNum%10;
					carryNum = 1;
				}
				newDigits.digits[i] = tempNum;
		}
		if(carryNum ==1) {
			delete[] newDigits.digits;
			newDigits.digits = new int[addend.numDigits+1];
			newDigits.numDigits = addend.numDigits+1;
			newDigits.isPositive = isPositive;
			carryNum = 0;
			for(int i = 0; i<addend.numDigits+1; i++){
				tempNum = digits[i] + addend.digits[i] + carryNum;
					carryNum=0;
					if (tempNum >9){
						tempNum = tempNum%10;
						carryNum = 1;
					}
				newDigits.digits[i] = tempNum;
			}
		}
	//delete[]newAdd.digits;
		return newDigits;	
		}
	}

//opposite sign
		else if((isPositive == true) && ( addend.isPositive == false)){
			newAdd.digits = new int[addend.numDigits];
			newAdd.isPositive = true;
			newAdd.numDigits = addend.numDigits;
			for (int n=0; n<addend.numDigits; n++){
				newAdd.digits[n] = addend.digits[n];
			}
			newDigits = this->minus(newAdd);
			//delete[]newSub.digits;
			return newDigits;
		}
		else if ((isPositive == false) && (addend.isPositive == true)){
			newAdd.digits = new int[numDigits];
			newAdd.isPositive = true;
			newAdd.numDigits = numDigits;
			for (int n=0; n<numDigits; n++){
				newAdd.digits[n] = digits[n];
			}
			newDigits = addend.minus(newAdd);
			return newDigits;		
		}

}


//minus
BigNum BigNum::minus(const BigNum &subtractend)const{
BigNum newDigits;
BigNum newSub;
BigNum newSize;
	int extraSD=0;
	int totalSD = 1;
	int carryNum = 0;
	int tempNum=0;
	int size = 0;
//same sign
 if(isPositive == subtractend.isPositive){
			if(numDigits > subtractend.numDigits){//this numDigits greater than that
			extraSD = numDigits-subtractend.numDigits;
			totalSD = extraSD + subtractend.numDigits;
			newSub.digits = new int[totalSD];
			newSub.isPositive = subtractend.isPositive;
			newSub.numDigits = totalSD;
				for (int i =0; i<subtractend.numDigits; i++){
					newSub.digits[i] = subtractend.digits[i];
				}
				for(int j = newSub.numDigits; j > extraSD+1; j--){
					newSub.digits[j] = 0;
				}

			newDigits.digits = new int[numDigits];
			newDigits.numDigits = numDigits;
			newDigits.isPositive = isPositive;
			for(int i = 0; i<numDigits; i++){
				if(digits[i] < newSub.digits[i]){
					tempNum = (10+digits[i]) - newSub.digits[i]-carryNum;
					carryNum = 1;
				}
				else if(digits[i] > newSub.digits[i]){
					tempNum = digits[i] - newSub.digits[i]-carryNum;
				}
				else if(digits[i] == newSub.digits[i]){
					tempNum = subtractend.digits[i] - newSub.digits[i]-carryNum;
				}
				newDigits.digits[i]= tempNum;
			}	
			}
			else if(numDigits < subtractend.numDigits){//this numDigits less than that
			extraSD = subtractend.numDigits-numDigits;
			totalSD = extraSD + numDigits;
			newSub.digits = new int[totalSD];
			newSub.isPositive = isPositive;
			newSub.numDigits = totalSD;
				for (int i =0; i<numDigits; i++){
					newSub.digits[i] = digits[i];
				}
				for(int j = newSub.numDigits; j > extraSD+1; j--){
					newSub.digits[j] = 0;
				}

			newDigits.digits = new int[subtractend.numDigits];
			newDigits.numDigits = subtractend.numDigits;
			newDigits.isPositive = false;
			for(int i = 0; i<subtractend.numDigits; i++){
				if(subtractend.digits[i] < newSub.digits[i]){
					tempNum = (10+subtractend.digits[i]) - newSub.digits[i]-carryNum;
					carryNum = 1;
				}
				else if(subtractend.digits[i] > newSub.digits[i]){
					tempNum = subtractend.digits[i] - newSub.digits[i]-carryNum;
				}
				else if(subtractend.digits[i] == newSub.digits[i]){
					tempNum = subtractend.digits[i] - newSub.digits[i]-carryNum;
				}
				newDigits.digits[i]= tempNum;
			}	
			}
			else if(numDigits == subtractend.numDigits){//this numDigits less than that
			newDigits.digits = new int[subtractend.numDigits];
			newDigits.numDigits = subtractend.numDigits;
			if((this->isGreaterThan(subtractend))==1){
			cout << " you are greater" << endl;
				newDigits.isPositive = true;
				for(int i = 0; i<newDigits.numDigits; i++){
				if(digits[i] < subtractend.digits[i]){
					tempNum = (10+digits[i]) - subtractend.digits[i]-carryNum;
					carryNum = 1;
				}
				else if(digits[i] > subtractend.digits[i]){
					tempNum = digits[i] - subtractend.digits[i]-carryNum;
				}
				else if(digits[i] == subtractend.digits[i]){
					tempNum = (10+digits[i]) - subtractend.digits[i]-carryNum;
					//cout << "temp Num" << tempNum << endl;
					carryNum = 1;
					if(tempNum >9){
					tempNum = tempNum%10;
					carryNum = 0;
					}
					
				}
				newDigits.digits[i] = tempNum;
			}
	for (int i = 0; i<newDigits.numDigits; i++){
	cout << "newdig[i] " <<endl;
		cout <<newDigits.digits[i] << endl;	
	}
			}
			else if ((this->isLessThan(subtractend))==1){
				cout << " you aren't greater" << endl;
				newDigits.isPositive = false;
				for(int i = 0; i<newDigits.numDigits; i++){
				if(digits[i] < subtractend.digits[i]){
					tempNum =  subtractend.digits[i]-digits[i]-carryNum;
				}
				else if(digits[i] > subtractend.digits[i]){
					tempNum = (10+subtractend.digits[i])- digits[i]-carryNum;
					carryNum =1;
				}
				else if(digits[i] == subtractend.digits[i]){
					tempNum = (10+subtractend.digits[i]) - digits[i]-carryNum;
					carryNum = 1;	
				}
				newDigits.digits[i] = tempNum;
				}

				}	
			
			else if((this->isEqualTo(subtractend)==1)){
			newDigits.digits = new int[1];
			newDigits.numDigits = 1;
			newDigits.isPositive = true;
			newDigits.digits[0] = 0;
			return newDigits;
			}		
			}
//take off leading zeros and return newSize
		extraSD = newDigits.numDigits;
		int increment = newDigits.numDigits;
		if(newDigits.digits[increment-1]==0){
		while (newDigits.digits[increment-1]==0){
			extraSD = extraSD-1;
			totalSD = extraSD;		
			increment--;
		}
		}
		else{
		totalSD = newDigits.numDigits;
		}
		newSize.digits = new int[totalSD];
		newSize.isPositive = newDigits.isPositive;
		newSize.numDigits = totalSD;
		for (int i =0; i <newSize.numDigits; i++){
			newSize.digits[i] = newDigits.digits[i];
		}

	return newSize;
}
//opposite sign
		else if((isPositive == true) && ( subtractend.isPositive == false)){
			newSub.digits = new int[subtractend.numDigits];
			newSub.isPositive = true;
			newSub.numDigits = subtractend.numDigits;
			for (int n=0; n<subtractend.numDigits; n++){
				newSub.digits[n] = subtractend.digits[n];
			}
			newDigits = this->plus(newSub);
			//delete[]newSub.digits;
			return newDigits;
		}
		else if ((isPositive == false) && (subtractend.isPositive == true)){
			newSub.digits = new int[numDigits];
			newSub.isPositive = true;
			newSub.numDigits = numDigits;
			for (int n=0; n<numDigits; n++){
				newSub.digits[n] = digits[n];
			}
			newDigits = subtractend.plus(newSub);
			newDigits.isPositive = false;
			//delete[]newSub.digits;
			return newDigits;		
		}
if(this==&subtractend){
newDigits.digits = new int[1];
newDigits.numDigits = 1;
newDigits.digits[0] = 0;
newDigits.isPositive = true;
return newDigits;	
}

	
}



//print()
void BigNum::print(ostream &os)const{
	if (isPositive == true){
		for(int u = 0; u <numDigits; u++){
			os <<digits[numDigits-1-u];
		}
	}
	else{
		os << '-';
	
		for (int t =0; t<numDigits; t++){
			os << digits[numDigits-1-t];
		}
	}
	os << endl;		
}


//Part II
ostream& operator << (ostream &os, const BigNum& bignum){
 	//return os << bignum.print(cout);
	if(bignum.isPositive==true){
		 for(int i =0; i<bignum.numDigits; i++){
			os<<bignum.digits[bignum.numDigits-1-i];
		}
	}
	else{
		os <<'-';
		 for(int i =0; i<bignum.numDigits; i++){
			os<<bignum.digits[bignum.numDigits-1-i];
		}
	}
	os << endl;

}

BigNum BigNum::operator+(const BigNum &addend)const{
	BigNum bigger;
	bigger = this->plus(addend);
	return bigger;
}
BigNum &BigNum::operator+=(const BigNum &addend){
	(*this)=this->plus(addend);
	return *this;
}

BigNum BigNum::operator-(const BigNum &subtractend)const{

	BigNum bigger;
	bigger = this->minus(subtractend);
	return bigger;

}
BigNum &BigNum::operator-=(const BigNum &subtractend){
	(*this)=this->minus(subtractend);
	return *this;

}
bool BigNum::operator>(const BigNum &anotherBigNum)const{
	if( this->isGreaterThan(anotherBigNum)==1){
		return true;
	}
	else{
		return false;
	}
}
bool BigNum::operator>=(const BigNum &anotherBigNum)const{
	if((this->isGreaterThan(anotherBigNum)==1) && (this->isEqualTo(anotherBigNum)==1)){
		return true;
	}
	else{
		return false;
	}
}
bool BigNum::operator<(const BigNum &anotherBigNum)const{
	if(this->isLessThan(anotherBigNum)==1){
		return true;
	}
	else{
		return false;
	}
}
bool BigNum::operator<=(const BigNum &anotherBigNum)const{
	if((this->isLessThan(anotherBigNum)==1)&& (this->isEqualTo(anotherBigNum)==1)){
		return true;
	}
	else{
		return false;
	}
}
bool BigNum::operator==(const BigNum &anotherBigNum)const{
	if(this->isEqualTo(anotherBigNum)==1){
		return true;
	}
	else{
		return false;
	}
}
bool BigNum::operator!=(const BigNum &anotherBigNum)const{
	if(this->isEqualTo(anotherBigNum)==0){
		return true;
	}
	else{
		return false;
	}
}
/* Hello there, folks; this input stream reader operator is kind of a pain
 * in the butt, so I'm just going to give you the code for it. Copy and
 * paste this code into your own BigNum.cpp file. */
//  Read a BigNum in from an input stream.
istream& operator>>(istream &is, BigNum& bignum) {

    //  Make sure the next character in the stream is a valid start to
    //  a BigNum; otherwise, throw an exception.
    char next = is.peek();
    while (isspace(next)) {
      is.get();
      next = is.peek();
    }
    if (!isdigit(next) && next != '+' && next != '-') {
        throw "No BigNum to read!!";
    }

    //  Read the sign character, if there is one.
    bignum.isPositive = true;
    if (next == '-') {
        is.get();
        bignum.isPositive = false;
    }
    if (next == '+') {
        is.get();
    }

    //  Read all consecutive digits into an array called "backwardsDigits,"
    //  resizing this array if necessary to accommodate all the input.
    //  (The array is called "backwards" because I'm storing the digits
    //  of the BigNum with the least significant digit in digits[0],
    //  and of course as we read the input from left to right, the most
    //  significant digit of backwardsDigits will instead be [0].)
    int capacity = 10;
    int *backwardsDigits = new int[capacity];
    int numDigits = 0;
    while (isdigit(is.peek())) {
        if (numDigits >= capacity) {
            //  Oops, our backwardsDigits array isn't big enough
            //  to handle all the digits in the BigNum the user
            //  typed in.  Double our capacity, and copy the
            //  existing digits into the new array.
            capacity *= 2;
            int *temp = new int[capacity];
            for (int i=0; i<(capacity/2); ++i) {
                temp[i] = backwardsDigits[i];
            }
            delete [] backwardsDigits;
            backwardsDigits = temp;
        }
        backwardsDigits[numDigits] = is.get() - '0';
        numDigits++;
    }

    //  Now all the digits that will represent this new BigNum are in the
    //  backwardsDigits array, stored in reverse order from how we want
    //  them stored in our BigNum.  Delete the old BigNum memory, and
    //  copy the digits into it.
    delete [] bignum.digits;
    bignum.digits = new int[numDigits];
    for (int i=0; i<numDigits; ++i) {
        bignum.digits[i] = backwardsDigits[numDigits-i-1];
    }
    bignum.numDigits = numDigits;

    //  Cool.  Now we have a new BigNum.  Delete this temporary memory we
    //  used, and return.
    delete [] backwardsDigits;
    return is;
}
