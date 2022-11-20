#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

struct ren
{
	int point;
	char name[20];
} arr[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)cin >> arr[i].point >> arr[i].name;
	int a, b;
	int num = 0;
	for (int i = 1; i <= m; ++i)
		{
			cin >> a >> b;
			if (a == 0)
				{
					if (arr[num].point == 0)
						{
							num = (n + num - b) % n;
						}
					else if (arr[num].point == 1)
						{
							num = (n + num + b) % n;
						}
				}
			else
				{
					if (arr[num].point == 1)
						{
							num = (n + num - b) % n;
						}
					else if (arr[num].point == 0)
						{
							num = (n + num + b) % n;
						}
				}
			//cout << arr[num].name << endl;
		}
	cout << arr[num].name << endl;
	return 0;
}
