#include <iostream>
#include "Date.h"
#include "Room.h"
#include "Hotel.h"

void checkin();
void availability();
void checkout();
void report();
void find();
void find_algo();
void unavailable();


int main() {
	char command[13];
	do {
		std::cin >> command;
		if (!strcmp(command, "checkin")) {
			void checkin();
		}
		else if (!strcmp(command, "availability")) {
			void availability();
		}
		else if (!strcmp(command, "checkout")) {
			void checkout();
		}
		else if (!strcmp(command, "report")) {
			void report();
		}
		else if (!strcmp(command, "find")) {
			void find();
		}
		else if (!strcmp(command, "find!")) {
			void find_algo();
		}
		else if (!strcmp(command, "unavailable")) {
			void unavailable();
		}
		else if (!strcmp(command, "exit")) {
			break;
		}
		else {
			std::cout << "Invalid Command!\n";
		}
	} while (true);

	return 0;
}