#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

void mysolve()
{
	int n, x;
	priority_queue<int>q1;//大堆，存小值（左区间）
	priority_queue<int, vector<int>, greater<int>>q2; //小堆（右区间）
	map<ll, ll>mp;
	cin >> n;
	ll sum1 = 0, sum2 = 0; //sum1累积元素和，sum累积元素平方和（后面方差可以用）
	int num = 0, t = 0;
	for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			sum1 += x, sum2 += x * x;
			mp[x]++;
			if (mp[x] >= num)
				{
					if (mp[x] > num)num = mp[x], t = x;
					else t = max(t, x);
				}
			//接下来维护两个堆
			q1.push(x);
			if (q2.size() && q1.top() > q2.top())//大堆的最大比小堆的最小还要大，交换
				{
					int maxn = q1.top(), minn = q2.top();
					q1.pop(), q2.pop();
					q1.push(minn), q2.push(maxn);
				}
			if (q1.size() > q2.size() + 1) //始终维持两个堆元素量差值1
				{
					int tmp = q1.top();
					q1.pop();
					q2.push(tmp);
				}
			if (i & 1)
				{
					double k = sum1 * 1.0 / i; //除法不要忘记1.0
					double cha = sum2 * 1.0 / i - 2 * sum1 * k * 1.0 / i + k * k;
					printf("%.7lf %.7lf %lld %lld\n", k, cha, q1.top(), t);
				}

		}
}

int32_t main()
{

	ll t;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
