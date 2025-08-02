#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

int dx[4] = {-1,0,1,0}; // up,right,down,left
int dy[4] = {0,1,0,-1};
char dir[4] = {'U','R','D','L'};
vector<char> fpath(1e6); // initialized to be n*m
//Your function here
int dfs(const vector<string>& grid,int a,int b,vector<vector<bool>>& vis,vector<char>& tpath){
    vis[a][b] = true;
    int lmin = 1e6;
    // if the path ends without 'B',i.e, all other 3 sides are #, 
    //the path is not valid,then lmin remains 1e6
    int v = grid.size();
    int h = grid[0].size();
    for(int i=0;i<4;i++){
        int x1 = a + dx[i],y1 = b + dy[i];
        if(x1>=0 && x1<v && y1>=0 && y1<h && !vis[x1][y1]){
            if(grid[x1][y1] == 'B'){
                tpath.push_back(dir[i]);
                if(tpath.size() < fpath.size()){
                    fpath = tpath;
                }
                tpath.pop_back(); // backtrack
                vis[a][b] = false; // backtrack    
                return 1;
            }
            if(grid[x1][y1] == '.'){
                tpath.push_back(dir[i]);
                int result = dfs(grid,x1,y1,vis,tpath);
                if(result!=1e6){
                    lmin = min(lmin,1+result);
                }
                tpath.pop_back(); // backtrack
            }
        }
    }
    vis[a][b] = false; // backtrack
    return lmin;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin >> n >> m;
    vector<string> grid(n);in(grid,n)
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    vector<char> tpath;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'A'){
                int res = dfs(grid,i,j,vis,tpath);
                if(res != 1e6) {cout << "YES\n" << res << "\n";out(fpath,fpath.size(),"");}
                else cout << "NO";
            }
        }
    }
    return 0;
}