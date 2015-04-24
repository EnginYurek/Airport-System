
/*
BLG252E- Object Oriented Programing Homework 1
Engin Yürek
040100524

CRN:22490
*/

#include<iostream>
#include<vector>
#include<string>
#include"FlightSection.h"

using namespace std;

class Flight{
	friend class SystemManager;
	string airlineName, orig, dest, id;    //keeps the information of airline, origin. destionation and id of the flight

	string sec1, sec2, sec3;  //keeps the information of section itinially all of equals to "not created"
	int year, month, day;
	
	static vector<FlightSection> allSections; //keep all sections that one particular flight has  

public:
	
	Flight(string fname, string origin, string destination,
		   int y, int m, int d , string fId);
	Flight();
	
	void createSection(int r, int c, int s);  //Creates sections in one flight

	
};

vector<FlightSection>  Flight::allSections;

void Flight::createSection(int r, int c, int s){
	if (s == 1 && sec1!="created"){										//if we want to create section 1 and it is not created alredy cre
	FlightSection  businessSect= FlightSection(airlineName,id, r, c, s);	//create section 1(business)
	sec1 ="created";														//change the identifier to "created"
	cout << "Section " << s << " of fight with this id: " << id << " is created." << endl;
	allSections.push_back(businessSect);	//keep the created section.
}
	else if (s == 2 && sec1 != "created"){
		FlightSection  FirstSect = FlightSection(airlineName, id, r, c, s);
		sec2 = "created";
		cout << "Section " << s << " of fight with this id: " << id << " is created." << endl;
		allSections.push_back(FirstSect);
	}
	else if (s == 3 && sec1 != "created"){
		FlightSection  economySect = FlightSection(airlineName, id, r, c, s);
		sec3 ="created";
		cout << "Section " << s << " of fight with this id: " << id << " is created." << endl;
		allSections.push_back(economySect);
	}
	else{
		cout << "Section is already created." << endl;
	}
 }
Flight::Flight(string aName, string origin, string destination,
	int y, int m, int d, string fId){
	sec1 = "not created";
	sec2 = "not created" ;
	sec3 = "not created";

	airlineName = aName;
	orig = origin;
	dest= destination;
	id = fId;
	 year=y;
	 month = m;
	 day = d;
	
}
Flight::Flight()
{
	airlineName = " ";
	orig = " ";
	dest = " ";
	id = " ";
	year = 0;
	month = 0;
	day = 0;
	sec1 = " ";
	sec2 = " ";
	sec3 = " ";
}
