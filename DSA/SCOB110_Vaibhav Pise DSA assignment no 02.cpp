//Department of Computer Engineering has student's club named ‘COMET’. Students of Second, third and final year of department
// can be granted membership on request. Similarly one may cancel the membership of club. First node is reserved for president
// of club and last node is reserved for secretary of club. Write program to maintain club member‘s information using singly linked list.
// Store student MIS registration no. and Name. Write functions to a) Add and delete the members as well as president or even secretary.
// b) Compute total number of members of club c) Display members d) Display list in reverse order using recursion 
// e) Two linked lists exists for two divisions. Concatenate two lists	


#include <iostream>
#include <string.h>
using namespace std;
class node
{
	friend class list;
	int misno;
	char name[30];
	node *next;//pointer to object
public:
	node(int d,char s[10])
	{
	misno=d;
		strcpy(name,s);
		next=NULL;
	}
};
class list
{
	node *start;
public:
	list()
    {
		start=NULL;
    }
void display()
{
	node *ptr;
	ptr=start;
	cout<<"\n Info is : \n";
	cout<<"\nMIS ID  NAME\n";
	while(ptr!=NULL)
	{
		cout<<"\n"<<ptr->misno;
		cout<<"\t"<<ptr->name;
		ptr=ptr->next;
	}
}
	void insertmember();
	void createmember();
	void insertpresident();
	void insertsecretary();
	void deletemember();
	void delete1();
	void deletesecretary();
	void deletepresident();
	void count();
	void reverse(node *);
	void reverse1()
	{
		reverse(start);
	}
	void concatinate(list,list);
};
void list::insertmember()
{
	int misno;
	char name[30];
	node *ptr,*temp;
	cout<<"\n Enter MIS no : ";
	cin>>misno;
	cout<<"\n Enter name : ";
	cin>>name;
	temp=new node(misno,name);
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
void list::insertpresident()
{
	int misno;
	char name[30];
		node *temp;
		cout<<"\n Enter MIS no : ";
		cin>>misno;
		cout<<"\n Enter name : ";
		cin>>name;
		temp=new node(misno,name);
		temp->next=start;
		start=temp;
}
void list::insertsecretary()
{
	int misno;
	char name[30];
			node *ptr,*temp;
			cout<<"\n Enter MIS No : ";
			cin>>misno;
			cout<<"\n Enter Name : ";
			cin>>name;
			temp=new node(misno,name);
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
}
void list::createmember()
{
	int ch;
	char ans;
	do
	{
    cout<<"***************WELCOME TO COMET CLUB******************";
	cout<<"\n Choose : ";
	cout<<"\n 1-Member\n 2-Secretary\n 3-President \n:";
	cin>>ch;
	switch(ch)
	{
	case 1: insertmember();
		    break;
	case 2: insertsecretary();
		    break;
	case 3: insertpresident();
		    break;
	default:cout<<"Invalid choice ! ";
		    break;
	}
	cout<<"\n Insert more if yes Enter (y) else (n)? \n:";
	cin>>ans;
	}while(ans=='y');
}
void list::delete1()
{
		int ch;
		char ans;
		do
		{
		cout<<"\n Choose : ";
		cout<<"\n 1-Member";
		cout<<"\n 2-Secretary";
		cout<<"\n 3-President";
		cin>>ch;
		switch(ch)
		{
		case 1:deletemember();
			   break;
		case 2:deletesecretary();
			   break;
		case 3:deletepresident();
			   break;
		default:cout<<"Invalid choice ! ";
			    break;
		}
		cout<<"\n Delete more if yes Enter (y) else (n) ?  \n:";
		cin>>ans;
		}while(ans=='y');
	}
void list::deletesecretary()
{
	node *ptr,*prev;
	ptr=start;
	while(ptr->next!=NULL)
	{
		prev=ptr;
		ptr=ptr->next;
	}
		prev->next=NULL;
		delete ptr;
	    cout<<"\n Deleted";
}
void list::deletepresident()
{
	node *ptr;
		ptr=start;
		start=start->next;
		delete ptr;
		cout<<"\n Deleted";
}
void list::deletemember()
{
	node *ptr,*prev;
	int p;
	cout<<"\n Enter MIS no. to delete : ";
	cin>>p;
			ptr=start;
			while(ptr->next!=NULL)
			{
				prev=ptr;
				ptr=ptr->next;
				if(ptr->misno==p)
				  break;
			}
			if(ptr->next==NULL)
			{
				cout<<"\n Data not found !";
			}
			else if(ptr->misno==p)
			{
				prev->next=ptr->next;
				ptr->next=NULL;
				delete ptr;
				cout<<"\n Deleted";
			}
}
void list::count()
{
	node *ptr;
	int cnt=0;
	ptr=start;
	while(ptr!=NULL)
	{
		cnt++;
		ptr=ptr->next;
	}
	cout<<"\n Total no. of nodes is : "<<cnt;
}
void list::reverse(node *ptr)
{
	if(ptr==NULL)
			return;
	else
	{
		reverse(ptr->next);
	}
		cout<<"\n"<<ptr->misno;
		cout<<"\t"<<ptr->name;
}
void list::concatinate(list s1,list s2)
	{
	node *ptr;
	ptr=s1.start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=s2.start;
		s1.display();
	}
int main()
{
	int ch;
	char ans;
	list sll1,sll2,s1,s2;
	do
	{
		cout<<"\n Enter your choice : ";
	    cout<<"\n 1-Create \n 2-Display\n 3-Delete \n 4-No. of nodes\n 5-Reverse\n 6-Concatenate   \n:";
        cin>>ch;
switch(ch)
{
   case 1: sll1.createmember();
		   break;
   case 2: sll1.display();
		   break;
   case 3: cout<<"\n Enter the nodes to be deleted in list : ";
		   sll1.delete1();
		   break;
   case 4: cout<<"\n No. of nodes is:";
		   sll1.count();
		   break;
   case 5: cout<<"\n Reversed is:";
		   sll1.reverse1();
		   break;
   case 6: sll2.createmember();
		   sll1.concatinate(sll1,sll2);
		   break;
   default: cout<<"\n Invalid choice ! ";
		    break;
 }
		   cout<<"\n\n Do you want to continue if yes Enter (y) else (n) ?  \n:";
		   cin>>ans;
	}while(ans=='y');
	return 0;
}
