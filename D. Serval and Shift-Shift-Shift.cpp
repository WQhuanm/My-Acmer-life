#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
#define endll            endl<<endl
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e3 + 100;

bool a[N], b[N], c[N];
int ans[N];
int  ah, al, bh;
int n;

void ainit(int x, int k)
{
	memcpy(c, a, sizeof(a));
	for (int i = 0; i < n; ++i)
		{
			int h = i - k;
			if (h < 0 || h >= n)continue;
			a[i] ^= c[h];
			if (a[i])ah = min(ah, i);
		}
}

void mysolve()
{
	string sa, sb;
	cin >> n >> sa >> sb;
	int cnta = 0, cntb = 0;
	bh = ah = n - 1, al = 0;
	for (int i = 0; i < n; ++i)
		{
			a[i] = sa[i] - '0';
			if (a[i])ah = min(ah, i), cnta++;
		}
	for (int i = 0; i < n; ++i)
		{
			b[i] = sb[i] - '0';
			if (b[i])bh = min(bh, i), cntb++;
		}
	if (!cnta && !cntb)
		{
			cout << 0 << endl;
			return;
		}

	if (cntb && cnta)
		{
			int k = 0;
			for (int i = bh; i < n; ++i)
				{
					if (b[i] != a[i])
						{
							ans[++k] = ah - i;
							ainit(i, i - ah);
						}
				}
			if (ah < bh)
				{
					for (int i = n - 1; i >= 0; --i)
						{
							if (a[i])
								{
									al = i;
									break;
								}
						}
					for (int i = bh - 1; i >= ah; --i)if (a[i])
							{
								ainit(i, i - al);
								ans[++k] = al - i;
							}
				}
			cout << k << endl;
			for (int i = 1; i <= k; ++i)
				{
					cout << ans[i];
					if (i == k)cout << endl;
					else cout << ' ';
				}
		}
	else cout << -1 << endl;

}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
