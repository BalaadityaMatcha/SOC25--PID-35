/* ChatGpt's code(nice one) made from yours.
   He added the set and also the count_bad condition which made it easy.
   TC = O(m+n)
   SC = O(n)*/


#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int count_bad(const vi &indices, int i) {
    return (i >= 1 && i < (int)indices.size() - 1 && indices[i] > indices[i + 1]) ? 1 : 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vi x(n);
    for(int i=0;i<n;i++){
        cin >> x[i];
    }

    vi indices(n + 2);  // 1-based indexing, guard with n+2
    for (int i = 0; i < n; ++i) indices[x[i]] = i;

    int rounds = 1;
    for (int i = 1; i < n; ++i){
        if (indices[i] > indices[i + 1]) rounds++;
    }
    while (m--) {
        int a, b; cin >> a >> b; --a; --b;
        set<int> affected = {
            x[a], x[b],
            x[a] - 1, x[a] + 1,
            x[b] - 1, x[b] + 1
        };

        for (int i : affected){
            if (i >= 1 && i < n) rounds -= count_bad(indices, i);
        }
        swap(x[a], x[b]);
        indices[x[a]] = a;
        indices[x[b]] = b;

        for (int i : affected){
            if (i >= 1 && i < n) rounds += count_bad(indices, i);
        }
        cout << rounds << '\n';
    }
    return 0;
}
