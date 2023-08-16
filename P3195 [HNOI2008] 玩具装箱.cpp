#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
#define int              long long
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 3e5 + 10;

struct node
{
	int x, y;
} q[N];
int n, l;
ll dp[N], s[N], c[N], sum[N];
void mysolve()
{
	cin >> n >> l;
	++l;
	for (int i = 1; i <= n; ++i)cin >> c[i], sum[i] = sum[i - 1] + c[i], s[i] = sum[i] + i;
	int head = 1, tail = 0;
	q[++tail] = {0, 0};
	for (int i = 1; i <= n; ++i)
		{
			int k = 2 * s[i];
			while (head + 1 <= tail && (1.0 * q[head].y - q[head + 1].y) / (1.0 * q[head].x - q[head + 1].x) - k < -eps)head++;
			ll b = q[head].y - k * q[head].x;
			dp[i] = b + (s[i] - l) * (s[i] - l);
			ll y = dp[i] + s[i] * s[i] + 2 * s[i] * l, x = s[i];
			while (head + 1 <= tail && (1.0 * q[tail - 1].y - y) / (1.0 * q[tail - 1].x - x) - (1.0 * q[tail - 1].y - q[tail].y) / (1.0 * q[tail - 1].x - q[tail].x) < -eps)tail--;
			q[++tail] = {x, y};
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
