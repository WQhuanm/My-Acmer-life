#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 30;
bool vis[N][N];
void bfs()
{
	queue<int>q;
	q.push(13);
	while (!q.empty())
		{
			int j = q.front();
			q.pop();
			if (j == 2)
				{
					cout << "Yes." << endl;
					memset(vis, 0, sizeof(vis));
					return ;
				}
			for (int i = 1; i <= 26; ++i)if (vis[i][j])
					{
						vis[i][j] = 0;
						q.push(i);
					}
		}
	cout << "No." << endl;
	memset(vis, 0, sizeof(vis));
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	while (cin >> s)
		{
			if (s[0] == '0')bfs();
			else
				{
					int	i = s[0] - 'a' + 1;
					int j = s[(int)s.size() - 1] - 'a' + 1;
					vis[i][j] = 1;
				}

		}

}
