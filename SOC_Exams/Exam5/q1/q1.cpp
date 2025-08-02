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
    int t;cin>>t;
    while(t--){
        int n,k;cin >> n >> k;
        if(k>(n+1)/2){cout << "-1\n";continue;}
        else{
            int posn = 0;
            int cnt = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(j==posn && i==posn && cnt<k){cout << "R";posn+=2;cnt++;}
                    else cout << ".";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}