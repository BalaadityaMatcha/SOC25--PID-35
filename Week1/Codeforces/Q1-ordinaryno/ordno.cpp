#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
int ordinary(int z){
    int n=0;
    int x=z;
    int y=1;
    while(x/10){
        n++;
        y*=10;
        x/=10;
    }
    if(y==1) return z;
    int k = z%y;
    int m = z/y;
    int r = 9*(n) + m - 1;
    if(k==0) return r;
    while(y>1){
        y/=10;
        if(m < k/y){r++;break;}
        if(m > k/y) break;
        else k%=y;
    }
    return (k ? r : r+1);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin >> n;
    while(n--){
        int x;cin >> x;
        cout << ordinary(x) << "\n";
    }
    return 0;
}