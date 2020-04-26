#include "Room.h"
#include "cstring"
#include <iostream>

Room::Room(unsigned room_number, int beds): beds(beds), room_number(room_number), guests(0),
											registrations_num(0), unavailable_registration() {
	registrations = nullptr;
}


Registration* Room::copyRegistrations(Registration* registrations, int old_num, int new_num) const {
	Registration* new_registrations = new Registration[new_num];
	for (int i = 0; i < old_num; ++i) 
		new_registrations[i] = registrations[i];
	return new_registrations;
}

Room::~Room() {
	delete[] registrations;
	registrations = nullptr;
}

Room& Room::operator=(const Room& other) {
	if (this != &other) {
		this->registrations = copyRegistrations(other.registrations, other.registrations_num, other.registrations_num);
		this->registrations_num = other.registrations_num;

		this->unavailable_registration = other.unavailable_registration;

		this->beds = other.beds;
		this->guests = other.guests;
		this->room_number = other.room_number;
	}
	return *this;
}

Registration* Room::getRegistrations() const {
	return copyRegistrations(this->registrations, this->registrations_num, this->registrations_num);
}
/*
int Room::getReservationsNum() const {
	return this->reservations_num;
}
*/

Registration Room::getUnavailableRegistration() const {
	return this->unavailable_registration;
}

/*
int Room::getUnavailableReservationsNum() const {
	return this->unavailable_reservations_num;
}
*/

int Room::getBeds() const {
	return beds;
}
unsigned Room::getRoomNumber() const {
	return room_number;
}

int Room::getGuests() const {
	return guests;
}

int Room::getFreeBeds() const {
	return this->beds - this->guests;
}


bool Room::availability(Date date) const {
	Date from = date;
	Date to = date.nextDay();
	if (!((registrations[registrations_num - 1].getEndDate() <= from) || (to <= registrations[registrations_num - 1].getStartDate())))
		return false;

	if (!((unavailable_registration.getEndDate() <= from) || (to <= unavailable_registration.getStartDate())))
		return false;
	return true;
}

bool Room::isAvailable(Date from, Date to) const {
	if(registrations_num != 0)
		if (registrations[registrations_num - 1].getIsCheckout() == false)
			return false;

	// If the dates intersect
	if (!((unavailable_registration.getEndDate() <= from) || (to <= unavailable_registration.getStartDate())))
		return false;

	return true;
	
	/*
	if(registrations[registrations_num - 1].getIsCheckout() == true)
		if (!((registrations[registrations_num - 1].getEndDate() <= from) || (to <= registrations[registrations_num - 1].getStartDate())))
			return false;

	if (!((unavailable_registration.getEndDate() <= from) || (to <= unavailable_registration.getStartDate())))
		return false;

	return true;
	*/
}

bool Room::isAvailable(Date date) const {
	return isAvailable(date, date.nextDay());
}

void Room::checkin(Date from, Date to, char* note, int guests) {
	Registration* new_registrations = copyRegistrations(registrations, registrations_num, registrations_num + 1);
	new_registrations[registrations_num] = Registration(Period(from, to), note);
	
	delete[] registrations;

	registrations = new_registrations;
	++registrations_num;
	new_registrations = nullptr;

	this->guests = guests;
}

bool Room::checkout() {
	if(registrations[registrations_num - 1].getIsCheckout() == false){
		registrations[registrations_num - 1].checkout();
		this->guests = 0;
		return true;
	}
	return false;
}


void Room::unavailable(Date from, Date to, char* note) {
	unavailable_registration = Registration(Period(from, to), note);
	/*
	Registration* new_unavailable_registration = copyRegistrations(unavailable_registration, unavailable_reservations_num, unavailable_reservations_num + 1);
	new_unavailable_reservations[unavailable_reservations_num] = Reservation(Period(from, to), note);
	if (unavailable_reservations_num == 1)
		delete unavailable_reservations;
	else
		delete[] unavailable_reservations;

	unavailable_reservations = new_unavailable_reservations;
	++reservations_num;
	new_unavailable_reservations = nullptr;
	*/
}


int Room::daysUsed(Date& from, Date& to) const {
	// I'll check in the Hotel function if this period is available or not, if its available Ill return that the room is used 0 days
	// 
	int days_used = 0;
	Date registration_start_date;
	Date registration_end_date;
	for (int i = 0; i < registrations_num; ++i) {
		registration_start_date = registrations[i].getStartDate();
		registration_end_date = registrations[i].getEndDate();

		// If the dates intersects
		if (!((registration_end_date <= from) ||
			(to <= registration_start_date))) {
			if (registration_start_date <= from && to <= registration_end_date) {
				days_used += to - from;
				continue;
			} 
			else if (registration_start_date <= from) {
				days_used += registration_end_date - from;
				continue;
			}
			else if (to <= registration_end_date) {
				days_used += to - registration_start_date;
				continue;
			}
			else {
				days_used += registration_end_date - registration_start_date;
			}
		}
	}
	return days_used;
}


void Room::addOtherPeople(Date from, Date to, int guests) {
	this->guests += guests;
	if (registrations[registrations_num - 1].getStartDate() < from) {
		from = registrations[registrations_num - 1].getStartDate();
		if (to < registrations[registrations_num - 1].getEndDate()) 
			to = registrations[registrations_num - 1].getEndDate();
		
		registrations[registrations_num - 1] = Registration(Period(from, to), registrations[registrations_num - 1].getNote());
	}
	else {
		if(to < registrations[registrations_num - 1].getEndDate())
			to = registrations[registrations_num - 1].getEndDate();

		registrations[registrations_num - 1] = Registration(Period(from, to), registrations[registrations_num - 1].getNote());
	}
}