#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;cin >> n >> m;
    int ats = n/m, rp = n%m;
    ll k_min = rp*((1LL*(ats+1)*(ats))/2) + (m-rp)*((1LL*(ats)*(ats-1))/2);
    ll k_max = (1LL*(n-m+1)*(n-m))/2;
    cout << k_min << " " << k_max;
    return 0;
}