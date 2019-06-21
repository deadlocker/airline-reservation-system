#ifndef BLUESKY_H_
#define BLUESKY_H_

#include <iostream>
#include <string>
using namespace std;

struct Node{ //node for the information of passengers
	string name;
	int id;
	int reservation_number;
	long long telephone_number;
	int seat_number;
	int menu_choice;
	Node * next;
};//struct ends

class Reservation{
	public:
			Reservation();
			bool do_reservation();
			bool cancel_reservation();
			void passenger_list();
			int data_size();
			void search_passenger();
			void change_reservation();
			bool check_seat_number(int);
			void report();
			~Reservation();
			char menu();

	private:
		Node *head;
};// class reservation ends here
#include "bluesky.cpp"
#endif
