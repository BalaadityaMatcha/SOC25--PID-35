#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
int mod = 998244353;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int q;cin >> q;
    vector<pair<int,int>> func;
    int i=-1;
    int last_i=-2;
    int last_size=0;
    ll u=0,v=0;
    while(q--){
        int query;cin >> query;
        if(query==0){
            int a,b;cin >> a >> b;
            func.push_back({a,b});
        }
        else if(query==1){last_i=i;i++;}
        else{
            int x;cin >> x;
            int func_size = (int)func.size();
            if(i == func_size-1){cout << x << "\n";}
            else{
                if(last_i != i){
                    u=1;v=0;
                    for(int j=func_size-1;j>i;j--){
                        ll temp = u;
                        u=((func[j].first)*temp) %mod;
                        v=(((func[j].second)*temp)%mod+v)%mod;
                    }
                    last_i=i;
                    last_size=func_size;
                    cout << ((u*x)%mod + v)%mod << "\n";
                    continue;
                }
                if(last_size != func_size){
                    while(last_size < func_size){
                        u = ((func[last_size].first)*u) % mod;
                        v = (((func[last_size].first)*v) % mod + func[last_size].second) % mod;
                        last_size++;
                    }
                    cout << ((u*x)%mod + v)%mod << "\n";
                    continue;
                }
                else{   // f2(f1(x)) = a2(a1 x + b1)+b2
                    cout << ((u*x)%mod + v)%mod << "\n";
                }
            }
            last_size = func.size();
        }

    }
    return 0;
}