/*
I initially wrote recursive which is slower
Chatgpt suggested bottom-up approach since i need to
calculate from bottom to top anyways in recursion.

*/

#include<bits/stdc++.h>
#define ll long long int
#define out(a,n,k) for(int lambda=0;lambda<n;lambda++){cout<<a[lambda]<<k;}
#define in(a,n) for(int lambda=0;lambda<n;lambda++){cin>>a[lambda];}
#define endl '\n'
#define vi vector<int>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s1, s2;cin >> s1 >> s2;
    int l1 = s1.length(),l2 = s2.length();
    //Memory can be made efficient to O(min(l1+1,l2+1))
    string big = (l1 >= l2) ? s1 : s2;
    string small = (l1 >= l2) ? s2 : s1;
    int bs = big.size()+1;
    int ss = small.size()+1;
    vi dp(ss),prev(ss);
    for (int i = 0; i < ss; ++i) prev[i] = i;

    for (int i = 1; i < bs; ++i) {
        for (int j = 0; j < ss; ++j) {
            if(j==0){dp[j]=i;continue;}
            if (big[i - 1] == small[j - 1]) {
                dp[j] = prev[j - 1];  // already calculated value
            } else {
                dp[j] = min({
                    prev[j] + 1,    // delete
                    dp[j - 1] + 1,    // insert
                    prev[j - 1] + 1 // replace
                });
            }
        }
        swap(dp,prev);
    }
    cout << prev[ss-1] << '\n';

    /*
    same TC but O(l1*l2) space
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 0; i <= l1; ++i) dp[i][0] = i;
    for (int j = 0; j <= l2; ++j) dp[0][j] = j;

    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // already calculated value
            } else {
                dp[i][j] = min({
                    dp[i - 1][j] + 1,    // delete
                    dp[i][j - 1] + 1,    // insert
                    dp[i - 1][j - 1] + 1 // replace
                });
            }
        }
    }
    cout << dp[l1][l2] << '\n';
    */
    return 0;
}
