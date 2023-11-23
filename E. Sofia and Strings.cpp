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
vector<int>cnt[30];

void mysolve()
{
	cin >> n >> m >> s >> t;
	for (int i = 0; i < 26; ++i)cnt[i].clear();
	for (int i = 0; i < n; ++i)cnt[s[i] - 'a'].push_back(i);
	for (int i = 0; i < 26; ++i)reverse(cnt[i].begin(), cnt[i].end());
	for (auto v : t)
		{
			int c = v - 'a';
			if (cnt[c].empty())return cout << "NO" << endl, void();
			for (int i = 0; i < c; ++i)
				{
					while (!cnt[i].empty() && cnt[i].back() < cnt[c].back())cnt[i].pop_back();
				}
			cnt[c].pop_back();
		}
	cout << "YES" << endl;
}

signed main()
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
