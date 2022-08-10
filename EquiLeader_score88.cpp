#include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)
    
    int len = A.size();
    int equiCount = 0;
    if (len != 0)
    {
        stack<int> myStack;
        for (auto el:A)
        {
            if (myStack.empty())
            {
                myStack.push(el);
            }
            else 
            {
                if (myStack.top() != el )
                {
                    myStack.pop();
                }
                else 
                {
                    myStack.push(el);
                }
            }
        }
        int candidate = myStack.top();
        int iCount = 0;
        for (int i = 0; i < len; i++)
        {
            if (A[i] == candidate)
            {
                iCount++;
            }

        }

        if (iCount > len/2)
        {
            int leaderCountLeft = 0;
            int leaderCountRight = iCount;
            int itemsCountLeft = 0;
            int itemsCountRight = len;    
            for (auto el:A)
            {
                if(el == candidate)
                {
                    leaderCountLeft++;
                    leaderCountRight--;
                }
                itemsCountLeft++;
                itemsCountRight--;

                if (leaderCountLeft > itemsCountLeft/2)
                {
                    if (leaderCountRight > itemsCountRight/2)
                    {
                        equiCount++;
                    }
                } 

            }
        }

            

    }


    return equiCount;
}
