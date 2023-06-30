#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;
int t[N];
void mysolve()
{
	int n, x;
	cin >> n;
	vector<pii>a;
	for (int i = 1; i <= n; ++i)cin >> x, a.push_back({x, i}), t[i] = x;
	sort(a.begin(), a.end(), greater<pii>());
	int m;
	cin >> m;
	vector<int>cnt(n + 1);
	set<int>s;
	t[0] = t[n + 1] = n ;
	s.insert(0);
	s.insert(n + 1);
	for (int i = 0; i < n; ++i)
		{
			int x = a[i].second;
			int l = *prev(s.lower_bound(x)), r = *s.upper_bound(x);
			cnt[r - l - 1] += min(t[l], t[r]) - t[x];
			s.insert(x);
		}
	ll ans = 0;
	for (int i = n; i > 1; --i)if (cnt[i])
			{
				if (m >= cnt[i]*i)m -= cnt[i] * i, ans += (i - 1) * cnt[i];
				else
					{
						int sum = m / i;
						m -= sum * i, ans += (i - 1) * sum;
						if (m > 0)ans += m - 1;
						break;
					}
			}
	cout << ans << endl;
}

int32_t main()
{
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
