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
    int n;cin >> n;
    vector<tuple<int,int,int>> abp(n);
    for(int i=0;i<n;i++){
        int a,b,p;cin >> a >> b >> p;
        abp[i] = {a,b,p};
    }
    sort(abp.begin(),abp.end(),[](const auto& x,const auto& y){
        return get<1>(x) < get<1>(y);
    });
    vi ends(n);
    for(int i=0;i<n;i++){
        ends[i]=get<1>(abp[i]);
    }
    vector<ll> dp(n+1); // dp[i] -> max profit in first i projects where projects are sorted based on end date
    // dp[0]=0 -> base case
    for(int i=0;i<n;i++){
        int a = get<0>(abp[i]);
        int index = upper_bound(ends.begin(),ends.end(),a-1) - ends.begin();
        // index = no.of projects with end <= a-1
        dp[i+1] = max(dp[i],dp[index] + get<2>(abp[i]));
        // 1st is without taking ith project(here i is 0-based) and other is with taking ith project
    }
    cout << dp[n];
    return 0;
}