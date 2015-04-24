/*
BLG252E- Object Oriented Programing Homework 1
Engin Yürek
040100524

CRN:22490
*/


#include<iostream>
#include<string>

using namespace std;

class Airport{
	string airPName; //airport name
public:
	Airport();
	Airport(string newAirportName);
	
};

Airport::Airport(string newAirportName){
		airPName = newAirportName;
}
Airport::Airport(){
	airPName = " ";
}