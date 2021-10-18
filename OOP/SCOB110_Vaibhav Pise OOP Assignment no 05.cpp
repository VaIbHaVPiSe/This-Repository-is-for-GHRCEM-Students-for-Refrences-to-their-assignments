#include<iostream>
#include<string.h>
using namespace std;

	class Student
	{

		int Roll;
		char Name[25];
		float Marks;

		public:


					Student()           //Default Constructor

					{
						Roll = 1;
						strcpy(Name,"Vaibhav");
						Marks = 90.00;
					}
					 ~Student();      // Destructor


		Student(int r,char nm[],float m)   //Constructor 1 : Parameterize Constructor
		{
			Roll = r;
			strcpy(Name,nm);
			Marks = m;
		}

		Student(Student &S)   //Constructor 2 : Copy Constructor
		{
			Roll = S.Roll;
			strcpy(Name,S.Name);
			Marks = S.Marks;
		}

		void Display()
		{
            cout<<"\n\tRoll : "<<Roll;
			cout<<"\n\tName : "<<Name;
			cout<<"\n\tMarks : "<<Marks;
		}
	};
	Student :: ~Student()
{
        cout<<"\n\nStudent Detail is Closed.............\n";
}


	int main()
	{
	    Student S;          //Creating Object

        S.Display();        //Displaying Student Details

		Student S1(2,"Vishal",99.00);


		Student S2(S1);    //Statement 1

		cout<<"\n\tValues in object S1";
		S1.Display();

		cout<<"\n\tValues in object S2";
		S2.Display();

}
