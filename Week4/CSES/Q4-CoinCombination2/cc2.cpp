#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,x;cin >> n >> x;
    vi coins(n);in(coins,n)
    vi ans(x+1);
    ans[0]=1;
    for(int c : coins){
        for(int i=c;i<=x;i++){
            ans[i]=(ans[i] + ans[i-c])%mod;
        }
    }
    cout << ans[x];
    return 0;
}