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
    vi tt(n);in(tt,n)
    int sum=0;int max_ele=*max_element(tt.begin(),tt.end());
    for(int i=0;i<n;i++) sum+=tt[i];
    cout << max(sum,2*max_ele);
    return 0;
}