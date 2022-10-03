#include <algorithm>
//#include <string>
#include <math.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
vector<int>   FibSequence(int N)
{
	vector<int> fibSequence(N);
	fibSequence[0] = 1;
	fibSequence[1] = 1;

	for (int i = 2; i < N; i++)
	{
		
		fibSequence[i] = fibSequence[i - 1] + fibSequence[i - 2];
		fibSequence[i] = fibSequence[i] % (int)pow(2, 30);
	}




	return fibSequence;
}


vector<int> solution(vector<int> &A, vector<int> &B) 
{
    // write your code in C++14 (g++ 6.2.0)
    vector<int> result(A.size());
	vector<int> fibSeq = FibSequence(A.size()+1); 

	for (int i = 0; i < A.size(); i++)
	{
		result[i] = fibSeq[A[i]] % (int)pow(2, B[i]);
	}


	return result;
}
