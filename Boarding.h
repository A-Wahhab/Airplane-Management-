#pragma once
#include<iostream>
using namespace std;
#define SIZE 50
class Boarding
{
protected:
	node** B = nullptr;
	int size;
public:
	Boarding()
	{
		B = new node * [SIZE];
		size = 0;
	}
	

};