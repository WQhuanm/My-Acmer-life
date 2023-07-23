#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-8
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 5e5 + 10;
const int mod = 998244353;

struct node
{
	int num, row, sum, tmp, p, lim; //一行格子数，有几行，一行的价值，残余行还有几格，残余行第一格的前一格,一行最高度
};

pii a[N], b[N];
int t[N], t2[N];
ll ans[N];
int n;

void add(int x, int w)
{
	for (int i = x; i <= n; i += i & -i)t[i] += w, t2[i] += w * a[x].second;
}

int ask_num(int x)
{
	int ans = 0;
	for (int i = x; i; i -= i & -i)ans += t[i];
	return ans;
}
ll ask_sum(int x)
{
	ll ans = 0;
	for (int i = x; i; i -= i & -i)ans += t2[i];
	return ans;
}

void mysolve()
{
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].first >> a[i].second;
			add(i, 1);
			sum += a[i].second;
			b[i].second = i, b[i].first = a[i].first;
		}
	sort(b + 1, b + 1 + n);
	int num = n;
	deque<node>q;
	int  p = 0;
	for (int j = 1; j <= n; ++j)
		{
			int tmp = b[j].first;
			q.push_back({num, tmp - p, sum, 0, 0, tmp});
			while (j <= n && b[j ].first == tmp)sum -= a[b[j++ ].second].second, num--;
			p = tmp;
			j--;
		}
	p = 0;
	int j = 1;
	for (int i = 1; i <= n; ++i)
		{
			int res = a[i].first;
			while (res)
				{
					node u = q.front();
					q.pop_front();
					if (u.tmp)
						{
							if (res <= u.tmp)
								{
									if (res == u.tmp)ans[i] += ask_sum(n) - ask_sum(u.p), u.tmp = u.p = 0;
									else
										{
											int lcnt = ask_num(u.p);
											int l = 1, r = n;
											while (l <= r)
												{
													int mid = l + ((r - l) >> 1);
													int cnt = ask_num(mid);
													if (cnt - lcnt == res)
														{
															u.tmp -= res;
															ans[i] += ask_sum(mid) - ask_sum(u.p);
															u.p = mid;
															break;
														}
													else if (cnt - lcnt < res)l = mid + 1;
													else r = mid - 1;
												}
										}
									res = 0;
								}
							else
								{
									ans[i] += ask_sum(n) - ask_sum(u.p), res -= u.tmp;
									u.tmp = u.p = 0;
								}
						}
					if (u.row)
						{
							int l = 0, r = u.row, cnt = 0;
							while (l <= r)
								{
									int mid = l + ((r - l) >> 1);
									if (mid * u.num <= res)cnt = mid, l = mid + 1;
									else r = mid - 1;
								}
							ans[i] += u.sum * cnt, res -= cnt * u.num, u.row -= cnt;
							if (u.row && res)
								{
									u.row--, u.tmp = u.num, u.p = 0;
									if (res == u.tmp)ans[i] += ask_sum(n) - ask_sum(u.p), u.tmp = u.p = 0;
									else
										{
											int lcnt = ask_num(u.p);
											int l = 1, r = n;
											while (l <= r)
												{
													int mid = l + ((r - l) >> 1);
													int cnt = ask_num(mid);
													if (cnt - lcnt == res)
														{
															u.tmp -= res;
															ans[i] += ask_sum(mid) - ask_sum(u.p);
															u.p = mid;
															break;
														}
													else if (cnt - lcnt < res)l = mid + 1;
													else r = mid - 1;
												}
										}
									res = 0;
								}
						}
					if (!u.row && !u.tmp)
						{
							p = u.lim;
							while (j <= n && b[j ].first == p)add(b[j++].second, -1);
						}
					else  q.push_front(u);
				}
			cout << ans[i] << " \n"[i == n];
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
