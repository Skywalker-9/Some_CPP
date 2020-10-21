#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

/* Get this file as a QCIF YUV file */
#define FRAME_SIZE (176*144*1.5)

int main ()
{
    unsigned int length = 0;
    ifstream input;
    input.open ("aud.yuv", ios::binary);
    input.seekg (0, ios::end);
    length = input.tellg();
    input.seekg(0);

    cout << "length of the input file = " << length << endl;

    cout << "frames in the input file = " << length / FRAME_SIZE << endl;

    char *buffer = new char [length];

    ofstream output;
    output.open ("aud_copy.yuv", ios::binary);

#if 1
    for (int i = 1; i <= (length / FRAME_SIZE); i++)
    {
        if (i % 2 == 0)
        {
            input.read (buffer, FRAME_SIZE);
            output.write (buffer, FRAME_SIZE);
        }
    }
#else
    
    istreambuf_iterator<char> begin_source(input);
    istreambuf_iterator<char> end_source;
    ostreambuf_iterator<char> begin_dest(output); 
    copy(begin_source, end_source, begin_dest);

    //copy(istreambuf_iterator<char>(input), istreambuf_iterator<char>( ), ostreambuf_iterator<char>(output));
#endif
    
    input.close();
    output.close();


}
