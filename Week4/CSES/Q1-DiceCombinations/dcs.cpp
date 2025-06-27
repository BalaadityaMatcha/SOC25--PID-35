#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
int mod = 1e9 + 7;
unordered_map<int,ll> memo={{1,1}};
ll f(int n){
    if(n<=0) return 0;
    if(memo[n]) return memo[n];
    if(n<7){memo[n]=pow(2,n-1);return memo[n];}
    memo[n] = (f(n-1)+f(n-2)+f(n-3)+f(n-4)+f(n-5)+f(n-6))%mod;
    return memo[n];
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin >> n;
    cout << f(n);
    return 0;
}