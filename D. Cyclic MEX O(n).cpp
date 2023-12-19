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
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 1e6 + 10;

int n;
int a[N];
bool vis[N];
void mysolve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> a[i], vis[i] = 0;
	vis[n]=0;
	deque<pii>q;
	int mex = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i)
		{
			vis[a[i]] = 1;
			while (vis[mex])mex++;
			q.push_back({mex, 1});
			sum += mex;
		}
	int ans = sum;
	for (int i = 0; i < n; ++i)
		{
			pii now = {a[i], 0};
			while (!q.empty() && q.back().first >= a[i])
				{
					sum -= q.back().first * q.back().second;
					now.second += q.back().second;
					q.pop_back();
				}
			sum += now.first * now.second;
			q.push_back(now), q.push_back({n, 1});
			sum += n;
			ans = max(ans, sum);
		}
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
