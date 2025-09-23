#include<iostream>
using namespace std;
class agv{
	int age;
	public:
	void get(){
		cout<<"Enter the age:";
		cin>>age;
	}
	int getage(){
		return age;
	}
};
int main(){
	agv a;
	a.get();
	try {
if (a.getage()>= 18) {
cout << "Access granted - you are old enough.";
} 
else {
throw (a.getage());
}
}
catch (int myNum) {
cout << "Access denied - You must be at least 18 years old.\n";
cout << "Age is: " << myNum;
}
}
