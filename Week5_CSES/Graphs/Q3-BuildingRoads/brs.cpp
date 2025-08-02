#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
void bfs(const vector<vi>& adj,int a,vector<bool>& vis){
    vis[a]=true;
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for( auto x : adj[node]){
            if(!vis[x]){
                q.push(x);
                vis[x] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin >> n >> m;
    vi a(m),b(m);
    vector<vi> adj(n+1);
    vector<bool> vis(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int connected = -1;
    vector<int> csp; // components starting points
    for(int i=1;i<=n;i++){
        if(!vis[i]){bfs(adj,i,vis);connected++;csp.push_back(i);}
    }
    cout << connected << "\n";
    for(int i=0;i<connected;i++){
        cout << csp[i] << " " << csp[i+1] << "\n";
    }
    return 0;
}