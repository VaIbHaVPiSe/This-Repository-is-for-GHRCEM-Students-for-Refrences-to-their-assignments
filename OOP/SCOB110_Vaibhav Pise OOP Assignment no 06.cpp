/*
Consider a class network of above figure.
The class master derives information from both account and admin classes which in turn derive information from the class person.
Define all the four classes (which in turn derive information from) x and
write a program to create, update and display the information contain in master objects.
*/

#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

class person
{
protected:
	char name[20];
	int code;
public:
	void get_per(int c,char *s)
	{
		code=c;
		strcpy(name,s);
	}
	void put_per()
	{
		cout<<"\nCode : "<<code;
		cout<<"\nName : "<<name;
	}
};

class account : public virtual person
{
protected:
	float pay;
public:
	void get_pay(float p)
	{
		pay=p;
	}
	void put_pay()
	{
		cout<<"\nPay amount : "<<pay;
	}
};

class admin : public virtual person
{
protected:
	int exp;
public:
	void get_exp(int e)
	{
		exp=e;
	}
	void put_exp()
	{
		cout<<"\nExperiance : "<<exp;
	}
};

class master : public account,public admin
{
	//private:
	//float pay;
	//int code,exp;
	//char name;

public:
	void display()
	{
		put_per();
		put_pay();
		put_exp();
	}
};

int main()
{
	master p1;


	p1.get_per(111,"Vaibhav");
	p1.get_pay(501.50);
	p1.get_exp(2);
	p1.display();


	return 0;
}

