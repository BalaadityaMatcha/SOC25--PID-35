#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
void dfs(const vector<vi>& adj,int node,int parent_node,vector<vi>& dp){
    // loop for finding dp[u][0]
    for(auto x : adj[node]){
        if(x == parent_node) continue;
        dfs(adj,x,node,dp);
        dp[node][0]+=max(dp[x][0],dp[x][1]); // v can be selected/not ->no constraint here
    }
    // loop for finding dp[u][1]
    for(auto x : adj[node]){
        if(x == parent_node) continue;
// here k represents no.of edges in max matching with edge node-x being selected and others aren't 
// max(...) is removing the matching from subtree with root'x'(cuz we dont know dp[x][0] or the other was added there)
    // since x should not be selected in *it's subtree*, we should add dp[x][0]
    // +1 is for node-x edge
        int k = dp[node][0] - max(dp[x][0],dp[x][1]) + dp[x][0] + 1;
        dp[node][1] = max(dp[node][1],k);
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin >> n;
    vector<vi> adj(n+1);
    for(int i=1;i<n;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // dp[x][...] is the max possible matchings in the subtree with x as root
    // dp[x][0] => node x is not selected,dp[x][1] => node x is selected in *their respective subtrees*
    vector<vi> dp(n+1,vi(2));
    dfs(adj,1,0,dp);
    cout << max(dp[1][0],dp[1][1]);
    return 0;
}