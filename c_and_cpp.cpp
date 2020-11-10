/*
 * Decompile c++ generated file to see what's going on
 *
 * g++ -c -std=c++11 -Wall -Wextra -pedantic -o c_and_cpp.o c_and_cpp.cpp
 *
 * now check if the symbols are mangled or not
 * readelf -s c_and_cpp.o
 *
 * run following command to check actual names of mangled symbol 
 * c++filt _Z1fv
 *
 * */

//#include <iostream>
#include <stdio.h>

#if 1
#ifdef __cplusplus
extern "C"
{
#endif

    void e()
    {

    }

    void f()
    {

    }

#ifdef __cplusplus
}
#endif

void m()
{
}

void h()
{
    e();
    f();
    m();
}

int main ()
{
    h();
}
#endif

/*
 * It becomes obvious that any C++ feature that requires name mangling will not work inside extern "C"
 * like done in below program
 * */
#if 0
#ifdef __cplusplus
extern "C"
{
#endif

    class X
    {
        public:
            int a;
            X()
            {
                printf ("default constructor\n");
            }
            X(int p)
            {
                a = p;
                printf ("parameterized constructor\n");
            }
            void display ()
            {
                printf ("display function with no arguments\n");
            }
#if 0
            void display (int a)
            {
                printf ("display function with an argument\n");
            }
#endif
    };


#ifdef __cplusplus
}
#endif


int main ()
{
    X p(5);
    printf ("value of a = %d\n", p.a);
    X *l = new (X)(10);
    printf ("value of a = %d\n", l->a);
    l->display();
#if 0
    p.display(3);
#endif
}
#endif
