// either tle or wrong ans

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
void dijkstras(const vector<vector<pair<int,int>>>& adj,int x,vector<pair<ll,int>>& dis,vector<bool>& processed){
    priority_queue<pair<ll,int>> q;
    q.push({0,x});
    while(!q.empty()){
        auto [d,node] = q.top();
        q.pop();
        if(processed[node]) continue;
        processed[node] = true;
        for(auto x : adj[node]){
            int p = x.first,w = x.second;
            if(dis[p].first> -d + w){
                dis[p].first = -d+w;
                dis[p].second = nm;
                q.push({-dis[p].first,p});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;cin >> a >> b >> c;
        adj[a].pb(mp(b,c));
    }
    vector<vector<ll>> dis(n+1);
    vector<bool> processed(n+1,false);
    dijkstras(adj,1,dis,processed);
    ll a = dis[n].first;
    int b = dis[n].second;
    return 0;
}