#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;

void msolve()
{
	int n;
	cin >> n;
	int ans = 0, tmp = 0, a, cnt = 0;
	for (int i = 0; i < 30; ++i)
		{
			int x = (1 << i);
			cout << "- " << x - tmp << endl;//每次减去x-tmp,保证每次都是给出n-x的二进制1个数
			cin >> a;
			if (a == -1)return;//-1说明错误直接下一个测试案例
			if (a == n - 1)//满足说明这一位有1
				{
					++cnt;
					ans += x;
				}
			if (cnt == n)//统计完所有1就可以退出了
				{
					cout << "! " << ans << endl;
					return;
				}
			tmp = x;//更新tmp
		}
}

int main()
{
	//互动题切忌解绑，否则会最后全部输出，等于无法互动
	int t;
	cin >> t;
	while (t--)
		{
			msolve();
		}
	return 0;
}
