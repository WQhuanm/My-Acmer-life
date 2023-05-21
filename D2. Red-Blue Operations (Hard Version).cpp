#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF

const int N = 3e5 + 10;
int a[N],min1[N],min2[N],b[N];
void mysolve()
{
	int n,q;
	cin>>n>>q;
	for(int i=1; i<=n; ++i)cin>>a[i];
	sort(a+1,a+1+n);
	min1[1]=b[1]=a[1];
	int sum=b[1];
	for(int i=2; i<=n; ++i)b[i]=a[i]-i+1,min1[i]=min(b[i],min1[i-1]),sum+=b[i];
	min2[n+1]=llINF;
	for(int i=n; i; --i)min2[i]=min(a[i],min2[i+1]);
	int k;
	while(q--)
		{
			cin>>k;
			if(n==1)
				{
					cout<<a[1]-k/2+(k&1?k:0)<<" ";
					continue;
				}
			if(k<=n)cout<<min(min1[k]+k,min2[k+1])<<" ";
			else
				{
					int tmp=k-n+1;
					if((k-n)%2==0)
						{
							tmp--;
							tmp/=2;
							int res=sum+n*k-n*(min1[n]+k);
							tmp=max(tmp-res,0ll);
							cout<<min1[n]+k-(tmp+n-1)/n<<" ";
						}
					else
						{
							int minn=min(min1[n-1]+k,a[n]);
							int res=sum+n-1+(n-1)*k-n*minn;
							tmp/=2;
							tmp=max(tmp-res,0ll);
							cout<<minn-(tmp+n-1)/n<<" ";
						}
				}
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
