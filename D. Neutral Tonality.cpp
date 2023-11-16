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
const int N = 1e6 + 10;

int n, m;
int a[N], b[N];

void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i <= m; ++i)cin >> b[i];
	sort(b + 1, b + 1 + m, greater<int>());
	int p = 1;
	vector<int>lis, ans; //这里求的是严格递增lis
	lis.push_back(0);
	for (int i = 1; i <= n; ++i)
		{

			if (lis.empty() || a[i] > lis.back())lis.push_back(a[i]); //严格递增你如果要放最后，那你必须>lis数组当前最后一个，如果是单调不下降则是>=
			else lis[lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin()] = a[i]; //严格递增如果你要替换，那么如果有相等的，必须替换掉，否则会出现=的情况，所以用lower_bound.如果是单调不下降，用upper_bound，即允许=存在
			while (p <= m && (int)lis.size() > 1 && b[p] >= lis.back())ans.push_back(b[p++]);
			ans.push_back(a[i]);
		}
	while (p <= m)ans.push_back(b[p++]);
	for (auto v : ans)cout << v << " ";
	cout << endl;
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
