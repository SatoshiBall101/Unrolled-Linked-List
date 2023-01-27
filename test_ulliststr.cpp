#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ostream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
	ULListStr dat;
	dat.push_back("7");
	dat.push_front("8");
	dat.push_back("9");
	cout << "1." <<dat.back() << endl;
	cout << "2." <<dat.front() << endl;
	cout << "3." << dat.empty() << endl;
	// prints: 8 7 9
	cout <<  "4." <<dat.size() << endl;  // prints 3 since there are 3 strings stored

	cout << "5." << dat.get(0) << endl;
	cout << "6." << dat.get(1) << endl;
	cout << "7." << dat.get(2) << endl; 

	dat.pop_back();
	dat.pop_front();
	
	cout << "8." << dat.get(0) << endl;

	while(!dat.empty())
	{
		dat.pop_back();
	}

	cout << "The size is now: " << dat.size();

	dat.push_back("Hi");
	dat.push_back("THere");
	dat.push_back("g");
	dat.push_back("tgi");
	dat.push_back("Hi");
	dat.push_back("Hgt");
	dat.push_back("vg");
	dat.push_back("Hi");
	dat.push_back("tfvHi");
	dat.push_back("gt");
	dat.push_back("vg");
	dat.push_back("vg");


	cout << endl;

	for (int i = 0; i < 12; i++)
	{
		cout << dat.front() << endl;
		dat.pop_front();
	}
	
	



}
