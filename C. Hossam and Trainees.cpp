#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
//#define int              long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
bool vis[N];
int cnt[N];
void oula(int n)
{
	for (int i = 2; i <= n; ++i)
		{
			if (!vis[i])
				{
					cnt[++cnt[0]] = i;
					vis[i] = 1;
				}
			for (int j = 1; j <= cnt[0] && i * cnt[j] <= n; ++j)
				{
					vis[cnt[j]*i] = 1;
					if (i % cnt[j] == 0)break;
				}
		}

}

void mysolve()
{
	int n;
	cin >> n;
	int x;
	map<int, int>mp;
	bool flag = 1;
	for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			if (flag)
				{
					for (int j = 1; cnt[j]* cnt[j] <= x && j <= cnt[0]; ++j)
						{
							int k = cnt[j];
							if (x % k == 0)
								{
									mp[k]++;
									if (mp[k] > 1)
										{
											flag = 0;
											break;
										}

									while (x % k == 0)x /= k;
								}
						}
					if (x > 1)mp[x]++;
					if (mp[x] > 1)
						{
							flag = 0;
						}
				}

		}
	if (flag)cout << "NO" << endl;
	else cout << "YES" << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	oula((int)(sqrt(1e9)));
	ll t;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
