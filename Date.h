#pragma once

//  ISO 8601 - [YYYY]-[MM]-[DD]

class Date {
	unsigned day;
	unsigned month;
	unsigned year;

	void recalculate(Date& date);

public:
	Date();
	Date(int year, int month, int day);
	Date(const Date& other);

	bool operator==(const Date& other) const;

	void addDays(int days);

	unsigned getDay() const;
	unsigned getMonth() const;
	unsigned getYear() const;

	void printDate() const;

};