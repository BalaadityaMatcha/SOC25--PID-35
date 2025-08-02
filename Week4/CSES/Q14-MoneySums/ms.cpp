/*
Learnt this solution and also learnt some special property of bitset
bitset is stored as a bit-string, bit operators like shifts,flips,etc..
b.set(i);       // sets bit i to 1
b.reset(i);     // sets bit i to 0
b.flip(i);      // toggles bit i
b.test(i);      // returns true if bit i is 1
b.any();        // returns true if any bit is 1
b.none();       // returns true if all bits are 0
b.count();      // number of bits set to 1
b.to_string();  // returns string of 0s and 1s
b << k;         // shifts all bits left by k
b >> k;         // shifts all bits right by k
*/

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
    int n;cin >> n;
    vi a(n);in(a,n)
    const int max_possible_sum = 1e5;
    bitset<max_possible_sum + 1> possible;
    possible[0]=1;
    for(auto x : a){
        possible |= possible << x;
    }
    int size=0;
    for(int i=1;i<=max_possible_sum;i++){
        if(possible[i]) size++;
    }
    cout << size << "\n";
    for(int i=1;i<=max_possible_sum;i++){
        if(possible[i]) cout << i << " ";
    }
    return 0;
}