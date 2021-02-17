#include<iostream>
#include<string>
#include<vector>
#include"Booking.h"
#include"Bus.h"

using namespace std;

Bus::Bus()
{
busid = 0;
depart = 0;
dest = "null";
}

Bus::Bus(int busid_in, int depart_in, string dest_in)
{
busid = busid_in;
depart = depart_in;
dest = dest_in;
}

int Bus::getbusid()
{
return busid;
}

int Bus::getdepart()
{
return depart;
}
string Bus::getdest()
{
return dest;
}

vector<Booking> Bus::getlistb()
{
return listb;
}

void Bus::setlistb(Booking bg)
{
listb.push_back(bg);
}

