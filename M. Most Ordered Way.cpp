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

int n;
struct node
{
	int id, t, d, lim;
	bool operator<(const node&k)const
	{
		if (d != k.d)return d < k.d;
		else return t < k.t;
	}
} a[N];

bool vis[N];

int b[N];
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i].t >> a[i].d, a[i].id = i;
	sort(a + 1, a + 1 + n);
	int now = 0;
	for (int i = 1; i <= n; ++i)
		{
			if (now + a[i].t > a[i].d)return cout << "*" << endl, void();
			else now += a[i].t, a[i].lim = a[i].d - now;
		}
	vector<node>tmp;
	vector<int>ans;
	for (int i = n; i; --i)tmp.push_back(a[i]);
	while (!tmp.empty())
		{
			if (vis[tmp.back().id])
				{
					tmp.pop_back();
					continue;
				}

			int lim = tmp.back().lim, p = -1, id = tmp.back().id;
			for (int i = (int)tmp.size() - 2; ~i; --i)if(!vis[tmp[i].id])
				{
					if (tmp[i].id < id && tmp[i].t <= lim)
						{
							p = i, id = tmp[i].id;
						}
					lim = min(lim, tmp[i].lim);
				}
			ans.push_back(id);
			if (~p)
				{
					vis[id] = 1;
					for (int i = p + 1; i < (int)tmp.size(); ++i)
						{
							tmp[i].lim -= tmp[p].t;
						}
				}
			else  tmp.pop_back();
		}
	for (auto v : ans)cout << v << " ";
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
