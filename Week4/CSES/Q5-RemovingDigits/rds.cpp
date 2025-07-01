#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
void returnn(int& n,ll& cnt){
    int x = n;
    int maxx = 0;
    while(x){
        maxx=max(maxx,x%10);
        if(maxx==9) break;
        x/=10;
    }
    n-=maxx;
    cnt++;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin >> n;
    ll cnt = 0;
    while(n) returnn(n,cnt);
    cout << cnt << "\n";
    return 0;
}