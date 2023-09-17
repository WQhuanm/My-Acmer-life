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
//const int mod = 998244353;
const int N = 3e6 + 10;

ll x, y, z, b, mod;
int m, n, len;

ll s[N], t[N];

vector<int> prefix()
{
	vector<int>p((int)n + 1);
	p[1] = 0;
	for (int i = 2; i <= n; ++i)
		{
			int j = p[i - 1];
			while (j && s[i] != s[j + 1])j = p[j]; //找到匹配的最长前缀长度j
			if (s[i] == s[j + 1])++j;
			p[i] = j;
		}
	y = p[n];
	return p;
}

int kmp() //a模板串，b匹配串
{
	vector<int>p = prefix(); //先求匹配串的前缀函数
	int j = 0;//j指针指向b字符串
	int cnt = 0;
	for (int i = 1; i <= len; ++i)
		{
			while (j && t[i] != s[j + 1])
				j = p[j ]; //找到当前匹配的最长长度
			if (t[i] == s[j + 1])++j;
			if (j == n)//j指向'\0',匹配成功
				{
					cnt++;
				}
		}
	return cnt;
}

void mysolve()
{
	cin >> n >> m >> b >> mod;
	ll ans = 0;
	int op, xs, c;
	ll sum = 1;
	for (int i = 1; i <= n; ++i)cin >> s[i];
	while (m--)
		{
			cin >> op;
			if (op == 1)
				{
					cin >> xs >> c;
					xs = (xs ^ z) % n + 1, c = c ^ z;
					s[xs] = c;
				}
			else
				{

					cin >> len;
					for (int i = 1; i <= len; ++i)cin >> t[i], t[i] ^= z;
					sum = sum * b % mod;
					if (len < n)
						{
							x = y = z = 0;
						}
					else
						{
							x = kmp();
							ans = (ans + x * y % mod * sum % mod) % mod;
							z = x * y;
						}

				}
		}
	cout << ans << endl;
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
