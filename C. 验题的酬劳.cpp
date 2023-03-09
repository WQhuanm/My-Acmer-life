#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int N = 1e6 + 10;

bool vis[N];
int ou[N];
int s, k;

void oula()
{
	for (int i = 2; i <= N; ++i)
		{
			if (!vis[i])
				{
					vis[i] = 1;
					ou[++ou[0]] = i;
				}
			for (int j = 1; j <= ou[0] && i * ou[j] <= N; ++j)
				{
					vis[ou[j]*i] = 1;
					if (i % ou[j] == 0)break;
				}
		}
}

void mysolve()
{

	cin >> s >> k;
	ll ans = 0;
	if (s % k == 0)
		{
			//	ll sum=1;
			for (int i = 1; i <= ou[0] && ou[i]*ou[i] <= s; ++i)
				{
					if (s % ou[i] == 0)
						{
							int cnt = 0;
							while (s % ou[i] == 0)cnt++, s /= ou[i];
							ans += (ans + 1) * cnt;
							//	sum*=cnt;
						}
				}
			if (s != 1)ans <<= 1;
			cout << ans / 2 + 1 << endl;
		}
	else cout << 0 << endl;

}

signed main()
{

	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	oula();
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
