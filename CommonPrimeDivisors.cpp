// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int gcd(int a, int b, int res)
{
	int result = 0;
	

	if (a == b)
	{
		return res * a;
	}
	else if (a % 2 == 0 && b % 2 == 0)
	{
		return gcd(a / 2, b / 2, 2 * res);
	}
	else if (a % 2 == 0)
	{
		return gcd(a / 2, b, res);
	}
	else if (b % 2 == 0)
	{
		return gcd(a, b / 2, res);
	}
	else if (a > b)
	{
		return gcd(a - b, b, res);
	}
	else
	{
		return gcd(a, b - a, res);
	}
	return result;
}

bool containsAllPrimeFactors(int x, int y)
{
	bool res;
	if (y == 1)
	{
		return true;
	}
	else
	{
		int gcDivisor = gcd(x, y, 1);

		if (gcDivisor == 1)
		{
			return false;
		}
		else
		{
			res = containsAllPrimeFactors(x, y / gcDivisor);
		}
	}

	return res;
}




int solution(vector<int> &A, vector<int> &B) 
{
    // write your code in C++14 (g++ 6.2.0)
    int result = 0;
	
	
	int len = A.size();

	
	for (int i = 0; i < len; i++)
	{
		if (containsAllPrimeFactors(A[i], B[i]) && containsAllPrimeFactors(B[i], A[i]))
		{
			result++;
		}

		
	}
	
	return result;
}
