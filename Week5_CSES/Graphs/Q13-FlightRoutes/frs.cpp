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
void dijkstras(const vector<vector<pair<int,int>>>& adj,int x,int k,vector<priority_queue<ll>>& dis){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
    q.push({0,x});
    dis[x].push(0);
    while(!q.empty()){
        auto [d,node] = q.top();
        q.pop();
        if (dis[node].size() == k && d > dis[node].top()) {
            continue;
        }
        for(auto x : adj[node]){
            int p = x.first,w = x.second;
            if(dis[p].size() < k){
                dis[p].push(d+w);
                q.push({d+w,p});
            }
            else if(d+w < dis[p].top()){
                dis[p].pop();
                dis[p].push(d+w);
                q.push({d+w,p});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m,k; cin >> n >> m >> k;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;cin >> a >> b >> c;
        adj[a].pb(mp(b,c));
    }
    vector<priority_queue<ll>> dis(n+1);
    dijkstras(adj,1,k,dis);
    vector<ll> result;
    while (!dis[n].empty()) {
        result.pb(dis[n].top());
        dis[n].pop();
    }    
    for(int i=result.size()-1;i>=0;i--){
        cout << result[i] << " ";
    }
    return 0;
}