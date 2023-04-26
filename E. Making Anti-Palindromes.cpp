#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 2e5 + 10;

void mysolve()
{
	int n;
	string s;
	cin>>n>>s;
	if(n&1)
	{
		cout<<-1<<endl;
		return;
	}
	vector<int>cnt(26);
	int sum=0;
	for(int i=0; i<n/2; ++i)if(s[i]==s[n-1-i])cnt[s[i]-'a']++,sum++;
	int maxn=max_element(cnt.begin(),cnt.end())-cnt.begin();
	if(cnt[maxn]*2<=sum)cout<<(sum+1)/2<<endl;
	else if(cnt[maxn]>n/2)cout<<-1<<endl;
	else
	{
		int tmp=0;
		for(int i=0; i<n/2; ++i)if(s[i]!=s[n-1-i]&&s[i]!='a'+maxn&&s[n-1-i]!='a'+maxn)tmp++;
		if(sum+tmp>=2*cnt[maxn])cout<<cnt[maxn]<<endl;
		else cout<<-1<<endl;
	}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	while (t--)
	{
		mysolve();
	}
	system("pause");
	return 0;
}
