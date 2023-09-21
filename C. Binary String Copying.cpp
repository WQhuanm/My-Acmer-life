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
const int N = 3e5 + 10;

int n, m;
string s;
int l[N], r[N];

void mysolve()
{
	cin >> n >> m >> s;
	s = '$' + s;
	r[0] = 0, l[n + 1] = n + 1;
	for (int i = 1; i <= n; ++i)
		{
			if (s[i] == '1')r[i] = r[i - 1];
			else r[i] = i;
		}
	for (int i = n; i; --i)
		{
			if (s[i] == '0')l[i] = l[i + 1];
			else l[i] = i;
		}
	set<pii>ans;
	bool fl = 0;
	int x, y;
	while (m--)
		{
			cin >> x >> y;
			x = l[x], y = r[y];
			if (x >= y)fl = 1;
			else
				{
					ans.insert({x, y});
				}
		}
	cout << (int)ans.size() + fl << endl;
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
