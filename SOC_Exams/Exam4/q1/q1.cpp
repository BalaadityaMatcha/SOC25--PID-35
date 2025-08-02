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
    int t;cin >> t;
    while(t--){
        int n,m,k;cin >> n >> m >> k;
        string sa,sb;cin >> sa >> sb;
        vector<char> a(sa.begin(),sa.end()),b(sb.begin(),sb.end());
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<char> c;
        int continuity = 1;
        int curr = (a[0] > b[0] ? 1 : 0);
        int posa=0,posb=0;
        if(curr){c.push_back(b[0]);posb++;}
        else{c.push_back(a[0]);posa++;}
        while(posa!=n && posb!=m){
            if(continuity < k){
                if(curr){
                    if(b[posb] < a[posa]){c.push_back(b[posb]);posb++;continuity++;}
                    else{
                        continuity=1;
                        curr = 0;
                        c.push_back(a[posa]);posa++;
                    }
                }
                else{
                    if(a[posa] < b[posb]){c.push_back(a[posa]);posa++;continuity++;}
                    else{
                        continuity=1;
                        curr = 1;
                        c.push_back(b[posb]);posb++;
                    }
                }
            }
            else{
                if(curr){
                    c.push_back(a[posa]);posa++;curr=0;
                }
                else{
                    c.push_back(b[posb]);posb++;curr=1;
                }
                continuity=1;
            }
        }
        out(c,c.size(),"");cout << "\n";
    }
    return 0;
}