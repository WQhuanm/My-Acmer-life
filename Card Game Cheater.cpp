#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 30;

struct node
{
	int x, y;
	bool operator<(const node &k)const
	{
		if (x != k.x)
			{
				return x > k.x;
			}
		else return y > k.y;
	}

} a[N], b[N];

bool mjudge(node a, node b)
{
	if (a.x > b.x)return 0;
	else if (a.x == b.x)
		{
			if (a.y >= b.y)return 0;
		}
	return 1;
}

int main()
{
	int t, n;
	cin >> t;
	while (t--)
		{
			cin >> n;
			string s;
			for (int i = 1; i <= n; ++i)
				{
					cin >> s;
					if (s[0] >= '2' && s[0] <= '9')a[i].x = s[0] - '0';
					else if (s[0] == 'T')a[i].x = 10;
					else if (s[0] == 'J')a[i].x = 11;
					else if (s[0] == 'Q')a[i].x = 12;
					else if (s[0] == 'K')a[i].x = 13;
					else a[i].x = 20;

					if (s[1] == 'C')a[i].y = 1;
					else if (s[1] == 'D')a[i].y = 2;
					else if (s[1] == 'S')a[i].y = 3;
					else a[i].y = 10;
				}
			for (int i = 1; i <= n; ++i)
				{
					cin >> s;
					if (s[0] >= '2' && s[0] <= '9')b[i].x = s[0] - '0';
					else if (s[0] == 'T')b[i].x = 10;
					else if (s[0] == 'J')b[i].x = 11;
					else if (s[0] == 'Q')b[i].x = 12;
					else if (s[0] == 'K')b[i].x = 13;
					else b[i].x = 20;

					if (s[1] == 'C')b[i].y = 1;
					else if (s[1] == 'D')b[i].y = 2;
					else if (s[1] == 'S')b[i].y = 3;
					else b[i].y = 10;
				}
			sort(a + 1, a + 1 + n);
			sort(b + 1, b + 1 + n);
			int j = 1, ans = 0;
			for (int i = 1; i <= n; ++i)
				{
					if (mjudge(a[i], b[j]))
						{
							++ans, ++j;
						}

				}
			cout << ans << endl;
		}

	return 0;
}
