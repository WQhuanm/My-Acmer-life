#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

vector<int> add(vector<int>&A, vector<int>&B)
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

	if (n == 1)
		{
			cout << 1;
			return 0;
		}
	if (n == 2)
		{
			cout << 2;
			return 0;
		}
	vector<int>A, B;
	A.push_back(1);
	B.push_back(2);
	for (int i = 3; i <= n; ++i)
		{
			auto C = add(A, B);
			A = B;
			B = C;
		}
	for (int i = (int)B.size() - 1; i >= 0; --i)cout << B[i];

}
