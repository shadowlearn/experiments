#include<iostream>
#include<string>
#include"Booking.h"

using namespace std;

Booking::Booking()
{
bookid = 0;
passname = "null";
contact = 0;
}

Booking::Booking(int bookid_in, string passname_in, long contact_in)
{
bookid = bookid_in;
passname = passname_in;
contact = contact_in;
}

int Booking::getbookid()
{
return bookid;
}

string Booking::getpassname()
{
return passname;
}

long Booking::getcontact()
{
return contact;
}
