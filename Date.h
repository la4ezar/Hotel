#pragma once

//  ISO 8601 - [YYYY]-[MM]-[DD]

class Date {
	unsigned day;
	unsigned month;
	unsigned year;

	//void recalculate(Date& date);
	bool isLeap(int year) const;
	void setDefault();
	bool isValidDate(int year, int month, int day) const;
	int getTotalDays(Date date) const;
	int leapYears(int year, int month) const;

public:
	Date();
	Date(int year, int month, int day);
	Date(const Date& other);

	Date& operator=(const Date& other);
	bool operator==(const Date& other) const;
	bool operator<(const Date& other) const;
	bool operator<=(const Date& other) const;
	int& operator-(const Date& other);

	//void addDays(int days);
	

	unsigned getDay() const;
	unsigned getMonth() const;
	unsigned getYear() const;

	void printDate() const;

};