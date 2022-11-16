#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e6 + 100;

int a[N][5];
int b[N][5];
int main()
{
	char c;
	int k1 = 1, k2 = 1;
	while (1)
		{
			c = getchar();
			//	cout << c << endl << endl;
			if (c == 'W')
				{
					a[k1][0]++;
					b[k2][0]++;
					if ((a[k1][0] >= 11 || a[k1][1] >= 11) && (abs(a[k1][0] - a[k1][1]) >= 2))k1++;
					if ((b[k2][0] >= 21 || b[k2][1] >= 21) && (abs(b[k2][0] - b[k2][1]) >= 2))k2++;
				}
			else if (c == 'L')
				{
					a[k1][1]++;
					b[k2][1]++;
					if ((a[k1][0] >= 11 || a[k1][1] >= 11) && (abs(a[k1][0] - a[k1][1]) >= 2))k1++;
					if ((b[k2][0] >= 21 || b[k2][1] >= 21) && (abs(b[k2][0] - b[k2][1]) >= 2))k2++;
				}
			else if (c == 'E')
				{
					break;
				}

		}
	//cin>>h;
	for (int i = 1; i <= k1; ++i)cout << a[i][0] << ':' << a[i][1] << endl;
	cout << endl;
	for (int i = 1; i <= k2; ++i)cout << b[i][0] << ':' << b[i][1] << endl;

	return 0;
}
