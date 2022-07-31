// you can use includes, for example:
 #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)
    bool triangleExist = false;
    int len = A.size(); 
    if (len >= 3)
    {
        sort(A.begin(),A.end());
        for (int i = 0; i < len - 2; i++)
        {
            unsigned int sum = A[i] + A[i+1];     
            if (sum >  (unsigned int)A[i+2])
            {
                triangleExist = true;
                break;
            }
        }

    }

    return triangleExist;

}
