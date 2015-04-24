/*
BLG252E- Object Oriented Programing Homework 1
Engin Yürek
040100524

CRN:22490
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Airline{ 
	string airLName;		//airline name
public:
	Airline(string newAirlineName);
	Airline();
};

Airline::Airline(string newAirlineName){
	 
	airLName = newAirlineName;	
}

Airline::Airline(){
	
	airLName = " ";
}