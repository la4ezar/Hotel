#include "Reservation.h"
#include "cstring"

Reservation::Reservation(): period(), note(nullptr), isCheckout(false) {}

Reservation::Reservation(Period period, char* note): isCheckout(false) {
	this->period = period;
	this->note = new char[strlen(note) + 1];
	strcpy(this->note, note);
}

Reservation::~Reservation() {
	delete[] note;
	note = nullptr;
}
Reservation& Reservation::operator=(const Reservation& other) {
	if (this != &other) {
		this->period = other.period;
		this->isCheckout = other.isCheckout;
		delete[] this->note;
		this->note = new char[strlen(other.note) + 1];
		strcpy(this->note, other.note);
	}
	return *this;
}

Period Reservation::getPeriod() const {
	return this->period;
}

bool Reservation::getIsCheckout() const {
	return this->isCheckout;
}

char* Reservation::getNote() const {
	char* new_note = new char[strlen(this->note) + 1];
	strcpy(new_note, this->note);
	return new_note;
}

Date Reservation::getStartDate() const {
	return period.getStartDate();
}
Date Reservation::getEndDate() const {
	return period.getEndDate();
}

void Reservation::checkout() {
	this->isCheckout = true;
}