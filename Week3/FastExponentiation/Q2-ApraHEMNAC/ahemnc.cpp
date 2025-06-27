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
    if(n==0){cout << "1\n";return 0;}
    int r = n%4;
    if(r == 1) cout << "8\n";
    else if(r == 2) cout << "4\n";
    else if(r == 3) cout << "2\n";
    else cout << "6\n";
    return 0;
}