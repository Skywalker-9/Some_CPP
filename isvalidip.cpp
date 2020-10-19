#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

bool isValidIP(std::string s)
{
	cout << "sizeof input string = " << s.size() << endl;
	int string_idx = 0;
	string substring;
    int dot_count = 0;;
	char ch = s.at(0);
    //cout << "ch " << ch << endl;

    try
    {
        while (true)
        {
            while (true)
            {
                substring.push_back(ch);
                string_idx++;
                if (s.size() == string_idx)
                {
                    cout << "substring = " << substring << endl;
                    stringstream temp1(substring);
                    int x1 = 0;
                    temp1 >> x1;
                    if (x1 > 255)
                    {
                        cout << "value cannot exceed 255 " << endl;
                        return false;
                    }
                    goto out;
                }
                ch = s.at(string_idx);
                //cout << "ch " << ch << endl;
                if (ch == '.')
                    break;
            }

            cout << "substring = " << substring << endl;
            substring.clear();
            string_idx++;
            ch = s.at(string_idx);
            if (atoi(&ch) == 0)
            {
                cout << "cannot start with 0 " << endl;
                return false;
            }
            stringstream temp(substring);
            int x = 0;
            temp >> x;
            if (x > 255)
            {
                cout << "value cannot exceed 255 " << endl;
                return false;
            }
            dot_count++;
            if (dot_count > 3)
            {
                cout << "invalid ip address input bigger than valid IP address" << endl;
                return false;
            }
            //cout << "string_idx = " << string_idx << endl;
        }
    }
    catch (char *excp)
    {
        cout << "caught " << excp << endl;
        return false;
    }
    catch (...)
    {
        cout << "Default Exception" << endl ;
        return false;
    }
out:
    cout << "whole string parsed successfully" << endl;
    if (dot_count < 3)
    {
        cout << "invalid IP address input not complete" << endl;
        return false;
    }
    return true;

}

int main ()
{
    bool result = false;
    string str;
    cout << "Enter an IP address " << endl;
    cin >> str;
    result = isValidIP (str);
    if (result == true)
        cout << "this is valid IP address" << endl;
    else
        cout << "this is invalid IP address" << endl;
}
