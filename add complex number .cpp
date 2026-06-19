#include<iostream>
using namespace std;

// for first complex number
class comp1
{
public:

    double real;
    double imag;
};
class comp2
{
public:
    double real;
    double imag;

    void add(comp1 c)
    {
        real+=c.real;
        imag+=c.imag;
    }

    void display()
    {
        cout<< real << " + " << imag << "i" <<endl;
    }
};

int main()
{
    comp1 num1;
    comp2 num2,result;

    // Assign value
    num1.real= 5.5;
    num1.imag=4.5;

    num2.real= 10.5;
    num2.imag=9.5;

    // add them
    result=num2;
    result.add(num1);

    cout<<" First number is "<< num1.real << " + " << num1.imag << "i" <<endl;
    cout<<" second number is "<< num2.real << " + " << num2.imag << "i" <<endl;

   cout<< " The sum is : ";
   result.display();
return 0;


}
