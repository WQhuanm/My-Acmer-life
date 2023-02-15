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
const int N = 1e6 + 10;

ll vis[N], sum[N], a[N];
int main()
{
	ll n, p, k, b, t;
	ll cnt = 0, ans = 0;
	cin >> n >> p >> k >> b >> t;
	for (int i = 0; i < n; ++i)cin >> a[i];
	for (int i = 1; i <= t; ++i)
		{
			if (vis[p])//每次使用p前先询问是否出现过，出现就退出
				{
					break;
				}
			vis[p] = ++cnt;
			ans += a[p];//ans为答案
			sum[cnt] = sum[cnt - 1] + a[p];//记录前cnt个a[p]的前缀和
			p = (k * p + b) % n;
		}
	if (cnt < t)//cnt<t，说明有重复
		{
			ll st = vis[p], sz = cnt - st + 1;//当前的p为开头，其序号为vis[p]，记录循环节点数sz
			//	assert(sz == cnt);    //这个断言如果使用，通过率就只有90%，进一步说明循环不一定从头开始
			t -= cnt;
			ll u1 = t / sz, u2 = t % sz;
			ans += (sum[cnt] - sum[st - 1]) * u1 + (sum[u2 + st - 1] - sum[st - 1]);
		}
	cout << ans << endl;
	return 0;
}
