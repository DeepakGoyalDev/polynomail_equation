#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

#include<iostream>
#include<cmath>

class Term
{
    public:
    int cof;
    int exp;
    public:
    Term(int c=0, int e=0)
    {
        cof = c;
        exp = e;
    }
    int eval_term(int var = 0)
    {
        return cof*pow(var, exp);
    }
    void operator=(const Term &);
    friend std::ostream& operator<<(std::ostream &out, const Term &);
    friend std::istream& operator>>(std::istream &in, Term &);
    friend Term operator+(const Term &, const Term &);
    friend Term operator-(const Term &, const Term &);
    friend Term operator*(const Term &, const Term &);
    friend Term operator/(const Term &, const Term &);
};
class Polynomial
{
    private:
    int max_capacity;
    int actual_count;
    Term *a;

    public:
    Polynomial(const Polynomial &p)
    {
        max_capacity = p.max_capacity;
        actual_count = p.actual_count;
        a = new Term[max_capacity];
        for(int iii(0); iii<p.actual_count; iii++)
            this->a[iii] = p.a[iii];
    }
    Polynomial(int input=0)
    {
        max_capacity = input;
        actual_count = 0;
        a = new Term[max_capacity];
    }
    ~Polynomial()
    {
        delete[] a;
    }
    long int eval(int var = 0)
    {
        long int result = 0;
        for(int i(0); i<actual_count; i++)
         result += a[i].eval_term(var);
        return result;
    }
    void operator=(const Polynomial &p);
    void resize(const int i)
    {
        max_capacity = i;
    }
    friend std::istream & operator>>(std::istream &in, Polynomial &p);
    friend std::ostream & operator<<(std::ostream &out, const Polynomial &p);
    friend Polynomial operator+(const Polynomial &, const Polynomial &);
    friend Polynomial operator-(const Polynomial &, const Polynomial &);
    friend Polynomial operator*(const Polynomial &, const Polynomial &);
};

#endif // POLYNOMIAL_H_INCLUDED
