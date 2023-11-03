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

int n;
string s;
void mysolve()
{
	cin >> n >> s;
	vector<int>ans;
	int cnt = 0;
	if (n & 1)return cout << -1 << endl, void();
	while (1)
		{
			while (!s.empty() && *s.begin() != s.back())
				{
					s.pop_back();
					reverse(s.begin(), s.end());
					s.pop_back();
					reverse(s.begin(), s.end());
					cnt++;
				}
			if (s.empty())break;
			if (count(s.begin(), s.end(), '0') != count(s.begin(), s.end(), '1'))return cout << -1 << endl, void();
			if (s.front() == '0')
				{
					ans.push_back((int)s.size() + cnt);
					reverse(s.begin(), s.end());
					s.pop_back();
					reverse(s.begin(), s.end());
					s += '0';
				}
			else if (s.back() == '1')
				{
					ans.push_back(0+cnt);
					s.pop_back();
					reverse(s.begin(), s.end());
					s.push_back('1');
					reverse(s.begin(), s.end());
				}
			cnt++;
		}
	cout << ans.size() << endl;
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
