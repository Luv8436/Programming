#include<iostream>
using namespace std;
class student{
	public:
	string name;
	int age;
	void printName();
	void printAge()
	{
		cout<<"\nThe age of the student is: "<<age;
	}
};
void student::printName()
{
	cout<<"The name of the student is: "<<name;
}
int main()
{
	student student1;
	student1.name="Love";
	cout<<"enter the age of the student1:\n ";
	cin>>student1.age;
	cout<<"\n";
	student1.printName();
	student1.printAge();
}

