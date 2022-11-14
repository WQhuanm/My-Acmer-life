#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

//思路，|运算，那么可以通过把a，b部分全部补上1，使得a|x==b|x==x，同时满足x整除d，那么只需要使x不断由的倍数累加获得就好，即，我在把x的0变为1时，是使用d的1去填充（使用d的最后一个1比较方便

int judgem(ll x)//找出x二进制后面有几个0
{
	int k = 0;
	for (k = 0; k < 32 && !((x >> k) & 1); ++k);
	//cout << k << endl;
	return k;
}

void mymin()
{
	ll a, b, d;
	cin >> a >> b >> d;
	ll k = judgem(d);
	if (k > judgem(a) || k > judgem(b))//如果a或者b的最后一个1比d还要考前，那我们保证无法整除
		{
			cout << -1 << endl;
			return ;
		}//我们保证，接下来一定有解，因为我们一定可以通过一定步骤使包含a，b的位数全为1，且x由d获得
	ll x = 0;
	for (ll i = k; i < 30; ++i) //对x的0到29位操作，开小不行，因为a，b为30位数，开大不行，因为极端情况，d为30位，那么x移动超过30次，则会超出自己60位的范围
		{
			//i=k开始，使x最开始等于d，然后我们保证获得后刚刚指向d的最前面一个1，接着往下走，只要第i位为0，那么就加上d向右移动i-k位（注意，d的第一个1在第k位，所以是i-k
			if (!((x >> i) & 1))x += (d << (i - k));
		}
	cout << x << endl;

}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
		{
			mymin();
		}
	system("pause");
	return 0;
}
