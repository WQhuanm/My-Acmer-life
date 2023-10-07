#include <bits/stdc++.h>
using namespace std;
#define endl             "\n"
const int N = 1e6 + 10, M = 1e6;

set<int>b[N];
int t[N], a[N];
struct node
{
	bool fl;
	int pre, p;
} st[N];
int q, top;

void add(int x, int w)
{
	for (int i = x; i <= M; i += i & -i)t[i] += w;
}

int ask(int x)
{
	int ans = 0;
	for (int i = x; i; i -= i & -i)ans += t[i];
	return ans;
}

void mysolve()
{
	cin >> q;
	int x, p = 0;
	char c;
	while (q--)
		{
			cin >> c;
			if (c == '+')
				{
					cin >> x;
					st[++top] = {0, a[p + 1], p};
					if (a[p + 1])
						{
							int tmp = a[p + 1];
							b[tmp].erase(b[tmp].find(p + 1));
							if (b[tmp].empty() || p + 1 < *b[tmp].begin())
								{
									add(p + 1, -1);
									if (!b[tmp].empty())add(*b[tmp].begin(), 1);
								}
						}
					a[++p] = x;
					if (b[x].empty() || *b[x].begin() > p)
						{
							add(p, 1);
							if (!b[x].empty())add(*b[x].begin(), - 1);
						}
					b[x].insert(p);
				}
			else if (c == '-')
				{
					cin >> x;
					st[++top] = {1, 0, p};
					p -= x;
				}
			else if (c == '!')
				{
					if (st[top].fl == 1)p = st[top--].p;
					else
						{
							x = a[p];
							b[x].erase(b[x].find(p));
							if (b[x].empty() || *b[x].begin() > p)
								{
									add(p, -1);
									if (!b[x].empty())add(*b[x].begin(),  1);
								}

							a[p] = st[top--].pre;
							if (a[p])
								{
									if (b[a[p]].empty() || *b[a[p]].begin() > p)
										{
											add(p, 1);
											if (!b[a[p]].empty())add(*b[a[p]].begin(), - 1);
										}
									b[a[p]].insert(p);
								}
							p--;
						}
				}
			else
				{
					cout << ask(p) << endl;
				}
		}
}

int32_t main()
{
	mysolve();
	return 0;
}
