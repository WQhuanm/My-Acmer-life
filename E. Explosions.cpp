#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 3e5 + 10;
int a[N], l[N], r[N], a1[N], n;

void cnt(int *f)
{
	stack<int>s;
	s.push(0);//放入左边边界外面0
	for (int i = 1; i <= n; ++i)a1[i] = a[i] - i; //记录比较数组
	for (int i = 1; i <= n; ++i)
		{
			while ((int)s.size() > 1 && a1[s.top()] >= a1[i])s.pop(); //从最靠近右边的点（堆顶）开始比较，不满足的点全部舍去，后面也没用了
			int len = min(a[i], (ll)i - s.top()); //爆炸可持续范围最长是a[i]（伤害不断递减），不是直接取遇到满足条件的j点（你可能到不了那个点）
			f[i] = f[s.top()] + len * (2 * a[i] - len + 1) / 2;
			s.push(i);//不断给栈存入新的点
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		{
			cin >> n;
			ll sum = 0;
			for (int i = 1; i <= n; ++i)cin >> a[i], sum += a[i];
			cnt(l);
			reverse(a + 1, a + 1 + n); //反转一下求右边爆炸
			cnt(r);
			reverse(r + 1, r + 1 + n); //r获得的是反转过的，要反转回来
			reverse(a + 1, a + 1 + n);
			ll ans = 0;
			for (int i = 1; i <= n; ++i)ans = max(ans, l[i] + r[i] - 2 * a[i]); //l与r都记录了a[i]造成的伤害，然而这个伤害是魔法产生的，不是被波及的
			cout << sum - ans << endl;
		}
	return 0;
}
