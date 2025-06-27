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
    int n; cin >> n;
    int sod=0,sf=0;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        int d; cin >> d;
        sod+=d;
    }
    sort(a.begin(),a.end());
    int current=0;
    for(int i=0;i<n;i++){
        current+=a[i];
        sf+=current;
    }
    cout << sod-sf << "\n";
    return 0;
}