#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
const int N = 2e5 + 10;

int n;
int a[N],  t[N];
pii b[N];
int dp[N][30], lg[N];
set<int>s[N];

void st()
{
	for (int i = 1; i <= n; ++i)dp[i][0] = a[i]; //dp[i][0]=[i,i-1+1]=[i,i]
	for (int j = 1; j <= lg[n]; ++j)for (int i = 1; i + (1 << j) - 1 <= n; ++i)dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]); //预处理st表
}

int stask(int l, int r)
{
	int k = lg[r - l + 1];
	return max(dp[l][k], dp[r - (1 << k) + 1][k]); //区间查询
}

void add(int x)
{
	for (int i = x; i <= n; i += i & -i)t[i]++;
}
int ask(int x)
{
	int ans = 0;
	for (int i = x; i; i -= i & -i)ans += t[i];
	return ans;
}


void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)s[i].clear(), t[i] = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i], s[a[i]].insert(i);
	for (int j = 1; j <= n; ++j)cin >> b[j].first, b[j].second = j;
	sort(b + 1, b + 1 + n);
	st();
	queue<pii>q;
	int now = 0, id, fl;
	for (int i = 1; i <= n; ++i)
		{
			now = b[i].first, id = b[i].second, fl = 1;
			while (!q.empty() && q.front().first != now)add(q.front().second), q.pop();
			if (a[id] > now)fl = 0;
			else if (a[id] < now)
				{
					if (s[now].empty())return cout << "NO" << endl, void();
					auto p = s[now].upper_bound(id);
					if (p != s[now].end())//have back
						{
							if (stask(id, *p) <= now && ask(*p) == ask(id - 1))s[now].insert(id);
							else if (p != s[now].begin())
								{
									p = prev(p);
									if (stask(*p, id) <= now && ask((*p) - 1) == ask(id))s[now].insert(id);
									else fl = 0;
								}
							else fl = 0;
						}
					else
						{
							p = prev(p);
							if (stask(*p, id) <= now && ask((*p) - 1) == ask(id))s[now].insert(id);
							else fl = 0;
						}
				}
			if (!fl)return cout << "NO" << endl, void();
			q.push({now, b[i].second});
		}
	cout << "YES" << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	lg[1] = 0;
	for (int i = 2; i <= N - 5; ++i)lg[i] = lg[i >> 1] + 1; //预处理lg
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
