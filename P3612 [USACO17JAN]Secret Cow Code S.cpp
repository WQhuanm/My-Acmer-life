#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;

char s[50];
ll p[65];
int main()
{
	p[0] = 1;
	for (int i = 1; i <= 63; ++i)p[i] = p[i - 1] * 2ll;
	ll n;
	cin >> s >> n;
	ll len = strlen(s);

	while (n > len)
		{
			int i = 0;
			while (len * p[i] < n)++i;
			if (n == len * p[i - 1] + 1)--n;
			else n -= len * p[i - 1] + 1;
		}
	cout << s[n - 1];
	return 0;
}
