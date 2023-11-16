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

int m, a, b;
int vis[N], val[N];
void bfs()
{
	queue<int>q;
	q.push(0);
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			if (u - b > 0 && !vis[u - b])vis[u - b] = vis[u], q.push(u - b), val[vis[u - b]]++;
			if (u <= b && !vis[u + a])vis[u + a] = max(vis[u], u + a), q.push(u + a), val[vis[u + a]]++;
		}
}
void mysolve()
{
	cin >> m >> a >> b;
	val[0] = 1;
	bfs();
	int ans = 1;
	for (int i = 1; i <= min(m, a + b); ++i)val[i] += val[i - 1], ans += val[i];

	int now = a + b + 1, g = __gcd(a, b);
	if (now <= m)
		{
			ans += m - now + 1;
			int l = now / g, r = m / g;
			if ((l + 1)*g - 1 >= m)ans += (m - now + 1) * (now / g), now = m + 1;
			else ans += ((l + 1) * g - now) * l, now = (l + 1) * g;
			if (now <= m)
				{
					if (r * g <= now)ans += (m - now + 1) * r;
					else
						{
							ans += (m - r * g + 1) * r, m = r * g - 1;
							ans += (now / g + m / g) * (m / g - now / g + 1) / 2 * g;
						}
				}
		}
	cout << ans << endl;
}

signed main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
