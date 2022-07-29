// you can use includes, for example:
 #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)
    int distinctValues = 1;
    int len = A.size();
    if (len > 1)
    {     
        sort(A.begin(), A.end());
        int distinctElement = A[0];
        for (auto el:A)
        {
            if (el != distinctElement)
            {
                distinctElement = el;
                distinctValues++;    
            }
            
        }

        
    }
    else if (!len) distinctValues = 0;

    return distinctValues;
}
