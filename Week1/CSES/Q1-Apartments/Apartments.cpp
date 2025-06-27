#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

int accepted(vi& a, vi& b, int& n, int& m, int& k){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int j=0;
    int count=0;
    for(int i=0;i<n;i++){
        while(j<m){
            if(b[j]<a[i]-k) j++;
            else if(b[j]<=a[i]+k){
                count++;
                j++;
                break;
            }
            else break;
        }
    }
    return count;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    vi a(n),b(m);
    in(a,n);
    in(b,m);
    cout << accepted(a,b,n,m,k) << "\n";
    return 0;
}