#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 12;
char a[N][N];
int way[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int main()
{
	int x1, x2, y1, y2;
	for (int i = 1; i <= 10; ++i)for (int j = 1; j <= 10; ++j)
			{
				cin >> a[i][j];
				if (a[i][j] == 'C')
					{
						x1 = i, y1 = j;
					}
				if (a[i][j] == 'F')
					{
						x2 = i, y2 = j;
					}
			}
	//if(y1==y2&&abs(x1-x2)==1){cout<<0<<endl;return 0;}
	int sum = 0;
	int c = 0, f = 0;
	while (1)
		{
			int tmpx = x1 + way[c][0], tmpy = y1 + way[c][1];
			if (tmpx >= 1 && tmpx <= 10 && tmpy >= 1 && tmpy <= 10 && a[tmpx][tmpy] != '*')
				{
					x1 = tmpx, y1 = tmpy;
				}
			else
				{
					c += 1;
					c %= 4;
				}
			tmpx = x2 + way[f][0], tmpy = y2 + way[f][1];
			if (tmpx >= 1 && tmpx <= 10 && tmpy >= 1 && tmpy <= 10 && a[tmpx][tmpy] != '*')
				{
					x2 = tmpx, y2 = tmpy;
				}
			else
				{
					f += 1;
					f %= 4;
				}
			sum++;
			if (x1 == x2 && y1 == y2)
				{
					cout << sum << endl;
					return 0;
				}
			if (sum > 300)
				{
					cout << 0 << endl;
					return 0;
				}
		}
	return 0;
}
