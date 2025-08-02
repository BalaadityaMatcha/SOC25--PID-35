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
    vi x(n);in(x,n)
    vi lis;  // the position where x[i] ends up in lis is the liss ending at x[i] -1 = liss(x[i])-1
    for(int i=0;i<n;i++){
        auto it = lower_bound(lis.begin(),lis.end(),x[i]);
        if(it == lis.end()){
            lis.push_back(x[i]);
        }
        else{
            *it = x[i];
        }
    }
    cout << lis.size();
    return 0;
}