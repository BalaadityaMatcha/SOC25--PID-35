// This code works for general case also(many arrivals/departures at same time)
// Best tc for this qsn is O(nlogn), SC=O(n)

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
    map<int,int> t;
    for(int j=0;j<n;j++){
        int a,b;
        cin >> a >> b;
        t[a]++;t[b]--;
    }
    int vmax=0,maxval=0;
    for(auto [k,v]: t){
        vmax+=v;
        maxval=max(maxval,vmax);
    }
    cout << maxval;
    return 0;
}