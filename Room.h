#pragma once
#include "Reservation.h"

class Room {
	Reservation* reservations;
	int reservations_num;
	Reservation* unavailable_reservations;	// for unavailable command
	int unavailable_reservations_num;
	int beds;
	unsigned room_number;

	Reservation* copyReservations(Reservation* reservations, int old_num, int new_num) const;
public:
	Room (unsigned room_number = 0, int beds = 0);
	~Room();
	Room& operator=(const Room& other);

	bool isAvailable(Date from, Date to) const;
	bool isAvailable(Date date) const;

	Reservation* getReservations() const;
	int getReservationsNum() const;
	Reservation* getUnavailableReservations() const;
	int getUnavailableReservationsNum() const;
	int getBeds() const;
	unsigned getRoomNumber() const;

	void checkin(Date from, Date to, char* note);
	void unavailable(Date from, Date to, char* note);
	bool checkout();
	int daysUsed(Date& from, Date& to) const; //with Date operator- I will cout the days

};