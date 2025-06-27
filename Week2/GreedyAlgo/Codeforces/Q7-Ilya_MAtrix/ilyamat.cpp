// Claude's suggestion for using power4 as parameter to reduce pow() calls
//There's also an iterative approach given by Claude derived from my code(but i didn't understood😭).
#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

//Your function here
ll beauty(const vi& a,int j,int n,int level,int power4){
    if(level==n) return 1LL* a[j];
    ll sum=1LL*a[j];
    level++;
    int nextpower=power4*4;
    int i=j;
    sum+=beauty(a,i,n,level,nextpower);
    i+=power4;
    sum+=beauty(a,i,n,level,nextpower);
    i+=power4;
    sum+=beauty(a,i,n,level,nextpower);
    i+=power4;
    sum+=beauty(a,i,n,level,nextpower);
    return sum;
}

// Alternative iterative approach (even faster for large inputs)
ll beauty_iterative(const vi& a, int n) {
    ll total = 0;
    int size = 1 << (2 * n); // 4^n
    
    // Process level by level
    for(int level = 0; level < n; level++) {
        int level_size = 1 << (2 * level); // 4^level
        int step = 1 << (2 * (n - level - 1)); // 4^(n-level-1)
        
        for(int block = 0; block < level_size; block++) {
            int base_idx = block * (step * 4);
            // Add the first element of each group of 4 at this level
            total += 1LL * a[base_idx];
        }
    }
    
    // Add the leaf level
    for(int i = 0; i < size; i++) {
        total += 1LL * a[i];
    }
    
    return total;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int four_n; cin >> four_n;
    vi a(four_n);in(a,four_n)
    sort(a.rbegin(),a.rend());
    int n = log2(four_n)/2;
    cout << beauty(a,0,n,0,1);
    cout << " " << beauty_iterative(a,n);
    return 0;
}