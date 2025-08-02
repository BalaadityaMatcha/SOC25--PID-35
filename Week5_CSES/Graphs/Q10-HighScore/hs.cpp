// A small tweak in Bellman-Ford 
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
int dfs(const vector<vi>& adj, int k, int n,const vector<ll>& dis_check,const vector<ll>& dist,vector<bool>& vis,bool change=false){
    vis[k] = true;
    for(auto x : adj[k]){
        if(k == 1){change = false;}
        if(!vis[x]){
            if(dis_check[x] != dist[x]){change = true;}
// change is used for whether the path from 1 to n is containing a cycle'd node or not and is passed
// to its next levels until it reaches 'n'
            vis[x] = true;
            if(x == n){
                if(change){return -1;} // if change detected, return -1
                vis[x]=false; // so that i can cover all the paths from 1 to n
                continue; // so that no further dfs which would not allow the above comment
            }
            int res = dfs(adj,x,n,dis_check,dist,vis,change);
            if(res == -1) return -1;
        }
    }
    return 1; // return 1 if no cycle'd node in the path
}
int belford(const vector<vi>& adj,vector<tuple<int,int,int>>& edges,int n,int s,vector<ll>& dist,vector<bool>& vis){
    for(int i=0;i<n-1;i++){ // normal n-1 iterations
        for(auto e : edges){
            auto [a,b,w] = e;
            dist[b] = max(dist[b], dist[a]+w);
        }
    }
    vector<ll> dis_check = dist;
// storing these so that i can check whether there is a point in the path of 1 to n that is also in a loop
// using a dfs later
    for(auto e : edges){ // next loop for finding the cycle
        auto [a,b,w] = e;
        dist[b] = max(dist[b],dist[a]+w);
    }
    for(int s = edges.size()-1;s>=0;s--){
// next loop in reverse order->this is used to recheck a case where 'n' is in a loop itself but
// wasn't detected in nth round because of the ordering of the edges in the vector.
        auto [a,b,w] = edges[s];
        dist[b] = max(dist[b],dist[a]+w);
    }
    if(dis_check[1] != dist[1]) return -1; // in dfs, im not checking this, so checked prior
    if(dfs(adj,1,n,dis_check,dist,vis,false) == -1) return -1;
    else return 1;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m; cin >> n >> m;
    vector<tuple<int,int,int>> edges;
    vector<vi> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        edges.pb(make_tuple(a,b,c));
        adj[a].pb(b);
    }
    vector<bool> vis(n+1,false);
    vector<ll> dist(n+1,-1e15);
    dist[1]=0;
    if(belford(adj,edges,n,1,dist,vis) == -1){cout << "-1";return 0;}
    cout << dist[n];
    return 0;
}