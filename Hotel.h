#pragma once

class Hotel {
	int rooms;
	//int floors;
	int available_rooms;

public:
	Hotel();

	int getRooms() const;
	int getAvailableRooms() const;

	void checkin();		// with the room checkin
	void checkout();	// with the room checkout
};