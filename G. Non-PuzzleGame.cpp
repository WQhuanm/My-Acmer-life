#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 1e6 + 10;
int n, k;
int b[N], pre[N];
int a[N];
void insert(ll x)
{
	for (int i = 30; ~i; --i)if (x & (1 << i)) //从高位到低位尝试插入
			{
				if (!a[i]) //线性基该位置未被插入即可插入后退出
					{
						a[i] = x;
						return;
					}
				else x ^= a[i];
			}
}

void mysolve()
{
	cin >> n >> k;
	for (int i = 30; ~i; --i)a[i] = 0;
	pre[0] = 1;
	for (int i = 1; i <= 70; ++i)pre[i] = min(n + 10, pre[i - 1] * 2);
	map<int, int>mp;
	for (int i = 1; i <= n; ++i)cin >> b[i], mp[b[i]] = 1;
	for (int i = 1; i <= n; ++i)
		{
			if (mp.count(k ^ b[i]))
				{
					cout << "Alice" << endl;
					return;
				}
		}
	int cnt = 0;
	for (int i = 1; i <= n; ++i)b[i] ^= k, insert(b[i]);
	for (int i = 30; ~i; --i)cnt += (a[i] ? 1 : 0);
	if (pre[cnt] == (int)mp.size())
		{
			cout << "Bob" << endl;
			return;
		}
	cout << "Draw" << endl;
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

