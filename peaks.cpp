#include <algorithm>
 #include <iterator>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)
    
    int blockNum = 0;
    int N = A.size();
    vector<int> Peaks(N,0);
    int numPeaks = 0;
    for (int i = 1; i < N-1; i++)
    {
        if (A[i] > A[i-1] && A[i] > A[i+1] )
        {
            Peaks[i] =1;
           numPeaks++;
        }
        
    }
    /*
    for (auto el:Peaks)
    {
        cout << "el=" << el << endl;
    }  
*/
    if ( numPeaks > 0)
    {
        blockNum = 1;
        //int startPos,endPos;
        int blockLength;
        bool noPeaks;
        vector<int>::iterator startBlock;
        vector<int>::iterator endBlock;
        for ( int i = numPeaks; i > 1; i--)
        {
            if (N % i == 0)
            {
                blockLength = N / i;
                
                int result=0;
                startBlock = Peaks.begin();
                noPeaks = false;
                for (int j = 0; j < i; j++)
                {
                    endBlock = startBlock + blockLength;
                   // cout << "endBlockVal=" << *(endBlock-1) << endl;
                   // cout << "startBlockPos=" << distance(Peaks.begin(),startBlock) << " endBlockPos=" << distance(Peaks.begin(),endBlock) << endl;
                    
                    result = *std::max_element(startBlock, endBlock);
                    //cout << "result=" << result << endl;
                    if (result == 1)
                    {
                        startBlock = endBlock;
                      //  cout << "startBlockPos=" << distance(Peaks.begin(),startBlock) << endl;
                    }
                    else
                    {
                        noPeaks = true;
                        break;
                    }        

                }
                if (noPeaks == false)
                {
                     blockNum = i;
                     break;          
                }

  /*              int j = 0;
                int nextPeak = Peaks[0];
                //cout << "i=" << i << endl;
                while (startPos < N)
                {
                  // cout << "N=" << N << " StartPos=" << startPos << " StartPos+Len=" << startPos+blockLength-1 << " nextPeak=" << nextPeak << endl;
                    endPos = startPos + blockLength - 1;
                  //  cout << "line 44: EndPos=" << endPos << endl;
                    if ( endPos < nextPeak)
                    {
                    //    cout << "[break] " << endl; 
                        break;
                    }
                    else 
                    {
                       while (Peaks[j] <= endPos) 
                        {
                      //      cout << "j=" << j << " Peaks[" << j << "]=" << Peaks[j] << endl;
                            j++;
                        };     
                        
                        //cout << "j=" << j << " numPeaks=" << numPeaks << endl; 

                        if (j < numPeaks)
                        {
                            startPos += blockLength;
                            nextPeak = Peaks[j];

                          //  cout << "J=" << j <<" StarPos=" << startPos << " nextPeak=" << nextPeak << endl;
                        }
                        else
                        {
                            //cout << "break" << endl;
                            break;
                        }
                       
                    }
                }
                //cout << "EndPos=" << endPos << endl;
                if (endPos >= N-1)
                {
                    blockNum = i;
                    break;
                }*/    
            }
        }



    }


    return blockNum;
}
