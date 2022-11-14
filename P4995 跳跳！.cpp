#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

ll a[N];
bool cmp(ll x, ll y)
{
	return x > y;
}
int main()
{
	ll n;
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	ll sum = 0;
	ll left = 1, right = n;
	sum += a[left] * a[left];
	int len = 1;
	while (left <= right)
		{
			sum += (a[left] - a[right]) * (a[left] - a[right]);
			if (len & 1)left++;
			else right--;
			len++;
		}

//	while (left <= right)
//		{
//			sum += a[left] * a[left];
//			if (left > right * 2)
//				{
//					sum += (a[left] - a[right]) * (a[left] - a[right]);
//				}
//			else sum += a[right] * a[right];
//			left++;
//			right--;
//		}
	cout << sum << endl;
	return 0;
}
