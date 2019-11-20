#include<iostream>
using namespace std;
class student{
	public:
	int roll_no;
	int age;
	int grade;
	// declaring parameterised constructor
	student(int r,int g,int a)
	{
	roll_no=r;
	age=a;
	grade=g;
	}
};
int main()
{
	// declaring parameterized constructor
	student student1(31,8,21);
	cout<<"Roll number: "<<student1.roll_no <<endl;
	cout<<"Age: "<<student1.age<<endl;
	cout<<"Average Grade: "<<student1.grade<<endl;
	
}
