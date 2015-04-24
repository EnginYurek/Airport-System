
/*
BLG252E- Object Oriented Programing Homework 1
Engin Yürek
040100524

CRN:22490
*/

#include<string>
#include<iostream>
#include<vector>
#include"Seat.h"
#include"Airport.h"
#include"Airline.h"
#include"Flight.h"

//#include<algorithm>

using namespace std;

class SystemManager{

private:
	Airport ap;
	Airline al;
	Flight  f;

	bool isAPExist(string newAPName);   //returns true if the airport is created
	bool isALExist(string newALName);	//returns true if the airline is created
	bool isFlOk(Flight f);				// returns true if the flight info is suitable (checks the airline name, date, flightId etc.)
	//bool isFInfoSuitable(string aName, string orig, string dest, int year, int month, int day);
	bool isFExist(string fId);          //checks if there is another flight with fId
	void myToUpper(string &name);		//converts lowercase strings to upper case

	static vector <string>  airportNames;  //keeps all airport names that are created in system.
	static vector<string>airlineNames;		//keeps all airline names that are created in system.
	static vector<Flight> allFlights;		 //keeps all flights that are created in system.

public:
	SystemManager();
	void createAirport(string aPort);
	void createAirline(string aLine);
	void printAll();						//prints all information of the system
	void createFlight(string aName, string orig, string dest,			//creates flights
						int year, int month, int day, string fId);		
	void createSection(string airline, string fId, int rows, int cols, int s);//creates section of particular flight with fId
	void bookSeat(string airline, string fId, int sec, int row, char col);   //books seats
	void findAvilableFlights(string orig, string dest);  //prints available flights between orig and dest airports
};

vector<string>SystemManager::airportNames;
vector<string>SystemManager::airlineNames;
vector<Flight>SystemManager::allFlights;

SystemManager::SystemManager(){
//	ap = Airport();
//	al = Airline();
//	f = Flight();
}

void SystemManager::myToUpper(string &s)
{
	for (int l = 0; l < s.length(); l++)
	{
		s[l] = toupper(s[l]);
	}
}

