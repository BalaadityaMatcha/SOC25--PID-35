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
    int a,b;cin >> a >> b;
    if(a==b){cout << "0";return 0;}
    int small = min(a,b);
    int large = max(a,b);
    int val = 0;
    while(small != large){ // small = a large = b => small = min(b-a,a) = a / b-a large = max(b-a,a) = b-a / a = large - small
        small = min(large - small,small);
        large = large - small;
        val++;
    }
    
    cout << val << "\n";
    return 0;
}