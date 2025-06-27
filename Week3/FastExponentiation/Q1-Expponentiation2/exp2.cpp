#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
int mod = 1e9 + 7;
int x_y(int x,int y,int m=mod){
    if((!x && !y) || x==1) return 1;
    int res=1;
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
    int t;cin >> t;
    while(t--){
        int a,b,c;cin >> a >> b >> c;
        cout << x_y(a,x_y(b,c,mod-1)) << "\n";
    }
    return 0;
}