int solution(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)
     // write your code in C++14 (g++ 6.2.0)
    int totalSum = 0;
    int totalSumABS = 0;
    for (auto el:A)
    {
        if (el > 1000 || el < -1000)
        {
            return  -1;
        }
        totalSum += el;
        totalSumABS += abs(el);
    }

    int leftSum = 0;
    int rightSum = 0;
    int min_diff = totalSumABS;
    int diff;
    int len =  A.size();
    for (int p = 0; p < len - 1; p++)
    {
       leftSum += A[p];
       rightSum = totalSum - leftSum;
      //cout << "totalSum=" << totalSum << " leftSum=" << leftSum << " rightSum=" << rightSum << endl;        
       diff = abs(rightSum - leftSum);
       
        //cout << " diff=" << diff << endl; 
        if ( diff < min_diff)
        {
            min_diff = diff;
        }
        //cout << " min_diff=" << min_diff << endl;

        if (min_diff == 0 )
            break;

    }
    return min_diff;
}
