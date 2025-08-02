#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
#define pb push_back
#define mp make_pair
using namespace std;

// Optimized DFS for cycle detection
vi dfs(const vector<vi>& adj, int s, vector<bool>& vis, vi& path, bool& status, vector<bool>& curr_vis) {
    vis[s] = true;
    curr_vis[s] = true;
    for(auto x : adj[s]){
        if(curr_vis[x]){
            auto it = find(path.begin(),path.end(),x);
            vi cycle(it,path.end());
            cycle.pb(x);
            status = true;
            return cycle;
        }   
        if(!vis[x]){
            path.pb(x);
            auto res = dfs(adj,x,vis,path,status,curr_vis);
            if(status) return res;
            path.pop_back();  // Backtrack
        }
    }
    curr_vis[s] = false;  // Backtrack curr_vis
    return {-1};
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, m;cin >> n >> m;
    vector<vi> adj(n+1);
    for(int i = 0; i < m; i++){
        int a, b;cin >> a >> b;
        adj[a].pb(b);
    }
    vector<bool> vis(n+1,false);
    vector<bool> curr_vis(n+1,false);
    bool status = false;
    vi res;
    for(int i=1;i<=n;i++) {
        if(!vis[i]){
            vi path = {i};
            res = dfs(adj,i,vis,path,status,curr_vis);
            if(status) break;
        }
    }
    
    if(!status) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    cout << res.size() << "\n";
    out(res, res.size(), " ");
    
    return 0;
}