// you can use includes, for example:
#include <algorithm>
#include "math.h"

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) 
{
    // write your code in C++14 (g++ 6.2.0)
    int result = 0;
    for (int i = 1; i <= (int)sqrt(N); i++)
    {
        if ( i *i == N)
        {
            result +=1;
            break;
        }
        else  if (N % i == 0)
        {
            result +=2;
        }
    }

    

    return result;
}
