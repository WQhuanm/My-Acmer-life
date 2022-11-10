#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
const int mod = 998244353;

ll n, m;
ll a[N];
ll ans;
ll d;
vector<ll>v;
void prime(ll x)
{
	v.clear();
	for (int i = 2; i * i <= x; ++i)
		{
			if (!(x % i))
				{
					v.push_back(i);
					while (!(x % i))x /= i;
				}
		}
	if (x > 1)v.push_back(x);
}

void dfs(ll num, ll sum, ll len)
{
	if (num == (int)v.size())
		{
			if (len)
				{
					if (len & 1)ans += d / sum;
					else ans -= d / sum;
				}
			return ;
		}
	dfs(num + 1, sum, len);
	dfs(num + 1, sum * v[num], len + 1);

}

void msolve()
{
	int flag = 1;
	cin >> n >> m;
	ll sum = 1; //一定组合是乘积，初始值赋值0就寄了
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			if (i >= 2)if (a[i - 1] % a[i])flag = 0;//只要不符合，等下输出0
		}
	if (!flag)
		{
			cout << 0 << endl;
			return ;
		}
	for (int i = 2; i <= n; ++i)//从2开始，是因为1b1的只能是a1（一个数的质数当然是他本身，没有其他情况）
		{
			if (a[i] == a[i - 1])sum = (sum * (m / a[i])) % mod;//(m / a[i])这里括号，不用这里会WA，因为会乘法溢出，能先除就先除     //a[i] == a[i - 1]，说明bi就是ai的倍数，所以直接m/ai就是bi的个数
			else
				{
					prime(a[i - 1] / a[i]);
					ans = 0;//ans是每个bi的可以有的值的数量，每次记得初始化
					d = m / a[i];//b[i]/a[i]范围为（1，m/a[i]）
					dfs(0, 1, 0);//从遍历0个，存入0个，乘积为1开始
					sum = (sum * (d - ans)) % mod;
				}
		}
	cout << sum << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		{
			msolve();
		}
	return 0;
}
