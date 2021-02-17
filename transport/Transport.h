#ifndef TRANSPORT_H
#define TRANSPORT_H

#include<iostream>
#include<string>
#include<vector>
#include"Bus.h"
#include"Booking.h"

using namespace std;

class Transport {

private:
vector<Bus> listbus;

public:

vector<Bus> getlistbus();

void setlistbus(Bus);

int count(int);
Bus details(string);

};
#endif

