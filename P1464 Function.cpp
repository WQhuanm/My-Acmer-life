#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 100;

ll h[N][N][N];
ll f(ll a, ll b, ll c)
{
	if (a <= 0 || b <= 0 || c <= 0)return 1;
	if ((a > 20 || b > 20 || c > 20))
		{
			if (h[20][20][20] != llINF)return h[20][20][20];
			else
				{
					h[20][20][20] = f(20, 20, 20);
					return h[20][20][20];
				}
		}
	if (h[a][b][c] != llINF)return h[a][b][c];
	if (a < b && b < c)
		{
			h[a][b][c] = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
			return h[a][b][c];
		}
	h[a][b][c] = f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1) - f(a - 1, b - 1, c - 1);
	return h[a][b][c];
}

int main()
{
	memset(h, 0x3f, sizeof(h));
	ll a, b, c;
	while (cin >> a >> b >> c && !(a == -1 && b == -1 && c == -1))
		{
			printf("w(%lld, %lld, %lld) = ", a, b, c);
			cout << f(a, b, c) << endl;
		}

	return 0;
}
