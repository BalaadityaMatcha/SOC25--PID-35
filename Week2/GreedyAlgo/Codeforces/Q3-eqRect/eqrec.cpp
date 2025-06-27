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
    int q;cin >> q;
    while(q--){
        int n; cin >> n;
        vi a(4*n);in(a,4*n)
        sort(a.begin(),a.end());
        int area = a[0]*a[4*n-1];
        int i=0;
        for(;i<2*n;i+=2){
            if(a[i]!=a[i+1]) {cout << "NO\n";break;}
            if(a[4*n-i-1]!=a[4*n-i-2]) {cout << "NO\n";break;}
            if(a[i]*a[4*n-1-i] != area) {cout << "NO\n";break;}
            else continue;
        }
        if(i == 2*n) cout << "YES\n";
    }
    return 0;
}