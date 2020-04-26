#pragma once
#include "Period.h"

class Registration {
	Period period;
	bool isCheckout;
	char* note;
public:
	Registration();
	Registration(Period period, char* note);
	~Registration();
	Registration& operator=(const Registration& other);

	void checkout();

	Period getPeriod() const;
	Date getStartDate() const;
	Date getEndDate() const;
	bool getIsCheckout() const;
	char* getNote() const;
};