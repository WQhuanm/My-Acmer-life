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

void mysolve()
{
	set<string>st;
	string s;
	cin >> n >> m;
	vector<string>a, b;
	for (int i = 1; i <= n; ++i)
		{
			cin >> s;
			if (!st.count(s))a.push_back(s);
			st.insert(s);
		}
	st.clear();
	for (int i = 1; i <= m; ++i)
		{
			cin >> s;
			if (!st.count(s))b.push_back(s);
			st.insert(s);
		}
	reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
	vector<string>ans;
	st.clear();
	while (!a.empty() && !b.empty())
		{
			if (!st.count(a.back()))ans.push_back(a.back());
			st.insert(a.back()), a.pop_back();
			if (!st.count(b.back()))ans.push_back(b.back());
			st.insert(b.back()), b.pop_back();
		}
	while (!a.empty())
		{
			if (!st.count(a.back()))ans.push_back(a.back());
			st.insert(a.back()), a.pop_back();
		}
	while (!b.empty())
		{
			if (!st.count(b.back()))ans.push_back(b.back());
			st.insert(b.back()), b.pop_back();
		}
	for (auto v : ans)cout << v << endl;
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
