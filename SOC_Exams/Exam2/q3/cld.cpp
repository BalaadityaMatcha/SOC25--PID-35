#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

const ll mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int t;
    cin >> t;
    
    while(t--) {
        string s;
        cin >> s;
        int n = s.length();
        char check = s[n-1];
        
        ll ans = 0;
        
        // Precompute all suffix differences
        vector<int> suffix_diff(n);
        suffix_diff[n-1] = 0;
        for(int j = n-2; j >= 0; j--) {
            suffix_diff[j] = suffix_diff[j+1] + (s[j+1] == check ? -1 : 1);
        }
        
        // For each position i, use a map to track which j values give temp_diff = 0
        map<int, ll> count_map; // diff_value -> sum of (n-j) for positions with this diff
        
        // Initialize map with all j positions
        for(int j = n-1; j >= 0; j--) {
            count_map[suffix_diff[j]] = (count_map[suffix_diff[j]] + (n-j)) % mod;
        }
        
        for(int i = n-2; i >= 0; i--) {
            int base_diff = 1 + (s[i] == check ? 1 : -1);
            
            // We want temp_diff = base_diff + suffix_diff[j] = 0
            // So suffix_diff[j] = -base_diff
            int target = -base_diff;
            
            // Remove current position i from consideration (j must be > i)
            count_map[suffix_diff[i]] = (count_map[suffix_diff[i]] - (n-i) + mod) % mod;
            
            // Add contribution if target exists
            if(count_map.count(target) && count_map[target] > 0) {
                ans = (ans + (ll)(i+1) * count_map[target]) % mod;
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}