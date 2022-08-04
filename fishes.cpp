// you can use includes, for example:
 #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) 
{
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();
    int stillAlive = len;
    int eaten = 0;
    //vector<int> upstream;
    vector<int> downstream;
    for (int i = 0; i < len-1; i++)
    {
        if (B[i] == 1)
        {
            downstream.push_back(A[i]);
        }
        //cout << "size=" << downstream.size() << " B[" << i << "+1]=" << B[i+1] << endl;

        if (B[i+1] ==0 )
        {
            while (!downstream.empty())
            {
                int downStreamFish = downstream.back();
                downstream.pop_back();
                eaten++;
                //cout << "downStreamFish= " << downStreamFish << " eaten=" << eaten << endl;
                if (downStreamFish > A[i+1])
                {
                    downstream.push_back(downStreamFish);
                    break;
                }

                
            }
        }

    }

    stillAlive -= eaten;
    
    return stillAlive;
}
