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
const int N = 3e5 + 10;

bool vis[N];
int n;
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)vis[i] = 0;
	vector<int>ans;
	ans.push_back(1);
	int p = 2;
	while (p <= n)
		{
			int now = p;
			while (now <= n)
				{
					if (!vis[now])ans.push_back(now), vis[now] = 1;
					now *= 2;
				}
			while (vis[p])p++;
		}
	for (auto v : ans)cout << v << " ";
	cout << endl;
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
