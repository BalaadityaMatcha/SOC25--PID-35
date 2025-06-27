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
        int x,y;cin >> x >> y;
        if((x&y)==0){cout << "0\n";continue;}
        vi a(63),b(63),k(63);
        int p=x,q=y;
        int i=0;
        while(p>0){
            a[i]=p%2;p/=2;i++;
        }
        i=0;
        while(q>0){
            b[i]=q%2;q/=2;i++;
        }
        i=0;
        while(i<63){
            if((a[i]==1 && b[i]==0) || (a[i]==0 && b[i]==1)){
                k[i]=1;swap(a[i],b[i]);
                if(a[i]==0){
                    for(int j=i+1;j<63;j++){
                    if(!a[j]){a[j]=1;break;}
                    else{a[j]=0;}
                    }
                }   // 2 5  010 101
                else{
                    for(int j=i+1;j<63;j++){
                    if(!b[j]){b[j]=1;break;}
                    else{b[j]=0;}
                    }
                }
            }
            else if(a[i]==0 && b[i]==0){k[i]=0;}
            else{
                k[i]=1;a[i]=0;b[i]=0; // 10011 01010
                for(int j=i+1;j<63;j++){
                    if(!a[j]){a[j]=1;break;}
                    else{a[j]=0;} 
                }
                for(int j=i+1;j<63;j++){
                    if(!b[j]){b[j]=1;break;}
                    else{b[j]=0;}
                }
            }
            i++;
        }
        ll ans = 0,c_pow=1;
        for(int j=0;j<63;j++){
            ans+=(k[j])*(c_pow);
            c_pow*=2;
        }
        if (ans > pow(10,18)){cout << "-1\n";continue;}
        cout << ans << "\n";
    }
    return 0;
}