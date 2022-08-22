// you can use includes, for example:
 #include <algorithm>
#include <cmath>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)
    std::vector<int> peaks;

    for (int i = 1; i < A.size()-1; i++)
    {
        if (A[i] > A[i-1] && A[i] > A[i+1])
        {
            peaks.push_back(i);
        }
    }
   
    /*for (auto el:peaks)
    {
        cout << "el=" << el << endl; 
    }*/
     
    int maxflags;
    int peaksLength = peaks.size();    
    if (peaksLength <= 1)
    {
        maxflags = peaksLength;
    }
    else 
    {
        int maxdistance = peaks[peaksLength-1] - peaks[0];
        maxflags = ceil(std::sqrt(maxdistance));
        //cout << maxflags <<endl;
              
        for (int flags = maxflags; flags > 1; flags--)
        {
            int startFlag = peaks[0];
            int flagPlaced = 1;    
            //cout << "For loop flags=" << flags << endl;     
            for (int i = 1; i < peaksLength; i++)
            {   
                //cout <<  i << endl;
                if (peaks[i] - startFlag >= flags && flagPlaced < flags)
                {
                    startFlag = peaks[i];
                    flagPlaced++;
                //cout << "flagPlaced=" << flagPlaced << " startFlag=" << startFlag << " flags=" << flags <<endl;
                
                }
            } 

            if (flagPlaced == flags)
            {
                maxflags = flagPlaced;
                //cout << "flagPlaced=" << flagPlaced << "flags=" << flags << endl;
                break;
            }          

        }
    }

    return maxflags;
}
