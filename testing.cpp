//enter values low to high order of values
#include <iostream>
#include"polynomial.h"
using namespace std;
int main()
{
    Polynomial p1(3);
    cin>>p1;
    cout<<p1;
    cout<<p1.eval(2)<<endl;
    Polynomial p2(1), p3(p1);
    p2 = p1;
    cout<<p2<<p3;
    p3 = p1+p2;
    cout<<p3;
    p2 = p1-p3;
    cout<<p2;
    p3 = p1*p2;
    cout<<p3;

    return 0;
}
