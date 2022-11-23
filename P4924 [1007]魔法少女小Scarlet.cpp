#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 510;

int a[510][510];
void shun(int x, int y, int r) //顺就是存左上，放右上
{
	queue<int>q;
	for (int k = 1; k <= r; ++k)
		{
			int i = x + k, j = y - k;
			while (j <= y + k)
				{
					q.push(a[i][j]);
					j++;
				}
			i--;
			j--;
			while (i >= x - k)
				{
					q.push(a[i][j]);
					i--;
				}
			j--;
			i++;
			while (j >= y - k)
				{
					q.push(a[i][j]);
					j--;
				}
			i++;
			j++;
			while (i < x + k)
				{
					q.push(a[i][j]);
					i++;
				}

			i = x + k, j = y + k;
			while (i >= x - k)
				{
					a[i][j] = q.front();
					q.pop();
					i--;
				}
			i++;
			j--;
			while (j >= y - k)
				{
					a[i][j] = q.front();
					q.pop();
					j--;
				}
			j++;
			i++;
			while (i <= x + k)
				{
					a[i][j] = q.front();
					q.pop();
					i++;
				}
			i--;
			j++;
			while (j < y + k)
				{
					a[i][j] = q.front();
					q.pop();
					j++;
				}
		}

}

void ni(int x, int y, int r)
{
	queue<int>q;
	for (int k = 1; k <= r; ++k)
		{

			int	i = x + k, j = y + k;
			while (i >= x - k)
				{
					q.push(a[i][j]);
					cout << q.front() << endl;
					i--;
				}
			i++;
			j--;
			while (j >= y - k)
				{
					q.push(a[i][j]);
					j--;
				}
			j++;
			i++;
			while (i <= x + k)
				{
					q.push(a[i][j]);
					i++;
				}
			i--;
			j++;
			while (j < y + k)
				{
					q.push(a[i][j]);
					j++;
				}

			i = x + k, j = y - k;
			while (j <= y + k)
				{
					a[i][j] = q.front();
					cout << q.front() << endl << endl;
					q.pop();

					j++;
				}
			i--;
			j--;
			while (i >= x - k)
				{
					a[i][j] = q.front();
					q.pop();

					i--;
				}
			j--;
			i++;
			while (j >= y - k)
				{
					a[i][j] = q.front();
					q.pop();

					j--;
				}
			i++;
			j++;
			while (i < x + k)
				{
					a[i][j] = q.front();
					q.pop();

					i++;
				}

		}

}

int main()
{
	int n, m;
	cin >> n >> m;
	int k = 1;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)a[i][j] = k++;
	int x, y, r, z;
	for (int i = 1; i <= m; ++i)
		{
			cin >> x >> y >> r >> z;
			if (z == 0)
				{
					ni(x, y, r);
				}
			else shun(x, y, r);
		}
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)
			{
				cout << a[i][j];
				if (j == n)cout << endl;
				else cout << ' ';
			}
	return 0;
}
