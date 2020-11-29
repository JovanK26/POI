#include <bits/stdc++.h>

using namespace std;
int n,d;
long long p;
int a[2000001];
long long f[2000001];
pair<long long,int> q[2000001];
bool check(int x)
{
    long long sum=0;
    for(int i=0;i<x;i++)
    {
        sum+=a[i];
    }
    int l,r;
    l=r=0;
    for(int i=0;i<=x-d;i++)
    {
        while(r>l && q[r-1].first<=f[i])r--;
        q[r++]={f[i],i};
    }
    if(sum-q[l].first<=p)return 1;
    for(int i=x;i<n;i++)
    {
        sum+=a[i]-a[i-x];
        while(r>l && q[r-1].first<=f[i-d+1])r--;
        q[r++]={f[i-d+1],i-d+1};
        if(q[l].second==i-x)l++;
        if(sum-q[l].first<=p)return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p >> d;
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<d;i++)
    {
        sum+=a[i];
    }
    f[0]=sum;
    for(int i=d;i<n;i++)
    {
        sum+=a[i]-a[i-d];
        f[i-d+1]=sum;
    }
    int l=d;
    int r=n;
    int m;
    while(l<=r)
    {
        m=(l+r)>>1;
        if(check(m))
        {
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    cout << l-1;
    return 0;
}
