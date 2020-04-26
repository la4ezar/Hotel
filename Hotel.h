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

	int findSuitableRoom(int beds, Date from, Date to) const;

	void checkin(int room_number, Date from, Date to, char* note, int beds);
	void checkout(int room_number);
	void availability(Date date) const;
	void report(Date from, Date to) const;
	void find(int beds, Date from, Date to) const;
	void unavailable(int room_number, Date from, Date to, char* note);
	void find_algo(int beds, Date from, Date to);
};