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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,x;cin >> n >> x;
    vi coins(n);in(coins,n)
    sort(coins.begin(),coins.end());
    vector<ll> nOfWays(x+1);
    nOfWays[0]=1;
    for (int i = 1;i <= x;i++){
        for (auto c : coins) {
            if(i<c) break;
            nOfWays[i] += nOfWays[i-c];
        }
        nOfWays[i]%=mod;
    }
    cout << nOfWays[x];
    return 0;
}