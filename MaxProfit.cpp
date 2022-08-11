// you can use includes, for example:
 #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();    

    int max_slice = 0;

    if (len > 1)
    {
        int dailyProfit[len-1]= {0};
        for (int i = 0; i < len; i++)
        {
            dailyProfit[i] = A[i+1]-A[i];
        }

        // now we have to find max slice
        
        int max_ending = 0;  

        for (auto el:dailyProfit)
        {
            max_ending = max(0, max_ending + el);
            max_slice = max(max_slice, max_ending);
        }
    }
    return max_slice;
}
