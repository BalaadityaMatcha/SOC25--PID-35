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
    vi x(n);
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin >> x[i];
        sum+=x[i];
    }
    /* 
    vector<vi> dp(n,vi(n)); // dp[i][j] represents the max difference b/w scores
    of 2 players for the subarray x[i]...y[i]
    But i will use only 2 rows for reducing SC. 
    */
    vector<ll> dp(n);
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(j==i) dp[j]=x[j];
            else dp[j]=max(x[i]-dp[j],x[j]-dp[j-1]);
        }
    }
    // dp[n-1] = max diff = score(1st) - score(2nd)\
       sum of x[i] = score(1st) + scpre(2nd)
    cout << (sum + dp[n-1])/2;
    return 0;
}