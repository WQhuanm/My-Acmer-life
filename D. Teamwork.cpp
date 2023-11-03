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

int a, b, c, l;

struct node
{
	int id, t;
	bool operator<(const node&k)const
	{
		return t > k.t;
	}
} f[5];

struct TMP
{
	int id, st, ed;
} ans[N];

void mysolve()
{
	cin >> a >> b >> c >> l;
	f[1] = {1, 0}, f[2] = {2, 0}, f[3] = {3, 0};
	int cnt = 0;
	for (int i = 1; i <= l; ++i)
		{
			bool fl = 0;
		sort(f+1,f+4);
			if (c)
				{
					for (int j = 1; j <= 3; ++j)if (i - 4 >= f[j].t)
							{
								fl = 1, c--;
								ans[++cnt] = {f[j].id, i - 4, i}, f[j].t = i;
								break;
							}
					if (fl)continue;
				}
			if (b)
				{
					for (int j = 1; j <= 3; ++j)if (i - 3 >= f[j].t)
							{
								fl = 1, b--;
								ans[++cnt] = {f[j].id, i - 3, i}, f[j].t = i;
								break;
							}
					if (fl)continue;
				}
			if (a)
				{
					for (int j = 1; j <= 3; ++j)if (i - 2 >= f[j].t)
							{
								fl = 1, a--;
								ans[++cnt] = {f[j].id, i - 2, i}, f[j].t = i;
								break;
							}
					if (fl)continue;
				}
		}
	cout << cnt << endl;
	for (int i = 1; i <= cnt; ++i)cout << ans[i].id << " " << ans[i].st << " " << ans[i].ed << endl;
}

int32_t main()
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
