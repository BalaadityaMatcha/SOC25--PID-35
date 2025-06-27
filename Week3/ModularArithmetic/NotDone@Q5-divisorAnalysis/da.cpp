#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
int mod = 1e9 + 7;

ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll mod_inverse(ll a, ll mod) {
    return mod_pow(a, mod - 2, mod);  // Valid only if mod is prime
}

ll gp_sum(ll x, ll k, ll mod) {
    if (x == 1) return (k + 1) % mod;
    ll num = (mod_pow(x, k + 1, mod) - 1 + mod) % mod;
    ll denom = (x - 1 + mod) % mod;
    return (num * mod_inverse(denom, mod)) % mod;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin >> n;
    ll ndivisors = 1;
    ll ndiv_prod = 1;
    ll sdivisors = 1;
    ll number = 1;
    for(int i=0;i<n;i++){
        int x,k; cin >> x >> k;
        ndivisors = (ndivisors * (k+1)) % mod;
        ndiv_prod = (ndiv_prod * (k+1)) % (mod-1);
        sdivisors = (sdivisors * gp_sum(x,k,mod)) % mod;
        number = (number * mod_pow(x,k,mod)) % mod;
    }
    cout << ndivisors << " " << sdivisors << " " << pdivisors;
    return 0;
}