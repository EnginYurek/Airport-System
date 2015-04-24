
/*
BLG252E- Object Oriented Programing Homework 1
Engin Yürek
040100524

CRN:22490
*/

using namespace std;

class Seat {
	friend class SystemManager;
	
private:
	int section;
	int column, row;
	bool isReserved;
	string booked;
public:
	Seat();
	Seat(int r, int col, int sec);
};

Seat::Seat(){
    section = 0;
	column = 0;
	row = 0;
    isReserved=false;
	booked = "Not Booked";
}

Seat::Seat(int r, int col, int sec){
	column = col;
	row = r;
	section = sec;
	isReserved = false;
	booked = "Not Booked";
}

