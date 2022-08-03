// you can use includes, for example:
#include <algorithm>
#include <stack>
#include <vector>

int solution(string &S) 
{
    // write your code in C++14 (g++ 6.2.0)
    bool isProperlyNested = false;
    bool isTerminated = false;
    const int len = S.length();
    if (len > 1 && !(len % 2) ) 
    { 
        stack<int> brackets;
        vector<int> str(len,0);
        int i = 0;
        for (auto el:S)
        {
            switch(el)
            {
                case '[': str[i] =1;  break;
                case ']': str[i] =-1; break;
                case '(': str[i] = 2; break;
                case ')': str[i] = -2; break;
                case '{': str[i] = 3; break;
                case '}': str[i] = -3; break;   
            }
            i++;
        }

        for (auto el:str)
        {
            //cout << "Element=" << el << endl;
            if (el > 0) 
            {
                brackets.push(el);
                //cout << "stack size=" << brackets.size() << endl;
            }
            else 
            {
                int stackItem = brackets.top();
                if (stackItem != abs(el))
                {
                    //cout << "StackItem=" << stackItem << " Element=" << el << " stack size=" << brackets.size()<< endl;
                    isTerminated = true;
                    break;
                }
                else
                {
                    brackets.pop();
                   // cout << "stack size=" << brackets.size() << endl;
                }    
            }        
        }
       // cout << "stack size=" << brackets.size() << endl;    
        if (brackets.empty() && !isTerminated)
        {
            isProperlyNested = true;
            //cout << "isProperlyNested=" << isProperlyNested << endl;            
        }

    
            
    }
    else if (len == 0) isProperlyNested = true;


        
    
    return isProperlyNested;
}
