#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
int MOD = 1e9 + 7;

vector<ll> fact = {1}, invfact = {1};

ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

void precompute(int n){
    int _size = fact.size();
    if(n+1 > _size){
        while(_size!=n+1){
            fact.push_back((fact[_size-1]*_size)%MOD);
            invfact.push_back((invfact[_size-1]*power(_size,MOD-2))%MOD);
            _size++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin >> n;
    while(n--){
        int a,b;cin >> a >> b;
        if(b == 0 || b == a){cout << "1\n";continue;}
        if(b == 1 || b == a-1){cout << a << "\n";continue;}
        
        precompute(a);
        ll ans = (fact[a]*(invfact[b]*invfact[a-b]%MOD))%MOD;
        cout << ans << "\n";
    }
    return 0;
}