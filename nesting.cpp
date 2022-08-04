// you can use includes, for example:
#include <algorithm>
#include <stack> 

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) 
{
    // write your code in C++14 (g++ 6.2.0)
    bool isProperlyNested = false;
    bool isTerminated = false;
    stack<char> curlyBrackets;
    int len = S.size();
    if (len > 1 && len % 2 == 0)
    {
        for (char el:S)
        {
            if (el == '(')
            {
                curlyBrackets.push(el);
            }
            else 
            {
                if (curlyBrackets.empty())
                {
                    isTerminated = true;
                }
                else 
                {
                    curlyBrackets.pop();
                }
            
            }
        }

        if (curlyBrackets.empty() && !isTerminated)
        {
            isProperlyNested = true;
        }
    }
    else if (len == 0 ) isProperlyNested = true;
    return isProperlyNested;
}
