#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
int loops(const vi& x, int n){
    int r=1;
    vi indices(n+1);
    for(int i=0;i<n;i++){
        indices[x[i]]=i;
    }
    for(int i=1;i<n;i++){
        if(indices[i]>indices[i+1]) r++;
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    vi x(n);
    in(x,n);
    cout <<loops(x,n);
    return 0;
}