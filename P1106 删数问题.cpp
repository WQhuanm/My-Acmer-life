#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

char a[N];
int main()
{
	cin >> a;
	int k;
	cin >> k;
	int len = strlen(a);
	for (int i = 1; i < len; ++i)
		{
			if (k)
				{
					if (a[i] < a[i - 1])
						{
							k--;
							for (int j = i - 1; j < len - 1; ++j)a[j] = a[j + 1];
							a[len - 1] = '\0';
							len--;
							i -= 2;
							//	cout << a << endl << endl;
						}

				}
			else break;
		}
	while (k)
		{
			k--;
			a[len - 1] = '\0';
			len--;
		}
	int flag = 1;
	for (int i = 0; i < len; ++i)
		{
			if (flag)
				{
					if (a[i] != '0')
						{
							flag = 0;
							cout << a[i];
						}
				}
			else cout << a[i];
		}
	if (flag)cout << 0 << endl;
	return 0;
}
