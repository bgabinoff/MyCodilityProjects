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


int solution(int N, int M)
{
	return N / gcd(N, M, 1);
}
