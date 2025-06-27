/* chatgpt suggested to use multiset instead of
   finding max value using a loop */

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
    int x,n;cin >> x >> n;
    set<int> p = {0,x};
    multiset<int> dis = {x};
    for(int i=0;i<n;i++){
        int pi;cin >> pi;
        auto it = p.upper_bound(pi);
        int r = *it;
        int l = *prev(it);
        p.insert(pi);
        dis.erase(dis.find(r-l));
        dis.insert(pi - l);dis.insert(r-pi);
        cout << *dis.rbegin() << " ";
    }
    return 0;
}