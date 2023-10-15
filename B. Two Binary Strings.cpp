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

struct node
{
	int l, r;
	bool operator<(const node&k)
	{
		if (l != k.l)
			return l < k.l;
		else return r < k.r;
	}
};

void mysolve()
{
	string a, b;
	cin >> a >> b;
	int n = (int)a.size();
	if (a[0] != b[0] || a[n - 1] != b[n - 1])return cout << "NO" << endl, void();
	vector<node>ans;
	vector<int>vis(n + 10), p0, p1;
	vis[0]=1;
	for (int i = 0; i < n; ++i)
		{
			if (a[i] == b[i])
				{
					if (i && vis[i - 1])vis[i] = 1;
					if (a[i] == '0')
						{
							for (auto v : p0)if (!v || vis[v - 1])vis[i] = 1;
							p0.push_back(i);
						}
					else
						{
							for (auto v : p1)if (!v || vis[v - 1])vis[i] = 1;
							p1.push_back(i);
						}
				}
		}

	if (vis[n - 1])cout << "YES" << endl;
	else
		cout << "NO" << endl;
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
