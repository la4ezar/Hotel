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
	int people_num;


	//Person* people;	// Bonus
	//Activities activities; // Bonus

public:
	Room (unsigned room_number = 0, int beds = 0);
	Room& operator=(const Room& other);

	bool isAvailable(Date date) const;

	bool getAvailability() const;
	int getBeds() const;
	unsigned getRoomNumber() const;
	bool getAccessibility() const;
	Date getHiredFrom() const;
	Date getHiredTo() const;
	const char* getNote() const;
	int getPeopleNum() const;

	void checkin(Date from, Date to, char* note);
	void unavailable(Date from, Date to, char* note);
	void checkout();



	//Activities getActivities() const;	// Bonus
};