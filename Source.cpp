
/*
BLG252E- Object Oriented Programing Homework 1

Engin Yürek
040100524

CRN:22490
*/

#include<iostream>
#include "SystemManager.h"


using namespace std;

int main(){
	
	SystemManager  res;
	cout << endl << "			*****CREATE AIRPORTS*****" << endl << endl;
	
	res.createAirport("DEN");
	res.createAirport("dfw");
	res.createAirport("LON");
	res.createAirport("DEN");//invalid, same name created before
	res.createAirport("denw");//invalid more than 3 chars

	cout <<endl<< endl << "			*****CREATE AIRLINES*****" << endl << endl;

	res.createAirline("delta");
	res.createAirline("AMER");
	res.createAirline("FRONT");
	res.createAirline("front"); //invalid same name created before

	cout << endl << endl << "			*****CREATE FLIGHTS*****" << endl << endl;

	res.createFlight("DELTA", "DEN", "LON", 2013, 10, 10, "123");
	res.createFlight("DELTA", "DEN", "DEH", 2013, 8, 8, "567abc");//invalid airports
	res.createFlight("DEL", "DEN", "LON", 2013, 9, 8, "567"); //invalid airline
	res.createFlight("DELTA", "LON33", "DEN33", 2013, 5, 7, "123");//invalid airports
	res.createFlight("AMER", "DEN", "LON", 2010, 40, 100, "123abc");//invalid date
    
	cout << endl << endl << "			*****CREATE SECTIONS*****" << endl << endl;

	res.createSection("DELTA", "123", 2, 2, 3);
	res.createSection("DELTA", "123", 2, 3, 1);

	res.createSection("DELTA", "123", 2, 3, 1);//Invalid
	res.createSection("SWSERTT", "123", 5, 5, 3);//Invalid airline*/
	
	cout << endl << endl << "			*****BOOK SEATS*****" << endl << endl;

	res.bookSeat("DELTA", "123",   1, 1,'A');
	res.bookSeat("DELTA", "123", 1, 2, 'A');
	res.bookSeat("DELTA", "123", 3, 4, 'A');
	res.bookSeat("DELTA", "123", 3, 2, 'B');
	res.bookSeat("DELTA", "123", 3, 2, 'A');
	res.bookSeat("DELTA", "123", 1, 3, 'B');
	res.bookSeat("DELTA", "123", 3, 1, 'B');
	res.bookSeat("DELTA888", "123", 2, 1, 'A'); //Invalid airline
	res.bookSeat("DELTA", "123haha7", 2, 1, 'A'); //Invalid flightId
	res.bookSeat("DELTA", "123", 3, 1, 'A'); //already booked
	
	res.findAvilableFlights("DEN", "LON");
	res.printAll();
	
	fflush(stdin);
	getchar();
	return 0;
}