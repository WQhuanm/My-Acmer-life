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
const int N = 1e5 + 10;
const int M = 1e4 + 10;
int s[N], cnt[M], dp[N];
vector<pii>q[M];
int tail[M], head[M];
int n;
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		{
			cin >> s[i];
			int p = s[i];
			if (q[s[i]].empty())q[s[i]].push_back({0, 0}), head[p] = tail[p] = 0;
			int y = dp[i - 1] + p * cnt[p] * cnt[p], x = 2 * p * cnt[p];

			if (head[p] <= tail[p] && q[p].back().first == x && q[p].back().second <= y)q[p].pop_back(), tail[p]--;
			while (head[p] + 1 <= tail[p] && (1.0 * y - q[p][tail[p] - 1].second) / (1.0 * x - q[p][tail[p] - 1].first) - (1.0 * q[p][tail[p]].second - q[p][tail[p] - 1].second) / (1.0 * q[p][tail[p]].first - q[p][tail[p] - 1].first) > - eps)q[p].pop_back(), tail[p]--;
			if (!(head[p] <= tail[p] && q[p].back().first == x && q[p].back().second >= y))q[p].push_back({x, y}), tail[p]++;

			cnt[p]++;
			while (head[p] + 1 <= tail[p] && (1.0 * q[p][tail[p]].second - q[p][tail[p] - 1].second) / (1.0 * q[p][tail[p]].first - q[p][tail[p] - 1].first) - cnt[p] < eps)q[p].pop_back(), tail[p]--;
			dp[i] = q[p][tail[p]].second - q[p][tail[p]].first * cnt[p] + p * cnt[p] * cnt[p];
		}
	cout << dp[n] << endl;
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
