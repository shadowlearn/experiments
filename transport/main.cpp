#include"Transport.h"
#include"Booking.h"
#include"Bus.h"

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
string name,end,pname;
char ans,ans1;
int id,dep,bid;
long cont;

Transport t;

cout << "\n\t Enter name of transport company > ";
cin >> name;

do {
        cout << "\n\t Enter bus ID > ";
        cin >> id;
        cout << "\n\t Enter departure of bus > ";
        cin >> dep;
        cout << "\n\t Enter destination of bus > ";
        cin >> end;

        Bus bu(id, dep, end);
do {
        cout << "\n\t Enter Booking ID > ";
        cin >> bid;
        cout << "\n\t Enter Passenger Name > ";
        cin >> pname;
        cout << "\n\t Enter contact details > ";
        cin >> cont;

        Booking bg(bid, pname, cont);
        bu.setlistb(bg);

        cout << "\n\t Do you want to continue > ";
                cin >> ans;
   } while(ans == 'y');

                t.setlistbus(bu);

        cout << "\n\t Do you want to continue > ";
        cin >> ans1;
   } while(ans1 == 'y');

int id_1,count_1=0;
cout << "\n\t Enter Bus ID to count number of booking > ";
cin >> id_1;

count_1 = t.count(id_1);
cout << "\n\t Number of Booking is -> " << count_1 <<endl;

string p_name;
cout << "\n\t Enter the passenger name ";
cin >> p_name;

Bus bu1;

bu1 = t.details(p_name);

cout << bu1.getbusid();
cout << bu1.getdepart();
cout << bu1.getdest();

}

