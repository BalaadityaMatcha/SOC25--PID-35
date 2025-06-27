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
    if(n>4){
        int k = 2*floor(n/2);
        for(int i=k;i>0;i-=2){
            cout << i << " ";
        }
        if(n%2){
            k+=(n%2);
            for(int i=k;i>0;i-=2){
                cout << i << " ";
            }
        }
        else{
            k-=1;
            for(int i=k;i>0;i-=2){
                cout << i << " ";
            }
        }
    }
    else if(n==1) cout << "1";
    else if(n==4) cout << "2 4 1 3";
    else cout << "NO SOLUTION";
    return 0;
}