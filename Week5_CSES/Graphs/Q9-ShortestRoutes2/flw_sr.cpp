#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
#define pb push_back
#define mp make_pair
using namespace std;

//Your function here
void flwl(const vector<vi>& adj,vector<vector<ll>>& dis){
    int n = adj.size()-1;
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m,q;cin >> n >> m >> q;
    vector<vi> adj(n+1,vi(n+1,0));
    for(int i=0;i<m;i++){
        int a,b,c;cin >> a >> b >> c;
        if(!adj[a][b]){adj[a][b] = c;adj[b][a] = c;}
        else{adj[a][b] = min(c,adj[a][b]);adj[b][a] = min(c,adj[b][a]);}
    }
    vector<vector<ll>> dis(n+1,vector<ll>(n+1,0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dis[i][j] = 0;
            else if (adj[i][j]) dis[i][j] = adj[i][j];
            else dis[i][j] = 1e15;
        }
    }
    flwl(adj,dis);
    for(int i=0;i<q;i++){
        int a,b;cin >> a >> b;
        if(dis[a][b] != 1e15) cout << dis[a][b] << "\n";
        else cout << "-1\n";
    }
    return 0;
}