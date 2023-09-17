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

int n, m, k;
int x[N];
vector<int>v[N];
void mysolve()
{
	cin >> m >> n >> k;
	int ans = 0;
	for (int i = 1; i <= n; ++i)cin >> x[i], v[i % k].push_back(x[i] - x[i - 1] - 1);
	for (int i = 0; i < k; ++i)
		{
			reverse(v[i].begin(), v[i].end());
			for (int j = 0; j < (int)v[i].size(); j += 2)ans ^= v[i][j];
		}
	if (ans)cout << "Twinkle" << endl;
	else cout << "Nova" << endl;
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
