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
    int n,q;cin >> n >> q;
    vi a(n);in(a,n)
    int active_pairs = 0;
    ll maxum=0;
    vector<int> actv(n+1);
    for(int i=0;i<q;i++){
        int l,r;cin >> l >> r;
        actv[l-1]++;actv[r]--;
    }
    for(int i=0;i<n;i++){
        active_pairs+=actv[i];
        actv[i]=active_pairs;
    }
    sort(actv.rbegin(),actv.rend());
    sort(a.rbegin(),a.rend());
    int i=0;
    while(actv[i]!=0 && i!=n){
        maxum+= 1LL*(a[i])*(actv[i]);
        i++;
    }
    cout << maxum;
    return 0;
}