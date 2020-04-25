#include "Period.h"

Period::Period(): startDate(), endDate() {}
Period::Period(Date startDate, Date endDate) {
	this->startDate = startDate;
	this->endDate = endDate;
}

Date Period::getStartDate() const {
	return this->startDate;
}
Date Period::getEndDate() const {
	return this->endDate;
}

Period& Period::operator=(const Period& other) {
	if (this != &other) {
		this->startDate = other.startDate;
		this->endDate = other.endDate;
	}
	return *this;
}