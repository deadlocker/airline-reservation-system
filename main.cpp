
#include <iostream>
#include "string.h"
#include <cstdlib>
#include "bluesky.h"
#include <time.h>
using namespace std;

int main(){
	Reservation bluesky;
	char choice;
	int done =0;
	while(!done){
		choice = bluesky.menu(); // calling menu
		switch(choice){
			case '1': 
			bluesky.do_reservation();
				break;
			case '2': 
			bluesky.cancel_reservation();
				break;
			case '3': 
			bluesky.search_passenger();
				break;
			case '4': 
			bluesky.change_reservation();
				break;
			case '5': 
			bluesky.passenger_list();
				break;
			case '6': 
			bluesky.report();
				break;
			case '7':
			exit(0);
			break;
			default : cout <<"Invalid choice, hit enter to return " << "MENU" <<"\n";
				cout<< "Welcome to Manin Menu. " <<"\n";
				break;
			cin.get();
		}//end of switchs
	}//end of while loop
	return 0;
}
