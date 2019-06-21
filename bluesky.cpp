#include "bluesky.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor
Reservation::Reservation(){
	head = NULL;
}
//this function lets user to make reservation and requires parameters like name, id , reservation number, 
//telephone number, and menu preference
bool Reservation::do_reservation(){
	Node * input = new Node;
	cout << "Enter your name :\t";
	cin >> (*input).name;
	cout <<"Enter your ID :\t";
	cin >> (*input).id;
	cout <<"Enter your Telephone Number :\t";
	cin >>(*input).telephone_number;
	cout <<"Enter your reservation number :\t";
	cin >>(*input).reservation_number;
	cout <<"Enter your seat number :\t";
	cin >>(*input).seat_number;

	//checks if seat number is available or not
	while(check_seat_number((*input).seat_number)){
		cout<<"The seat is not available. Enter another choice...\t";
		cin>>(*input).seat_number;
	}
	//choices for food
	cout << "Available menu Preferences :\n";
	cout <<"\n";
	cout << " 1 is alcoholic beverages, 2 is non vegeterian food, 3 is vegeterian food, enter 4 if you dont want any.\n";
	cout << "Enter your choice :\n";
	cin >> (*input).menu_choice;
	cout <<"\n";
	
		switch((*input).menu_choice){
			case 1 : cout << " Your choice is alcoholic beverages.\n";
				break;
			case 2 : cout << "Your choice is vegetarian food.\n";
				break;
			case 3 : cout << "Your choice is vegetarian food.\n";
				break;
			case 4 : cout << "You didnt include any choice.\n";
				break;
			default : cout <<"You dint like to chose any of those. \n";
		}

	cout <<"\n";
	cout <<"\n";

	if(head == NULL){
		head = input;
		return true;
	}
	else if((*head).name > (*input).name){
		(*input).next = head;
		head = input;
	}
	else{
		Node *pre, *cur;
		pre = head;
		cur = (*head).next;
		while(cur != NULL && (*cur).name < (*input).name){
			pre = cur;
			cur = (*cur).next;
		}
		(*input).next = cur;
		(*pre).next = input;
		return true;
	}
	cout <<"\n";
}//do_reservation ends


//function to display all information in the list
void Reservation::passenger_list(){
	Node * temp = head;
	cout << "Information available in the list :\n";

	while(temp != NULL){
		cout << "Passenger Name : ";
		cout << (*temp).name <<"\n";
		cout << "Passenger ID :\t";
		cout << (*temp).id <<"\n";
		cout << "Reservation # :\t";
		cout << (*temp).reservation_number <<"\n";
		cout << "Telephone # :\t";
		cout << (*temp).telephone_number <<"\n";
		cout << "Seat # :\t";
		cout << (*temp).seat_number <<"\n";
		cout << "Menu choice :\t";
		cout << (*temp).menu_choice <<"\n";
		cout <<"\n";
		temp = (*temp).next; 
	}
	cout <<"\n";
}//passenger_list ends

//destructor 
Reservation::~Reservation(){
	if(head == NULL)
		return;
	else{
		Node * del;
		while (head != NULL){
			del = head;
			head = (*head).next;
			delete head;
		}
	}
}


//increament for data size
int Reservation::data_size(){
	Node *temp = head;
	int count = 0;
	while (temp != NULL){
		count++;
		temp = (*temp).next;
	}
	return count;
}


//this function searches for a passenger and displays its information available in the system
void Reservation::search_passenger(){
	Node * input = new Node;

	cout << "Searching for passenger :\t";
	cin >> (*input).name;
	cout << "\n";

	if(head == NULL){
		cout << "Passenger" << (*input).name << " has not registered yet. !!!! NOT FOUND !!!";
		cout <<"\n";
	}
	else if((*head).name.compare((*input).name) == 0){
		cout << "Passenger " <<(*input).name <<" data found sucessfully \n";
		input = head;	

		cout << "Passenger Name : ";
		cout << (*input).name <<"\n";
		cout << "Passenger ID :\t";
		cout << (*input).id <<"\n";
		cout << "Reservation # :\t";
		cout << (*input).reservation_number <<"\n";
		cout << "Telephone # :\t";
		cout << (*input).telephone_number <<"\n";
		cout << "Seat # :\t";
		cout << (*input).seat_number <<"\n";
		cout << "Menu choice :\t";
		cout << (*input).menu_choice <<"\n";
		cout <<"\n";
	}
	else{
		Node *temp = (*head).next;
	
		while((temp != NULL) && ((*temp).name.compare((*input).name)) !=0){
			temp = (*temp).next;
		}

		if(temp != NULL){
		cout <<" Passenger" <<(*input).name<<" data found sucessfully !!\n";
		cout << "Passenger Name : ";
		cout << (*temp).name <<"\n";
		cout << "Passenger ID :\t";
		cout << (*temp).id <<"\n";
		cout << "Reservation # :\t";
		cout << (*temp).reservation_number <<"\n";
		cout << "Telephone # :\t";
		cout << (*temp).telephone_number <<"\n";
		cout << "Seat # :\t";
		cout << (*temp).seat_number <<"\n";
		cout << "Menu choice :\t";
		cout << (*temp).menu_choice <<"\n";
		cout <<"\n";
		}
		else{
			cout << "Passenger" << (*input).name <<" data not found. !!!!PLEASE REGISTER!!!!";
		}
	}
}//search_passenger ends


