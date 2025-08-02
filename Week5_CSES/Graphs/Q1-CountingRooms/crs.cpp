#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

int dx[4] = {-1,0,1,0}; // up,right,down,left
int dy[4] = {0,1,0,-1};
//Your function here
void bfs(const vector<string>& grid,int a,int b,vector<vector<bool>>& vis){
    int v = grid.size(),h = grid[0].size();
    vis[a][b]=true;
    stack<pair<int,int>> q;
    q.push(make_pair(a,b));
    while(!q.empty()){
        auto [x,y] = q.top();
        q.pop();
        for(int i=0;i<4;i++){
            int x1 = x + dx[i],y1 = y + dy[i];
            if(x1>=0 && x1<v && y1>=0 && y1<h && grid[x1][y1] == '.' && !vis[x1][y1]){
                q.push(make_pair(x1,y1));
                vis[x1][y1] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin >> n >> m;
    vector<string> grid(n);in(grid,n)
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    int rooms = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j] == '.'){bfs(grid,i,j,vis);rooms++;}
        }
    }
    cout << rooms;
    return 0;
}