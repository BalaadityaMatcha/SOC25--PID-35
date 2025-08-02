// dijkstra's -> tle'd for n = 500,m = 249500,q = 100000
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
void dijkstras(const vector<vector<pair<int,int>>>& adj,int x,vector<ll>& dis){//,vector<bool>& processed){
    priority_queue<pair<ll,int>> q;
    vector<bool> processed(adj.size(),false);
    q.push({0,x});
    dis[x]=0;
    while(!q.empty()){
        auto [d,node] = q.top();
        q.pop();
        if(processed[node]) continue;
        processed[node] = true;
        for(auto x : adj[node]){
            int p = x.first,w = x.second;
            if(dis[p] > -d+w){
                dis[p] = -d+w;
                q.push({-dis[p],p});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,q;cin >> n >> m >> q;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;cin >> a >> b >> c;
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
    }
    unordered_map<int, vector<ll>> dist_from; // starting node -> distances
    vector<bool> computed(n+1, false);
    // i -> whether dijkstra's computed with i as starting node or not
    for (int i = 0; i < q; i++){
        int a,b;cin >> a >> b;
        if (!computed[a]){
            vector<ll> dis(n+1,1e15);
            dijkstras(adj,a,dis);
            dist_from[a] = dis;
            computed[a] = true;
        }
        vector<ll>& dis = dist_from[a];
        if (dis[b] == 1e15) cout << "-1\n";
        else cout << dis[b] << "\n";
    }
    return 0;
}