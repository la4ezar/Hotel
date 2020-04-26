#pragma once
#include "Registration.h"

class Room {
	Registration* registrations;
	int registrations_num;
	Registration unavailable_registration;
	int beds;
	int guests;
	unsigned room_number;

	Registration* copyRegistrations(Registration* Registrations, int old_num, int new_num) const;
public:
	Room (unsigned room_number = 0, int beds = 0);
	~Room();
	Room& operator=(const Room& other);

	bool isAvailable(Date from, Date to) const;
	bool isAvailable(Date date) const;

	Registration* getRegistrations() const;
	//int getRegistrationsNum() const;
	Registration getUnavailableRegistration() const;
	int getBeds() const;
	int getGuests() const;
	unsigned getRoomNumber() const;
	int getFreeBeds() const;

	void checkin(Date from, Date to, char* note, int guests);
	void unavailable(Date from, Date to, char* note);
	bool checkout();
	int daysUsed(Date& from, Date& to) const; //with Date operator- I will cout the days

};