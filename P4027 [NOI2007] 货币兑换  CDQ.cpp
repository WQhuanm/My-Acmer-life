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

double dp[N], a[N], b[N], R[N];

struct node
{
	double y, x;
	bool operator<(const node&k)const
	{
		if (fabs(x - k.x) > -eps)return x < k.x;
		else return y < k.y;
	}
} q[N], que[N];

void solve(int l, int r)
{
	if (l == r)return ;
	int mid = l + ((r - l) >> 1);
	solve(l, mid);
	int len = 0;
	double mx = 0;
	for (int i = l; i <= mid; ++i)
		{
			double tmp = dp[i] / (b[i]  + a[i] * R[i]);
			q[++len] = {tmp, tmp*R[i]};
			mx = max(mx, dp[i]);
		}
	sort(q + 1, q + 1 + len);
	int head = 1, tail = 0;
	for (int i = 1; i <= len; ++i)
		{
			if (head <= tail && fabs(q[i].x - que[tail].x) < eps)
				{
					if (q[i].y - que[tail].y < -eps)tail--;
					else continue;
				}
			while (head + 1 <= tail && (que[tail - 1].y - q[i].y) / (que[tail - 1].x - q[i].x) - (que[tail - 1].y - que[tail].y) / (que[tail - 1].x - que[tail].x) > -eps)tail--;
			que[++tail] = q[i];
		}
	for (int i = mid + 1; i <= r; ++i)
		{
			dp[i] = max(mx,dp[i]);
			int ql = head, qr = tail - 1, ans = tail;
			double k = -a[i] / b[i];
			while (ql <= qr)
				{
					int qm = ql + ((qr - ql) >> 1);
					if ((que[qm].y - que[qm + 1].y) / (que[qm].x - que[qm + 1].x) - k < eps)ans = qm, qr = qm - 1;
					else ans = ql = qm + 1;
				}
			dp[i] = max(dp[i], b[i] * (que[ans].y + que[ans].x * -k));
		}
	solve(mid + 1, r);
}

int n;
double s;
void mysolve()
{
	cin >> n >> s;
	dp[1] = s;
	for (int i = 1; i <= n; ++i)cin >> a[i] >> b[i] >> R[i];
	solve(1, n);
	printf("%.3lf", dp[n]);
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
