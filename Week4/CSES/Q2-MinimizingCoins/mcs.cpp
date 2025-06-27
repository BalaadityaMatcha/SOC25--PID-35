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
    int n,x;cin >> n >> x;
    vi coins(n);in(coins,n)
    int inf = 1e6 + 7;
    vi value(inf);
    value[0] = 0;
    for (int i = 1;i <= x;i++){
        value[i] = inf;
        for (auto c : coins) {
            if (i-c >= 0) value[i] = min(value[i], value[i-c]+1);
        }
    }
    if(value[x]==inf){cout << "-1";return 0;}
    cout << value[x];
    return 0;
}