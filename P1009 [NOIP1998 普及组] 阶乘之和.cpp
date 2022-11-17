#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

vector<int> mul(vector<int>&A, int b)
{
	vector<int>C;
	int t = 0;
	for (int i = 0; i < (int)A.size() || t; ++i)
		{
			if (i < (int)A.size())t += A[i] * b;
			C.push_back(t % 10);
			t /= 10;
		}
	while ((int)C.size() > 1 && !C.back())C.pop_back();
	return C;
}

vector<int> addi(vector<int>&A, vector<int>&B)
{
	vector<int>C;
	int t = 0;
	for (int i = 0; i < (int)A.size() || i < (int)B.size(); ++i)
		{
			if (i < (int)A.size())t += A[i];
			if (i < (int)B.size())t += B[i];
			C.push_back(t % 10);
			t /= 10;
		}
	if (t)C.push_back(t);
	return C;
}

int main()
{
	int n;
	cin >> n;
	vector<int>A;
	vector<int>sum;
	A.push_back(1);
	sum.push_back(1);
	for (int i = 2; i <= n; ++i)
		{
			A = mul(A, i);
			sum = addi(sum, A);
		}
	for (int i = (int)sum.size() - 1; i >= 0; --i)cout << sum[i];
	return 0;
}
