#ifndef BUS_H
#define BUS_H

#include<iostream>
#include<string>
#include<vector>
#include "Booking.h"

class Bus {

private:

int busid;
int depart;
string dest;

vector<Booking> listb;

public:

Bus();
Bus(int, int, string);

int getbusid();
int getdepart();
string getdest();

vector<Booking> getlistb();
void setlistb(Booking);
};
#endif

