#include "Room.h"
#include "cstring"
#include <iostream>

Room::Room(unsigned room_number, int beds): beds(beds), room_number(room_number), 
											reservations_num(0), unavailable_reservations_num(0) {
	reservations = nullptr;
	unavailable_reservations = nullptr;
}


Reservation* Room::copyReservations(Reservation* reservations, int old_num, int new_num) const {
	Reservation* new_reservations = new Reservation[new_num];
	for (int i = 0; i < old_num; ++i) 
		new_reservations[i] = reservations[i];
	return new_reservations;
}

Room::~Room() {
	delete[] reservations;
	delete[] unavailable_reservations;
	reservations = nullptr;
	unavailable_reservations = nullptr;
}

Room& Room::operator=(const Room& other) {
	if (this != &other) {
		this->reservations = copyReservations(other.reservations, other.reservations_num, other.reservations_num);
		this->reservations_num = other.reservations_num;

		this->unavailable_reservations = copyReservations(other.unavailable_reservations, other.unavailable_reservations_num, other.unavailable_reservations_num);
		this->unavailable_reservations_num = other.unavailable_reservations_num;

		this->beds = other.beds;
		this->room_number = other.room_number;
	}
	return *this;
}

Reservation* Room::getReservations() const {
	return copyReservations(this->reservations, this->reservations_num, this->reservations_num);
}
int Room::getReservationsNum() const {
	return this->reservations_num;
}
Reservation* Room::getUnavailableReservations() const {
	return copyReservations(this->unavailable_reservations, this->unavailable_reservations_num, this->unavailable_reservations_num);
}
int Room::getUnavailableReservationsNum() const {
	return this->unavailable_reservations_num;
}

int Room::getBeds() const {
	return beds;
}
unsigned Room::getRoomNumber() const {
	return room_number;
}

bool Room::isAvailable(Date from, Date to) const {
	if (reservations_num == 0)
		return true;
	for (int i = 0; i < reservations_num; ++i) {
		if (!((reservations[i].getEndDate() <= from) ||
			(to <= reservations[i].getStartDate()))) {
			return false;
		}
	}
	return true;
}

bool Room::isAvailable(Date date) const {
	Date date_nextDay(date.getYear(), date.getMonth(), date.getDay() + 1);
	return isAvailable(date, date_nextDay);
}

void Room::checkin(Date from, Date to, char* note) {
	// validation on the Hotel cpp
	Reservation* new_reservations = copyReservations(reservations, reservations_num, reservations_num + 1);
	new_reservations[reservations_num] = Reservation(Period(from, to), note);
	if (reservations_num == 1)
		delete reservations;
	else
		delete[] reservations;

	reservations = new_reservations;
	++reservations_num;
	new_reservations = nullptr;
}

void Room::checkout() {
	for (int i = 0; i < reservations_num; ++i) {
		if (reservations[i].getIsCheckout() == false) {
			reservations[i].checkout();
			return;
		}
	}
	// maybe cerr for unsuccesfull checkout here
}


void Room::unavailable(Date from, Date to, char* note) {
	Reservation* new_unavailable_reservations = copyReservations(unavailable_reservations, unavailable_reservations_num, unavailable_reservations_num + 1);
	new_unavailable_reservations[unavailable_reservations_num] = Reservation(Period(from, to), note);
	if (unavailable_reservations_num == 1)
		delete unavailable_reservations;
	else
		delete[] unavailable_reservations;

	unavailable_reservations = new_unavailable_reservations;
	++reservations_num;
	new_unavailable_reservations = nullptr;
}

void Room::report(Date& from, Date& to) const {
	// I'll check in the Hotel function if this period is available or not, if its available Ill return that the room is used 0 days
	// 
	int days_used = 0;
	Date reservation_start_date;
	Date reservation_end_date;
	for (int i = 0; i < reservations_num; ++i) {
		reservation_start_date = reservations[i].getStartDate();
		reservation_end_date = reservations[i].getEndDate();
		if (!((reservation_end_date <= from) ||
			(to <= reservation_start_date))) {
			if (reservation_start_date <= from && to <= reservation_end_date) {
				days_used += to - from;
				continue;
			} 
			else if (reservation_start_date <= from) {
				days_used += reservation_end_date - from;
				continue;
			}
			else if (to <= reservation_end_date) {
				days_used += to - reservation_start_date;
			}
		}
	}

	std::cout << days_used;
}