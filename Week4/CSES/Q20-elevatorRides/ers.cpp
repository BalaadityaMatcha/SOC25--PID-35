// O(n*2^n) works for n<=20

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
    int n,x;cin >> n >> x; // since n<=20 < 32, will use bitmask
    vector<pair<int,int>> dp(1<<n,pair<int,int>(n,n));
    dp[0]={1,0}; // 1 trip for no members
    vi wt(n);in(wt,n)
    for(int mask = 0; mask < (1<<n); mask++){
        for(int i=0;i<n;i++){
            if(mask & 1<<i) continue; // person already there
            int new_mask = mask | 1<<i;
            int w = wt[i];
            auto [trips,last_total_wt] = dp[mask];
            if(last_total_wt + w <= x){
                dp[new_mask] = min(dp[new_mask],make_pair(trips,last_total_wt + w));
            }
            else{
                dp[new_mask] = min(dp[new_mask],make_pair(trips + 1, w));
            }
        }
    }
    // this dp table covers all possible cases of filling the lifts via the loop at line 22 
    cout << dp[(1<<n)-1].first << endl;
    return 0;
}