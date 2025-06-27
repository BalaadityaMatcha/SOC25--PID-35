#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
int mod = 1e9 + 7;

ll power(ll a, ll b, ll mod = mod) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin >> n >> m;
    ll fac=1,invfac=1; // n+m-1 c n-1
    ll up = n+m-1;
    int dn = max(n-1,m)+1;
    for(int i=dn;i<=up;i++){
        fac=(fac*i)%mod;
        invfac = (invfac*(power(i-dn+1,mod-2)))%mod;
    }
    cout << (fac*invfac)%mod << "\n";
    return 0;
}