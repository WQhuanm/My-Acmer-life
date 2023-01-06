#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;

vector<int> add(vector<int> &a, vector<int> &b)
{
	vector<int>c;
	int j = 0;
	for (int i = 0; i < (int)a.size() || i < (int)b.size() || j; ++i)
		{
			if (i < (int)a.size())j += a[i];
			if (i < (int)b.size())j += b[i];
			c.push_back(j % 10);
			j /= 10;
		}
	return c;
}

int main()
{
	vector<int>a, b;
	a.push_back(1), b.push_back(2);
	int m, n;
	cin >> m >> n;
	for (int i = 4; i <= n - m + 1; ++i)
		{
			auto c = add(a, b);
			a = b, b = c;
		}
	for (int i = (int)b.size() - 1; i >= 0; --i)cout << b[i];
	return 0;
}
