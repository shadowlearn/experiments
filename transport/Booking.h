#ifndef BOOKING_H
#define BOOKING_H
#include<iostream>
#include<string>

using namespace std;

class Booking {

private:
int bookid;
string passname;
long contact;

public:

Booking();
Booking(int, string, long);

int getbookid();
string getpassname();
long getcontact();


};
#endif
