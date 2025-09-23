/* B24CE1095 */
#include<iostream>
using namespace std;
class complex{
	int real, img;
	public:
	friend istream&operator>>(istream &in,  complex &c);
	friend ostream&operator<<(ostream &out, const complex &c);
complex operator+(complex c) //OPERATOR OVERLOADING USING MEMBER FUNCTION
{
        complex  temp;             
        temp.real=real + c.real;
        temp.img =img+c.img ;
        return(temp);  
}
friend complex operator*(complex c1, complex c2);//OPERATOR OVERLOADING USING FRIEND
};
complex operator*(complex c1, complex c2) {
    complex mul;
    mul.real = (c1.real*c2.real)-(c1.img*c2.img); 
    mul.img = (c1.real*c2.img)+(c1.img*c2.real); 
    return mul;
}

istream& operator>>(istream &in, complex &c) {
    cout<<"Enter real part: ";
    in>>c.real;
    cout<<"Enter imaginary part: ";
    in >> c.img;
    return in;
}

ostream& operator<<(ostream &out, const complex &c) {
    out<<c.real<<" + "<< c.img << "i";
    return out;
}
int main(){
	 complex c1, c2, c3, m3;
    cout<<"Enter first complex number:\n";
    cin>>c1;
    cout<<"Enter second complex number:\n";
    cin>>c2;
    c3=c1 + c2;
    m3=c1 * c2;
    cout<<"\nFirst Complex Number: "<<c1<<endl;
    cout<<"Second Complex Number: "<<c2<<endl;
    cout<<"Sum: "<<c3<<endl;
    cout<<"Product: "<<m3<<endl;

    return 0;
}
