#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
void dfs(const vector<vi>& adj,int node,vector<bool>& vis,vi& toleaf){
    vis[node]=true;
    for(auto x : adj[node]){
        if(!vis[x]){
            dfs(adj,x,vis,toleaf);
            toleaf[node] = max(toleaf[node],toleaf[x]+1);
        }
    }
}
void dfs2(const vector<vi>& adj,int node,vector<bool>& vis,const vi& toleaf,vi& maxLength){
    vis[node]=true;
    int max1=0,max2=0;
    int leaves = 0;
    for(auto x : adj[node]){
        if(!vis[x]){
            leaves++;
            dfs2(adj,x,vis,toleaf,maxLength);
            int temp = max1;
            max1 = max(max1,toleaf[x]);
            max2 = (max1 == temp ? max(toleaf[x],max2) : temp);
        }
    }
    maxLength[node] = (leaves>=2 ? max1+max2+2 : max1+max2+leaves);
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
    vector<bool> vis(n+1);
    vi toleaf(n+1); // max length b/w any leaf and itself for a subtree from it
    dfs(adj,1,vis,toleaf);
    vis.assign(n+1,false); // reinitializing for second dfs
    vi maxLength(n+1);
    dfs2(adj,1,vis,toleaf,maxLength);
    cout << *max_element(maxLength.begin(),maxLength.end()) << endl;
    return 0;
}
