#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;

int a[210];
int n;
void print()
{
	for (int i = 1; i <= 2 * n + 2; ++i)
		{
			if (a[i] == 1)
				cout << "o";
			else if (a[i] == 2)cout << '*';
			else cout << '-';
		}
	cout << endl;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)a[i] = 1, a[i + n] = 2;
	print();
	int j = 2 * n + 2, k = n + 1;
	for (int i = 1; i <= (n - 2) * 2 - 3; ++i)
		{
			if (i & 1)
				{
					a[j] = a[k], a[j - 1] = a[k - 1];
					a[k] = a[k - 1] = 0;
					j -= 2;
				}
			else
				{
					a[k] = a[j], a[k - 1] = a[j - 1];
					a[j] = a[j - 1] = 0;
					k -= 1;
				}
			print();
		}
	++j;
	a[k] = a[j], a[k - 1] = a[j - 1];
	a[j] = a[j - 1] = 0;
	print();

	k -= 2;
	a[j] = a[k], a[j - 1] = a[k - 1];
	a[k] = a[k - 1] = 0;
	print();
	--j;
	a[k] = a[j], a[k - 1] = a[j - 1];
	a[j] = a[j - 1] = 0;
	print();
	--k;
	a[j] = a[k], a[j - 1] = a[k - 1];
	a[k] = a[k - 1] = 0;
	print();
	return 0;
}
