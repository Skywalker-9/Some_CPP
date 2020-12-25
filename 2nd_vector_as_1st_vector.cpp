#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

int getnumber(string str)
{
    // For atoi, the input string has to start with a digit, so lets search for the first digit
    size_t i = 0;
    for ( ; i < str.length(); i++ ){ if ( isdigit(str[i]) ) break; }

    // remove the first chars, which aren't digits
    str = str.substr(i, str.length() - i );

    // convert the remaining text to an integer
    int id = atoi(str.c_str());

    return id;
}

int search_index_of_item_in_vector (vector<int> vec, int a)
{
    for (int i=0; i<vec.size(); i++)
    {
        if (vec.at(i) == a)
            return i;
    }
}

int main ()
{
    vector<string> vec1 = {"source55","source66","source33","source11","source22", "source115", "source219"};
    vector<string> vec2 = {"id115", "id219", "id55","id11","id22","id33","id66"};
    vector<string> vec3;
    vector<int> intvec1;
    vector<int> intvec2;
    vector<int> intvec3;

    cout << "Printing vec1" << endl;
    for (auto s = vec1.begin(); s != vec1.end(); s++)
        cout << *s << endl;

    cout << endl << endl;
    cout << "Printing vec2" << endl;
    for (auto s = vec2.begin(); s != vec2.end(); s++)
        cout << *s << endl;

    cout << endl << endl;
    //cout << "vector size = " << vec1.size() << endl;
    for (int i=0; i<vec1.size(); i++)
    {
        int v1 = getnumber(vec1.at(i)); 
        //cout << v1 << endl;
        intvec1.push_back (v1);
    }
    for (int i=0; i<vec2.size(); i++)
    {
        int v2 = getnumber(vec2.at(i)); 
        //cout << v2 << endl;
        intvec2.push_back (v2);
    }

#if 0
    for (auto a = intvec1.begin(); a != intvec1.end(); a++)
        cout << *a << endl;
    cout << endl << endl;
    for (auto a = intvec2.begin(); a != intvec2.end(); a++)
        cout << *a << endl;
#endif

    int index = -1;
    for (int i=0; i<vec1.size(); i++)
    {
        index = search_index_of_item_in_vector (intvec2, intvec1.at(i));
        if (index != i)
        {
            string temp = vec2.at(i);
            vec2.at(i) = vec2.at(index);
            vec2.at(index) = temp;

            int temp1 = intvec2.at(i);
            intvec2.at(i) = intvec2.at(index);
            intvec2.at(index) = temp1;
        }
    }

    cout << "Printing reordered vec2 " << endl;
    for (auto s = vec2.begin(); s != vec2.end(); s++)
        cout << *s << endl;

    cout << endl << endl;
}
