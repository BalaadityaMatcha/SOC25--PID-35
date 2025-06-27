#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
int x_y(ll x,int y,int m){
    if((!x && !y) || x==1) return 1;
    int res=1;
    while(y>0){
        if(y%2){res = (1LL * res * x)%m;}
        x = x * x % m;
        y/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin >> n;
    int sum_k=0;
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++){
        int k;cin >> k;
        for(int j=0;j<k;j++){
            int a;cin >> a;
            freq[a]++;
        }
        sum_k+=k;
    }
    ll x = 0;
    for (const auto& [key, value] : freq) {
        x += 1LL * value * value;
    }
    ll y = 1LL * sum_k * n;
    ll g = gcd(x,y);
    x/=g;y/=g;
    const int m=998244353;
    int yi = x_y(y%m,m-2,m);
    int ans = ((x%m)*yi)%m;
    cout << ans << "\n";
    return 0;
}