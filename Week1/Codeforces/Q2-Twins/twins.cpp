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
    int sum=0;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    int imGreed=0;
    int count=0;
    auto it=a.end();
    int mini= sum/2 + sum%2;
    while(imGreed <= mini){
        --it;
        imGreed += *it;
        count++;
    }
    cout << count;
    return 0;
}
