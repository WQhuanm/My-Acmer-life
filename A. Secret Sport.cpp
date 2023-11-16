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
	s = '$' + s;
	int a = 0, b = 0;
	for (int i = 1; i <= n; ++i)
		{
			int win = 1, cnt = 0, cnt2 = 0, A = 0, B = 0;
			for (int j = 1; j <= n; ++j)
				{
					if (s[j] == 'A')cnt++;
					else cnt2++;
					if (cnt == i)A++, win = 1, cnt = cnt2 = 0;
					else if (cnt2 == i)B++, win = 2, cnt = cnt2 = 0;
				}
			if (!cnt && !cnt2)
				{
					if (win == 1 && A > B)a++;
					else if (win == 2 && A < B)b++;
				}
		}
	if (a && b)cout << "?" << endl;
	else if (a)cout << "A" << endl;
	else cout << "B" << endl;
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
