#include"polynomial.h"

using namespace std;

void Term::operator=(const Term &t)
{
    exp = t.exp;
    cof = t.cof;
}
ostream& operator<<(ostream &out, const Term &t)
{
    if(t.cof<0)
    out<<" "<<t.cof<<"X^"<<t.exp;
    else if(t.cof>0)
    out<<" +"<<t.cof<<"X^"<<t.exp;
    return out;
}
istream& operator>>(istream &in, Term &t)
{
    cout<<"Enter cofficient: ";
    in>>t.cof;
    cout<<"Enter Exponent: ";
    in>>t.exp;
    return in;
}
Term operator+(const Term &t1, const Term &t2)
{
    Term temp;
    if(t1.exp == t2.exp)
    {
        temp.exp = t1.exp;
        temp.cof = t1.cof + t2.cof;
    }
    return temp;
}
Term operator-(const Term &t1, const Term &t2)
{
    Term temp;
    if(t1.exp == t2.exp)
    {
        temp.exp = t1.exp;
        temp.cof = t1.cof - t2.cof;
    }
    return temp;
}
Term operator*(const Term &t1, const Term &t2)
{
    Term temp;
    temp.cof = t1.cof*t2.cof;
    temp.exp = t1.exp+t2.exp;
    return temp;
}
Term operator/(const Term &t1, const Term &t2)
{
    Term temp;
    temp.exp = t1.exp - t2.exp;
    temp.cof = static_cast<double>(t1.cof)/t2.cof;
    return temp;
}


void Polynomial::operator=(const Polynomial &p)
{
       this->resize(p.max_capacity);
        this->actual_count = p.actual_count;
        for(int i(0); i<p.actual_count; i++)
            this->a[i] = p.a[i];
}
istream& operator>>(istream &in, Polynomial &p)
{
    for(int i(0); i<p.max_capacity; i++)
    {
        cout<<"Term "<<i+1<<". \n";
        in>>p.a[i];
        p.actual_count++;
    }
    return in;
}
ostream& operator<<(ostream &out, const Polynomial &p)
{
    cout<<"Polynomial:";
    for(int i(0); i<p.actual_count; i++)
       out<<p.a[i];
       cout<<endl;
    return out;
}
Polynomial operator+(const Polynomial &p1, const Polynomial &p2)
{
    int l1 = p1.actual_count;
    int l2 = p2.actual_count;
    Polynomial temp(l1+l2);
    int i(0), j(0), k(0);
    while(i<l1 && j<l2)
    {
        if(p1.a[i].exp > p2.a[j].exp)
        {
            temp.a[k] = p1.a[i];
             i++;
        }
        else if(p1.a[i].exp < p2.a[j].exp)
        {
            temp.a[k] = p2.a[j];
            j++;
        }
        else
        {
            temp.a[k] = p1.a[i] + p2.a[j];
            i++; j++;
        }
        k++;
    }
    while(i<l1)
    {
        temp.a[k] = p1.a[i];
        k++; i++;
    }
    while(j<l2)
    {
        temp.a[k] = p2.a[j];
        k++; j++;
    }
    temp.actual_count = k;
    return temp;
}
Polynomial operator-(const Polynomial &p1, const Polynomial &p2)
{
    int l1 = p1.actual_count;
    int l2 = p2.actual_count;
    Polynomial temp(l1+l2);
    int i(0), j(0), k(0);
    while(i<l1 && j<l2)
    {
        if(p1.a[i].exp > p2.a[j].exp)
        {
            temp.a[k] = p1.a[i];
             i++;
        }
        else if(p1.a[i].exp < p2.a[j].exp)
        {
            temp.a[k] = p2.a[j];
            temp.a[k].cof *= -1;
            j++;
        }
        else
        {
            temp.a[k] = p1.a[i] - p2.a[j];
            i++; j++;
        }
        k++;
    }
    while(i<l1)
    {
        temp.a[k] = p1.a[i];
        k++; i++;
    }
    while(j<l2)
    {
        temp.a[k] = p2.a[j];
        temp.a[k].cof *= -1;
        k++; j++;
    }
    temp.actual_count = k;
    return temp;
}
Polynomial operator*(const Polynomial &p1, const Polynomial &p2)
{
    int l1 = p1.actual_count;
    int l2 = p2.actual_count;
    Polynomial temp(l1*l2);
    for(int i(0); i<l1; i++)
    {
        Polynomial t(l2);
        for(int j(0); j<l2; j++)
        {
            t.a[j] = p1.a[i] * p2.a[j];
            t.actual_count++;
        }
        temp = temp + t;
    }
    return temp;
}
