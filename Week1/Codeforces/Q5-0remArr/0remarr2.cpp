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
    freopen("output2.txt","w",stdout);
    int t;cin >> t;
    while(t--){
        int n,k;cin >> n >> k;
        map<int,int> a;
        for(int i=0;i<n;i++){
            int x;cin >> x;
            if(x%k) a[k - (x%k)]++;
        }
        int ans=0;
        for(auto [key,value] : a){
            ans=max(ans,(value-1)*k+key);
        }
        if(!ans) cout << "0\n";
        else cout << ans + 1 << "\n";
    }
    return 0;
}