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

//const int MAXN = 1e6;
int cnt, n; //插入直线数量
double dp[N], A[N], B[N], r[N], c[N];
struct line
{
	double k, b;
} a[N];//记录填入直线

double cal(int id, double x)//x为坐标
{
	return a[id].k * x + a[id].b;//如果是实数，需要改为double
}

struct LC_tree//这里要求是加入直线，而不是线段(需要开辟空间直到线段包含当前区间），才能保证nlogn空间复杂度（否则是nlogn^2）
{
	int tot = 0;//tot为开点数
	struct tree
	{
		int  ls, rs, id;
	} t[N << 5]; //空间nlogn,M为x定义域

	void clear()
	{
		for (int i = 1; i <= tot; ++i)t[i].ls = t[i].rs = t[i].id = 0;
		tot = 0;
	}

	void update(int l, int r, int &p, int id)//求min
	{
		if (!p)return t[p = ++tot].id = id, void();//动态开点，这个区间是新的，覆盖完就走

		int mid = l + ((r - l) >> 1);
		if (cal(id, c[mid]) - cal(t[p].id, c[mid]) > eps)swap(id, t[p].id); //保证t[p].id对应的是该位置的最优线段，只有严格小）才更新
		if (l == r)return;

		//操作后 x为次优，在他能够比t[p].id优越的子区间更新
		if (cal(id, c[l]) - cal(t[p].id, c[l]) > eps)update(l, mid, t[p].ls, id); //两个区间只会进入一个，严格小才更新（避免直线是重合还多更新）
		if (cal(id, c[r]) - cal(t[p].id, c[r]) > eps)update(mid + 1, r, t[p].rs, id);
	}

	double ask(int l, int r, int p, int x) //x为坐标
	{
		if (!p)return -INF;//没开过点，这个区间不存在新直线了，返回极值
		if (l == r)return cal(t[p].id, c[x]);

		//李超没有下传标记，所有覆盖x的区间的最值才是最优
		int mid = l + ((r - l) >> 1);
		double ans = cal(t[p].id, c[x]);
		if (x <= mid)ans = max(ans, ask(l, mid, t[p].ls, x));
		else ans = max(ans, ask(mid + 1, r, t[p].rs, x));
		return ans;
	}
} T;

int s;
int rt;
void mysolve()
{
	cin >> n >> s;
	dp[0] = s;
	for (int i = 1; i <= n; ++i)cin >> A[i] >> B[i] >> r[i], c[i] = A[i] / B[i];
	sort(c + 1, c + 1 + n);
	for (int i = 1; i <= n; ++i)
		{
			dp[i] = dp[i - 1];
			int num = lower_bound(c + 1, c + 1 + n, A[i] / B[i]) - c;
			dp[i] = max(dp[i], B[i] * T.ask(1, n, 1, num));
			double tmp = dp[i] / (A[i] * r[i] + B[i]);
			a[++cnt] = {tmp*r[i], tmp};
			T.update(1, n, rt, cnt);
		}
	printf("%.3lf\n", dp[n]);
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
