// took hint from a friend😭

#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
int mod = 1e9 + 7;
ll twosets(ll curr_sum,int curr_num,int max_num,ll req_sum,vector<vi>& memo){
    if(curr_num <= max_num && memo[curr_num-1][curr_sum]>=0) return memo[curr_num-1][curr_sum];
    if(curr_num > max_num){
        if(curr_sum == req_sum) return 1;
        else return 0;
    }
    memo[curr_num-1][curr_sum]=0;
    if(curr_sum+curr_num <= req_sum){
        memo[curr_num-1][curr_sum] += twosets(curr_sum+curr_num,curr_num+1,max_num,req_sum,memo);
        memo[curr_num-1][curr_sum] %= mod;
    }
    memo[curr_num-1][curr_sum] += twosets(curr_sum,curr_num+1,max_num,req_sum,memo);
    memo[curr_num-1][curr_sum] %= mod;
    return memo[curr_num-1][curr_sum];
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin >> n;
    ll k = (1LL*n*(n+1))/2;
    if(k % 2){cout << "0";return 0;}
    vector<vi> memo(n,vi(k+1,-1));
    int mod_inv2 = (1e9+8)/2;
    cout << (twosets(0,1,n,k/2,memo) * mod_inv2) % mod;
    return 0;
}