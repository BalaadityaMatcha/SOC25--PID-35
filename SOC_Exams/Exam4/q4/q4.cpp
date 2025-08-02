#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
void flip(int row,int column,vector<vi>& changes,int n){
    int c = column;int r = row+1;
    while(r<n){
        for(int i=max(c-(r-row),0);i<min(n,c+r-row+1);i++){
            changes[r][i]++;
        }
        r++;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<string> s(n);in(s,n)
        vector<vi> changes(n,vi(n,0));
        ll cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i][j] == '1'){
                    s[i][j]=0;
                    flip(i,j,changes,n);
                    cnt++;
                }
            }
            if(i<n-1){
                for(int j=0;j<n;j++){
                    if(s[i+1][j] - '0'){
                        if(changes[i+1][j]%2) s[i+1][j] = '0';
                    }
                    else{
                        if(changes[i+1][j]%2) s[i+1][j] = '1'; 
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}