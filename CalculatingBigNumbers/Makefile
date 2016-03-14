tester: tester.o BigNum.o
	g++ -o tester tester.o BigNum.o
BigNum.o: BigNum.cpp BigNum.h
	g++ -c BigNum.cpp
tester.o: BigNum.h tester.cpp
	g++ -c tester.cpp
