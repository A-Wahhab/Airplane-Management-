#pragma once
#include<string.h>
#include<iostream>
using namespace std;
#include"Ticket.h"
#include"Boarding.h"
struct Ticket_NO
{
	string n;
	int N;
	Ticket_NO()
	{
		n = " ";
		N = 0;
	}
	friend bool operator==(const Ticket_NO t1, const Ticket_NO t2)
	{
		if ((t1.n == t2.n) && (t1.N == t2.N))
			return true;
		return false;
	}
	friend istream& operator>>(istream& cin, Ticket_NO t)
	{
		cin >> t.n >> t.N;
		return cin;
	}
	friend ostream& operator<<(ostream& cout, Ticket_NO t)
	{
		cout << t.n << t.N;
		return cout;
	}
};
class Passenger:public Ticket, public Time,public Boarding
{
	node** PQ;
protected:
	string Name;				
	Ticket_NO t_no;					// ticket number
	bool seat_type;				// true is bussiness class and false is economy class
public:
	Passenger()
	{
		Name = nullptr;
		seat_type = false;			// default is economy class
		PQ = new node*;
	}
	Ticket_NO ticketno()
	{
		return t_no;
	}
	void P_Input()
	{
		cout << "\nEnter passenger details";
		cout << "\nName:";
		cin >> Name;
		cout << "\nSeat Type; 1 for Bussiness Class, 0 for Economy Class:";		//payment 
		cin >> seat_type;
		//ticket input
		t_no = T_input();			// return the ticket number
	}
	void Display()
	{
		if (F_type)
			cout << "International Flight with ";
		else
			cout << "Domestic Flight with ";
		cout << "Airline :" << airline << endl;
		cout << "Name :" << Name << endl;
		cout << "Ticket Number" << t_no << endl;
		if (seat_type)
			cout << "Seat Type: Bussiness Class\n";
		else
			cout << "Seat Type: Economy Class\n";
		cout << "Departure Time :" << T_depart << endl;
		cout << "Departure :" << depart << endl;
		cout << "Destination :" << dest << endl;
	}
};
struct node
{
	node()
	{
		next = nullptr;
	}
	Passenger data;
	node* next;
};
class Passengerlist:public Boarding
{
	node* first; 
	node* last; 
public:
	Passengerlist() 
	{	
		first = nullptr;
		last = nullptr;
	}
	void insert()				
	{
		node* t = new node; 
		t->data.P_Input();				// input of passenger details
		t->next = nullptr;
		if (first == last && last == nullptr) 
		{
			first = last = t;
		}
		else 
		{
			last->next = t;
			last = t;
		}
		Boarding::B[size] = t;
		Boarding::size++;
	}
	void search(Ticket_NO ticket_no) 
	{
		int a = 0;
		node* t = first;
		while (t != nullptr)
		{
			if (t->data.ticketno() == ticket_no)		// returns index when value is found
				t->data.Display();
			t = t->next;
			a++;
		}
		cout << "Data Not Found\n";
	}
	void Delete(Ticket_NO ticket_no)
	{
		int a = 0;
		node* t = first;
		while (t != nullptr)
		{
			if (t->next->data.ticketno() == ticket_no)		// returns index when value is found
			{
				t->next = t->next->next;
				return;
			}
			t = t->next;
			a++;
		}
		cout << "Data Not Found\n";
	}
	void print()											// print function for the list
	{
		node* t = first;
		while (t != nullptr)
		{
			t->data.Display();
			t = t->next;
		}
		cout << endl;
	}
};
