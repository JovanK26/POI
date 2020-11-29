#include <bits/stdc++.h>

using namespace std;
int n,m;
vector<int> v[500001];
int a[500001];
int query(int l,int r,int pos)
{
    return upper_bound(v[pos].begin(),v[pos].end(),r)-lower_bound(v[pos].begin(),v[pos].end(),l);
}
int main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    int l,r;
    for(int i=0;i<m;i++)
    {
        cin >> l >> r;
        bool check=0;
        for(int j=0;j<25;j++)
        {
            int uzi=uniform_int_distribution<int>(l,r)(rng);
            if(query(l,r,a[uzi])>(r-l+1)/2)
            {
                check=1;
                cout << a[uzi]<<'\n';
                break;
            }
        }
        if(!check)
        {
           cout << 0 <<'\n';
        }
    }
    return 0;
}
