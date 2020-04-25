#pragma once
#include "Period.h"

class Reservation {
	Period period;
	bool isCheckout;
	char* note;
public:
	Reservation();
	Reservation(Period period, char* note);
	~Reservation();
	Reservation& operator=(const Reservation& other);

	void checkout();

	Period getPeriod() const;
	Date getStartDate() const;
	Date getEndDate() const;
	bool getIsCheckout() const;
	char* getNote() const;
};