#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> sum (string s1, string s2)
{
    vector<int> result;
    int carry = 0;
    
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        int sum = 0, digit = 0;
        int x = 0, y = 0;

        string str1;
        str1.push_back(s1.at(i));
        stringstream temp1(str1);
        temp1 >> x;

        string str2;
        str2.push_back(s2.at(i));
        stringstream temp2(str2);
        temp2 >> y;

        sum = x + y + carry;
        if (sum > 10)
            carry = 1;
        else
            carry = 0;
        digit = sum % 10;

        //cout << digit;
        result.push_back(digit);
    }

    if (carry == 1)
    {
#if 0
        string strf = to_string(1);
        cout << "1" << endl;
        result.push_back(strf.at(0));
#else
        result.push_back(carry);
#endif
    }
    else
    {
        result.push_back(carry);
    }

    return result;
}

double simple_sum (double num1, double num2)
{
    return num1 + num2;
}


int main ()
{
    string str1, str2;
    vector<int> result;
    cout << "Enter first string : " << endl;
    cin >> str1;
    cout << "Enter second string : " << endl;
    cin >> str2;
    result = sum (str1, str2);

    for (int i = (result.size() - 1); i >= 0 ; i--)
    {
        cout << result.at(i);
    }

    //cout << result << endl;

    cout << "\n\n\n\n\n" << endl;

    double result1, num1, num2;
    cout << "Enter first number " << endl;
    cin >> num1;
    cout << "Enter second number " << endl;
    cin >> num2;
    result1 = simple_sum (num1, num2);
    cout << result1 << endl;

}