//this function searches for the desired passenger and deletes the node when user enters exactly the
//same option to cancel reservation
bool Reservation::cancel_reservation(){
	Node *input = new Node;
	cout << "Enter the name of passenger to cancel reservation :";
	cin >> (*input).name;
	cout <<"\n";
	if (head == NULL){
		cout <<"List is empty!!!\n";
		return false;
	}
	else if(((*head).name).compare((*input).name)== 0){
		Node * del;
		del = head;
		head = (*head).next;
		delete del;
		cout << "Reservation for "<< (*input).name << " has been canceled!!!\n"; 
	}
	else{
		Node *pre, *cur;
		pre = head;
		cur = (*head).next;

		while (cur != NULL && (((*cur).name).compare((*input).name)!=0)){
			pre = cur;
			cur = (*cur).next;
		}

		if(cur != NULL){
			(*pre).next = (*cur).next;
			cout << "Reservation for "<< (*input).name << " has been canceled!!!\n"; 
			return true;
		}
		else{
			cout << "!!!!!!!!!!!Passenger" <<(*input).name <<" record is not found in the list!!!!!!!!!\n";
			return false;
		}
	}
	cout <<"\n";
	cout <<"\n";
}


//this is a driver function for user. Looking at this user can do various processes available in 
//airline reservation system
char Reservation::menu(){
	cout << "####################################################\n";
	cout << "\tAIRLINE RESERVATION SIMULATION SYSTEM.\n";
	cout << "####################################################\n";
	cout << "\n" << "\n";
	cout << "These are the following choices you can make. Chose accordingly.\n";
	cout << "1. Make Reservation.\n";
	cout << "2. Cancel Reservation.\n";
	cout << "3. Search for a Passenger Information.\n";
	cout << "4. Change a Reservation.\n";
	cout << "5. Print Passengers List.\n";
	cout << "6. Design the record report.\n";
	cout << "7. Exit. \n";
	cout << "Enter your choice :";
	cout << "\n";
	char option;
	cin >> option;
	cout <<"\n";
	cout <<"\n";
	return option;
}


//function searches for a passenger and tells user to make a change in reservation, then saves the record.
void Reservation::change_reservation(){
	Node *input = new Node;

	cout << " Searching for desired Passenger.....\n";
	cin >> (*input).name;
	if(head == NULL){
		cout << "Passenger " << (*input).name << " was not found in database!!! Please proceed..\n";
		cout << "\n";
	}
	else if((*head).name.compare((*input).name)== 0){
		cout << "Passenger "<<(*input).name <<" data successfully found!! Please proceed..\n";
		input = head;
		cout << "Seat # : ";
		cin >> (*input).seat_number;
		cout << "Menu choices :";
		cin >> (*input).menu_choice;
		cout <<"\n";
		cout <<" The change of reservation is done. Thanks.\n";
		cout <<"\n";
	}
	else{
		Node *temp = (*head).next;
		
		while((temp != NULL) && ((*temp).name.compare((*input).name))!=0){
			temp = (*temp).next;
		}
		
		if(temp != NULL){
			cout << "Passenger " <<(*input).name <<" data successfully found!! Please proceed..\n";
			input = head;
			cout << "Seat # : ";
			cin >> (*input).seat_number;
			cout << "Menu choices :";
			cin >> (*input).menu_choice;
			cout <<"\n";
			cout <<" The change of reservation is done. Thanks.\n";
			cout <<"\n";
		}
		else{
			cout << "!!!!!!!!!!Passenger "<<(*input).name <<"data not found!!!!!!!!!!\n";
		}
	}
}//change_reservation ends


//function to check if seat number is available or not. If empty makes reservation, else tells to chose another
//number
bool Reservation::check_seat_number(int s){
	Node *input = new Node;
	(*input).seat_number = s;
	if(head == NULL){
		cout << "Mr/Mrs, We found seat and reservation is made for you. Have a safe flight..\n";
		cout <<"\n";
		return 0;
	}
	else if ((*head).seat_number == (*input).seat_number){
		return 1;
	}
	else{
		Node *temp = new Node;
		while (temp != NULL && (*temp).seat_number != (*input).seat_number){
			temp = (*temp).next;
		}
		if(temp != NULL){
			return 1;
		}
		else{
			return 0;
		}
	}
}//check_seat_number ends

//function to display all information given while making reseervation
void Reservation::report(){
	cout << "####################################################################\n";
	cout << " Detailed information about the reservation made by the passenger.\n";
	cout << "####################################################################\n";
	Node * temp = head;
	cout << "Here is your details : \n";
	cout <<"\n";
	cout << " 1 is alcoholic beverages, 2 is non vegeterian food, 3 is vegeterian food, 4 is you didnt chose to select. \n";

	while(temp != NULL){
		cout << "Passenger Name :\t";
		cout << (*temp).name <<"\n";
		cout << "Passenger ID :\t";
		cout << (*temp).id <<"\n";
		cout << "Reservation # : ";
		cout << (*temp).reservation_number <<"\n";
		cout << "Telephone # :\t";
		cout << (*temp).telephone_number <<"\n";
		cout << "Seat # :\t";
		cout << (*temp).seat_number <<"\n";
		cout << "Menu choice :\t";
		cout << (*temp).menu_choice <<"\n";
		cout <<"\n";
		cout <<"\n";
		temp = (*temp).next; 
	}//while loop ends
	cout << "\n";
	cout <<"\n";
}//report ends
