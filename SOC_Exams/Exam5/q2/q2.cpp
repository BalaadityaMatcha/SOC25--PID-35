#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while(t--) {
        int n;cin >> n;
        
        vector<ll> a(n);in(a,n)
        vector<ll> choices(a.begin()+1,a.end());
        sort(choices.begin(),choices.end(),greater<long long>());
        long long total_moves = a[0];
        for(int i = 0; i < choices.size(); i++) {
            if(i % 2 == 0) {
                total_moves += choices[i];
            } else {
                total_moves += choices[i];
            }
        }
        if(total_moves % 2 == 1) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
    
    return 0;
}
