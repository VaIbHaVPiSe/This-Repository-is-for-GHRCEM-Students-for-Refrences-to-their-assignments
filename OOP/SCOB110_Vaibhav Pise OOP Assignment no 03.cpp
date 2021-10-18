#include<conio.h>
#include<iostream>
using namespace std;
class DM
{ public:
float meter;
voidgetdata()
{cout<< "enter distance in meters and centimeters :" ;
cin>> meter ;
}
friend void add();
} A1;
class DB
{ public:
float inch;
voidgetdata()
{cout<< "Enter distance in feets and inches :" ;
cin>> inch ;
}
friend void add();
} A2;
void add()
{ float a,RES;
a=A1.meter*39.37;
RES=a+A2.inch;
cout<< " Total Inches = " << RES <<endl;
a=A2.inch/39.37;
RES=a+A1.meter;
cout<< " Total Meters = " << RES ;
}
main()
{
A1.voidgetdata();
A2.voidgetdata();
add();

return 0;
}
