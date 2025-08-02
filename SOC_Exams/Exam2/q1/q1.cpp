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
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        ll sqr=0;
        for(int i=0;i<n;i++){
            int x;cin >> x;
            sqr+=x;
        }
        ll root = sqrt(sqr);
        if(root * root != sqr) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}