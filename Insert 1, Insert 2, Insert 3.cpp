#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 1e6 + 10;

vector<int>b[N];
int a[N], nx[N];
int n;
bool vis[N];
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	ll ans = 0;
	nx[n + 1] = n + 1;
	for (int i = n; i; --i)
		{
			if (a[i] == 1)
				{
					if (!b[a[i] + 1].empty())
						{
							int p = b[a[i] + 1].back();
							vis[p] = 1, b[a[i] + 1].pop_back();
							nx[p] = p + 1;
						}
					vis[i] = 1;
					int tmp = i + 1;
					for (int j = i + 1; j <= n + 1; j = nx[j])
						{
							if (!vis[j])
								{
									tmp = j;
									break;
								}
						}
					nx[i] = tmp;
					ans += tmp - i;
				}
			else
				{
					if (!b[a[i] + 1].empty())
						{
							int p = b[a[i] + 1].back();
							vis[p] = 1, b[a[i] + 1].pop_back();
							nx[p] = p + 1;
						}
					b[a[i]].push_back(i);
					nx[i] = i;
				}
		}
	cout << ans << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	return 0;
}
