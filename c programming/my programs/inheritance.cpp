#include <iostream>
using namespace std;
class parent{
	public:
	parent(){
	cout<<"Name of the parent is" <<endl;
	cout<<"pravendra singh" <<endl;
	}
};
class child : public parent{
	public:
	child(){
	cout<<"Name of the children"<<endl;
	cout<<"Luv kumar" <<endl;
	}
}; 
int main(void)
{
	child obj;
	return 0;
}
