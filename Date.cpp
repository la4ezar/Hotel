#include <iostream>
#include <iomanip>
#include <cstring>
#include "Date.h"

Date::Date() : day(0), month(0), year(0) {}

void Date::recalculate(Date& date) {
	if (date.day < 1 || date.month < 1) {
		date.day = 1;
		date.month = 1;
	}
	else {
		if (date.day > 31) {
			date.month += ((date.day - 1) / 31);
			if (date.day % 31 == 0) {
				date.day = 31;
			}
			else {
				date.day = date.day % 31;
			}
		}
		if (date.month > 12) {
			date.year += ((date.month - 1) / 12);
			if (date.month % 12 == 0) {
				date.month = 12;
			}
			else {
				date.month = date.month % 12;
			}
		}
	}
}

Date::Date(int year, int month, int day) {
	this->day = day;
	this->month = month;
	this->year = year;
	recalculate(*this);
}

Date::Date(const Date& other) {
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

bool Date::operator==(const Date& other) const {
	return (this->day == other.day &&
		this->month == other.month &&
		this->year == other.year);
}

unsigned Date::getDay() const {
	return day;
}
unsigned Date::getMonth() const {
	return month;
}
unsigned Date::getYear() const {
	return year;
}

void Date::printDate() const {
	std::cout << std::setfill('0') << std::setw(4)
		      << year << "-" << std::setw(2)
			  << month << "-" << std::setw(2)
			  << day 
			  << std::endl;
}

void Date::addDays(int days) {
	this->day += days;
	recalculate(*this);
}

Date& Date::operator=(const Date& other) {
	if (this != &other) {
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}
	return *this;
}

bool Date::operator<(const Date& other) const {
	if (this == &other) {
		return false;
	}
	if (this->year < other.year)
		return true;
	else if (this->month < other.month)
		return true;
	else if (this->day < other.day)
		return true;
	return false;
}

bool Date::operator<=(const Date& other) const {
	return (*this < other && *this == other);
}

int& Date::operator-(const Date& other) {
	return((this->day - other.day) + 31 * (this->month - other.month) + 365 * (this->year - other.year));
}
