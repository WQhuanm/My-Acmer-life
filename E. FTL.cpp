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
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 5010;

int p1, p2, t1, t2, h, s;
int f[N], g[N];

void mysolve()
{
	cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
	memset(f, 0x3f, sizeof(f));
	memset(g, 0x3f, sizeof(g));
	f[0] = g[0] = 0;
	for (int i = 1; i <= h; ++i)
		{
			for (int j = 0; ; ++j)
				{
					int now = i - (p1 + p2 - s);
					int cnt = max(0ll, (now - j * (p1 - s) + p2 - s - 1) / (p2 - s));
					f[i] = min(f[i], max((j + 1) * t1, (cnt + 1) * t2));

					cnt = (i - j * (p1 - s) + p2 - s - 1) / (p2 - s);
					f[i] = min(f[i], max(j * t1, cnt * t2));
					if (j * p1 >= i)break;
				}
		}
	swap(t1, t2), swap(p1, p2);

	for (int i = 1; i <= h; ++i)
		{
			for (int j = 0; ; ++j)
				{
					int now = i - (p1 + p2 - s);
					int cnt = max(0ll, (now - j * (p1 - s) + p2 - s - 1) / (p2 - s));
					f[i] = min(f[i], max((j + 1) * t1, (cnt + 1) * t2));

					cnt = (i - j * (p1 - s) + p2 - s - 1) / (p2 - s);
					f[i] = min(f[i], max(j * t1, cnt * t2));if (j * p1 >= i)break;
				}
			
		}
	for (int i = 1; i <= h; ++i)for (int j = 1; j <= i; ++j)g[i] = min(g[i], g[i - j] + f[j]);
	cout << g[h] << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
