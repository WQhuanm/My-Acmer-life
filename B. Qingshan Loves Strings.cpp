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
const int N = 3e5 + 10;

int n, m;
string s, t;
void mysolve()
{
	cin >> n >> m >> s >> t;
	int cnt = 0;
	for (int i = 0; i < n - 1; ++i)if (s[i] == s[i + 1])cnt++;
	for (int i = 0; i < m - 1; ++i)if (t[i] == t[i + 1] && cnt)return cout << "NO" << endl, void();
	char l = t[0], r = t[m - 1];
	for (int i = 0; i < n - 1; ++i)if (s[i] == s[i + 1])
			{
				if (s[i] == l || s[i + 1] == r)return cout << "NO" << endl, void();
			}
	cout << "YES" << endl;
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
