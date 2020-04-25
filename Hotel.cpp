#include "Hotel.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Hotel::Hotel() {
	int room_number = 1;
	int beds;
	int x = (rand() % 100) + 1;
	rooms = new Room[x];
	for (int i = 0; i < x; ++i) {
		beds = (rand() % 5) + 1;
		rooms[i] = Room(room_number++, beds);
	}
	rooms_num = x;
}

Hotel::~Hotel() {
	delete[] rooms;
}
/*
Room* Hotel::getRooms() const {
	Room* new_rooms = new Room[rooms_num];
	for (int i = 0; i < rooms_num; ++i)
		new_rooms[i] = rooms[i];
	return new_rooms;

}
int Hotel::getRoomsNum() const {
	return rooms_num;
}

void Hotel::checkin(int room_number, Date from, Date to, char* note) {
	for (int i = 0; i < rooms_num; ++i) {
		if (room_number == rooms[i].getRoomNumber()) {
			if (rooms[i].getAvailability() && rooms[i].getAccessibility()) {
				rooms[i].checkin(from, to, note);
				std::cout << "Succesfull checkin.\n";
				return;
			}
			else {
				std::cout << "The room is not available. Sorry!\n";
				return;
			}
		}
	}
}

void Hotel::checkout(int room_number) {
	for (int i = 0; i < rooms_num; ++i) {
		if (room_number == rooms[i].getRoomNumber()) {
			if (!rooms[i].getAvailability() && rooms[i].getAccessibility()) {
				rooms[i].checkout();
				std::cout << "Succesfull checkout.\n";
				return;
			}
			else {
				std::cout << "The room can't be checkout. Sorry!\n";
				return;
			}
		}
	}
}

void Hotel::availability(Date date) const {
	std::cout << "Rooms available:\n";
	for (int i = 0; i < rooms_num; ++i) 
		if (rooms[i].isAvailable(date)) 
			std::cout << "Room " << rooms[i].getRoomNumber() << std::endl;
}*/