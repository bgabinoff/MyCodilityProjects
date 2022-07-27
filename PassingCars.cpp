// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)
     // write your code in C++14 (g++ 6.2.0)
    unsigned int sum = 0;
    unsigned int len = A.size();
    unsigned int countZeroes = 0;
    //int pairsPassed = 0;
    for (unsigned int i = 0; i < len; i++)
    {
        if (A[i] != 0)
        {
            sum += countZeroes;
            //cout << "i=" << i << " sum=" << sum << endl; 
        }
        else 
        {
             countZeroes++;
        }
            
    }
    
    if (sum > 1000000000)
    {
        return -1;
    }
    else 
    {
        return sum;
    }
}
