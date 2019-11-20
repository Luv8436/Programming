#include <iostream> 
using namespace std; 
class construct{
	public:
		int a,b;
		// declare a default constructor
		construct(){
		a=10;
		b=20;}
};
int main()
{
	//default construct called automatically when object is created
	construct cst;
	cout<<"a: "<<cst.a <<endl
	<<"b: "<<cst.b;
	return 0;	
}
