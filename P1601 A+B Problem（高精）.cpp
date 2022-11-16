#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 1100;

int a[N];
int b[N];

void stringint(char x[], char y[])
{
	a[0] = strlen(x);
	b[0] = strlen(y);
	int len1 = a[0], len2 = b[0];
	for (int i = 1; i <= a[0]; ++i)
		{
			a[i] = x[--len1] - '0';
		}
	for (int i = 1; i <= b[0]; ++i)
		{
			b[i] = y[--len2] - '0';
		}
}

void addt()
{
	int flag = 0;
	int len = a[0] > b[0] ? a[0] + 1 : b[0] + 1;
	for (int i = 1; i <= len; ++i)
		{
			int tmp = a[i] + b[i] + flag;
			a[i] = tmp % 10;

			flag = tmp / 10;
		}
	a[0] = len;
	while (!a[len] && len > 1)
		{
			a[0]--;
			len--;
		}

}

int main()
{
	char a1[N];
	char b1[N];
	cin >> a1 >> b1;
	stringint(a1, b1);
	addt();
	int len = a[0];
	while (len)
		{
			cout << a[len];
			len--;
		}
	return 0;
}
