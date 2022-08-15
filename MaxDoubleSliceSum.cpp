// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)

    int bestSum = 0;
    int len = A.size();
    int lefttoRightSum[len] = {0};
    int righttoLeftSum[len] = {0};

    for (int i = 1; i < len-1; i++)
    {
        lefttoRightSum[i] = max(A[i], lefttoRightSum[i-1] + A[i]);  
        if (lefttoRightSum[i] < 0)
        {
            lefttoRightSum[i] = 0;
        }
        
        //cout << "i=" << i << " lefttoRightSum[" << i << "]=" << lefttoRightSum[i] << " A[" << i << "]=" << A[i] << " lefttoRightSum[i-1]=" << lefttoRightSum[i-1] << endl;
    }

    for (int i = len - 2; i > 0; i--)
    {
        righttoLeftSum[i] = max(A[i], righttoLeftSum[i+1] + A[i]);
        if (righttoLeftSum[i] < 0)
        {
            righttoLeftSum[i] = 0;
        }
        
       // cout << "i=" << i << " righttoLeftSum[" << i << "]=" << righttoLeftSum[i] << " A[" << i << "]=" << A[i] << " righttoLeftSum[i-1]=" << righttoLeftSum[i-1] << endl;
    }

    for (int i = 1; i < len -1; i++)
    {
        bestSum = max(bestSum, lefttoRightSum[i-1] + righttoLeftSum[i+1]);
       // cout << "lefttoRightSum[i-1]=" << lefttoRightSum[i-1] << " righttoLeftSum[" << i << "+1]=" << righttoLeftSum[i+1] << endl;
    }



    return bestSum;
}
