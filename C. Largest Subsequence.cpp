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
const int N = 3e5 + 10;

int nx[N][26];
void init(string &s)//s从1~n
{
	int len = (int)s.size() - 1;
	memset(nx[len], -1, sizeof(nx[len]));
	for (int i = len ; i; --i)memcpy(nx[i - 1], nx[i], sizeof(nx[i - 1])), nx[i - 1][s[i] - 'a'] = i;//从后往前更新，只更新当前点，其余继承
}
//使用时从0开始，寻找到-1则没有了


int n;
string s;
void mysolve()
{
	cin >> n >> s;
	string t = s;
	s = '$' + s;
	init(s);
	vector<int>now;
	vector<char>tmp;
	for (int i = 0; i <= n; ++i)
		{
			for (int k = 25; ~k; --k)if (~nx[i][k])
					{
						tmp.push_back('a' + k);
						now.push_back(nx[i][k]);
						i = nx[i][k] - 1;
						break;
					}
		}
	reverse(tmp.begin(), tmp.end());
	int cnt = 0, len = (int)now.size();
	for (int i = 0; i < len; ++i)
		{
			s[now[i]] = tmp[i];
			if (tmp[i] != tmp.back())cnt++;
		}
	sort(t.begin(), t.end());
	t = '$' + t;
	if (t == s)cout << cnt << endl;
	else cout << -1 << endl;

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
