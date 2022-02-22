#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class Time
{
public:
	int h, m, s;
	Time()
	{
		h = 0; m = 0; s = 0;
	}
	void settime()
	{
		h = rand() % 24;
		m = rand() % 60;
		s = rand() % 60;
	}
	friend ostream& operator<<(ostream& cout, Time d)
	{
		cout << d.h << ":" << d.m << ":" << d.s;
		return cout;
	}
};
class Ticket
{
protected:
	bool F_type;						// domestic is false and international is true
	bool Seat[25][25] = { 0 };			// seats in flight
	const int seats = 50;				// total numbers of seats
	string dest, airline, depart;		// destination, airline and departure
	Time T_depart;						// time of departure
public:
	Ticket()
	{
		F_type = false; dest = nullptr, depart = nullptr; T_depart;
	}
	void displaySeats()
	{
		for (int r = 0; r < 25; r++)
		{
			for (int c = 0; c < 25; c++)
			{
				if (Seat[r][c] == 0)
					cout << " _ ";
			}
			cout << endl;
		}
	}
	void flightMenu()
	{
		cout << "\t\tWELCOME TO TICKET MENU\t\t\n";
		cout << "\t\tWe offer 3 Airline and Various Destination\t\t\n";
		cout << "\t\tInternational & Domestic Flights\t\t\n";	
		cout << "\t\t1: LAHORE TO KARACHI 2:LAHORE TO ISLAMABAD 3: ISLAMABAD TO KARACHI\t\t\n";
		cout << "\t\t1: AMERICA TO KARACHI 2:LAHORE TO LONDON 3: ISLAMABAD TO DUBAI\t\t\n";
	}
	Ticket_NO T_input()
	{
		flightMenu();
		Ticket_NO t_no;
		cout << "\nFlight Type; 1 for International, 0 for Domestic: ";
		cin >> F_type;
		cout << "\nDestination: ";
		cin >> dest;
		cout << "\nDeparture: ";
		cin >> depart;
		cout << "\nAirline 1: PIA	 2: Qatar Airways	3: Emirates: ";
		cin >> airline;
		displaySeats();
		cout << "1st row is for bussiness class and 2nd row is Economy(Lahore to Karachi, LtK15): ";
		cin >> t_no;
		T_depart.settime();
		return t_no;
	}
	Ticket(bool type,string Dest,string Airline,string Depart)
	{
		F_type = type; dest = Dest; airline = Airline; depart = Depart; T_depart.settime();
	}
};

