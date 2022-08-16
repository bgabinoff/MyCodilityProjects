// you can use includes, for example:
#include <algorithm>
#include <math.h>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) 
{
    // write your code in C++14 (g++ 6.2.0)
    int minPerimeter = 0;
    double anchorPoint = sqrt(N);
    int candidate =  anchorPoint;
    int a,b = 0;
    //cout << "anchorPoint=" << anchorPoint << " candidate=" << candidate << endl;
    while ( N % candidate != 0 ) candidate--;
    a = candidate;
    b = N / candidate;
    //cout << "a=" << a << " b=" << b << endl;
    minPerimeter = 2 * (a + b);
    return minPerimeter;
}
