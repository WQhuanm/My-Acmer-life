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
int a[N], b[N], cnt[N], pre[N];
set<int>kind[N];

vector<int> jud(int x)
{
	vector<int>now;
	for (int i = 1; i * i <= x; ++i)if (x % i == 0)
			{
				now.push_back(i);
				if (x / i != i)now.push_back(x / i);
			}
	sort(now.begin(), now.end());
	return now;
}

void mysolve()
{
	cin >> n;
	pre[0] = 1;
	for (int i = 1; i <= n; ++i)cin >> a[i], pre[i] = pre[i - 1] * 2 % mod;
	for (int i = 1; i <= n; ++i)
		{
			b[i] = a[i];
			for (int j = 2; j * i <= n; ++j)b[i] = max(b[i], a[i * j]);
			cnt[b[i]]++;
		}
	for (int i = 1; i <= 1e5; ++i)cnt[i] += cnt[i - 1];
	ll sum = 0;
	for (int i = 1; i <= n; ++i)
		{
			if (b[i] == a[i])
				{
					vector now = jud(i);
					for (int j = (int)now.size() - 1; j >= 0; --j)
						{
							if (b[now[j]] <= a[i])kind[a[i]].insert(now[j]);
//							else break;
						}
				}
		}
	for (int i = 0; i <= 1e5; ++i)if (!kind[i].empty())
			{
				int sz = (int)kind[i].size();
				sum = (sum + (pre[sz] - 1 + mod) % mod * pre[cnt[i] - sz] % mod * i % mod) % mod;
			}
	cout << sum << endl;
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
