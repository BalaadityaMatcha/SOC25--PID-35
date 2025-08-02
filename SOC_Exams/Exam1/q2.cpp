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
    string s;cin >> s;
    int begin = 0;
    int end = s.length()-1;
    while(s[begin]!='(') begin++;
    while(s[end]!=')') end--;
    if(begin>end){cout << "0";return 0;}
    vi indices={begin+1,end+1};
    begin++;
    end--;
    while(begin<end){
        while(s[begin]!='(') begin++;  // ())())
        while(s[end]!=')') end--;
        if(begin<end){indices.push_back(begin+1);indices.push_back(end+1);begin++;end--;}
    }
    cout << "1\n";
    cout << indices.size() << "\n";
    sort(indices.begin(),indices.end());
    out(indices,indices.size()," ");
    return 0;
}