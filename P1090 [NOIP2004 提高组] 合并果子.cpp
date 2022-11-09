#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

int main()
{
	int n, k;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>>q;
	for (int i = 1; i <= n; ++i)
		{
			cin >> k;
			q.push(k);
		}
	ll sum = 0;
	int a;
	int b;
	while ((int)q.size() > 1)
		{
			a = q.top();
			q.pop();
			b = q.top();
			q.pop();
			q.push(a + b);
			sum += a + b;

		}
	cout << sum << endl;
	return 0;
}
