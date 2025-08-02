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
        string s;cin >> s;
        int n= s.length();
        vi sum(n-1);
        vector<pair<int,int>> tens;
        for(int i=0;i<n-1;i++){  // if all sums < 10 first sum would prevail
            sum[i]=s[i]-'0' + s[i+1] - '0';
            // if there are some sum >= 10 , the last sum >= 10 would prevail.
            if(sum[i]>=10) tens.push_back({sum[i],i});
        }
        int rem_pos;
        if(tens.size()){
            rem_pos = tens[tens.size()-1].second;
        }
        else{
            rem_pos = 0;
        }
        for(int i=0;i<n;i++){
            if(i==rem_pos){
                cout << sum[i];i++;
            }
            else{cout << s[i];}
        }
        cout << "\n";
    }
    return 0;
}