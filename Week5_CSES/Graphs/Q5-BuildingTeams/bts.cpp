#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
void bfs(const vector<vi>& adj,int a,vector<bool>& vis,vi& t1,vi& t2,bool& suc){
    vis[a]=true;
    queue<int> q;
    q.push(a);
    t1.push_back(a);
    vector<int> dist(adj.size());
    while(!q.empty()){
        int node = q.front();
        q.pop();
        int d1 = 0,d2=0;
        for(auto x : adj[node]){
            if(vis[x]){
                if(dist[x]%2) d1++;
                else d2++;
            }
            if(!vis[x]){
                vis[x]=true;
                q.push(x);
                dist[x]=dist[node]+1;
                if(dist[x]%2){
                    t2.push_back(x);
                }
                else{
                    t1.push_back(x);
                }
            }
        }
        if(d1>0 && d2>0){suc = false;}
    }
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
    vi t1,t2;
    bool suc = true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){bfs(adj,i,vis,t1,t2,suc);}
    }
    if(!suc){cout << "IMPOSSIBLE";return 0;}
    vector<int> f(n);
    for(int i=0;i<t1.size();i++){f[t1[i]-1] = 1;}
    for(int i=0;i<t2.size();i++){f[t2[i]-1] = 2;}
    out(f,n," ")
    return 0;
}