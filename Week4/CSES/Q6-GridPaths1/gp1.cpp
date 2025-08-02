#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin >> n;
    vector<string> quest(n); 
    vi paths(n);
    for(int i=0; i < n; i++){
        cin >> quest[i];
    }
    if(quest[0][0]=='*' || quest[n-1][n-1]=='*'){cout << "0";return 0;}
    paths[0]=1;
    int row = 1;
    for(int i=1;i<n;i++){
        if(quest[0][i]=='*'){break;}
        else paths[i]=paths[i-1];
    }
    while(row != n){
        if(quest[row][0]=='*') paths[0]=0;
        for(int i=1;i<n;i++){
            if(quest[row][i]=='*') paths[i]=0;
            else{
                paths[i]=(paths[i]+paths[i-1])%mod;
            }
        }
        row++;
    }
    cout << paths[n-1] << endl;
    return 0;
}