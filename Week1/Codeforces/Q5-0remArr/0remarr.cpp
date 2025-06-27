#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

int moovz(vi& a, int n, int k){
    int fsumz = k - a[n-1];
    int sumz = k - a[n-1];
    for(int i=n-2;i>=0;i--){
        if(a[i]==a[i+1] && a[i]!=0){
            sumz+=k;
        }
        else if(a[i]==0) break;
        else{
            fsumz=max(sumz,fsumz);
            sumz = k - a[i];
        }
    }
    return ( fsumz % k ? max(fsumz,sumz) + 1 : 0 );
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        vi a;
        for(int i=0;i<n;i++){
            int x;cin >> x;
            a.push_back(x%k);
        }
        sort(a.begin(),a.end());
        cout << moovz(a,n,k) << "\n";
    }
    return 0;
}