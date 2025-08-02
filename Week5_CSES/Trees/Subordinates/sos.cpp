#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
void bfs(const vector<vi>& adj,int node,vi& sub){
    for(int i=0;i<adj[node].size();i++){
        bfs(adj,adj[node][i],sub);
        sub[node]+=sub[adj[node][i]];
        sub[node]++;
        //sub[node]+=bfs(adj,[adj[node][i]],sub);
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin >> n;
    vector<vi> adj(n+1);
    for(int i=2;i<=n;i++){
        int x;cin >> x;
        adj[x].push_back(i);
    }
    vi sub(n+1,0);
    bfs(adj,1,sub);
    for(int i=1;i<=n;i++){
        cout << sub[i] << " ";
    }
    return 0;
}