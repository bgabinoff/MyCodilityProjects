#include <algorithm>
#include <stack>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) 
{
    // write your code in C++14 (g++ 6.2.0)
    stack<int> localMinStack;
    //int currentIndex = 0;
    int nBlocks = 0;
    for (int el:H)
    {
        
        while (!localMinStack.empty() && localMinStack.top() > el)
        {
             localMinStack.pop();
             
        }
        if (localMinStack.empty() || (!localMinStack.empty() && localMinStack.top() != el))
        {
            localMinStack.push(el);
            nBlocks++;
        }
    }

    
    return nBlocks;

}
