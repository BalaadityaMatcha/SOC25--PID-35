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
    vector<pair<int,double>> a(n);
    int sum=0;
    for(int i=0;i<n;i++){
        double x;cin >> x;
        a[i].first = floor(x);
        a[i].second = fabs(x - floor(x));
        sum+=a[i].first;
    }
    for(int i=0;i<n;i++){
        if(sum==0) break;
        if(a[i].second > 1e-9){
            a[i].second=0;a[i].first++;
            sum++;
        }
    }
    for(int i=0;i<n;i++) cout << a[i].first << "\n";
    return 0;
}