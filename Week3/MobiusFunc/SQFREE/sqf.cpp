// Inefficient

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
    int t;cin >> t;
    unordered_map<ll,bool> sqprimes={{1,false}};
    while(t--){
        ll n;cin >> n;
        ll cnt = 1;
        for(ll i=2;i<=sqrt(n);i++){
            if(sqprimes[i]) continue;
            for(ll j=i*i;j<=n;j+=i*i){
                if(sqprimes[j]==false && j>sqrt(n)){
                    sqprimes[j]=true;
                    cnt--;
                }
                
            }
            cnt++;
        }
        ll ans = n - sqrt(n) + cnt;
        cout << ans << "\n";
    }
    return 0;
}