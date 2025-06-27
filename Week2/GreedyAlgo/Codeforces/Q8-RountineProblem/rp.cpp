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
    int a,b,c,d; cin >> a >> b >> c >> d;
    double k1 = static_cast<double>(a)/static_cast<double>(c);
    double k2 = static_cast<double>(b)/static_cast<double>(d);
    char code;int den,fnum,fden;
    double area_cov;
    if(k1*d <= b){
        if(k2*c > a){
            code='a';
        } 
        else{
            area_cov = max(k1*k1*c*d/(a*b),k2*k2*c*d/(a*b));
            code=(area_cov == k1*k1*c*d/(a*b) ? 'a' : 'b');
        }
    }
    else{
        code='b';
    }
    if(code =='a'){
        den = b*c;
        fnum = b*c - a*d;
    }
    if(code == 'b'){
        den = d*a;
        fnum = d*a - b*c;
    }
    int g = gcd(fnum,den);
    fnum/=g;fden=den/g;
    cout << fnum << "/" << fden;
    return 0;
}