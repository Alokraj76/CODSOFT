#include<iostream>
using namespace std;

class Calculator
{
    public:
    void calculation()
    {
        double a,b,result,alok;
        int op;
        
        cout<<"Enter two number a and b: ";
        cin>>a>>b;
        cout<<"1-Addition\n2-Subtraction\n3-Multiplication\n4-Division"<<endl;
        cout<<"Enter your option: ";
        cin>>op;
        switch(op)
        {
            case 1: cout<<a<<" + "<<b<<" = "<<a+b;
            break;
            case 2: cout<<a<<" - "<<b<<" = "<<a-b;
            break;
            case 3: cout<<a<<" * "<<b<<" = "<<a*b;
            break;
            case 4: 
            if(b!=0)
            cout<<a<<" / "<<b<<" = "<<a/b;
            else
            cout<<"Cannot divide by zero";
            break;
            default: cout<<"Please enter correct option";
        }
    } 
};
int main()
{
    Calculator calc;
    calc.calculation();
    return 0;
}
