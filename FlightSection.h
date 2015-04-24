
/*
BLG252E- Object Oriented Programing Homework 1
Engin Yürek
040100524

CRN:22490
*/

#include<iostream>

using namespace std;

class FlightSection {
	friend class SystemManager;
private:
	string airlineName, flightId;    //identifies the flight and airline that section belongs to
	int section, rows, cols;  // the number of the rows and colums that section has
	Seat seat[100][10];   //each section can have maximum 100 X 10 seats
public:
	
	FlightSection();
	FlightSection(string alName, string fId, int r, int c, int sec);
	
	 
};

FlightSection::FlightSection(){
	
	airlineName = " ";
	flightId = " ";
	rows = 0;
	cols = 0;
	section = 1;
	seat[100][10] = {  Seat() };
	
}

FlightSection::FlightSection(string alName, string fId, int r, int c, int sec){
	airlineName = alName;
	flightId = fId ;
	rows = r;
	cols = c;
	section=sec;
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 10; j++){
			if (r < 100 && c < 10){
				seat[i][j] = Seat(i, j, sec);
			}else
			{
				cout << "There is no that much seats" << endl;
			}
		}
	}
}