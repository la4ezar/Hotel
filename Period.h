#pragma once
#include "Date.h"

class Period {
	Date startDate;
	Date endDate;
public:
	Period();
	Period(Date startDate, Date endDate);
	Period& operator=(const Period& other);

	Date getStartDate() const;
	Date getEndDate() const;
};