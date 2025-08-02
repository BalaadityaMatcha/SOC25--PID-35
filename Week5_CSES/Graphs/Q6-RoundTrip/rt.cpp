#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
pair<int,int> dfs(const vector<vi>& adj,int node,int pnode,vector<bool>& vis,vi& dis){
    vis[node] = true;
    dis[node] = dis[pnode]+1;
    for(auto x : adj[node]){
        if(vis[x] && x!=pnode){
            int snode = x;
            int mnode = node; // move to mnode 
            return make_pair(snode,mnode); // return as soon as a cycle is found
        }
        if(!vis[x]){
            auto res = dfs(adj,x,node,vis,dis);
            if(res.first != -1){
                return res;
            }
        }
    }
    return make_pair(-1,-1);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m; cin >> n >> m;
    vector<vi> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n+1);
    vi dis(n+1);
    int i;
    int snode,mnode;
    for(i=1;i<=n;i++){
        if(!vis[i]){
            auto res = dfs(adj,i,0,vis,dis);
            if(res.first != -1){
                snode = res.first;
                mnode = res.second;
                break;
            }
        }
    }
    if(i == n+1){cout << "IMPOSSIBLE";return 0;}
    vi cycle = {snode};
    while(mnode!=snode){
        cycle.push_back(mnode);
        for(auto x : adj[mnode]){
            if(dis[x] == dis[mnode]-1){
                mnode = x;
                break;
            }
        }
    }
    cycle.push_back(snode);
    cout << cycle.size() << "\n";
    out(cycle,cycle.size()," ")
    return 0;
}
