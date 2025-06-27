/* Completely done by me for TC - O(n), chatgpt helped in optimizing SC by replacing
 <int,pair<int,int>> with <int,int> in lastIndex */

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
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        int minl=n;
        vector<int> a(n);unordered_map<int,int> lastIndex;
        for(int s=0;s<n;s++){
            cin >> a[s];
            if (lastIndex.count(a[s])) {
                minl = min(minl, s - lastIndex[a[s]]);
            }
            lastIndex[a[s]] = s;
        }
        if(minl==n) cout << "-1\n";
        else cout << minl+1 << "\n";
    }
    return 0;
}