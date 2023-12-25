#include <bits/stdc++.h>
using namespace std;
#define endl             "\n"
const int N = 1e6 + 5;

const int lg = 21;
int n;
int nx[N], t[N], bc[N];

struct node
{
	priority_queue<int, vector<int>, greater<int>>q, p;
	void insert(int x)
	{
		q.push(x);
	}
	void erase(int x)
	{
		if (x == q.top())
			{
				q.pop();
				while (!p.empty() && p.top() == q.top())q.pop(), p.pop();
			}
		else p.push(x);
	}
	bool empty()
	{
		return q.empty();
	}
	int top()
	{
		return q.top();
	}
	int size()
	{
		return (int)q.size() - (int)p.size();
	}
} b[N];

void add(int x, int w)
{
	for (int i = x; i <= n; i += i & -i)t[i] += w;
}

int ask(int x)
{
	int ans = 0;
	for (int i = x; i; i -= i & -i)ans += t[i];
	return ans;
}

int find(int x)
{
	if (nx[x] != x)nx[x] = find(nx[x]);
	return nx[x];
}

int find2(int x)
{
	if (bc[x] != x)bc[x] = find2(bc[x]);
	return bc[x];
}
string s;
void mysolve()
{
	cin >> n >> s;
	s = '$' + s;
	nx[n + 1] = n + 1;
	for (int i = 1; i <= n; ++i)
		{
			add(i, 1), nx[i] = bc[i] = i;
			if (s[i] == '1')
				{
					int now = 0;
					for (int j = i; j <= n; ++j)
						{
							now = now * 2 + (s[j] == '1' ? 1 : 0);
							if (now > n)break;
							b[now].insert(i);
						}
				}
		}
	for (int i = 1; i <= n; ++i)
		{
			if (b[i].empty())cout << -1 << " " << 0 << endl;
			else
				{
					int id = b[i].top();
					cout << ask(id) << " " << b[i].size() << endl;
					for (int l = find2(id - 1), cnt = lg; l >= 1 && cnt; l = find2(l - 1), cnt--)if (nx[l] == l && s[l] == '1') //clear
							{
								int now = 0;
								for (int r = l; r <= n; r = find(r + 1))
									{
										now = now * 2 + (s[r] == '1' ? 1 : 0);
										if (now > n)break;
										if (now > i)b[now].erase(l);
									}
							}
					int now = 0;
					for (int l = id; l <= n; l = find(l + 1))
						{
							now = now * 2 + (s[l] == '1' ? 1 : 0);
							if (nx[l] == l && s[l] == '1')
								{
									int sum = 0;
									for (int r = l; r <= n; r = find(r + 1))
										{
											sum = sum * 2 + (s[r] == '1' ? 1 : 0);
											if (sum > n)break;
											if (sum > i)b[sum].erase(l);
										}
								}
							if (now == i)break;
						}
					now = 0;
					for (int p = id; p <= n; p = find(p + 1))
						{
							now = now * 2 + (s[p] == '1' ? 1 : 0);
							add(p, -1), nx[p] = find(p + 1), bc[p] = find2(p - 1);
							if (now == i)break;
						}
					for (int l = find2(id - 1), cnt = lg; l >= 1 && cnt; l = find2(l - 1), cnt--)if (nx[l] == l && s[l] == '1') //add new
							{
								int now = 0;
								for (int r = l; r <= n; r = find(r + 1))
									{
										now = now * 2 + (s[r] == '1' ? 1 : 0);
										if (now > n)break;
										if (now > i)b[now].insert(l);
									}
							}
				}
		}
}

int32_t main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
