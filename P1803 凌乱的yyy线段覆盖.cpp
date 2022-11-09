#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e6 + 100;

struct ti
{
	int a, b;
	bool operator <(const ti&k)const
	{
		return b < k.b;
	}
} a[N];
int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].a >> a[i].b;

		}
	sort(a + 1, a + 1 + n);
	int count = 0;
	int t = -1;
	for (int i = 1; i <= n; ++i)
		{
			if (t <= a[i].a)
				{
					count++;
					t = a[i].b;
				}
		}
	cout << count << endl;
	return 0;
}
