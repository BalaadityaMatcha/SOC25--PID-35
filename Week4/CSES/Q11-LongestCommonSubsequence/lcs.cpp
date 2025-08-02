/*
Dumb enough to take hint, but took.
*/

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
    int n,m;cin >> n >> m;
    vi a(n),b(m);in(a,n);in(b,m)
    vector<vi> dp(n+1,vi(m+1)); // dp[i][j] -> LCS of a[0...i-1] & b[0...j-1]
    vi lcs;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << "\n";
    int i=n,j=m;
    while(i && j){
        if(a[i-1]==b[j-1]){lcs.push_back(a[i-1]);i--;j--;}
        else{
            (dp[i-1][j] >= dp[i][j-1] ? i-- : j--);
        }
    }
    for(auto it = lcs.rbegin();it!=lcs.rend();it++) cout << *it << " ";
    return 0;
}