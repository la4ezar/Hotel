#include "Registration.h"
#include "cstring"

Registration::Registration(): period(), note(nullptr), isCheckout(false) {}

Registration::Registration(Period period, char* note): isCheckout(false) {
	this->period = period;
	this->note = new char[strlen(note) + 1];
	strcpy(this->note, note);
}

Registration::~Registration() {
	delete[] note;
	note = nullptr;
}
Registration& Registration::operator=(const Registration& other) {
	if (this != &other) {
		this->period = other.period;
		this->isCheckout = other.isCheckout;
		delete[] this->note;
		if (other.note != nullptr) {
			this->note = new char[strlen(other.note) + 1];
			strcpy(this->note, other.note);
		}
		else
			this->note = nullptr;
		
	}
	return *this;
}

Period Registration::getPeriod() const {
	return this->period;
}

bool Registration::getIsCheckout() const {
	return this->isCheckout;
}

char* Registration::getNote() const {
	char* new_note = new char[strlen(this->note) + 1];
	strcpy(new_note, this->note);
	return new_note;
}

Date Registration::getStartDate() const {
	return period.getStartDate();
}
Date Registration::getEndDate() const {
	return period.getEndDate();
}

void Registration::checkout() {
	this->isCheckout = true;
}