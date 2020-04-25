#pragma once
#include "Room.h"

class Hotel {
	Room* rooms;
	int rooms_num;
public:
	Hotel();
	~Hotel();

	Room* getRooms() const;
	int getRoomsNum() const;

	void checkin(int room_number, Date from, Date to, char* note);		// with the room checkin
	void checkout(int room_number);	// with the room checkout
	void availability(Date date) const;
};