#include<iostream>
using namespace std;
#include"FlightMenu.h"
#include"Passenger.h"

void Menu()
{
	cout << "\t\t\t\tWELCOME TO FLIGHT MANAGEMENT SYSTEM\t\t\t\t\n\n";
}
int main()
{
	//FlightMenu M;
	Menu();
	Passenger p;
	p.Display();
	return 0;
}