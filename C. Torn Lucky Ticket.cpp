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

int cnt[N][20];
int n;
void mysolve()
{
	cin >> n;
	vector<string>now;
	string s;
	for (int i = 0; i <= 100; ++i)for (int j = 1; j <= 5; ++j)cnt[i][j] = 0;
	for (int i = 1; i <= n; ++i)
		{
			cin >> s;
			now.push_back(s);
			int sum = 0;
			for (auto v : s)sum += v - '0';
			cnt[sum][(int)s.size()]++;
		}
	int ans = 0;
	for (auto s : now)
		{
			int sz = (int)s.size();
			vector<int>sum(10);
			for (int i = 0; i < sz; ++i)sum[i + 1] = sum[i] + s[i] - '0';
			for (int i = sz; i > 0; i -= 2)
				{
					int len = i + sz, hf = len / 2;
					if (sum[hf] >= sum[sz] - sum[hf])ans += cnt[2 * sum[hf] - sum[sz]][i];
					if (i != sz)
						{
							if (sum[sz] - sum[sz - hf] >= sum[sz - hf])ans += cnt[sum[sz] - 2 * sum[sz - hf]][i];
						}
				}
		}
	cout << ans << endl;
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
