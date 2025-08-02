#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
ll mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;cin >> t;
    while(t--){
        string s;cin >> s;
        int n = s.length();
        int check = s[n-1];
        int diff=1;
        ll ans = 0;
        int i=n-2;
        while(i>=0){
            int temp_diff = diff;
            for(int j=n-1;j>i;j--){
                if(j==n-1){
                    (s[i]==check ? diff++ : diff--);
                    temp_diff=diff;
                }
                else{
                    (s[j+1]==check ? temp_diff-- : temp_diff++); 
                }
                if(temp_diff == 0){
                    ans=(ans+(i+1)*(n-j))%mod;
                }
            }
            i--;
        }
        cout << ans << "\n";
    }
    return 0;
}