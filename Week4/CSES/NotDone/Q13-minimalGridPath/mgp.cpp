//incomplete

#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
void func(const vector<string>& a,int n,pair<int,int> l,vector<vector<char>>& memo){
    int x=l.first,y=l.second;
    if (!memo[x][y].empty()) return;
    while(x!=n-1 || y!=n-1){
        if(x==n-1){
            memo[x][y]='R';y++;continue;
        }
        if(y==n-1){
            memo[x][y]='D';x++;continue;
        }
        else{
            if(a[x+1][y]!=a[x][y+1]){
                if(a[x+1][y] > a[x][y+1]){
                    memo[x][y]='R';y++;
                }
                else{
                    memo[x][y]='D';x++;
                }
            }
            else{
                memo[x][y]=edo_func(a,n,{x+1,y},memo); // incomplete
                break;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin >> n;
    vector<string> a(n);in(a,n)
    vector<vector<char>> memo(n,vector<string>(n));
    cout << func(a,n,{0,0},memo);
    return 0;
}