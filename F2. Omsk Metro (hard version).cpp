#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int ll
const int N = 2e5 + 10;

struct tree
{
	int lmx, lmn, rmx, rmn, mx, mn, sum;
	tree(int x = 0)
	{
		lmx = rmx = mx = max(0ll, x);
		rmn = mn = lmn = min(0ll, x);
		sum = x;
	}
	tree operator+(const tree&k)
	{
		tree t;
		t.lmx = max(lmx, sum + k.lmx);
		t.lmn = min(lmn, sum + k.lmn);
		t.rmn = min(k.rmn, k.sum + rmn);
		t.rmx = max(k.rmx, k.sum + rmx);
		t.mx = max({mx, k.mx, rmx + k.lmx});
		t.mn = min({mn, k.mn, rmn + k.lmn});
		t.sum = sum + k.sum;
		return t;
	}
};

tree ans[N][32];
int dep[N], pre[N][32];
int  tot;
int lg = 18;

tree LCA(int u, int v)
{
	tree a, b ;
	if (dep[v] != dep[u])//不相等时才求，否则出现log2(0)
		{
			if (dep[u] < dep[v])swap(u, v); //始终让u深度大
			for (int i = lg ; ~i; --i)if (dep[pre[u][i]] >= dep[v])
					{
						a = a + ans[u][i];
						u = pre[u][i];
					}
		}
	if (u == v)
		{
			a = a + ans[u][0];
		}
	else
		{
			for (int i = lg ; ~i; --i)
				{
					if (pre[u][i] != pre[v][i])
						{
							a = a + ans[u][i], b = b + ans[v][i];
							u = pre[u][i];
							v = pre[v][i];
						}
				}
			a = a + ans[u][1], b = b + ans[v][0];
		}
	swap(b.lmx, b.rmx), swap(b.lmn, b.rmn);
	a =  a + b;
	return a; //儿子的父亲才是LCA
}

void mysolve()
{
	int n;
	cin >> n;
	tot = 1;
	dep[1] = 1;
//	vector<int> dep(n + 2);
	ans[1][0] = tree(1);
	char op;
	int x, y, k;
	for (int i = 1; i <= n; ++i)
		{
			cin >> op >> x >> y;
			if (op == '+')
				{
					dep[++tot] = dep[x] + 1, pre[tot][0] = x;
					ans[tot][0] = tree(y);
					for (int i = 1; i <= lg; ++i)
						{
							pre[tot][i] = pre[pre[tot][i - 1]][i - 1];
							ans[tot][i] = ans[tot][i - 1] + ans[pre[tot][i - 1]][i - 1];
						}
				}
			else
				{
					cin >> k;
					tree tmp = LCA(x, y);
					if (tmp.mn <= k && k <= tmp.mx)cout << "YES" << endl;
					else cout << "NO" << endl;
				}
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
