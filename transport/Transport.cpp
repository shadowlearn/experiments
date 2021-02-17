#include<iostream>
#include<string>
#include<vector>

#include"Transport.h"
#include"Booking.h"
#include"Bus.h"

using namespace std;

void Transport::setlistbus(Bus bu)
{
listbus.push_back(bu);
}

int Transport::count(int id)
{
vector<Booking> n;
int count = 0;

for (int i=0; i < listbus.size(); i++)
{
        if (listbus[i].getbusid() == id)
   {
                n = listbus[i].getlistb();

                        count = n.size();
   }
}
     return count;
}
Bus Transport::details(string p_name)
{

vector<Booking> c;

for (int i=0; i < listbus.size(); i++)
{
c = listbus[i].getlistb();

	for (int j=0; j < c.size(); j++)
      {
		if (c[j].getpassname() == p_name)
	{
		return listbus[i];
	}
       }
 }
}

