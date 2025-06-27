#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
int maxsum(const vi& a, int n){
    int sum=INT_MIN,csum=0;
    for(int i=0;i<n;i++){
        csum = max(a[i],a[i]+csum);
        sum=max(sum,csum);
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    vi a(n);
    in(a,n);
    cout << maxsum(a,n);
    return 0;
}