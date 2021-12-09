#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;
class media
{
	protected : char title[50]; float price;
	public : media(char *s, float a)
	{
		strcpy(title,s);
		price=a;
	}
	virtual void display()
	{
		// empty virtual function
	}
};

class book: public media
{
	int pages;
	public : book(char *s,float a, int p):media(s,a)
	{
		pages=p;
	}
	void display();
};

class tape: public media
{
	float time;
	public : tape(char *s,float a,float t):media(s,a)
	{
		time=t;
	}
	void display();
};

void book::display()
{
	cout << "\n Name of Publication is :" << title;
	cout << "\n Price of "<<title<<" book in rupees is :" << pages;
	cout <<"\n No.of Pages containing in "<<title<<" book : " << price;
}

void tape::display()
{
	cout << "\n Name of Album is :" << title;
	cout << "\n Duration time of "<<title<<" for listining tape in minutes is : " << time <<"mins";
	cout << "\n Price of "<<title<<" tape in rupees is :"<< price;
}

int main()
{
	char *title=new char[30];
	float price,time;
	int pages;
	cout<<"\n  Welcome to'VP Stores...'\n\n";
	// Book Details
	cout << "\nEnter the details for Books \n";
	cout << "Enter the name of Publication : ";
	cin >> title;
	cout << "Enter the price of "<<title<<" book in rupees : ";
	cin >> price;
	cout << "Enter the no.of Pages containing in "<<title<<" book : ";
	cin >> pages;
	book book1(title,price,pages);
	// Tape Details
	cout << "\nEnter the details for Video Tape \n";
	cout << "Enter the name of Album :";
	cin >> title;
	cout << "Enter the price of "<<title<<" tape in rupees is : ";
	cin >> price;
	cout << "Enter the duration time of "<<title<<" for listining in minutes : ";
	cin >> time;
	tape tape1(title, price, time);
	media* list[2];
	list[0]=&book1;
	list[1]=&tape1;
	cout << "\n Purchased Details\n";
	cout << "\n....... Book.........\n";
	list[0]->display();                                            // display book details
	cout << "\n\n....... Tape.........\n";
	list[1]->display();                                            // display tape details
	cout<<endl<<"\t\t\t\t\t\t\t\t\t\t Code by: Vaibhav Pise SCOB110...\n";
	getch();
}
