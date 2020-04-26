#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include "Date.h"

Date::Date() : day(0), month(0), year(0) {}

void Date::setDefault() {
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

bool Date::isLeap(int year) const {
	if (year % 4 == 0) {
		if (year % 400 == 0)
			return true;
		if (year % 100 == 0)
			return false;
		return true;
	}
	return false;
}


bool Date::isValidDate(int year, int month, int day) const {
	if (day > 31 || year < 0 || month < 1 || month > 12 || day < 1)
		return false;

	switch (month) {
	case 2:
		if (isLeap(year)) {
			if (day > 29) {
				return false;
			}
		}
		else
			if (day > 28)
				return false;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day > 30)
			return false;
		break;
	}
	return true;
}

Date Date::nextDay() {
	Date new_date;
	if (isValidDate(this->year, this->month, this->day + 1))
		new_date = Date(this->year, this->month, this->day + 1);
	else {
		if (isValidDate(this->year, this->month + 1, 1)) 
			new_date = Date(this->year, this->month + 1, 1);
		else
			new_date = Date(this->year + 1, 1 , 1);
	}
	return new_date;
}

Date::Date(int year, int month, int day) {
	if(isValidDate(year, month, day)){	
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else {
		std::cerr << "Unvalid date.\n";
		setDefault();
	}
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
	else if (this->year == other.year) {
		if (this->month < other.month)
			return true;
		else if(this->month == other.month){
			if (this->day < other.day)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool Date::operator<=(const Date& other) const {
	return (*this < other || *this == other);
}

int Date::leapYears(int year, int month) const {
	if (month < 3)
		--year;
	return ((year / 4) - (year / 100) + (year / 400));
}


int Date::getTotalDays(Date date) const {
	int days = date.getDay() + date.getYear() * 365;

	for (int i = 1; i < date.getMonth(); ++i) {
		switch (i) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				days += 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				days += 30;
				break;
			case 2:
				days += 28;
				break;
		}
	}

	days += leapYears(date.getYear(), date.getMonth());
	return days;
}


int& Date::operator-(const Date& other) {
	int days1 = getTotalDays(*this);
	int days2 = getTotalDays(other);
	int difference = abs(days1 - days2);
	return difference;
}