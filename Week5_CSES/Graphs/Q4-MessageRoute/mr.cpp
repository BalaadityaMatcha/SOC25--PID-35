#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
int bfs(const vector<vi>& adj,int a,vector<bool>& vis,vi& dist,int n){
    vis[a] = true;
    queue<int> q; // since bfs goes level-wise, as soon as we get 'B'(shortest),the bfs should end
    q.push(a);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto x : adj[node]){
            if(x != n && !vis[x]){
                vis[x] = true;
                q.push(x);
                dist[x] = dist[node]+1;
            }
            if(x == n && !vis[x]){
                vis[x] = true;
                q.push(x);
                dist[x] = dist[node]+1;
                return x;
            }
        }
    }
    return -1; // just for no path
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin >> n >> m;
    vector<vi> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n+1);
    vi dist(n+1);
    int res = bfs(adj,1,vis,dist,n);
    if(res == -1){
        cout << "IMPOSSIBLE";return 0;
    }
    cout << dist[res]+1 << "\n";
    vi backtrack={res};
    while(res!=1){
        for(auto x : adj[res]){ 
            if(vis[x] && dist[x] == dist[res]-1){
                backtrack.push_back(x);
                res = x;
                break;
            }
        }
    }
    int s = backtrack.size();
    for(int i=0;i<s;i++){
        cout << backtrack[s-1-i] << " ";
    }
    return 0;
}