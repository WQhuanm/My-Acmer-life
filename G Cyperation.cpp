#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 3e6 + 10;

int n, k;
int a[N];
bool vis[N];
bool check(vector<int>&v)
{
	int len = (int)v.size();
	ll l = -INF, r = INF;
	ll s_odd = 0, s_even = 0;
	for (int i = 1; i < len; ++i)
		{
			if (i & 1)
				{
					s_odd += a[v[i]];
					r = min(r, s_odd - s_even);
				}
			else
				{
					s_even += a[v[i]];
					l = max(l, s_odd - s_even);
				}
			if (l > r || r < 0)return 0;
		}
//	s_even += a[v[0]];
	if (len % 2 == 0)
		{
			s_even += a[v[0]];
			if (s_even - s_odd)return 0;
		}
	else
		{
			s_odd += a[v[0]];
			ll tmp = s_odd - s_even;
			if (tmp >= 0 && tmp % 2 == 0 && l <= tmp / 2 && tmp / 2 <= r)return 1;
			else return 0;
		}
	return 1;
}
void mysolve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)cin >> a[i], vis[i] = 0;
	if (*max_element(a + 1, a + 1 + n) == 0)
		{
			cout << "YES" << endl;
			return;
		}
	if (k > n / 2)
		{
			cout << "NO" << endl;
			return;
		}

	for (int i = 1; i <= n; ++i)if (!vis[i])
			{
				vector<int>v;
				int p = i;
				while (!vis[p])
					{
						v.push_back(p), vis[p] = 1;
						p = (p + k) % n;
						if (!p)p = n;
					}
				if (!check(v))
					{
						cout << "NO" << endl;
						return;
					}
			}
	cout << "YES" << endl;
}

int32_t main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
