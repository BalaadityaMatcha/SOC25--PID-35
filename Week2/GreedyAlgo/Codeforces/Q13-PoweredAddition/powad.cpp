/* Took hint from claude
   Told to use the add thing (which i also
   got intuition but dumb enough to let it
   go), should have thought with a peaceful mind */
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
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vi a(n);in(a,n)
        int add=0,max_add=0;
        for(int i=1;i<n;i++){
            add=max(0,a[i-1]+add-a[i]);
            max_add=max(add,max_add);
        }
        if(max_add==0){cout << 0 << "\n";continue;}
        // Method 1
        cout << static_cast<int>(log2(max_add))+1 << "\n";
        // Method 2
        // cout << 64 - __builtin_clzll(max_add) << "\n";
        /* that built in function returns
        no.of leading zeros in the long long format, so 64 - ... */
    }
    return 0;
}