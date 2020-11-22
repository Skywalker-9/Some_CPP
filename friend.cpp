#include <iostream>

using namespace std;

class one
{
    private:
        int x;
    public:
        one ()
        {
            cout << "default constructor of class one" << endl;
        }

        ~one ()
        {
            cout << "default destructor of class one" << endl;
        }

        one (int a):x(a) {}

        int get_x () {return x;}

        friend void friend_func (one& o);

        friend class two;
};

class two 
{
    public:
        void show_one_private_member (one& o)
        {
            cout << "Inside friend class two, private member of one o.x = " << o.x << endl;
        }
};

void friend_func (one& o)
{
    o.x = 200;
    cout << "inside friend function o.x = " << o.x << endl;
}


int main ()
{
    one o(100);
    cout << "o.x = " << o.get_x() << endl;
    friend_func (o);
    two t;
    t.show_one_private_member(o);
}
