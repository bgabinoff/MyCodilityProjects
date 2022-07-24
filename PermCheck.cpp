// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)
    int isPermutated = 0; 
    int len = A.size();
    if (!len) return isPermutated; 

    sort(A.begin(),A.end());
    
    int index = 1;
    for (auto el:A)
    {
        //cout << "Element=" << el << endl;
        if (el != index)
        {
            break;
        }
        else
        {
            index++;
        }
    }
   // cout << "index=" << index << endl;
    if (index == len+1)
    {
        isPermutated = 1;        
    }
return isPermutated;

}
