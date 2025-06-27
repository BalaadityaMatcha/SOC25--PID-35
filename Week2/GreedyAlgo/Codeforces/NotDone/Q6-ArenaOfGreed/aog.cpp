//Wrong Understanding of Question.

#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
unordered_map<ll,ll> greedy = {{0, 0}};
ll greed(ll t) {
    if (t < 100000 && greedy.count(t)) return greedy[t];
    ll coins = 0;
    if (t % 2 == 1) {
        coins = 1 + greed((t - 1) / 2);
    } else {
        ll half = t / 2;
        ll coins1 = half + greed((half % 2) ? (half - 1) : (half / 2));
        ll coins2 = 1 + greed(t - 2);
        coins = max(coins1, coins2);
    }
    if (t < 100000) {
        greedy[t] = coins;
    }
    return coins;
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;cin >> t;
    while(t--){
        ll n;cin >> n;
        cout << greed(n) << "\n";
    }
    return 0;
}