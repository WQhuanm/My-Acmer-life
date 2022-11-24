#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

int myjudge(int a, int b)
{
	if (a == b)return 0;
	if (a == 0 && (b == 1 || b == 4))return -1;
	if (a == 0 && (b == 2 || b == 3))return 1;
	if (b == 0 && (a == 1 || a == 4))return 1;
	if (b == 0 && (a == 2 || a == 3))return -1;
	if (a == 1 && (b == 2 || b == 4))return -1;
	if (a == 1 && (b == 3))return 1;
	if (b == 1 && (a == 2 || a == 4))return 1;
	if (b == 1 && (a == 3))return -1;
	if (a == 2 && (b == 3))return -1;
	if (a == 2 && b == 4)return 1;
	if (b == 2 && (a == 3))return 1;
	if (b == 2 && a == 4)return -1;
	if (a == 3 && b == 4)return 1;
	if (b == 3 && a == 4)return -1;
}

int a1[N];
int b1[N];
int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	int suma = 0, sumb = 0;
	for (int i = 0; i < a; ++i)cin >> a1[i];
	for (int i = 0; i < b; ++i)cin >> b1[i];
	int k1 = 0, k2 = 0;
	for (int i = 1; i <= n; ++i)
		{
			int tmp = myjudge(a1[k1], b1[k2]);
			if (tmp == 1)suma++;
			if (tmp == -1)sumb++;
			k1++, k2++;
			k1 %= a, k2 %= b;
		}
	cout << suma << ' ' << sumb << endl;
	return 0;
}
