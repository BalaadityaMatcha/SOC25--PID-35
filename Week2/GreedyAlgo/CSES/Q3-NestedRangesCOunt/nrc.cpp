#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin >> n;
    vector<pair<pair<int,int>,int>> p(n);vector<pair<int,int>> r(n);
    for(int i=0;i<n;i++){
        int x,y;cin >> x >> y;
        p[i].first={x,y};
        p[i].second=i;
    }
    sort(p.begin(),p.end(),[](const auto& a, const auto& b){
        if((a.first).first != (b.first).first) return (a.first).first < (b.first).first;
        else return (a.first).second > (b.first).second;
    });
    unordered_map<int,pair<int,int>> maxx;
    for(int i=0;i<n;i++){
        
    }
    for(int i=n-2;i>=0;i--){
        if((p[i].first).second < minsec){
            minsec=(p[i].first).second;
        }
        else{
            r[(p[i].second)].first=1;
        }
    }
    for(int i=0;i<n;i++){
        cout << r[i].first << " ";
    }
    cout << "\n";
    for(int i=0;i<n-1;i++){
        cout << r[i].second << " ";
    }
    cout << r[n-1].second;
    return 0;
}