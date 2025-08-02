/*
Found that it (0/1 Knapsack problem) is a common problem and learnt the
optimal solution from GfG
I first mistakenly wrote Knapsack code for fractions one and understood
when a testcase gave mistake
*/

#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
int knapsack(int w,const vi& wt,const vi& val){
    vi dp(w+1,0);
    for(int i=1;i<=wt.size();i++){
        for(int j=w;j>=wt[i-1];j--){
            dp[j] = max(dp[j],dp[j-wt[i-1]] + val[i-1]);
        }
    }
    return dp[w];
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,x;cin >> n >> x;
    vi prices(n);in(prices,n)
    vi pages(n);in(pages,n)
    cout << knapsack(x,prices,pages) << endl;
    return 0;
}