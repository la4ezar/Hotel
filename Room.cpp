#include "Room.h"
#include "cstring"

Room::Room(unsigned room_number, int beds): beds(beds), room_number(room_number), available(true), accessible(true),
											hired_from(), hired_to(), people_num(0), notes("") {}

Room& Room::operator=(const Room& other) {
	if (this != &other) {
		this->available = other.available;
		this->beds = other.beds;
		this->room_number = other.room_number;
		this->hired_from = other.hired_from;
		this->hired_to = other.hired_to;
		strcpy(this->notes, other.notes);
		this->accessible = other.accessible;
		this->people_num = other.people_num;
	}
	return *this;
}

bool Room::getAvailability() const {
	return available;
}
int Room::getBeds() const {
	return beds;
}
unsigned Room::getRoomNumber() const {
	return room_number;
}
bool Room::getAccessibility() const {
	return accessible;
}
Date Room::getHiredFrom() const {
	return hired_from;
}
Date Room::getHiredTo() const {
	return hired_to;
}
const char* Room::getNote() const {
	return notes;
}
int Room::getPeopleNum() const {
	return people_num;
}

void Room::checkin(Date from, Date to, char* note) {
	hired_from = from;
	hired_to = to;
	if (strlen(note) < 100)
		strcpy(notes, note);
	else
		strcpy(notes, "");
	available = false;
}


void Room::unavailable(Date from, Date to, char* note) {
	hired_from = from;
	hired_to = to;
	if (strlen(note) < 100)
		strcpy(notes, note);
	else
		strcpy(notes, "");
	accessible = false;
}

void Room::checkout() {
	hired_from = Date();
	hired_to = Date();
	available = true;
	strcpy(notes, "");
}

bool Room::isAvailable(Date date) const {
	if (hired_from == Date() && hired_to == Date())
		return true;
	if (date < hired_to && (hired_from < date || hired_from == date))
		return false;
	return true;
}