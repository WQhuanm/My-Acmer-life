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

int n;
int a[N];
void mysolve()
{
	cin >> n;
	int x, y;
	for (int i = 0; i <= n; ++i)cin >> x >> y, a[i] = (x + y) % 2;
	set<int>s[2];
	for (int i = 1; i <= n; ++i)
		{
			if (a[i] == a[0])s[0].insert(i);
			else s[1].insert(i);
		}
	if (s[0].size() >= s[1].size())
		{
			cout << "First" << endl;
			bool fl = 1;
			while (!s[0].empty() || !s[1].empty())
				{
					if (fl)
						{
							if (!s[1].empty())
								{
									cout << *s[1].begin() << endl;
									s[1].erase(s[1].begin());
								}
							else
								{
									cout << *s[0].begin() << endl;
									s[0].erase(s[0].begin());
								}
						}
					else
						{
							cin >> x;
							if (s[0].count(x))s[0].erase(x);
							else s[1].erase(x);
						}
					fl ^= 1;
				}
		}
	else
		{
			cout << "Second" << endl;
			bool fl = 0;
			while (!s[0].empty() || ! s[1].empty())
				{
					if (fl)
						{
							if (!s[0].empty())
								{
									cout << *s[0].begin() << endl;
									s[0].erase(s[0].begin());
								}
							else
								{
									cout << *s[1].begin() << endl;
									s[1].erase(s[1].begin());
								}
						}
					else
						{
							cin >> x;
							if (s[0].count(x))s[0].erase(x);
							else s[1].erase(x);
						}
					fl ^= 1;
				}
		}

}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