bool SystemManager::isAPExist(string newAPName){
	if (airportNames.empty()){
		return false;
	}
	else{
		for (unsigned int i = 0; i < airportNames.size(); i++){
			if (newAPName == airportNames[i])
				return true;
		}
	}
	return false;
}
bool SystemManager::isALExist(string newALName){
	if (airlineNames.empty()){
		return false;
	}
	else{
		for (unsigned int i = 0; i < airlineNames.size(); i++){
			if (newALName == airlineNames[i])
				return true;
		}
	}
	return false;
}
bool SystemManager::isFExist(string fId){
	if (allFlights.empty()){
		return false;
	}
	else {
		for (int i = 0; i < allFlights.size(); i++){
			if (allFlights[i].id == fId){
				return true;
			}
			else{
				return false;
			}
		}
	}
}
bool SystemManager::isFlOk(Flight f){
	if (allFlights.empty()){
		return true;
	}
	else{
		for (int i = 0; i < allFlights.size(); i++){
			if (f.airlineName == allFlights[i].airlineName && f.orig == allFlights[i].orig && f.dest == allFlights[i].dest &&
				f.id == allFlights[i].id && f.year == allFlights[i].year && f.month == allFlights[i].month && f.day == allFlights[i].day){
				return false;
			}
			else if (f.id == allFlights[i].id){
				cout << "This id belongs to another flight" << endl;
				return false;
			}
			else if (!isALExist(f.airlineName)){
				cout << "This airline doesnt exist" << endl;
				return false;
			}
			else if ((!isAPExist(f.orig)) || (!isAPExist(f.dest))){
				cout << "Wrong airports" << endl;
				return false;
			}
			else if (f.year > 2015){
				cout << "Year must be lower than 2015 " << endl;
				return false;
			}
			else if (f.month > 12 || f.month < 1){
				cout << "Month must be between 1-12" << endl;
				return false;
			}
			else if (f.day>30 || f.day < 1){
				cout << "Month must be between 1-12" << endl;
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}


void SystemManager::createAirport(string aPort){
	myToUpper(aPort);  //convert the name to all characters uppercase

	if (aPort.size() != 3){  //check the size of the airport name
		cout << aPort << " is not suitabe name. Airport name must have exactly 3 characters." << endl;
	}
	else
		if (isAPExist(aPort)){ //check if the airopt is already created
			cout << aPort << " is already exist." << endl;
		}
		else{
			ap = Airport(aPort);  //create airport
			airportNames.push_back(aPort);  //keep airprot name for future functions
		}
}
void SystemManager::createAirline(string aLine){

	myToUpper(aLine);	//convert the name to all characters uppercase

	if (isALExist(aLine)){
		cout << "There is already an airline named " << aLine << "." << endl;
		cout << "Please choose another name." << endl;
	}
	else{
		al = Airline(aLine);
		airlineNames.push_back(aLine);		//keep airline name for future functions
	}
}
void SystemManager::createFlight(string aName, string orig, string dest,
	int year, int month, int day, string fId){
	myToUpper(aName);
	myToUpper(orig);
	myToUpper(dest);


	f = Flight(aName, orig, dest, year, month, day, fId);  // creates the flight

	if (!isFlOk(f)){  //checks the created flight is suitable to our system
		cout << "Flight is exist" << endl;
	}
	else{
		cout << "Flight with " << f.id << " is created." << endl;
		allFlights.push_back(f);  //stores the flight info in static vector
	}
	//}
}
 void SystemManager::createSection(string airline, string fId, int rows, int cols, int s){
	 myToUpper(airline);
	 if (!isALExist(airline)){  //check the airline
		 cout << "Wrong airline." << endl;
	 }
	 else{
		 for (unsigned int i = 0; i < allFlights.size(); i++){  
			 if (fId == allFlights[i].id){						//finds the flight 
				 allFlights[i].createSection(rows, cols, s);  //creas sections in that flight
			 }

		 }
	 }
 }
 void SystemManager::bookSeat(string airline, string fId, int sec, int row, char column){
	 column=toupper(column);
	 int col = 0;			
	 switch (column)					// it is hard to code with chars especially in loops we cant use it as counters
	 {								   //this is the easiest solution I find to convert the chars to int numbers
	 case 'A':		col = 1; break;   //so ý can use the number equivalence of the letters in square brackets and loops
	 case 'B':      col = 2; break;
	 case 'C':		col = 3; break;
	 case 'D':		col = 4; break;
	 case 'E':		col = 5; break;
	 case 'F':		col = 6; break;
	 case 'G':		col = 7; break;
	 case 'H':		col = 8; break;
	 case 'I':		col = 9; break;
	 case 'J':		col = 10; break;
	 default:		break; 
	 }
	 
	 row = row - 1;  //system user dont know that the matrices start to count from 0
	 col = col - 1; //so ý decrease 1 the numbers of columns and rows
	 myToUpper(airline);
	
	 if (!isALExist(airline)){
		 cout << "There is no such airline" << endl;
	 }
	 else if (!isFExist(fId)){
		 cout << "There is no such flight" << endl;
	 }
	 else{
		 for (int i = 0; i < allFlights.size(); i++){ 

			 if (allFlights[i].airlineName == airline && allFlights[i].id == fId){   //finds the flight that we want to book a seat in it.
				 for (int j = 0; j < allFlights[i].allSections.size(); j++){

					 if (allFlights[i].allSections[j].section == sec){ //finds the section that we want to book a seat in that section of flight
						 if (allFlights[i].allSections[j].rows < row){ //checks if that section has that seat in it.(in next to if statements)
							 cout << "There is only " << allFlights[i].allSections[j].rows << " rows in section " << sec << endl;
						 }
						 else 
							 if (allFlights[i].allSections[j].cols < col){
							 cout << "There is only " << allFlights[i].allSections[j].cols << " columns in section " << sec << endl;
						 }else 
							 //ý have chain here like a fligth has section and ection has seat matrix and every single seat has booked attribute
							 if (allFlights[i].allSections[j].seat[row][col].booked == "Not Booked"){ //checks if the seat is already booked or not

							 cout << "Flight: " << allFlights[i].id << " Section: " << allFlights[i].allSections[j].section
								 << " Seat: " << row+1 << ", " << col << " is booked" << endl;
							 allFlights[i].allSections[j].seat[row][col].booked = "Booked"; //change the status of the seat so we cant book it twice
						 }
						 else{
							 cout << "Seat is already booked." << endl;
						 }
					 }
				 }
			 }
		 }
	 }


 }
 void SystemManager::findAvilableFlights(string orig, string dest){
	 myToUpper(orig);
	 myToUpper(dest);

	 cout << endl << endl << "			*****Available Flights*****" << endl << endl;

	 for (int i = 0; i < allFlights.size(); i++){
		 if (allFlights[i].orig == orig && allFlights[i].dest == dest){
			 cout << "Origin= " << orig << ", Destination= " << dest << ", Flight Id= " << allFlights[i].id << endl;
		 }
	 }


 }
 void SystemManager::printAll(){
	 cout << endl << endl << "			****All Infos****" << endl << endl;
	 cout << "-Airport Names: " << endl;

	 for (unsigned int i = 0; i < airportNames.size(); i++){
		 cout << airportNames[i] << endl;
	 }

	 cout << endl << "-Airline Names: " << endl;

	 for (unsigned int i = 0; i < airlineNames.size(); i++){
		 cout << airlineNames[i] << endl;
	 }

	 cout << endl << "-Current Flights" << endl;

	 for (unsigned int i = 0; i < allFlights.size(); i++){
		 cout << allFlights[i].id << endl;
	 }

	 cout << endl << "-Booked Seats:" << endl;
	 for (int i = 0; i < allFlights.size(); i++){
		 for (int j = 0; j < allFlights[i].allSections.size(); j++){
			 cout << endl << "Seats of flight " << allFlights[i].id << " in section" << allFlights[i].allSections[j].section << " are: " << endl;
			 for (int k = 0; k < allFlights[i].allSections[j].rows; k++){

				 for (int l = 0; l < allFlights[i].allSections[j].cols; l++){

					 cout << "[ " << allFlights[i].allSections[j].seat[k][l].booked << " ]";
				 }
				 cout << endl;
			 }
		 }
	 }
 }




















