#pragma once
#include "Date.h"
//#include "Person.h" // Bonus

class Room {
	bool available;
	int beds;
	unsigned room_number;
	Date hired_from;
	Date hired_to;
	char notes[100];
	bool accessible;
	//Person* people;	// Bonus
	int people_num;
	//Activities activities; // Bonus

public:
	Room(int beds, unsigned room_number);

	bool getAvailability() const;
	int getBeds() const;
	unsigned getRoomNumber() const;
	bool getAccessibility() const;
	Date getHiredFrom() const;
	Date getHiredTo() const;
	char* getNote() const;
	int getPeopleNum() const;
	//Activities getActivities() const;	// Bonus

	void checkin(Date from, Date to, char* note);
	void unavailable(Date from, Date to, char* note);
	void checkout();

};