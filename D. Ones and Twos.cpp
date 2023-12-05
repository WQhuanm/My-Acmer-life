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
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

int n, q;
int t[N], a[N];

void add(int x, int w)
{
	for (int i = x; i <= n; i += i & -i)t[i] += w;
}

int ask(int x)
{
	int ans = 0;
	if (!x)return 0;
	for (int i = x; i; i -= i & -i)ans += t[i];
	return ans;
}

void mysolve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)t[i] = 0;
	set<int>s;
	int op, x, y;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i], add(i, a[i]);
			if (a[i] == 1)s.insert(i);
		}
	while (q--)
		{
			cin >> op;
			if (op == 1)
				{
					cin >> x;
					if (s.empty())
						{
							if (x & 1 || x / 2 > n)cout << "NO" << endl;
							else cout << "YES" << endl;
							continue;
						}
					if (x == 1)
						{
							cout << "YES" << endl;
							continue;
						}
					int now = *s.begin();
					if (now < n)
						{
							int l = now + 1, r = n, ans = now, tmp = ask(now);
							while (l <= r)
								{
									int mid = l + ((r - l) >> 1);
									if (ask(mid) - tmp <= x)ans = mid, l = mid + 1;
									else r = mid - 1;
								}
							int sum = ask(ans) - tmp;
							if (x - sum <= 1 || ((x - sum - 1) % 2 == 0 && (x - sum - 1) / 2 < now))
								{
									cout << "YES" << endl;
									continue;
								}
						}
					now = *prev(s.end());
					if (now > 1)
						{
							int l = 1, r = now - 1, ans = now, tmp = ask(now - 1);
							while (l <= r)
								{
									int mid = l + ((r - l) >> 1);
									if (tmp - ask(mid - 1) <= x)ans = mid, r = mid - 1;
									else l = mid + 1;
								}
							int sum = tmp - ask(ans - 1);
							if (x - sum <= 1 || ((x - sum - 1) % 2 == 0 && (x - sum - 1) / 2 <= n - now))
								{
									cout << "YES" << endl;
									continue;
								}
						}
					cout << "NO" << endl;
				}
			else
				{
					cin >> x >> y;
					if (a[x] == 1)s.erase(x);
					add(x, -a[x]);
					a[x] = y, add(x, a[x]);
					if (a[x] == 1)s.insert(x);
				}
		}

}

signed main()
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
