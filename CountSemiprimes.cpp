//you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &P, vector<int> &Q) 
{
    // write your code in C++14 (g++ 6.2.0)

    

    //first lets find prime numbres in the range
    vector<int> counts;
    vector<bool> prime(N,true);
    vector<int> primeNum;
    int semiPrimesCounts[N+1] = {0};
    
    for (int i = 2; i*i <= N; i++)
    {
        if (prime[i])
        {
            for (int j = i*i; j < N; j +=i)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (prime[i])
        {
            primeNum.push_back(i);
           // cout << i << endl;
        }
    }
    //
    int M = P.size();
    if (N < 4)
    {
     
     return vector<int>(M,0);
    }
    // find all semiprimes
    for (int j = 0; j <  primeNum.size(); j++)
    {
        for (int k = j; k < primeNum.size();k++)
        {
            long num = (long) primeNum[j] * primeNum[k];
            if( num > N ) 
                break;
            //semiPrimes.push_back(num);
            semiPrimesCounts[num] = 1;   
        }
            

    }

    
    // fill precounts array
    //sort(semiPrimes.begin(),semiPrimes.end());
    
    int k = 0;
    for (int j = 0; j <= N; j++)
    {
        k += semiPrimesCounts[j];
        semiPrimesCounts[j] = k;
    }    
        
    
    for (int i = 0; i < M; i++)
    {
        int count = semiPrimesCounts[Q[i]] - semiPrimesCounts[P[i]-1];
        counts.push_back(count);
    }

    return counts;
}
