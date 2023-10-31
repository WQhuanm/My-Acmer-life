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
	vector<int>now;
	for (int i = 0; i < n; ++i)if (s[i] == '0')now.push_back(i);
	int p = -1;
	vector<int>ans;
	for (int i = n - 1; i >= 0; --i)
		{
			if (s[i] == '0')ans.push_back(0),now.pop_back();
			else
				{
					p = i;
					break;
				}
		}
	int sum = 0;
	while (p >= 0)
		{
			if (now.empty())break;
			sum += p - now.back();
			now.pop_back();
			ans.push_back(sum);
			p--;
		}
	while ((int)ans.size() < n)ans.push_back(-1);
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
