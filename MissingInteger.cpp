
int solution(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)
    // write your code in C++14 (g++ 6.2.0)
     // write your code in C++14 (g++ 6.2.0)
    int missingSmallestInteger = 1;
    int len = A.size();

    //sorting an array first


    sort(A.begin(), A.end());
    bool allNegatives = true;
    int i;
    int firstPositive = 1;
    // cout << "len=" << len << endl;

     if (len == 1)
     {
         if (A[0] == 1 ) missingSmallestInteger = 2;        
     }
    else 
    {
        
        for (i = 0; i < len - 1; i++)
        {
            //cout << "A[i]=" << A[i] << " A[i+1]=" << A[i+1] << endl;
            if (A[i+1] > 0 )
            {            
                allNegatives = false;
                if (A[i] > 0 )
                {
if (A[0] > 1) return 1;                    
if (A[i+1] - A[i] > 1)
                    {
                        
                        missingSmallestInteger = A[i] + 1;
                       // cout << "missingSmallestInteger=" << missingSmallestInteger << endl;
                        break;
                    }
                    else 
                    {
                        //cout << "missingSmallestInteger=" << missingSmallestInteger << endl;
                        if (A[i] == 1) firstPositive = 2; 
                    }
                    
                    
                }
                else
                {
                    if (A[i+1] > 1) //crossing form negative to positive
                    {
                        
                        missingSmallestInteger = 1;
                        
                        //cout << "missingSmallestInteger=" << missingSmallestInteger << endl;
                        break;
                    }
                    else {
                        firstPositive = 2;
                    }              
                    
                }
            } 
        }
        //cout << "i=" << i << " allNegarives = " << allNegatives << endl;
        if (i == len - 1)
        {
            //cout << "firstPositive = " << firstPositive << endl;
            if (!allNegatives && firstPositive > 1)
            {
                missingSmallestInteger = A[len - 1] + 1;
            }
        }
    }

    return missingSmallestInteger;
