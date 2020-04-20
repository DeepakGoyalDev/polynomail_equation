# polynomail_equation
Polynomial equation solver. Support operation like create variable(copy intialisation/no intialisation), input(cin>>), output(cout<<), operator=, operator+, operators- and operators*.
NOTE: 
1. enter input in decreasing order of power.
2. Every variable has a maximum term holding capacity which with we can resize using "var.resize(new size)" member function. 
Example: Polynomial p1(3), p2;
         cin>>p1>>;
         p2 = p1;
         Polynomial p3(p1);
         cout<<p1;
         cout<<p2;
         p3 = p1 + p2;
         cout<<p3;
         p3 = p1 * p2;
         cout<<p3;
         p3 = p1 - p2;
         cout<<p3;
         
     


