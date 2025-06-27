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
    int n;cin >> n;
    while(n--){
        int x;cin >> x;
        if(x==1){cout << "1\n";continue;}
        int k = x;unordered_map<int,int> freq;
        while(k%2==0){
                freq[2]++;
                k=k>>1;
        }
        for(int i=3;i*i<=k;i+=2){
            while(k%i==0){
                freq[i]++;
                k/=i;
            }
        }
        int ans = 1;
        for(auto [key,value] : freq){
            ans*=(value+1);
        }
        if(k!=1) ans*=2;
        cout << ans << "\n";
    }
    return 0;
}