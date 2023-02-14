#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1e5 + 10;

int n, k, cnt, x[30], num;
ll ans;
bool vis[30];
string a, b;
set<int>s;

void dfs(int i1, int cnt1)
{
	if (i1 > cnt)
		{
			if (cnt1 == num)//当选取的数对于num时
				{
					ll sum = 0, tmp = 0;
					for (int i = 0; i < n; ++i)
						{
							if (a[i] == b[i] || vis[a[i] - 'a'])sum++;
							else tmp += (sum) * (sum + 1) / 2, sum = 0;

						}
					tmp += sum * (sum + 1) / 2;
					ans = max(tmp, ans);
				}
		}
	else
		{
			dfs(i1 + 1, cnt1);
			vis[x[i1]] = 1;//标记x数组的这个数选了
			if (cnt1 < num)dfs(i1 + 1, cnt1 + 1);//只有选取的数小于需要的数量时才选
			vis[x[i1]] = 0;

		}
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		{
			memset(vis, 0, sizeof(vis));
			s.clear();
			cin >> n >> k >> a >> b;
			cnt = 0;
			for (int i = 0; i < n; ++i)
				{
					int tmp = a[i] - 'a';
					if (!s.count(tmp))x[++cnt] = tmp, s.insert(tmp);//记录a中不同的字母数
				}
			ans = 0;
			num = min(k, cnt);
			dfs(1, 0);
			cout << ans << endl;
		}
	return 0;
}

