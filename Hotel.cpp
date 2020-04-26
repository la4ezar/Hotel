#include "Hotel.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Hotel::Hotel() {
	int room_number = 1;
	int beds;
	//int x = (rand() % 100) + 1;
	int x = 6;
	rooms = new Room[x];
	for (int i = 0; i < x; ++i) {
		//beds = (rand() % 5) + 1;
		beds = 6;
		rooms[i] = Room(room_number++, beds);
	}
	rooms_num = x;
}

Hotel::~Hotel() {
	delete[] rooms;
}

Room* Hotel::getRooms() const {
	Room* new_rooms = new Room[rooms_num];
	for (int i = 0; i < rooms_num; ++i)
		new_rooms[i] = rooms[i];
	return new_rooms;

}
int Hotel::getRoomsNum() const {
	return rooms_num;
}

void Hotel::checkin(int room_number, Date from, Date to, char* note, int beds) {
	
	for (int i = 0; i < rooms_num; ++i) {
		if (room_number == rooms[i].getRoomNumber()) {
			if (beds == 0)
				beds = rooms[i].getBeds();
			if (rooms[i].isAvailable(from,to) && rooms[i].getBeds() >= beds) {
				rooms[i].checkin(from, to, note, beds);
				std::cout << "Succesfull checkin.\n";
				return;
			}
			else {
				std::cout << "Unsuccessful checkin. Sorry!\n";
				return;
			}
		}
	}
}

void Hotel::checkout(int room_number) {
	for (int i = 0; i < rooms_num; ++i) {
		if (room_number == rooms[i].getRoomNumber()) {
			bool successful_checkout = rooms[i].checkout();

			if(successful_checkout)
				std::cout << "Successful checkout.\n";
			else
				std::cout << "Unsuccessful checkout.\n";

			return;
		}
	}
}

void Hotel::availability(Date date) const {
	std::cout << "Rooms available:\n";
	bool atLeastOne = false;
	for (int i = 0; i < rooms_num; ++i) {
		if (rooms[i].availability(date)) {
			std::cout << "Room " << rooms[i].getRoomNumber() << std::endl;
			atLeastOne = true;
		}
	}
	if (!atLeastOne)
		std::cout << "There are no available rooms on this date. Sorry!\n";
	std::cout << std::endl;
}

void Hotel::report(Date from, Date to) const {
	int days_used; 
	for (int i = 0; i < rooms_num; ++i) {
		days_used = rooms[i].daysUsed(from, to);

		if (days_used == 0)
			continue;
	
		std::cout << "Room " << i+1 << " is used " << days_used << " times in this period.\n";
	}
}

void Hotel::unavailable(int room_number, Date from, Date to, char* note) {
	for (int i = 0; i < rooms_num; ++i) {
		if (rooms[i].getRoomNumber() == room_number) {
			if (rooms[i].isAvailable(from, to)) {
				rooms[i].unavailable(from, to, note);
				std::cout << "Successful command. The room is now unavailable in this period.\n";
				return;
			}
			else {
				std::cerr << "Unsuccessful command.The room is already unavailable in this period.\n";
			}
		}
	}
}


void Hotel::find(int beds, Date from, Date to) const {
	int min = 0;
	int i = 0;
	for (; i < rooms_num; ++i) {
		if(rooms[i].isAvailable(from,to)){
			if (beds <= rooms[i].getBeds()) {
				if (min == 0)
					min = rooms[i].getBeds();
				if (rooms[i].getBeds() < min)
					min = rooms[i].getBeds();
				if (min == beds)
					break;
			}
		}
	}
	if (min != 0)
		std::cout << "Room " << i + 1 << " with " << min << " bed.\n";
	else
		std::cerr << "Can not find room with at least " << beds << " beds. Sorry!\n";
}

int Hotel::findSuitableRoom(int beds, Date from, Date to) const {
	int min = 0;
	int pos = -1;
	int i = 0;
	for (; i < rooms_num; ++i) {
		if (beds <= rooms[i].getBeds()) {
			if (min == 0) {
				min = rooms[i].getGuests();
				pos = i;
			}
			if (rooms[i].getGuests() < min)	{
				min = rooms[i].getGuests();
				pos = i;
			}
			if (min == 1)
				break;
		}
	}
	return pos;
}


void Hotel::find_algo(int beds, Date from, Date to) {
	int firstRoom = findSuitableRoom(beds, from, to);

	if (firstRoom == -1){
		std::cout << "The algorithm can't free room for the special guests. Sorry! \n";
		return;
	}

	int guests = rooms[firstRoom].getGuests();
	for (int i = 0; i < rooms_num ; ++i) {
		if (i != firstRoom && rooms[i].getFreeBeds() >= guests) {
			rooms[i].addOtherPeople(from, to, guests);
			rooms[firstRoom].checkout();
			std::cout << "Room " << firstRoom + 1 << " is free for the special guests.\n";
			return;
		}
	}

	int secondRoom = findSuitableRoom(guests, from, to);
	if (secondRoom == -1) {
		std::cout << "The algorithm can't free room for the special guests. Sorry! \n";
		return;
	}
	int guestsInSecondRoom = rooms[secondRoom].getGuests();
	for (int i = 0; i < rooms_num, i != firstRoom, i != secondRoom; ++i) {
		if (i != firstRoom && i != secondRoom && rooms[i].getFreeBeds() >= guestsInSecondRoom) {
			rooms[i].addOtherPeople(from, to, guestsInSecondRoom);
			rooms[secondRoom].addOtherPeople(from, to, guests);
			rooms[firstRoom].checkout();
			std::cout << "Room " << firstRoom + 1 << " is free for the special guests.\n";
			return;
		}
	}

	std::cout << "The algorithm can't free room for the special guests. Sorry! \n";
}