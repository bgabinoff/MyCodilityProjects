// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) 
{
    // write your code in C++14 (g++ 6.2.0)
    int numOfInt = 0;
    int fisrtDiv = A;
    for (int i = A; i <= B; i++)
    {
        if ( i % K == 0)
        {
             numOfInt++;
            //cout << "A =" << A << " K =" << K << " i=" << i << endl;
            break; 
        }
        else 
        {
            fisrtDiv++;    
            //cout << "A =" << A << " K =" << K << " i=" << i << endl; 
        }
    }
    //cout << "fistDiv=" << fisrtDiv << endl;
    numOfInt += (B - fisrtDiv)/K;
    return numOfInt;
}
