// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)
    int max_slice = -0xffffff;
    int max_ending = 0;
    for (auto el:A)
    {
        max_ending = max(el, max_ending + el);

        max_slice = max(max_ending, max_slice);
    }

    return max_slice;
}
