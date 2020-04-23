#pragma once

enum Activities {
	Karaoke,
	Gaming,
	Poker,
	Business
};

class Person {
	char first_name[20];
	char family_name[20];
	Activities activities;
};