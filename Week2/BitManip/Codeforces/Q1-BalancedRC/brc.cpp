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
        int n,z;cin >> n >> z;
        vi a;
        int x=z;
        if(x==0){
            if(n%2){
                if(n==1) cout << "-1" << "\n";
                else cout << n+3 << "\n";
            }
            else cout << n << "\n";
            continue;
        }
        while(x>0){
            a.push_back(x%2);
            x/=2;
        }
        int bits = a.size(),y=0;
        int mindex=bits;
        for(int i=bits-1;i>=0;i--){
            if(a[i]) y++;
            else mindex=i;
        }
        int rem = n-y;
        if(rem<=0){cout << z << "\n";continue;}
        ll ans=0;
        if(rem%2){
            if(rem>2) ans = (z)+rem+3;
            else ans = z+pow(2,mindex+1);
        }
        else ans = z+rem;
        cout << ans << "\n";
    }
    return 0;
}