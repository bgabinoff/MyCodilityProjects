// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int solution(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)
    int smallestMissingInt = 1;
    int len = A.size();
    sort(A.begin(),A.end());

    bool smallestMissingFound  = false;
    //case 1 all negatives
    if (A[len-1] <= 0 || A[0] >1 )
    {
        smallestMissingFound  = true;    
    }
    else
     {
        int firstPositive= 0;
        int prevPositive = 0;
        
        for (auto el:A)
        {
            if (el > 0)
            {
                
                if (!firstPositive)
                {
                    firstPositive = el;
                }
               // cout << "firstPositive=" << firstPositive << " el=" << el << endl;
                if (firstPositive > 1)
                {
                    smallestMissingFound  = true;
                    break;        
                }
                if (el - prevPositive > 1)
                { 
                    smallestMissingInt = prevPositive + 1;
                    smallestMissingFound  = true;
                   // cout << "prevPositive=" << prevPositive << " el=" << el << " smallestMissingFound=" << smallestMissingFound << endl;
                    break;        
                }
                else 
                {
                    prevPositive = el; 
                }
            }
        }
     }    
     
     if (!smallestMissingFound)
     {
         smallestMissingInt = A[len-1] + 1;
     }

    return smallestMissingInt;

}
