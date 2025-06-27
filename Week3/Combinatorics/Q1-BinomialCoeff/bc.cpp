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
    int n;cin >> n;
    while(n--){
        int a,b;cin >> a >> b;
        if(b==0){cout << "1\n";continue;}
        if(b==1){cout << a << "\n";continue;}
        ll num=1,den=1;
        if(a>2*b){
            for(int i=a-b+1;i<=a;i++){
                num=(num*i)%mod;
                den=(den*(a+1-i))%mod;
            }
            int ans = (num*x_y(den,mod-2,mod))%mod;
            cout << ans << "\n";
        }
        if(a<=2*b){
            for(int i=b+1;i<=a;i++){
                num=(num*i)%mod;
                den=(den*(a+1-i))%mod; 
            }
            int ans = (num*x_y(den,mod-2,mod))%mod;
            cout << ans << "\n";
        }
    }
    return 0;
}