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
    int n;cin >> n;
    if(n%2){
        if(n==1){
            cout << "0";return 0;
        }
        ll ans = -1;
        ll curr = n;
        for(int i=n-1;i>2;i--){
            ans=(ans+curr)%mod;
            curr=-(curr*i)%mod;
        }
        cout << (ans+curr+mod)%mod;
    }
    else{
        if(n==2){
            cout << "1";return 0;
        }
        ll ans = 1;
        ll curr = -n;
        for(int i=n-1;i>2;i--){
            ans=(ans+curr)%mod;
            curr=-(curr*i)%mod;
        }
        cout << (ans+curr+mod)%mod;
    }
    return 0;
}