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
	if (s[0] != s[2 * n - 1] || count(s.begin(), s.end(), '1') & 1)return cout << -1 << endl, void();
	vector<string>ans;
	for (int i = 1; i < 2 * n - 1; i += 2)if (s[i] != s[i + 1])
			{
				string tmp = "(";
				s[0] = (s[0] == '1' ? '0' : '1');
				bool fl = 0;
				for (int j = 1; j < 2 * n - 1; j += 2)
					{
						if (s[j] == s[j + 1])tmp += "()";
						else
							{
								if (fl)tmp += "))", fl = 0, s[j] = s[j + 1];
								else fl = 1, tmp += "((", s[j + 1] = s[j];
							}
					}
				tmp += ')';
				ans.push_back(tmp);
				break;
			}
	if (s[0] == '0')//to 1
		{
			string tmp = "(";
			for (int i = 1; i < 2 * n - 1; i += 2)
				{
					if (s[i] == '1')tmp += "()";
					else tmp += ")(", s[i] = s[i + 1] = '1';
				}
			tmp += ')';
			ans.push_back(tmp);
		}
	string tmp = "(";
	for (int i = 1; i < 2 * n - 1; i += 2)
		{
			if (s[i] == '1')tmp += ")(";
			else tmp += "()";
		}
	tmp += ')';
	ans.push_back(tmp);
	cout << (int)ans.size() << endl;
	for (auto v : ans)cout << v << endl;
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
