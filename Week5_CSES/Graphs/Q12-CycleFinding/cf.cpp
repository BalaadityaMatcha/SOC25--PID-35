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

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for(int i = 0; i < m; ++i){
        int u, v, w;cin >> u >> v >> w;
        edges.pb(make_tuple(u, v, w));
    }
    vector<ll> dist(n+1,1e13);
    vector<int> parent(n+1,-1);
    dist[1] = 0;
    int x;
    for(int i = 0; i < n; ++i){
        x = -1;
        for(auto [u, v, w] : edges){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }
    if(x == -1){
        cout << "NO\n";
    }
    else{
        for(int i = 0; i < n; ++i) x = parent[x];
        // Making sure x is inside the negative cycle
        vector<int> cycle;
        int cur = x;
        do{
            cycle.pb(cur);
            cur = parent[cur];
        } while(cur != x);
        cycle.pb(x); // to show cycle ends where it began
        cout << "YES\n";
        reverse(cycle.begin(),cycle.end());
        out(cycle,cycle.size()," ")
    }
    return 0;
}