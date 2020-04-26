#include <iostream>
#include "Hotel.h"
#include <ctime>
#include <cstdlib>

void checkin(Hotel& hotel);

void availability(){}
void checkout(){}
void report(){}
void find(){}
void find_algo(){}
void unavailable() {}
void open() {}
void exit() {}
void save() {}
void save_as() {}
void help() {}
void close() {}


bool isWhiteSpace(char c);
char* readStr();

void TestHotelConstructor(Hotel& hotel);
void TestHotelCheckin(Hotel& hotel);
void TestHotelCheckout(Hotel& hotel);
void TestHotelAvailability(Hotel& hotel);
void TestHotelUnavailable(Hotel& hotel);
void TestHotelReport(Hotel& hotel);
void TestHotelFind(Hotel& hotel);

int main() {
	srand(time(0));
	Hotel hotel;
	//TestHotelConstructor(hotel);
	//TestHotelCheckin(hotel);
	//TestHotelCheckout(hotel);
	//TestHotelAvailability(hotel);
	//TestHotelUnavailable(hotel);
	//TestHotelReport(hotel);
	//TestHotelFind(hotel);

	
	char command[13];
	do {
		std::cin >> command;
		if (!strcmp(command, "checkin")) {
			checkin(hotel);
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
	

	return 0;
}

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
	hotel.checkin(1, from, to, note, 1);

	hotel.checkin(1, from, to, note, 1);

	delete[] note;
	from = Date(2020, 4, 23);
	to = Date(2020, 4, 25);
	note = new char[12];
	strcpy(note, "The Susan's");
	hotel.checkin(2, from, to, note, 2);

	delete[] note;
}

void TestHotelCheckout(Hotel& hotel) {
	TestHotelCheckin(hotel);
	Room* rooms = hotel.getRooms();
	hotel.checkout(1);
	hotel.checkout(2);
	hotel.checkout(3);
	delete[] rooms;
	rooms = hotel.getRooms();
	delete[] rooms;
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
}


void TestHotelUnavailable(Hotel& hotel) {
	Date from(2020, 4, 23);
	Date to(2020, 4, 25);
	char* note = new char[16];
	strcpy(note, "The Bogomilov's");
	Room* rooms = hotel.getRooms();
	hotel.unavailable(1, from, to, note);
	hotel.unavailable(1, from, to, note);
	hotel.checkin(1, from, to, note, 1);

	Room* rooms1 = hotel.getRooms();
	delete[] note;
	from = Date(2020, 4, 23);
	to = Date(2020, 4, 25);
	note = new char[12];
	strcpy(note, "The Susan's");
	hotel.unavailable(2, from, to, note);
	Room* rooms2 = hotel.getRooms();

	delete[] rooms;
	delete[] rooms1;
	delete[] rooms2;
	delete[] note;
}


void TestHotelReport(Hotel& hotel) {
	Date from(2020, 4, 23);
	Date to(2020, 4, 25);
	char* note = new char[16];
	strcpy(note, "The Bogomilov's");
	hotel.checkin(1, from, to, note, 2);
	hotel.checkin(2, from, to, note, 2);
	hotel.checkin(3, from, to, note, 2);
	hotel.checkout(1);
	hotel.checkout(2);
	hotel.checkout(3);

	Date start(2020, 3, 23);
	Date end(2020, 4, 26);
	hotel.report(start, end);

	delete[] note;
}

void TestHotelFind(Hotel& hotel) {
	//Room* rooms = hotel.getRooms();
	Date from(2020, 4, 23);
	Date to(2020, 4, 25);
	hotel.find(1, from, to);
	hotel.find(2, from, to);
	hotel.find(3, from, to);
	hotel.find(4, from, to);
	hotel.find(5, from, to);
	hotel.find(6, from, to);

}

bool isWhiteSpace(char c) {
	return (c == ' ') ||
		(c == '\n') ||
		(c == '\t') ||
		(c == '\r');
}

char* readStr() {
	int n = 8;
	char* str = new char[n];
	int cnt = 0;
	char c = std::cin.get();
	if (c == '\n') {
		strcpy(str, "Unknown");
		std::cin.putback(c);
		return str;
	}
	while (isWhiteSpace(c)) {
		c = std::cin.get();
	}

	while (!isWhiteSpace(c)) {
		if (cnt == n - 1) {
			str[cnt] = '\0';
			char* new_str = new char[n * 2];
			strcpy(new_str, str);
			delete[] str;
			str = new_str;
			new_str = nullptr;
			n *= 2;
		}
		str[cnt++] = c;
		std::cin.get(c);
	}
	std::cin.putback(c);
	str[cnt] = '\0';
	char* new_str = new char[cnt + 1];
	strcpy(new_str, str);
	delete[] str;
	str = new_str;
	new_str = nullptr;
	return str;
}

char* readManyStr() {
	char* str = nullptr;
	char* tmp;
	for (int i = 0; true; ++i) {
		tmp = readStr();
		if (!strcmp(tmp, "Unknown") || std::atoi(tmp)) {
			if (std::atoi(tmp))
				while (*tmp)
					std::cin.putback(*tmp++);
			if (i == 0)
				return nullptr;
			break;
		}
		if (i == 0) {
			str = new char[strlen(tmp) + 1];
			strcpy(str, tmp);
		}
		else {
			strcat(str, " ");
			strcat(str, tmp);
		}
	}
	return str;
}

Date strToDate(char* str) {
	int year = atoi(str);
	str += 5;
	int month = atoi(str);
	str += 3;
	int day = atoi(str);
	Date date(year, month, day);
	return date;
}

void checkin(Hotel& hotel) {
	char* str1 = readStr();
	char* str2 = readStr();
	char* str3 = readStr();
	char* note = readManyStr();
	char* str4 = readStr();

	int room_number = atoi(str1);
	Date from = strToDate(str2);
	Date to = strToDate(str3);
	int guests = atoi(str4);

	hotel.checkin(room_number, from, to, note, guests);
}