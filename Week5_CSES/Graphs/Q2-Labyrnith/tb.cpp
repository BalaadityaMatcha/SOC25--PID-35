//bfs - easiest
#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

int dx[4] = {-1,0,1,0}; // up,right,down,left
int dy[4] = {0,1,0,-1};
int bt[4] = {'D','L','U','R'}; // backtracking directions(reverse)
//Your function here
pair<int,int> bfs(const vector<string>& grid,int a,int b,vector<vector<bool>>& vis,vector<vi>& dist){
    int n = grid.size();
    int m = grid[0].size();
    vis[a][b] = true;
    queue<pair<int,int>> q; // since bfs goes level-wise, as soon as we get 'B'(shortest),the bfs should end
    q.push(make_pair(a,b));
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x1 = x+dx[i],y1 = y+dy[i];
            if(x1>=0 && y1>=0 && x1<n && y1<m && grid[x1][y1] == '.' && !vis[x1][y1]){
                vis[x1][y1] = true;
                q.push(make_pair(x1,y1));
                dist[x1][y1] = dist[x][y]+1;
            }
            if(x1>=0 && y1>=0 && x1<n && y1<m && grid[x1][y1] == 'B' && !vis[x1][y1]){
                vis[x1][y1] = true;
                q.push(make_pair(x1,y1));
                dist[x1][y1] = dist[x][y]+1;
                return make_pair(x1,y1);
            }
        }
    }
    return make_pair(-1,-1); // just for no path
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin >> n >> m;
    vector<string> grid(n);in(grid,n)
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    vector<vi> dist(n,vi(m,0));
    int xf,yf;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'A'){
                pair<int,int> res = bfs(grid,i,j,vis,dist);
                xf = res.first;yf = res.second;break;}
        }
    }
    if(xf == -1){
        cout << "NO";return 0;
    }
    cout << "YES\n";
    cout << dist[xf][yf] << "\n";
    vector<char> backtrack;
    while(grid[xf][yf]!='A'){
        for(int i=0;i<4;i++){
            int x = xf + dx[i],y = yf + dy[i]; 
            if(x>=0 && y>=0 && x<n && y<m && vis[x][y] && dist[x][y] == dist[xf][yf]-1){
                backtrack.push_back(bt[i]);
                xf = x;yf = y;
                break;
            }
        }
    }
    int s = backtrack.size();
    for(int i=0;i<s;i++){
        cout << backtrack[s-1-i];
    }
    return 0;
}