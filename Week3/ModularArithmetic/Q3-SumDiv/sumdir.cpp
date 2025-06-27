#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
ll mod = 1e9 + 7;
ll x_y(ll x,ll y,ll m=mod){
    if((!x && !y) || x==1) return 1;
    ll res=1;
    while(y>0){
        if(y%2){res = (1LL * res * x)%m;}
        x = 1LL * x * x % m;
        y/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll a,b; cin >> a >> b;
    vector<ll> divisors;
    for(ll i=2;i<=sqrt(a);i++){
        if(a%i==0){
            divisors.push_back(i);
            if(i != a/i) divisors.push_back(a/i);
        }
    }
    int ans=0;
    for(auto x:divisors){
        ll x_b = (x_y(x,b+1)-1+mod)%mod;
        ll y = (x_b*(x_y(x-1,mod-2)))%mod;
        ans=(ans+y)%mod;
    }
    if(divisors.size()==0){
        ll a_b = (x_y(a,b+1)-1+mod)%mod;
        ll y = (a_b*(x_y(a-1,mod-2)))%mod;
        ans=(ans+y)%mod;
    }
    cout << ans;
    return 0;
}