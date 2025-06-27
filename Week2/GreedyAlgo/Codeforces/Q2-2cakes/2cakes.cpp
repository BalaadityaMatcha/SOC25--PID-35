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
    int n;cin >> n;
    vector<pair<int,int>> a(2*n);
    for(int i=0;i<2*n;i++){
        cin >> a[i].first;
        a[i].second=i;
    }
    sort(a.begin(),a.end(),[](const auto& a,const auto& b){
        if(a.first!=b.first) return a.first < b.first;
        else return a.second < b.second; 
    });
    ll dist=0;
    for(int i=0;i<2*n-3;i+=2){
        dist+=1LL*min(abs(a[i].second - a[i+2].second)+abs(a[i+1].second - a[i+3].second),abs(a[i].second - a[i+3].second)+abs(a[i+1].second - a[i+2].second));
    }
    dist+=1LL*(a[0].second+a[1].second);
    cout << dist;
    return 0;
}