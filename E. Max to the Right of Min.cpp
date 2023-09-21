#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 1e6 + 1;

int n;
int dp[N][21], lg[N];

#define ls p<<1
#define rs p<<1|1
#define mid  (L + ((R - L) >> 1))
struct tree
{
	int mx, p;
} t[N << 2];

void build(int L, int R, int p)
{
	if (L == R)
	{
		t[p].mx = dp[L][0], t[p].p = L;
		return;
	}
	build(L, mid, ls), build(mid + 1, R, rs);
	if (t[ls].mx > t[rs].mx)t[p].mx = t[ls].mx, t[p].p = t[ls].p;
	else t[p].mx = t[rs].mx, t[p].p = t[rs].p;
}

pii ask(int l, int r, int L, int R, int p)
{
	if (l <= L && R <= r)return {t[p].mx, t[p].p};
	pii ans = {0, 0};
	if (l <= mid)
	{
		pii tmp = ask(l, r, L, mid, ls);
		if (tmp.first > ans.first)ans = tmp;
	}
	if (r > mid)
	{
		pii tmp = ask(l, r, mid + 1, R, rs);
		if (tmp.first > ans.first)ans = tmp;
	}
	return ans;
}

#undef ls
#undef rs
#undef mid

int stask(int l, int r)
{
	int k = lg[r - l + 1];
	return min(dp[l][k], dp[r - (1 << k) + 1][k]); //区间查询
}

ll ans;
void solve(int l, int r)
{
	if (l >= r)return ;
	int ml, mr, mid = ask(l, r, 1, n, 1).second;
	solve(l, mid - 1), solve(mid + 1, r);
	ans += mid - l;
	if (mid - l <= r - mid)//枚举左边
	{
		for (int i = mid - 1; i >= l; --i)
		{
			ml = mid + 1, mr = r;
			int tmp = mid, now = stask(i, mid);
			while (ml <= mr)
			{
				int mmid = ml + ((mr - ml) >> 1);
				if (stask(mid, mmid) > now)tmp = mmid, ml = mmid + 1;
				else mr = mmid - 1;
			}
			ans += tmp - mid;
		}
	}
	else
	{
		for (int i = mid + 1; i <= r; ++i)
		{
			ml = l, mr = mid - 1;
			int tmp = l - 1, now = stask(mid + 1, i);
			while (ml <= mr)
			{
				int mmid = ml + ((mr - ml) >> 1);
				if (stask(mmid, mid) < now)tmp = mmid, ml = mmid + 1;
				else mr = mmid - 1;
			}
			ans += tmp - l + 1;
		}
	}
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> dp[i][0];
	for (int j = 1; j <= lg[n]; ++j)for (int i = 1; i + (1 << j) - 1 <= n; ++i)dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]); //预处理st表
	build(1, n, 1);
	solve(1, n);
	cout << ans << endl;
}

signed main()
{
	//		freopen("in.in", "r", stdin);
	//		freopen("out2.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	lg[1] = 0;
	for (int i = 2; i <= 1e6; ++i)lg[i] = lg[i >> 1] + 1; //预处理lg
	mysolve();
	return 0;
}
