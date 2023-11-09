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

int n, m;
int a[N];

int ask(int x, int y)
{
	int ans = 0;
	if (x <= y)return y - x;
	while (x / 2 >= y)x /= 2, ans++;
	ans += min(x - y, y - x / 2 + 1);
	return ans;
}

void mysolve()
{
	cin >> n >> m;
	set<int>s;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			int x = a[i];
			while (x)s.insert(x), x /= 2;
		}
	int x, ans = INF;
	for (auto v : s)
		{
			int sum = 0;
			priority_queue<int>q;
			for (int i = 1; i <= n; ++i)
				{
					x = ask(a[i], v);
					sum += x, q.push(x);
				}
			for (int i = 1; i <= m; ++i)sum -= q.top(), q.pop();
			ans = min(ans, sum);
		}
	cout << ans << endl;
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
