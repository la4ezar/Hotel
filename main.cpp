#include <iostream>
#include "Hotel.h"
#include <ctime>
#include <cstdlib>
/*
void checkin();
void availability();
void checkout();
void report();
void find();
void find_algo();
void unavailable();
*/


void TestHotelConstructor(Hotel& hotel);
void TestHotelCheckin(Hotel& hotel);
void TestHotelCheckout(Hotel& hotel);
void TestHotelAvailability(Hotel& hotel);


int main() {
	srand(time(0));
	Hotel hotel;
	//TestHotelConstructor(hotel);
	//TestHotelCheckin(hotel);
	//TestHotelCheckout(hotel);
	//TestHotelAvailability(hotel);

	/*
	char command[13];
	do {
		std::cin >> command;
		if (!strcmp(command, "checkin")) {
			checkin();
		}
		else if (!strcmp(command, "availability")) {
			availability();
		}
		else if (!strcmp(command, "checkout")) {
			checkout();
		}
		else if (!strcmp(command, "report")) {
			report();
		}
		else if (!strcmp(command, "find")) {
			find();
		}
		else if (!strcmp(command, "find!")) {
			find_algo();
		}
		else if (!strcmp(command, "unavailable")) {
			unavailable();
		}
		else if (!strcmp(command, "open")) {
			open();
			break;
		}
		else if (!strcmp(command, "close")) {
			close();
			break;
		}
		else if (!strcmp(command, "save")) {
			save();
			// or save _as();, I should get the next string to see if it is "as"
			break;
		}
		else if (!strcmp(command, "help")) {
			exit();
			break;
		}
		else if (!strcmp(command, "exit")) {
			exit();
			break;
		}
		else {
			std::cout << "Invalid Command!\n";
		}
	} while (true);
	*/

	return 0;
}
/*
void TestHotelConstructor(Hotel& hotel) {
	int n = hotel.getRoomsNum();
	Room* rooms = hotel.getRooms();
	for (int i = 0; i < n; ++i) 
		std::cout << "Room " << rooms[i].getRoomNumber() << " have " << rooms[i].getBeds() << " beds.\n";
	delete[] rooms;
}

void TestHotelCheckin(Hotel& hotel) {
	Date from(2020, 4, 23);
	Date to(2020, 4, 25);
	char* note = new char[16];
	strcpy(note, "The Bogomilov's");
	hotel.checkin(1, from, to, note);

	hotel.checkin(1, from, to, note);

	delete[] note;
	from = Date(2020, 4, 23);
	to = Date(2020, 4, 25);
	note = new char[12];
	strcpy(note, "The Susan's");
	hotel.checkin(2, from, to, note);

	delete[] note;
}

void TestHotelCheckout(Hotel& hotel) {
	TestHotelCheckin(hotel);
	hotel.checkout(1);
	hotel.checkout(2);
	hotel.checkout(3);
}

void TestHotelAvailability(Hotel& hotel) {
	Date date(2020, 4, 24);
	int n = hotel.getRoomsNum();
	std::cout << "===============================" << std::endl;
	std::cout << "Rooms are " << n << std::endl;
	hotel.availability(date);
	
	TestHotelCheckin(hotel);
	std::cout << "===============================" << std::endl;
	hotel.availability(date);

	Room* rooms = hotel.getRooms();

	TestHotelCheckout(hotel);
	std::cout << "===============================" << std::endl;
	hotel.availability(date);

	std::cout << "===============================" << std::endl;
}*/