#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
void maxsum(vi& a,vi& b,int n,int k){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for (int i = 0; i < k && a[i] < b[n - 1 - i]; i++) {
        swap(a[i], b[n - 1 - i]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i]; 
    }
    cout << sum << "\n";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        vi a(n),b(n);
        in(a,n)
        in(b,n)
        maxsum(a,b,n,k);
    }
    return 0;
}