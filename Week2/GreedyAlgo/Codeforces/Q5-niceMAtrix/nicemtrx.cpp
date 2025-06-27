#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
ll nice(vector<vi>& a,int n,int m){
    ll steps=0;
    for(int i=0;i<(n+1)/2;i++){
        for(int j=0;j<(m+1)/2;j++){
            vi vals={a[i][j],a[i][m-j-1],a[n-i-1][j],a[n-i-1][m-j-1]};
            sort(vals.begin(),vals.end());
            if((n%2 && i==(n+1)/2 - 1) || (m%2 && j==(m+1)/2 - 1)) {steps+=vals[3]-vals[0];continue;}
            steps+=vals[3]+vals[2]-vals[1]-vals[0];
        }
    }
    return steps;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;cin >> t;
    while(t--){
        int n,m;cin >> n >> m;
        vector<vi> a(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x;cin >> x;
                a[i].push_back(x);
            }
        }
        cout << nice(a,n,m) << "\n";
    }
    return 0;
}